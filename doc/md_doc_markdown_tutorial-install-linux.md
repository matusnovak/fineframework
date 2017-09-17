GCC on Linux
=================

This tutorial will explain how to include any FFW module into your C++ project. You will need GCC compiler 4.9.2 or newer!

#### Installing dependencies


First, you will need to install GCC and other build files by running:


<pre><div class="lang-cpp" style="white-space: nowrap;"><span class="hljs-normal">$ sudo apt-get update</span>
<span class="hljs-normal">$ sudo apt-get install build-essential git curl</span>
</div></pre>



To test if you have GCC 4.9.2 or newer, simply run:


<pre><div class="lang-cpp" style="white-space: nowrap;"><span class="hljs-normal">$ gcc --version</span>
</div></pre>



You will need the following install the third party libraries.

> _Note:_ Graphics module also needs GLFW v3.2 library. Downloading GLFW with sudo apt-get install libglfw3-dev might download older version! 



To install the libary, simply run `sudo apt-get install <package-name>` To install all of the libraries, run the following commands:


<pre><div class="lang-cpp" style="white-space: nowrap;"><span class="hljs-normal">$ sudo apt-get install curl xorg-dev libgl1-mesa-glx libgl1-mesa-dev libglu1-mesa-dev freeglut3-dev mesa-common-dev mesa-common-dev libfreetype6-dev libpng12-dev libjpeg8-dev libtiff5-dev zlib1g-dev libglfw3-dev</span>
</div></pre>



Note: On Debian the `libjpeg8-dev` package might be renamed as `libjpeg-dev`

Next, you will need to update glext.h to the newest version. If you are running latest Linux, for example Ubuntu 16.04 or newer, this is not needed. Run the following command, this will download official `glect.h` and puts it at the right place:


<pre><div class="lang-cpp" style="white-space: nowrap;"><span class="hljs-normal">$ sudo curl -o /usr/include/GL/glext.h https://www.khronos.org/registry/OpenGL/api/GL/glext.h</span>
</div></pre>



If you **need to install glfw3.2 or newer** because your package manager downloads the old version, run the following commands:


<pre><div class="lang-cpp" style="white-space: nowrap;"><span class="hljs-normal">$ cd ~ # Go to the home directory</span>
<span class="hljs-normal">$ git clone https://github.com/glfw/glfw # Will create a "glfw" directory</span>
<span class="hljs-normal">$ mkdir glfw/build</span>
<span class="hljs-normal">$ cd glfw/build</span>
<span class="hljs-normal">$ cmake .. -G "Unix Makefiles"</span>
<span class="hljs-normal">$ make </span>
<span class="hljs-normal">$ sudo make install</span>
</div></pre>



#### Installing FFW (building from source code)


Clone (or download as zip or tar file) and run cmake by running the following commands:


<pre><div class="lang-cpp" style="white-space: nowrap;"><span class="hljs-normal">$ cd ~ # Go to the home directory</span>
<span class="hljs-normal">$ git clone https://github.com/matusnovak/fineframework.git # Will create a "fineframework" directory</span>
<span class="hljs-normal">$ mkdir fineframework/build</span>
<span class="hljs-normal">$ cd fineframework/build</span>
<span class="hljs-normal">$ cmake .. -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release</span>
</div></pre>



Make sure that the dependencies (third party libraries) are found and C++11 is supported. The `LIBRARY-NOTFOUND` will be displayed if the given library was not found.


<pre><div class="lang-cpp" style="white-space: nowrap;"><span class="hljs-normal"># The following output will be printed by cmake </span>
<span class="hljs-normal">-- Performing Test COMPILER_SUPPORTS_CXX11</span>
<span class="hljs-normal">-- Performing Test COMPILER_SUPPORTS_CXX11 - Success</span>
<span class="hljs-normal">-- 1</span>
<span class="hljs-normal">-- glfw3 library path: /usr/local/lib/libglfw3.a</span>
<span class="hljs-normal">-- freetype library path: /usr/lib/x86_64-linux-gnu/libfreetype.so</span>
<span class="hljs-normal">-- png library path: /usr/lib/x86_64-linux-gnu/libpng.so</span>
<span class="hljs-normal">-- jpeg library path: /usr/lib/x86_64-linux-gnu/libjpeg.so</span>
<span class="hljs-normal">-- tiff library path: /usr/lib/x86_64-linux-gnu/libtiff.so</span>
<span class="hljs-normal">-- zlib library path: /usr/lib/x86_64-linux-gnu/libz.so</span>
<span class="hljs-normal">-- Looking for include file pthread.h</span>
<span class="hljs-normal">-- Looking for include file pthread.h - found</span>
</div></pre>



**Note:** If you do not have those dependencies, you can download them in binary form from [https://github.com/matusnovak/fineframework/releases/tag/v0.2.5-deps](https://github.com/matusnovak/fineframework/releases/tag/v0.2.5-deps) (search for `x86_64-linux-gnu.zip` file)


* If you have problems locating the libraries, you can add `-DCMAKE_LIBRARY_PATH="/usr/local/lib"` into the cmake command. If you need more than one directory, you can append them with collon: `-DCMAKE_LIBRARY_PATH="/usr/local/lib:/home/test/libs"` or with semicollon on windows. If that does not work, use spaces.

* You can also add additional include directories by adding `-DINCLUDE_DIRECTORIES="/usr/local/include"`

* If you wish to link against static stdlib, add `-DSTATIC_STDLIB=ON` at the end of the cmake command.

* To change the install directory, add `-DCMAKE_INSTALL_PREFIX:PATH=/path/to/install/dir`




Lastly, compile and install:


<pre><div class="lang-cpp" style="white-space: nowrap;"><span class="hljs-normal">$ make all</span>
<span class="hljs-normal">$ sudo make install</span>
</div></pre>



That's it!

#### Your first code


Your configuration is done, now test the project to make sure everything works. Copy paste the following example into empty cpp file:


<pre><div class="lang-cpp" style="white-space: nowrap;"><span class="hljs-meta-keyword">#include &lt;<a href="">ffw/graphics.h</a>&gt;</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span>
<span class="hljs-keyword">class </span><span class="hljs-normal">App: </span><span class="hljs-keyword">public</span><span class="hljs-normal"> <a href="ffw_GLFWRenderWindow.html">ffw::GLFWRenderWindow</a> &#123;</span>
<span class="hljs-normal"></span><span class="hljs-keyword">public</span><span class="hljs-normal">:</span>
<span class="hljs-normal">    App()&#123;</span>
<span class="hljs-normal">    &#125;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">    ~App()&#123;</span>
<span class="hljs-normal">    &#125;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">    </span><span class="hljs-title">bool</span><span class="hljs-normal"> <a href="ffw_GLFWRenderWindow.html#68554ce1">setup</a>()</span><span class="hljs-keyword"> override </span><span class="hljs-normal">&#123;</span>
<span class="hljs-normal">        std::cout &lt;&lt; </span><span class="hljs-string">"Window setup!"</span><span class="hljs-normal"> &lt;&lt; std::endl;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">        <a href="ffw_Texture2D.html">ffw::Texture2D</a> first;</span>
<span class="hljs-normal">        <a href="ffw_Texture2D.html">ffw::Texture2D</a> second;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">        <a href="">std::swap</a>(first, second);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">        </span><span class="hljs-keyword">return</span><span class="hljs-normal"> </span><span class="hljs-keyword">true</span><span class="hljs-normal">;</span>
<span class="hljs-normal">    &#125;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">    </span><span class="hljs-title">void</span><span class="hljs-normal"> <a href="ffw_GLFWRenderWindow.html#93db1d16">render</a>()</span><span class="hljs-keyword"> override </span><span class="hljs-normal">&#123;</span>
<span class="hljs-normal">        this-&gt;<a href="ffw_RenderContext.html#6b8df6af">setDrawColor</a>(<a href="ffw.html#e71e7885">ffw::rgb</a>(0xFF0000)); </span><span class="hljs-comment">// Red color</span><span class="hljs-normal"></span>
<span class="hljs-normal">        this-&gt;<a href="ffw_RenderContext.html#e04aedbb">drawRectangle</a>(10, 10, <a href="ffw_GLFWRenderWindow.html#70919473">getSize</a>().x-20, <a href="ffw_GLFWRenderWindow.html#70919473">getSize</a>().y-20);</span>
<span class="hljs-normal">    &#125;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">    </span><span class="hljs-title">void</span><span class="hljs-normal"> <a href="ffw_GLFWRenderWindow.html#eb5dbf50">close</a>()</span><span class="hljs-keyword"> override </span><span class="hljs-normal">&#123;</span>
<span class="hljs-normal">        std::cout &lt;&lt; </span><span class="hljs-string">"Window is closing!"</span><span class="hljs-normal"> &lt;&lt; std::endl;</span>
<span class="hljs-normal">    &#125;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">    </span><span class="hljs-title">void</span><span class="hljs-normal"> <a href="ffw_GLFWRenderWindow.html#707e5f61">textInputEvent</a>(</span><span class="hljs-title">unsigned</span><span class="hljs-normal"> </span><span class="hljs-title">int</span><span class="hljs-normal"> C)</span><span class="hljs-keyword"> override </span><span class="hljs-normal">&#123;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">    &#125;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">    </span><span class="hljs-title">void</span><span class="hljs-normal"> <a href="ffw_GLFWRenderWindow.html#ce25f297">keyPressedEvent</a>(<a href="ffw.html#23661d50">ffw::Key</a> key, <a href="ffw.html#e03b52d5">ffw::Mode</a> mode)</span><span class="hljs-keyword"> override </span><span class="hljs-normal">&#123;</span>
<span class="hljs-normal">        </span><span class="hljs-keyword">if</span><span class="hljs-normal">(mode == <a href="ffw_Mode.html#0d56c1de">ffw::Mode::PRESSED</a>)</span>
<span class="hljs-normal">            std::cout &lt;&lt; </span><span class="hljs-string">"Key pressed: "</span><span class="hljs-normal"> &lt;&lt; key &lt;&lt; std::endl;</span>
<span class="hljs-normal">    &#125;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">    </span><span class="hljs-title">void</span><span class="hljs-normal"> <a href="ffw_GLFWRenderWindow.html#eaa1a6c6">mouseMovedEvent</a>(</span><span class="hljs-title">int</span><span class="hljs-normal"> mousex, </span><span class="hljs-title">int</span><span class="hljs-normal"> mousey)</span><span class="hljs-keyword"> override </span><span class="hljs-normal">&#123;</span>
<span class="hljs-normal">        std::cout &lt;&lt; </span><span class="hljs-string">"Mouse moved to: "</span><span class="hljs-normal"> &lt;&lt; mousex &lt;&lt; </span><span class="hljs-string">"x"</span><span class="hljs-normal"> &lt;&lt; mousey &lt;&lt; std::endl;</span>
<span class="hljs-normal">    &#125;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">    </span><span class="hljs-title">void</span><span class="hljs-normal"> <a href="ffw_GLFWRenderWindow.html#fbe7329a">mouseScrollEvent</a>(</span><span class="hljs-title">int</span><span class="hljs-normal"> scroll)</span><span class="hljs-keyword"> override </span><span class="hljs-normal">&#123;</span>
<span class="hljs-normal">        std::cout &lt;&lt; </span><span class="hljs-string">"Mouse scroll: "</span><span class="hljs-normal"> &lt;&lt; scroll &lt;&lt; std::endl;</span>
<span class="hljs-normal">    &#125;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">    </span><span class="hljs-title">void</span><span class="hljs-normal"> <a href="ffw_GLFWRenderWindow.html#1e8d2373">mouseButtonEvent</a>(<a href="ffw.html#f80e46cc">ffw::MouseButton</a> button, <a href="ffw.html#e03b52d5">ffw::Mode</a> mode)</span><span class="hljs-keyword"> override </span><span class="hljs-normal">&#123;</span>
<span class="hljs-normal">        </span><span class="hljs-keyword">if</span><span class="hljs-normal">(mode == <a href="ffw_Mode.html#0d56c1de">ffw::Mode::PRESSED</a>)&#123;</span>
<span class="hljs-normal">            </span><span class="hljs-keyword">switch</span><span class="hljs-normal">(button)&#123;</span>
<span class="hljs-normal">                </span><span class="hljs-keyword">case</span><span class="hljs-normal"> <a href="ffw_MouseButton.html#8cc6295d">ffw::MouseButton::LEFT</a>: std::cout &lt;&lt; </span><span class="hljs-string">"Left mouse button pressed!"</span><span class="hljs-normal"> &lt;&lt; std::endl; </span><span class="hljs-keyword">break</span><span class="hljs-normal">;</span>
<span class="hljs-normal">                </span><span class="hljs-keyword">case</span><span class="hljs-normal"> <a href="ffw_MouseButton.html#5cbd7d75">ffw::MouseButton::MIDDLE</a>: std::cout &lt;&lt; </span><span class="hljs-string">"middle mouse button pressed!"</span><span class="hljs-normal"> &lt;&lt; std::endl; </span><span class="hljs-keyword">break</span><span class="hljs-normal">;</span>
<span class="hljs-normal">                </span><span class="hljs-keyword">case</span><span class="hljs-normal"> <a href="ffw_MouseButton.html#7f682f94">ffw::MouseButton::RIGHT</a>: std::cout &lt;&lt; </span><span class="hljs-string">"Right mouse button pressed!"</span><span class="hljs-normal"> &lt;&lt; std::endl; </span><span class="hljs-keyword">break</span><span class="hljs-normal">;</span>
<span class="hljs-normal">                </span><span class="hljs-keyword">default</span><span class="hljs-normal">: </span><span class="hljs-keyword">break</span><span class="hljs-normal">;</span>
<span class="hljs-normal">            &#125;</span>
<span class="hljs-normal">        &#125;</span>
<span class="hljs-normal">    &#125;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">    </span><span class="hljs-title">void</span><span class="hljs-normal"> <a href="ffw_GLFWRenderWindow.html#e4b39662">windowResizedEvent</a>(</span><span class="hljs-title">int</span><span class="hljs-normal"> width, </span><span class="hljs-title">int</span><span class="hljs-normal"> height)</span><span class="hljs-keyword"> override </span><span class="hljs-normal">&#123;</span>
<span class="hljs-normal">        std::cout &lt;&lt; </span><span class="hljs-string">"Window resized to: "</span><span class="hljs-normal"> &lt;&lt; width &lt;&lt; </span><span class="hljs-string">"x"</span><span class="hljs-normal"> &lt;&lt; height &lt;&lt; std::endl;</span>
<span class="hljs-normal">    &#125;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">    </span><span class="hljs-title">void</span><span class="hljs-normal"> <a href="ffw_GLFWRenderWindow.html#e57c71a5">windowMovedEvent</a>(</span><span class="hljs-title">int</span><span class="hljs-normal"> windowx, </span><span class="hljs-title">int</span><span class="hljs-normal"> windowy)</span><span class="hljs-keyword"> override </span><span class="hljs-normal">&#123;</span>
<span class="hljs-normal">        std::cout &lt;&lt; </span><span class="hljs-string">"Window moved to: "</span><span class="hljs-normal"> &lt;&lt; windowx &lt;&lt; </span><span class="hljs-string">"x"</span><span class="hljs-normal"> &lt;&lt; windowy &lt;&lt; std::endl;</span>
<span class="hljs-normal">    &#125;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">    </span><span class="hljs-title">void</span><span class="hljs-normal"> <a href="ffw_GLFWRenderWindow.html#727ce05e">windowFocusEvent</a>(</span><span class="hljs-title">bool</span><span class="hljs-normal"> focus)</span><span class="hljs-keyword"> override </span><span class="hljs-normal">&#123;</span>
<span class="hljs-normal">        </span><span class="hljs-keyword">if</span><span class="hljs-normal">(focus)std::cout &lt;&lt; </span><span class="hljs-string">"Focus gained!"</span><span class="hljs-normal"> &lt;&lt; std::endl;</span>
<span class="hljs-normal">        </span><span class="hljs-keyword">else</span><span class="hljs-normal"> std::cout &lt;&lt; </span><span class="hljs-string">"Focus lost!"</span><span class="hljs-normal"> &lt;&lt; std::endl;</span>
<span class="hljs-normal">    &#125;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">    </span><span class="hljs-title">void</span><span class="hljs-normal"> <a href="ffw_GLFWRenderWindow.html#d1e6b4ff">windowCloseEvent</a>()</span><span class="hljs-keyword"> override </span><span class="hljs-normal">&#123;</span>
<span class="hljs-normal">        std::cout &lt;&lt; </span><span class="hljs-string">"Window close button pressed!"</span><span class="hljs-normal"> &lt;&lt; std::endl;</span>
<span class="hljs-normal">        this-&gt;<a href="ffw_GLFWRenderWindow.html#f26e03bc">shouldClose</a>(</span><span class="hljs-keyword">true</span><span class="hljs-normal">);</span>
<span class="hljs-normal">    &#125;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">    </span><span class="hljs-title">void</span><span class="hljs-normal"> <a href="ffw_GLFWRenderWindow.html#c02a201a">filesDroppedEvent</a>(std::vector&lt;std::string&gt; filelist)</span><span class="hljs-keyword"> override </span><span class="hljs-normal">&#123;</span>
<span class="hljs-normal">        std::cout &lt;&lt; </span><span class="hljs-string">"Files dropped: "</span><span class="hljs-normal"> &lt;&lt; std::endl;</span>
<span class="hljs-normal">        </span><span class="hljs-keyword">for</span><span class="hljs-normal">(</span><span class="hljs-keyword">const</span><span class="hljs-normal"> </span><span class="hljs-keyword">auto</span><span class="hljs-normal">&amp; file : filelist)&#123;</span>
<span class="hljs-normal">            std::cout &lt;&lt; </span><span class="hljs-string">"\t\'"</span><span class="hljs-normal"> &lt;&lt; file &lt;&lt; </span><span class="hljs-string">"\'"</span><span class="hljs-normal"> &lt;&lt; std::endl;</span>
<span class="hljs-normal">        &#125;</span>
<span class="hljs-normal">    &#125;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">&#125;;</span>
<span class="hljs-normal"></span>
<span class="hljs-title">int</span><span class="hljs-normal"> main(</span><span class="hljs-title">int</span><span class="hljs-normal"> argc, </span><span class="hljs-title">char</span><span class="hljs-normal"> *argv[])&#123;</span>
<span class="hljs-normal">    </span><span class="hljs-comment">// Instance to our app class</span><span class="hljs-normal"></span>
<span class="hljs-normal">    App app;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">    </span><span class="hljs-comment">// set arguments</span><span class="hljs-normal"></span>
<span class="hljs-normal">    <a href="ffw_GLFWRenderWindowArgs.html">ffw::GLFWRenderWindowArgs</a> args;</span>
<span class="hljs-normal">    args.<a href="ffw_GLFWRenderWindowArgs.html#427706b8">size</a>.<a href="ffw_Vec2.html#e49a9b9e">set</a>(400, 400);</span>
<span class="hljs-normal">    args.<a href="ffw_GLFWRenderWindowArgs.html#b1b7d616">title</a> = </span><span class="hljs-string">"Empty Example"</span><span class="hljs-normal">;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">    </span><span class="hljs-comment">// create window</span><span class="hljs-normal"></span>
<span class="hljs-normal">    </span><span class="hljs-keyword">if</span><span class="hljs-normal">(!app.create(args, NULL))&#123;</span>
<span class="hljs-normal">        std::cerr &lt;&lt; </span><span class="hljs-string">"Failed to create window!"</span><span class="hljs-normal"> &lt;&lt; std::endl;</span>
<span class="hljs-normal">        </span><span class="hljs-keyword">return</span><span class="hljs-normal"> 1;</span>
<span class="hljs-normal">    &#125;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">    </span><span class="hljs-comment">// Run setup</span><span class="hljs-normal"></span>
<span class="hljs-normal">    </span><span class="hljs-keyword">if</span><span class="hljs-normal">(!app.setup())&#123;</span>
<span class="hljs-normal">        std::cerr &lt;&lt; </span><span class="hljs-string">"Failed to setup window!"</span><span class="hljs-normal"> &lt;&lt; std::endl;</span>
<span class="hljs-normal">        </span><span class="hljs-keyword">return</span><span class="hljs-normal"> 1;</span>
<span class="hljs-normal">    &#125;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">    </span><span class="hljs-comment">// The main window loop</span><span class="hljs-normal"></span>
<span class="hljs-normal">    </span><span class="hljs-keyword">while</span><span class="hljs-normal">(app.shouldRender())&#123;</span>
<span class="hljs-normal">        app.renderFrame();</span>
<span class="hljs-normal">        app.poolEvents();</span>
<span class="hljs-normal">    &#125;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">    </span><span class="hljs-comment">// destroy window, this will delete all graphics data used by the window.</span><span class="hljs-normal"></span>
<span class="hljs-normal">    </span><span class="hljs-comment">// Must be called after the setup and before the graphics</span><span class="hljs-normal"></span>
<span class="hljs-normal">    </span><span class="hljs-comment">// is terminated</span><span class="hljs-normal"></span>
<span class="hljs-normal">    app.destroy();</span>
<span class="hljs-normal">    </span><span class="hljs-keyword">return</span><span class="hljs-normal"> 0;</span>
<span class="hljs-normal">&#125;</span>
</div></pre>



Now compile it using g++


<pre><div class="lang-cpp" style="white-space: nowrap;"><span class="hljs-normal">$ g++ -c example.cpp -o example.o -std=c++11</span>
<span class="hljs-normal">$ g++ -o example example.o -lfinegraphics</span>
<span class="hljs-normal">$ ./example</span>
</div></pre>



If you want your executable to be portable (for example, distributing it on other systems) you might want to add `-Wl,-rpath '-Wl,$ORIGIN'` to the linker and copy necessary FFW *.so files into the executable's folder. This will make sure that the executable looks for its dependencies inside its folder. 

