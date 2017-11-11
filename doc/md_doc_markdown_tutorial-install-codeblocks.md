CodeBlocks and MinGW
=================

This tutorial will explain how to include any FFW module into your C++ project. You will need Code::Blocks which comes in two versions, with MinGW compiler and without it. It is highly recommended to use MinGW-w64 which supports much more features than original MinGW. MinGW-w64 can be downloaded from [https://sourceforge.net/projects/mingw-w64/](https://sourceforge.net/projects/mingw-w64/) and download CodeBlocks **without MinGW** from [http://www.codeblocks.org/downloads/26](http://www.codeblocks.org/downloads/26)

If you wish yo use MinGW over MinGW-w64, you can download the setup from [https://sourceforge.net/projects/mingw/](https://sourceforge.net/projects/mingw/)

#### Installing MinGW-w64


When installing MinGW-w64, **use either i686 architecture or x86_64**. (i686 = 32-bit and x86_64 = 64-bit) The version of the compiler must be **4.9.3 or newer!**

![tutorial-cb-01.png](tutorial-cb-01.png)


Next, when you install CodeBlocks, run it and go to **Settings (main top menu bar) -> Compiler -> Toolchain Executables** and set the compiler installation directory to the compiler's bin path. For example: `C:\Program Files (x86)\mingw-w64\i686-5.4.0-posix-dwarf-rt_v5-rev0\mingw32\bin`

![tutorial-cb-02.png](tutorial-cb-02.png)


#### Installing MinGW (not w64)


To install MinGW, follow [http://www.mingw.org/wiki/HOWTO_Install_the_MinGW_GCC_Compiler_Suite](http://www.mingw.org/wiki/HOWTO_Install_the_MinGW_GCC_Compiler_Suite) The next few steps are all exactly same for both MinGW and MinGW-w64, you will just need to set different paths.

#### Installing FFW


First, you will need to download glext.h (this is only necessary if using Graphics Module). Glext is an OpenGL extension header file which is updated regularly several times per year and can be downloaded from: [https://www.opengl.org/registry/api/GL/glext.h](https://www.opengl.org/registry/api/GL/glext.h) The easiest way for MinGW to know about the glext header is to put it into `C:\path\to\mingw\install\folder\mingw32\XXX-w64-mingw32\include\GL` The folder might already contain an old glext.h file!

Next, download the pre-built FineFramework DLLs from [GitHub Release Page](https://github.com/matusnovak/fineframework/releases). Look for the most recent release and download the **ffw-XXX-w64-mingw32.zip** zip file! **Make sure you download correct one! Either i686 or x84_64 depending on your compiler!** You do not need to download the source code! You can unpack the zip wherever you like, it does not matter.

The zip contains the following folders:


* **bin** - You can find DLLs files here, they are needed when running your C++ project executable. When distributing your executable, you must also include these DLLs next to your exe file!

* **include** - Header files needed by the compiler.

* **lib** - A-files also needed by the compiler, more precisely, needed by the linker.




#### Configuring FFW project


Create a CodeBlocks console application project. You will need to let the compiler know where to find FFW headers and library files. The DLLs are not needed for the compiler itself, instead the DLLs must be copied into the folder where your executable is, we will get into that later.

In the Project Workspace, right click on your project name and select **Build Options**. Next, add the following properties listed below to **both Release and Debug** configuration. Go to **Compiler Settings -> Compiler Flags** and enable **Have g++ follow the C++11 ISO** alternatively, go to #defines and add -std=c++11 flag.

![tutorial-cb-03.png](tutorial-cb-03.png)


Now, go to **Search Directories -> Compiler** and add a new path to include folder of your downloaded copy of pre-build FFW, for example: `C:\ffw-XXX-w64-mingw32\include`

![tutorial-cb-04.png](tutorial-cb-04.png)


For the library files, go to **Search Directories -> Linker** and add a new path to `C:\ffw-XXX-w64-mingw32\lib`

![tutorial-cb-05.png](tutorial-cb-05.png)


Now, go to the **Linker Settings** and add the following libraries to the **Link libraries** window on the left side: `opengl32`, `finegraphics`, `finedata`, `finemedia`, and `finegui`. (You don't need to include all modules if you are not going to use them in your project).

_Note that OpenGL library is needed only when using Graphics Module!_

![tutorial-cb-06.png](tutorial-cb-06.png)


#### Your first code


Your configuration is done, now test the project to make sure everything works. Copy paste the following example:


<pre><div class="lang-cpp" style="white-space: pre-wrap;"><span class="hljs-meta-keyword">#include &lt;<a href="">ffw/graphics.h</a>&gt;</span><span class="hljs-normal"></span>
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



Now compile it and run it! You might see the following message:

![tutorial-cb-07.png](tutorial-cb-07.png)


This is where DLL files comes...

Simply copy all DLLs files from `C:\path\to\ffw-XXX-w64-mingw32\bin` into `C:\path\to\your\codeblocks\project\bin\Debug` as well into Release folder. (this folder contains your executable file!)

Alternatively (not recommended!) you can put all DLLs into your MinGW bin folder. The folder is the same folder listed in the compiler's bin path located in: Settings (main top menu bar) -> Compiler -> Toolchain Executables.

When done, try to run the example again. This should show up:

![tutorial-cb-08.png](tutorial-cb-08.png)
 

