/* This file is part of FineFramework project */
#ifndef FFW_GRAPHICS_RENDER_WINDOW
#define FFW_GRAPHICS_RENDER_WINDOW
#include "rendercontext.h"

namespace ffw {
    /**
    * @ingroup graphics
    */
    class FFW_API RenderWindow {
    public:
        virtual ~RenderWindow() = default;
        /**
         * @brief Sets the position of the window
         */
        virtual void setPos(int posx, int posy) = 0;
        /**
         * @brief Sets the size of the window
         */
        virtual void setSize(int width, int height) = 0;
        virtual ffw::Vec2i getPos() const = 0;
        virtual ffw::Vec2i getSize() const = 0;
        virtual void destroy() = 0;
        /**
         * @brief Returns true if the window is not closed
         * @details When shouldClose() is called with a 'true' boolean value,
         * this function will then return false
         */
        virtual bool shouldRender() const = 0;
        /**
         * @brief Renders a frame
         */
        virtual void renderFrame() = 0;
        /**
         * @brief Pools all user input events, if any
         * @details This is blocking function that will return whenever there are 
         * any events in the queue. If you wish to wait for the user first, see
         * waitForEvents()
         */
        virtual void poolEvents() = 0;
        /**
         * @brief Pools all user input events and waits if there is none
         * @details This is blocking function that will not return unless
         * there is at least one user event. If you wish to have continuous
         * rendering, even if there are no user events, use poolEvents()
         */
        virtual void waitForEvents() = 0;
        /**
         * @brief Returns true if the window is initialized
         */
        virtual bool isInitialized() const = 0;
        /**
         * @brief Set whether the window should close or stay alive
         */
        virtual void shouldClose(bool close) = 0;
        /**
         * @brief Shows the window if the window has been hidden
         */
        virtual void show() = 0;
        /**
         * @brief Hides the window if the window is visible
         */
        virtual void hide() = 0;
        /**
         * @brief Minimizes the window into the task bar
         */
        virtual void iconify() = 0;
        /**
         * @brief Restores minimized window into a visible window
         */
        virtual void restore() = 0;
        /**
         * @brief Maximizes the window in order to utilize whole screen
         * @details This is not the same as full screen mode!
         */
        virtual void maximize() = 0;
        /**
         * @brief Sets whether the window should operate using two
         * buffets (back and front) or only in one
         */
        virtual void setSingleBufferMode(bool enabled) = 0;
    };
};

#endif