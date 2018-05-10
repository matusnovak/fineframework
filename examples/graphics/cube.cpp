#include <iostream>
#include <ffw/graphics.h>
#include <ffw/math.h>

#define EYES_DEFAULT_POS 1.7f, 1.7f, 1.7f
#define STRINGIFY(x) #x

///=============================================================================
static const std::string vertexShaderCode = "#version 130\n" STRINGIFY(
in vec3 position;
in vec3 color;

out vec3 out_color;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main() {
    out_color = color;
    gl_Position = projection * view * model * vec4(position, 1.0f);
}
);

///=============================================================================
static const std::string fragmentShaderCode = "#version 130\n" STRINGIFY(
in vec3 out_color;
void main() {
    gl_FragColor = vec4(out_color, 1.0f);
}
);

static const float cubeVertices[] = {
    -1.0f, -1.0f, -1.0f, 0.0f, 0.0f, 0.0f,
    -1.0f, -1.0f,  1.0f, 0.0f, 1.0f, 0.0f,
     1.0f, -1.0f,  1.0f, 0.0f, 1.0f, 1.0f,
     1.0f, -1.0f, -1.0f, 0.0f, 0.0f, 1.0f,

    -1.0f, -1.0f, -1.0f, 0.0f, 0.0f, 0.0f,
    -1.0f,  1.0f, -1.0f, 1.0f, 0.0f, 0.0f,
     1.0f,  1.0f, -1.0f, 1.0f, 0.0f, 1.0f,
     1.0f, -1.0f, -1.0f, 0.0f, 0.0f, 1.0f,

    -1.0f, -1.0f,  1.0f, 0.0f, 1.0f, 0.0f,
    -1.0f,  1.0f,  1.0f, 1.0f, 1.0f, 0.0f,
    -1.0f,  1.0f, -1.0f, 1.0f, 0.0f, 0.0f,
    -1.0f, -1.0f, -1.0f, 0.0f, 0.0f, 0.0f,

    -1.0f, -1.0f,  1.0f, 0.0f, 1.0f, 0.0f,
     1.0f, -1.0f,  1.0f, 0.0f, 1.0f, 1.0f,
     1.0f,  1.0f,  1.0f, 1.0f, 1.0f, 1.0f,
    -1.0f,  1.0f,  1.0f, 1.0f, 1.0f, 0.0f,

     1.0f, -1.0f,  1.0f, 0.0f, 1.0f, 1.0f,
     1.0f, -1.0f, -1.0f, 0.0f, 0.0f, 1.0f,
     1.0f,  1.0f, -1.0f, 1.0f, 0.0f, 1.0f,
     1.0f,  1.0f,  1.0f, 1.0f, 1.0f, 1.0f,

     1.0f,  1.0f, -1.0f, 1.0f, 0.0f, 1.0f,
     1.0f,  1.0f,  1.0f, 1.0f, 1.0f, 1.0f,
    -1.0f,  1.0f,  1.0f, 1.0f, 1.0f, 0.0f,
    -1.0f,  1.0f, -1.0f, 1.0f, 0.0f, 0.0f,
};

///=============================================================================
class App : public ffw::GLFWRenderWindow {
public:
    App() {
        mouseDown = false;
        mouseOld = 0;
        eyesRot = 0;
    }

    ~App() {
    }

    bool setup() override {
        // Load shader
        try {
            shader.createFromData("", vertexShaderCode, fragmentShaderCode);
        }
        catch (std::exception& e) {
            // Error while loading shader
            std::cerr << "Failed to create shader!" << std::endl << e.what() << std::endl;
            return false;
        }

        vbo.create(cubeVertices, sizeof(cubeVertices), GL_STATIC_DRAW);

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

        // set the model matrix
        modelMatrix = ffw::Mat4x4f(1.0f);

        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glEnable(GL_DEPTH_TEST);
        glClearColor(0.3f, 0.3f, 0.3f, 1.0f);

        return true;
    }

    void render() override {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        // Begin shader program
        shader.bind();
        // bind cube object
        vbo.bind();
        // set uniforms and attribute pointers
        // set the position attribute to length 3 starting at position 0 in the vertex buffer
        // Each vertex has 8 floats total: {Px, Py, Pz, Nx, Ny, Nz, U, V}
        // Where P is position, N is normal and UV are texture coordinates
        shader.setAttributePointerf(shader.getAttributeLocation("position"), 3, 6 * sizeof(float), (void*)(0 * sizeof(float)));
        // set the normal attribute to length 3 starting at position 3 in the vertex buffer
        shader.setAttributePointerf(shader.getAttributeLocation("color"), 3, 6 * sizeof(float), (void*)(3 * sizeof(float)));
        // set the model, view and projection matrices
        shader.setUniformMatrix4fv(shader.getUniformLocation("model"), &modelMatrix[0], 1);
        shader.setUniformMatrix4fv(shader.getUniformLocation("view"), &viewMatrix[0], 1);
        shader.setUniformMatrix4fv(shader.getUniformLocation("projection"), &projectionMatrix[0], 1);
        // draw whole object
        shader.drawArrays(GL_QUADS, 0, vbo.getSize() / sizeof(float) / 6); // 6 floats per one vertex
        // Stop object shader
        shader.unbind();
        vbo.unbind();
    }

    void close() override {
        shader.destroy();
        vbo.destroy();
    }

    void textInputEvent(unsigned int C) override {

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
        }
        else {
            mouseOld.x = mousex;
            mouseOld.y = mousey;
        }
    }

    void mouseScrollEvent(int scroll) override {
    }

    void mouseButtonEvent(ffw::MouseButton button, ffw::Mode mode) override {
        if (mode == ffw::Mode::PRESSED)mouseDown = true;
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
    ffw::Shader shader;
    ffw::Vbo vbo;

    // Model, view and projection matrices used in shader
    ffw::Mat4x4f projectionMatrix;
    ffw::Mat4x4f viewMatrix;
    ffw::Mat4x4f modelMatrix;

    ffw::Vec3f eyesPos;
    bool mouseDown;
    ffw::Vec2i mouseOld;
    ffw::Vec2f eyesRot;
};

///=============================================================================
int main(int argc, char *argv[]) {
    // Instance to our app class
    App app;

    // set arguments
    ffw::GLFWRenderWindowArgs args;
    args.size.set(800, 600);
    args.title = "Cube Example";
    args.samples = 4;

    // create window
    if (!app.create(args, NULL)) {
        std::cerr << "Failed to create window!" << std::endl;
        return 1;
    }

    // Run setup
    if (!app.setup()) {
        std::cerr << "Failed to setup window!" << std::endl;
        return 1;
    }

    // The main window loop
    while (app.shouldRender()) {
        app.renderFrame();
        app.waitForEvents();
    }

    // destroy window, this will delete all graphics data used by the window.
    // Must be called after the setup and before the graphics
    // is terminated
    app.destroy();
    return 0;
}