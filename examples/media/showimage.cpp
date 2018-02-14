#include <ffw/graphics.h>
#include <ffw/media.h>

#define STRING_TO_SHOW "Drop image file here"

///=============================================================================
class App: public ffw::GLFWRenderWindow {
public:
    App(){
    }

    ~App(){
    }

    bool setup() override {
        // Blending is needed by the font
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

        if(!font.createFromData(ffw::defaultFont, ffw::defaultFontSize, 18, 96)){
            std::cerr << "Failed to create font!" << std::endl;
            return false;
        }

        textSize = font.getStringSize(STRING_TO_SHOW);
        return true;
    }

    void render() override {
        this->beginFrame();

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        this->setDrawColor(ffw::rgb(0xFFFFFF)); // white color

        if(!imagePath.empty()){
            texture.destroy();

            ffw::ImageBuffer buffer;
            if(ffw::readImage(imagePath, buffer)){
                if (texture.createFromBuffer(buffer)) {
                    // Image loaded
                } 
                else {
                    std::cerr << "Texture failed to create from image: " << imagePath 
                        << " OpenGL does not support this image format!" << std::endl;
                }
            }
            else {
                std::cerr << "Image: " << imagePath << " failed to load!" << std::endl;
            }

            imagePath = "";
            texture.setFiltering(ffw::Texture::Filtering::LINEAR);
        }

        if(texture.isCreated()){
            // Finds dimension so the texture can fit into the window
            // contain image - finds a largets size and position of an image
            //                 that can fit into the area.
            // cover image - finds a largets size and position of an image
            //               that will fill entire area with no space left.
            // You can see live demo of CSS equivalent at:
            // http://www.w3schools.com/cssref/playit.asp?filename=playcss_background-size&preval=contain
            ffw::Vec4i ret = ffw::containImage(texture.getWidth(), texture.getHeight(), this->getSize().x, this->getSize().y);
            //ffw::vec4i ret = ffw::coverImage(texture.getWidth(), texture.getHeight(), this->getSize().x, this->getSize().y);

            // draw texture
            this->drawTexture2D(ret.x, ret.y, ret.z, ret.w, &texture);
        } 
        else {
            ffw::Vec2i textPos = this->getSize()/2 - textSize/2;
            this->drawString(textPos.x, textPos.y, &font, STRING_TO_SHOW);
        }

        this->endFrame();
    }

    void close() override {
        font.destroy();
        texture.destroy();
    }

    void textInputEvent(unsigned int c) override {
    }

    void keyPressedEvent(ffw::Key key, ffw::Mode mode) override {
    }

    void mouseMovedEvent(int mousex, int mousey) override {
    }

    void mouseScrollEvent(int scroll) override {
    }

    void mouseButtonEvent(ffw::MouseButton button, ffw::Mode mode) override {
    }

    void windowResizedEvent(int width, int height) override {
    }

    void windowMovedEvent(int windowx, int windowy) override {
    }

    void windowFocusEvent(bool focus) override {
    }

    void windowCloseEvent() override {
        this->shouldClose(true);
    }

    void filesDroppedEvent(std::vector<std::string> filelist) override {
        // There will be always at least one item in the vector
        imagePath = filelist[0];
    }

private:
    ffw::Texture2D texture;
    ffw::TrueTypeFont font;
    ffw::Vec2i textSize;
    std::string imagePath;
};

///=============================================================================
int main(int argc, char *argv[]){
    // Instance to our app class
    App app;

    // set arguments
    ffw::GLFWRenderWindowArgs args;
    args.size.set(800, 400);
    args.title = "Example show Image";
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

    //app.setSingleBufferMode(true);

    // The main window loop
    while(app.shouldRender()){
        app.renderFrame();
        app.poolEvents();
    }

    // destroy window, this will delete all graphics data used by the window.
    // Must be called after the setup and before the graphics
    // is terminated
    app.destroy();
}
