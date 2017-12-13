# Creating a Rendering Window

This tutorial will explain how to create and manage an OpenGL rendering window using ffw::GLFWRenderWindow class.

## Starting from scratch

First, you need to include the necessary FFW header file. The FineFramework is separated into several modules: Graphics, Math, Data, Gui, etc... They are all independent, however, they all rely on the Math module. The header file you are looking for is ffw/graphics.h

```cpp
#include <ffw/graphics.h>
```

> You don't need to include math module as well, it is automatically included by **all** modules.

Next, we need to create our own class which will hold the functionality of the window. Simply, create a class derived from ffw::GLFWRenderWindow.

```cpp
#include <ffw/graphics.h>

class MyCustomClass: public ffw::GLFWRenderWindow {
public:
	MyCustomClass(){
	}
	
	~MyCustomClass(){
	}
}
```

Next, you will need to override some basic method from ffw::GLFWRenderWindow:
* **ffw::GLFWRenderWindow::setup** - This method is called only once before the rendering begins. Put your code here that needs to be executed once.
* **ffw::GLFWRenderWindow::render** - This method is called each frame. If you want to render something, this is a place to put it in.
* **ffw::GLFWRenderWindow::close** - This method is called only once when the window is begin destroyed. If you need to do a clean-up, this is a place for you.
* **ffw::GLFWRenderWindow::windowCloseEvent** - This mthod is called when you click on the [X] button on the window.


```cpp
#include <ffw/graphics.h>

class MyCustomClass: public ffw::GLFWRenderWindow {
public:
	MyCustomClass(){
	}
	
	~MyCustomClass(){
	}
	
	bool setup() override {
		// Return true or false
		// true - Setup is OK
		// false - Setup failed
		return true;
	}
	
	void render() override {
		this->setDrawColor(ffw::rgb(0xFF0000)); // Red color
        this->drawRectangle(10, 10, getSize().x-20, getSize().y-20);
	}
	
	void close() override {
		// Window is being destroyed
	}
	
	void windowCloseEvent() override {
        std::cout << "Window close button pressed!" << std::endl;
		// Let the window know that we want to be closed.
        this->shouldClose(true);
    }
}
```

All C++ applications need a main function

```cpp
#include <ffw/graphics.h>

class MyCustomClass: public ffw::GLFWRenderWindow {
public:
	...
}

int main(int argc, char *argv[]){
	return 0;
}
```

Inside of main, we will create an instance of our window. First, we need to set arguments for the window. These arguments define what the size of the window should be (or the position) when the window is created and so on. All the arguments and its description can be found here ffw::GLFWRenderWindowArgs.

```cpp
#include <ffw/graphics.h>

class MyCustomClass: public ffw::GLFWRenderWindow {
public:
	...
}

int main(int argc, char *argv[]){
	// Set arguments
    ffw::GLFWRenderWindowArgs args;
	// Set initial size to 400x400 pixels
    args.size.set(400, 400);
	// Set the window title to "Empty Example" (UTF-8 compatible)
    args.title = "Empty Example";
	
	return 0;
}
```

Lastly, we need to declare an instance of our window and write a code that will run the main loop. This will be explained below.

```cpp
#include <ffw/graphics.h>

class MyCustomClass: public ffw::GLFWRenderWindow {
public:
	...
}

int main(int argc, char *argv[]){
    // Instance to our window class
    MyCustomWindow myCustomWindow;
    // Set arguments
    ffw::GLFWRenderWindowArgs args;
    args.size.Set(400, 400);
    args.title = "Empty Example";
    // Create window
    if(!myCustomWindow.create(args, NULL)){
        std::cerr << "Failed to create window!" << std::endl;
        return 1;
    }
    // Run setup
    if(!myCustomWindow.setup()){
        std::cerr << "Failed to setup window!" << std::endl;
        return 1;
    }
    // The main window loop
    while(myCustomWindow.shouldRender()){
        myCustomWindow.renderFrame();
        myCustomWindow.poolEvents();
    }
    // Destroy window, this will delete all graphics data used by the window.
    // Must be called after the setup and before the graphics
    // is terminated
    myCustomWindow.destroy();
    return 0;
}
```

The `if(!myCustomWindow.create(args, NULL)){` will create a new rendering window. If this fails, your parameters are wrong (width or height is zero, etc...). This may also fail if your OS does not support OpenGL. In this case, it will print out "Failed to iniailize GLFW graphics!". If you are using remote connection over X11 on Linux, make sure your DISPLAY system variable is set.

The `if(!myCustomWindow.create(args, NULL)){` will set up necessary OpenGL environment for the window and then it will call your own overriden function `MyCustomClass::Setup()` 

The `while(myCustomWindow.shouldRender()){` will ask the window if we should continue rendering the window. The method is defined inside of ffw::GLFWRenderWindow::ShouldRender and will return false if one passed a 'true' into ffw::GLFWRenderWindow::ShouldClose method. 

Inside of the loop, you need to call `myCustomWindow.renderFrame();` which will set the OpenGL viewport and then it will call myCustomWindow::Render() function. The `myCustomWindow.poolEvents();` will check for the user input.

Now, compile it and you should see something like this image below. If you are not sure how to compile FFW application or if you get any errors, please refer to the [Getting started section in tutorials](md_markdown_tutorials.html).

![Alt](tutorial-vs12-05.png)

## Additional window event methods 

You might ask yourself, how do I get a mouse position? You will need to override a specific function inside of ffw::GLFWRenderWindow and they are the following:

* **ffw::GLFWRenderWindow::textInputEvent**
* **ffw::GLFWRenderWindow::keyPressedEvent**
* **ffw::GLFWRenderWindow::mouseMovedEvent**
* **ffw::GLFWRenderWindow::mouseScrollEvent**
* **ffw::GLFWRenderWindow::mouseButtonEvent**
* **ffw::GLFWRenderWindow::windowResizedEvent**
* **ffw::GLFWRenderWindow::windowMovedEvent**
* **ffw::GLFWRenderWindow::windowCloseEvent**
* **ffw::GLFWRenderWindow::windowFocusEvent**
* **ffw::GLFWRenderWindow::filesDroppedEvent**

They are self explanatory. To read more about each method, [simply look it up in the documentation of ffw::GLFWRenderWindow](../doxygen/ffw_GLFWRenderWindow.md).

To use the function, for example MouseMovedEvent (tracking the mouse position) simply add it into your class and mark is as `override`

```cpp
#include <ffw/graphics.h>

class MyCustomClass: public ffw::GLFWRenderWindow {
public:
	...
	void mouseMovedEvent(int mousex, int mousey) override {
        std::cout << "Mouse moved to: " << mousex << "x" << mousey << std::endl;
    }
	...
}
```