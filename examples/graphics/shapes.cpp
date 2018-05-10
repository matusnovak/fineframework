#include <ffw/graphics.h>
#include <iostream>
#include <iostream>

inline int RandomRange(int min, int max) {
    return (std::rand() % (max - min)) + min;
}
    

///=============================================================================
class App : public ffw::GLFWRenderWindow {
public:
    App() {
    }

    ~App() {
    }

    bool setup() override {
        if (!font.createFromFile("FreeSans.ttf", 14, 72)) {
            std::cerr << "Failed to create font from: \'FreeSans.ttf\' File is missing?" << std::endl;
            return false;
        }

        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

        return true;
    }

    void render() override {
        this->beginFrame();

        //const auto halfSize = getSize() / 2.0f;
        //this->transformMove(halfSize.x, halfSize.y);
        //this->transformRotate(mousePos.x / 2.0f);
        //this->transformMove(-halfSize.x, -halfSize.y);

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        this->setDrawColor(ffw::rgb(0xFFFFFF)); // White color
        this->setFillMode();
        this->setStrokeSize(1);

        this->drawString(10 + 0, 10, &font, "Rectangle:");
        this->drawString(10 + 260, 10, &font, "Rectangle rounded:");
        this->drawString(10 + 520, 10, &font, "Triangles:");

        this->drawString(10 + 0, 10 + 190, &font, "Circle:");
        this->drawString(10 + 260, 10 + 190, &font, "Arc:");
        this->drawString(10 + 520, 10 + 190, &font, "Lines:");

        this->drawString(10 + 0, 10 + 380, &font, "Bezier:");
        this->drawString(10 + 260, 10 + 380, &font, "Bezier thick:");
        this->drawString(10 + 520, 10 + 380, &font, "Quad:");

        // Rectangles
        this->setDrawColor(ffw::rgba(0xFF000080));
        this->drawRectangle(10, 30, 100, 100);
        this->setFillColor(ffw::rgba(0x00FF0080));
        this->setStrokeColor(ffw::rgba(0x0000FF80));
        this->setFillAndStrokeMode();
        this->setStrokeSize(5);
        this->drawRectangle(10 + 53, 30 + 23, 100, 100);
        this->setDrawColor(ffw::rgba(0x0000FF80));
        this->setStrokeMode();
        this->drawRectangle(10 + 106, 30 + 46, 100, 100);
        this->setFillMode();

        // Rounded rectangles
        this->setDrawColor(ffw::rgba(0xFF000080));
        this->drawRectangleRounded(10 + 260, 30, 100, 100, 10, 10, 10, 10);
        this->setFillColor(ffw::rgba(0x00FF0080));
        this->setStrokeColor(ffw::rgba(0x0000FF80));
        this->setFillAndStrokeMode();
        this->setStrokeSize(5);
        this->drawRectangleRounded(10 + 260 + 53, 30 + 23, 100, 100, 20, 20, 20, 20);
        this->setDrawColor(ffw::rgba(0x0000FF80));
        this->setStrokeMode();
        this->drawRectangleRounded(10 + 260 + 106, 30 + 46, 100, 100, 10, 20, 30, 40);
        this->setFillMode();

        // Triangles
        this->setDrawColor(ffw::rgba(0xFF000080));
        this->drawTriangle(10 + 520, 30,
                                       10 + 520 + 260, 30,
                                       10 + 520 + 260/2, 30 + 170/2);
        this->setFillColor(ffw::rgba(0x00FF0080));
        this->setStrokeColor(ffw::rgba(0x0000FF80));
        this->setFillAndStrokeMode();
        this->setStrokeSize(5);
        this->drawTriangle(10 + 520, 30, 
                                       10 + 520 + 260 / 2, 30 + 170 / 2,
                                       10 + 520, 30 + 170);
        this->setDrawColor(ffw::rgba(0x0000FF80));
        this->setStrokeMode();
        this->drawTriangle(10 + 520 + 260, 30,
                                       10 + 520 + 260 / 2, 30 + 170 / 2,
                                       10 + 520 + 260, 30 + 170);
        this->setFillMode();

        // Circles
        this->setDrawColor(ffw::rgba(0xFF000080));
        this->drawCircle(60, 80 + 190, 50);
        this->setFillColor(ffw::rgba(0x00FF0080));
        this->setStrokeColor(ffw::rgba(0x0000FF80));
        this->setFillAndStrokeMode();
        this->setStrokeSize(5);
        this->drawCircle(60 + 53, 80 + 190 + 23, 50);
        this->setDrawColor(ffw::rgba(0x0000FF80));
        this->setStrokeMode();
        this->drawCircle(60 + 106, 80 + 190 + 46, 50);
        this->setFillMode();

        // Arc
        this->setDrawColor(ffw::rgba(0xFF000080));
        this->drawArc(60 + 260, 80 + 190, 25, 50, 0.0, 270.0);
        this->setFillColor(ffw::rgba(0x00FF0080));
        this->setStrokeColor(ffw::rgba(0x0000FF80));
        this->setFillAndStrokeMode();
        this->drawArc(60 + 260 + 53, 80 + 190 + 23, 15, 50, 90.0, 235.0);
        this->setDrawColor(ffw::rgba(0x0000FF80));
        this->setStrokeMode();
        this->drawArc(60 + 260 + 106, 80 + 190 + 46, 35, 50, -90.0, 90.0);
        this->setFillMode();

        // Lines
        this->setStrokeSize(1);
        for (int i = 0; i <= 32; i++) {
            this->setDrawColor(ffw::rgb(i*8, 255 - i*8, 0));
            this->drawLine(
                10 + 520 + i * (260 / 32), 30 + 190,
                10 + 520 + (32 - i) * (260 / 32), 30 + 190 + 170
            );
        }

        this->setStrokeSize(5);
        for (int i = 0; i <= 8; i++) {
            this->setDrawColor(ffw::rgb(0, 255 - i * 32, i * 32));
            this->drawLine(
                10 + 520, 30 + 190 + (i) * (170 / 8),
                10 + 520 + 260, 30 + 190 + (8 - i) * (170 / 8)
            );
        }

        // Bezier
        this->setStrokeSize(1);
        this->setDrawColor(ffw::rgba(0xFF000080));
        this->drawBezier(
            10 + 5,       30 + 380 + 85, // Start
            10 + 5,       30 + 380,      // CP 0
            10 + 250 - 5, 30 + 380,      // CP 1
            10 + 250 - 5, 30 + 380 + 85  // End
        );
        this->setDrawColor(ffw::rgba(0x00FF0080));
        this->drawBezier(
            10 + 5, 30 + 380 + 85,       // Start
            10 + 5, 30 + 380 + 170,      // CP 0
            10 + 250 - 5, 30 + 380 + 170,// CP 1
            10 + 250 - 5, 30 + 380 + 85  // End
        );

        // Bezier thick
        this->setStrokeSize(10);
        this->setDrawColor(ffw::rgba(0xFF000080));
        this->drawBezier(
            10 + 270 + 5, 30 + 380 + 85, // Start
            10 + 270 + 5, 30 + 380,      // CP 0
            10 + 510 - 5, 30 + 380,      // CP 1
            10 + 510 - 5, 30 + 380 + 85  // End
        );
        this->setDrawColor(ffw::rgba(0x00FF0080));
        this->drawBezier(
            10 + 270 + 5, 30 + 380 + 85, // Start
            10 + 270 + 5, 30 + 380 + 170,// CP 0
            10 + 510 - 5, 30 + 380 + 170,// CP 1
            10 + 510 - 5, 30 + 380 + 85  // End
        );

        // To compare thick bezier, we draw normal one on top of thick one
        this->setStrokeSize(1);
        this->setDrawColor(ffw::rgba(0xFF000080));
        this->drawBezier(
            10 + 270 + 5, 30 + 380 + 85, // Start
            10 + 270 + 5, 30 + 380,      // CP 0
            10 + 510 - 5, 30 + 380,      // CP 1
            10 + 510 - 5, 30 + 380 + 85  // End
        );
        this->setDrawColor(ffw::rgba(0x00FF0080));
        this->drawBezier(
            10 + 270 + 5, 30 + 380 + 85, // Start
            10 + 270 + 5, 30 + 380 + 170,// CP 0
            10 + 510 - 5, 30 + 380 + 170,// CP 1
            10 + 510 - 5, 30 + 380 + 85  // End
        );

        // Quad
        this->setDrawColor(ffw::rgba(0xFF000080));
        this->drawQuad(
            10 + 520 + 50, 30 + 380 + 0,
            10 + 520 + 100, 30 + 380 + 50,
            10 + 520 + 50, 30 + 380 + 100,
            10 + 520 + 0, 30 + 380 + 50
        );
        this->setFillColor(ffw::rgba(0x00FF0080));
        this->setStrokeColor(ffw::rgba(0x0000FF80));
        this->setFillAndStrokeMode();
        this->setStrokeSize(5);
        this->drawQuad(
            10 + 520 + 53 + 50, 30 + 380 + 23 + 0,
            10 + 520 + 53 + 100, 30 + 380 + 23 + 50,
            10 + 520 + 53 + 50, 30 + 380 + 23 + 100,
            10 + 520 + 53 + 0, 30 + 380 + 23 + 50
        );
        this->setDrawColor(ffw::rgba(0x0000FF80));
        this->setStrokeMode();
        this->drawQuad(
            10 + 520 + 106 + 50, 30 + 380 + 46 + 0,
            10 + 520 + 106 + 100, 30 + 380 + 46 + 50,
            10 + 520 + 106 + 50, 30 + 380 + 46 + 100,
            10 + 520 + 106 + 0, 30 + 380 + 46 + 50
        );

        this->endFrame();
    }

    void close() override {
        std::cout << "Window is closing!" << std::endl;
    }

    void windowCloseEvent() override {
        std::cout << "Window close button pressed!" << std::endl;
        this->shouldClose(true);
    }

    void mouseMovedEvent(int mousex, int mousey) override {
        mousePos.set(mousex, mousey);
    }

private:
    ffw::TrueTypeFont font;
    ffw::Vec2i mousePos;
};

///=============================================================================
int main(int argc, char *argv[]) {
    // Instance to our app class
    App app;

    // set arguments
    ffw::GLFWRenderWindowArgs args;
    args.size.set(800, 600);
    args.title = "Font Example";
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
}
