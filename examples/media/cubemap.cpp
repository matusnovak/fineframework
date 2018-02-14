#include <ffw/graphics.h>
#include <ffw/media.h>
#include <ffw/math.h>

#define EYES_DEFAULT_POS 1.0f, 1.0f, 1.0f
#define STRINGIFY(x) #x

///=============================================================================
// Monkey shader (vertex)
static const std::string monkeyVertexShaderCode = "#version 140\n" STRINGIFY(
in vec3 position;
in vec3 normals;
in vec2 texCoords;

out vec3 v_normals;
out vec3 v_position;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main() {
    v_normals = mat3(transpose(inverse(model))) * normals;
    v_position = vec4(model * vec4(position, 1.0)).xyz;
    gl_Position = projection * view * model * vec4(position, 1.0);
}
);


static const std::string monkeyFragmentShaderCode = "#version 140\n" STRINGIFY(
in vec3 v_normals;
in vec3 v_position;

uniform samplerCube sampler;
uniform vec3 eyespos;

const float brightness = 2.0;

void main() {
    vec3 I = normalize(v_position - eyespos);
    vec3 R = reflect(I, normalize(v_normals));
    vec3 reflection = texture(sampler, R).rgb;
    gl_FragColor = vec4(mix(R, reflection, 0.8), 1.0) * brightness;
}
);

///=============================================================================
// Skybox shader credits: https://learnopengl.com/#!Advanced-OpenGL/Cubemaps
static const std::string skyboxVertexShaderCode = "#version 130\n" STRINGIFY(
in vec3 position;

out vec3 v_texcoords;

uniform mat4 projection;
uniform mat4 view;

void main(){
    v_texcoords = position;
    gl_Position = projection * view * vec4(position * 100.0, 1.0);
}  
);


static const std::string skyboxFragmentShaderCode = "#version 130\n" STRINGIFY(
in vec3 v_texcoords;

uniform samplerCube sampler;

const float brightness = 2.0;

void main(){    
    gl_FragColor = texture(sampler, v_texcoords) * brightness;
}
);

// The following represents skybox vertices needed to create a 3D cube
float skyboxVertices[] = {
    // positions          
    -1.0f,  1.0f, -1.0f,
    -1.0f, -1.0f, -1.0f,
     1.0f, -1.0f, -1.0f,
     1.0f, -1.0f, -1.0f,
     1.0f,  1.0f, -1.0f,
    -1.0f,  1.0f, -1.0f,

    -1.0f, -1.0f,  1.0f,
    -1.0f, -1.0f, -1.0f,
    -1.0f,  1.0f, -1.0f,
    -1.0f,  1.0f, -1.0f,
    -1.0f,  1.0f,  1.0f,
    -1.0f, -1.0f,  1.0f,

     1.0f, -1.0f, -1.0f,
     1.0f, -1.0f,  1.0f,
     1.0f,  1.0f,  1.0f,
     1.0f,  1.0f,  1.0f,
     1.0f,  1.0f, -1.0f,
     1.0f, -1.0f, -1.0f,

    -1.0f, -1.0f,  1.0f,
    -1.0f,  1.0f,  1.0f,
     1.0f,  1.0f,  1.0f,
     1.0f,  1.0f,  1.0f,
     1.0f, -1.0f,  1.0f,
    -1.0f, -1.0f,  1.0f,

    -1.0f,  1.0f, -1.0f,
     1.0f,  1.0f, -1.0f,
     1.0f,  1.0f,  1.0f,
     1.0f,  1.0f,  1.0f,
    -1.0f,  1.0f,  1.0f,
    -1.0f,  1.0f, -1.0f,

    -1.0f, -1.0f, -1.0f,
    -1.0f, -1.0f,  1.0f,
     1.0f, -1.0f, -1.0f,
     1.0f, -1.0f, -1.0f,
    -1.0f, -1.0f,  1.0f,
     1.0f, -1.0f,  1.0f
};

///=============================================================================
class App: public ffw::GLFWRenderWindow {
public:
    App(){
        mouseDown = false;
    }

    ~App(){
    }

    bool setup() override {
        // Load shader
        try {
            monkeyShader.createFromData("", monkeyVertexShaderCode, monkeyFragmentShaderCode);
        } catch(std::exception& e){
            // Error while loading shader
            std::cerr << "Failed to create monkey shader!" << std::endl << e.what() << std::endl;
            return false;
        }

        try {
            skyboxShader.createFromData("", skyboxVertexShaderCode, skyboxFragmentShaderCode);
        } catch(std::exception& e){
            // Error while loading shader
            std::cerr << "Failed to create skybox shader!" << std::endl << e.what() << std::endl;
            return false;
        }

        // Load skybox textures
        if(!skybox.create(1024, 1024, GL_RGB8, GL_RGB, GL_UNSIGNED_BYTE)){
            std::cerr << "Failed to create cubemap texture!" << std::endl;
            return false;
        }

        // The order of the files corresponds with the side index needed by ffw::TextureCubemap
        static const std::string filenames[6] = {
            "skybox_right.png",  // GL_TEXTURE_CUBE_MAP_POSITIVE_X = 0
            "skybox_left.png",   // GL_TEXTURE_CUBE_MAP_NEGATIVE_X = 1
            "skybox_top.png",    // GL_TEXTURE_CUBE_MAP_POSITIVE_Y = 2
            "skybox_bottom.png", // GL_TEXTURE_CUBE_MAP_NEGATIVE_Y = 3
            "skybox_front.png",  // GL_TEXTURE_CUBE_MAP_POSITIVE_Z = 4
            "skybox_back.png",   // GL_TEXTURE_CUBE_MAP_NEGATIVE_Z = 5
        };

        for(int i = 0; i < 6; i++) {
            ffw::ImageBuffer buffer;
            if(!ffw::readImage(filenames[i], buffer)) {
                std::cerr << "Failed to load image: " << filenames[i] << " cannot read file!" << std::endl;
                return false;
            }

            if(buffer.getWidth() != 1024 || buffer.getHeight() != 1024 || buffer.getImageType() != ffw::ImageType::RGB_888) {
                std::cerr << "Failed to load image: " << filenames[i] << " expected 1024x1024 RGB (24-bit) image!" << std::endl;
                return false;
            }

            skybox.setPixels(0, 0, 0, 1024, 1024, i, buffer.getPtr());
        }

        // Load monkey OBJ directly into VBO
        if(!ffw::readObj("monkey.obj", &monkeyVbo)){
            std::cerr << "Failed to load monkey.obj!" << std::endl;
            return false;
        }

        // Load skybox VBO
        if(!skyboxVbo.create(skyboxVertices, sizeof(skyboxVertices), GL_STATIC_DRAW)) {
            std::cerr << "Failed to create skybox VBO!" << std::endl;
            return false;
        }
        
        eyesPos.set(EYES_DEFAULT_POS);
        
        // This is not the most efficient way to calculate 
        // Model-View-Projection
        // We are doing it this way just for the purpose
        // of the example...

        // get the aspect ratio of the window
        ffw::Vec2i windowSize = this->getSize();
        float aspectRatio = windowSize.x / float(windowSize.y);
        // create the projection matrix
        // 60 deg field of view
        // 0.1 near distance of frustum
        // 1000.0 far distance of frustum
        projectionMatrix = ffw::makeProjectionMatrix(60.0f, aspectRatio, 0.05f, 1000.0f);

        // set the view matrix
        //viewMatrix = ffw::Mat4x4f(1.0f);
        viewMatrix = ffw::makeLookAtMatrix(eyesPos, ffw::Vec3f(0.0f, 0.0f, 0.0f), ffw::Vec3f(0.0f, 1.0f, 0.0f));
        skyboxViewMatrix = ffw::makeLookAtMatrix(ffw::Vec3f(0.0f, 0.0f, 0.0f), -eyesPos, ffw::Vec3f(0.0f, 1.0f, 0.0f));

        // set the model matrix
        modelMatrix = ffw::Mat4x4f(1.0f);

        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

        return true;
    }

    void render() override {
        // Blending is needed by the font
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // Render the skybox
        glDisable(GL_DEPTH_TEST);

        skyboxShader.bind(); // Use shader
        skyboxVbo.bind(); // Bind VBO
        skybox.bind(); // Bind cube map texture

        skyboxShader.setUniform1i(skyboxShader.getUniformLocation("sampler"), 0);
        skyboxShader.setAttributePointerf(skyboxShader.getAttributeLocation("position"), 3, 3*sizeof(float), 0);
        skyboxShader.setUniformMatrix4fv(skyboxShader.getUniformLocation("view"), &skyboxViewMatrix[0], 1);
        skyboxShader.setUniformMatrix4fv(skyboxShader.getUniformLocation("projection"), &projectionMatrix[0], 1);
        // draw whole object
        skyboxShader.drawArrays(GL_TRIANGLES, 0, 36);

        // Render the monkey
        glEnable(GL_DEPTH_TEST);

        monkeyShader.bind();
        monkeyVbo.bind();
        skybox.bind(); // Bind skybox texture for reflection (see GLSL)

        // set uniforms and attribute pointers
        // set the texture sampler to 0 (GL_TEXTURE0)
        monkeyShader.setUniform1i(monkeyShader.getUniformLocation("sampler"), 0);
        // Set the eyes pos needed by the reflection algorithm
        monkeyShader.setUniform3f(monkeyShader.getUniformLocation("eyespos"), eyesPos);
        // set the position attribute to length 3 starting at position 0 in the vertex buffer
        // Each vertex has 8 floats total: {Px, Py, Pz, Nx, Ny, Nz, U, V}
        // Where P is position, N is normal and UV are texture coordinates
        monkeyShader.setAttributePointerf(monkeyShader.getAttributeLocation("position"), 3, 8*sizeof(float), (void*)(0*sizeof(float)));
        // set the normal attribute to length 3 starting at position 3 in the vertex buffer
        monkeyShader.setAttributePointerf(monkeyShader.getAttributeLocation("normals"), 3, 8*sizeof(float), (void*)(3*sizeof(float)));
        // set the texture coordinates attribute to length 2 starting at position 6 in the vertex buffer
        monkeyShader.setAttributePointerf(monkeyShader.getAttributeLocation("texCoords"), 2, 8*sizeof(float), (void*)(6*sizeof(float)));
        // set the model, view and projection matrices
        monkeyShader.setUniformMatrix4fv(monkeyShader.getUniformLocation("model"), &modelMatrix[0], 1);
        monkeyShader.setUniformMatrix4fv(monkeyShader.getUniformLocation("view"), &viewMatrix[0], 1);
        monkeyShader.setUniformMatrix4fv(monkeyShader.getUniformLocation("projection"), &projectionMatrix[0], 1);
        // draw whole object
        monkeyShader.drawArrays(GL_TRIANGLES, 0, monkeyVbo.getSize()/24);

        // Disable depth test
        // Depth test needs to be disabled in order to
        // draw user interface or any other 2D graphics components
        glDisable(GL_DEPTH_TEST);

        // Draw GUI or any 2D stuff here
    }

    void close() override {
        skybox.destroy();
        monkeyShader.destroy();
        monkeyVbo.destroy();
        skyboxShader.destroy();
        skyboxVbo.destroy();
    }

    void textInputEvent(unsigned int c) override {
    }

    void keyPressedEvent(ffw::Key key, ffw::Mode mode) override {
    }

    void mouseMovedEvent(int mousex, int mousey) override {
        if (mouseDown) {
            int diffx = mousex - mouseOld.x;
            int diffy = mousey - mouseOld.y;
            mouseOld.x = mousex;
            mouseOld.y = mousey;

            eyesRot.x += -diffx/2;
            eyesRot.y += -diffy/2;

            eyesPos.set(EYES_DEFAULT_POS);
            eyesPos.rotateY(eyesRot.x);

            // get penpedicular vector
            ffw::Vec3f axis((float)eyesPos.z, 0.0f, (float)-eyesPos.x);

            axis.normalize();

            //std::cout << "axis: " << axis << std::endl;
            eyesPos.rotateByAxis(eyesRot.y, axis);

            viewMatrix = ffw::makeLookAtMatrix(eyesPos, ffw::Vec3f(0.0f, 0.0f, 0.0f), ffw::Vec3f(0.0f, 1.0f, 0.0f));
            skyboxViewMatrix = ffw::makeLookAtMatrix(ffw::Vec3f(0.0f, 0.0f, 0.0f), -eyesPos, ffw::Vec3f(0.0f, 1.0f, 0.0f));
        }
        else {
            mouseOld.x = mousex;
            mouseOld.y = mousey;
        }
    }

    void mouseScrollEvent(int scroll) override {
    }

    void mouseButtonEvent(ffw::MouseButton button, ffw::Mode mode) override {
        if(mode == ffw::Mode::PRESSED)mouseDown = true;
        else mouseDown = false;
    }

    void windowResizedEvent(int width, int height) override {
        // Get the aspect ratio of the window
        float aspectRatio = width / float(height);
        // create the projection matrix
        // 60 deg field of view
        // 0.1 near distance of frustum
        // 1000.0 far distance of frustum
        projectionMatrix = ffw::makeProjectionMatrix(60.0f, aspectRatio, 0.05f, 1000.0f);
    }

    void windowMovedEvent(int windowx, int windowy) override {
    }

    void windowFocusEvent(bool focus) override {
    }

    void windowCloseEvent() override {
        this->shouldClose(true);
    }

    void filesDroppedEvent(std::vector<std::string> filelist) override {
    }

private:
    // Monkey stuff
    ffw::Vbo monkeyVbo;
    ffw::Shader monkeyShader;

    // Skybox stuff
    ffw::Vbo skyboxVbo;
    ffw::Shader skyboxShader;

    // Skybox texture
    ffw::TextureCubemap skybox;

    // Model, view and projection matrices used in shader
    ffw::Mat4x4f projectionMatrix;
    ffw::Mat4x4f skyboxViewMatrix;
    ffw::Mat4x4f viewMatrix;
    ffw::Mat4x4f modelMatrix;

    ffw::Vec3f eyesPos;
    bool mouseDown;
    ffw::Vec2i mouseOld;
    ffw::Vec2f eyesRot;
};

///=============================================================================
int main(int argc, char *argv[]){
    // Instance to our app class
    App app;

    // set arguments
    ffw::GLFWRenderWindowArgs args;
    args.size.set(800, 400);
    args.title = "Example Cubemap";
    args.samples = 4;

    // create window
    if(!app.create(args, NULL)){
        std::cerr << "Failed to create window!" << std::endl;
        return 1;
    }

    // Run setup
    if(!app.setup()){
        std::cerr << "Failed to setup window!" << std::endl;
        return 1;
    }

    // The main window loop
    while(app.shouldRender()){
        app.renderFrame();
        app.waitForEvents();
    }

    // destroy window, this will delete all graphics data used by the window.
    // Must be called after the setup and before the graphics
    // is terminated
    app.destroy();
    return 0;
}
