Example: Tree
=================

![example-tree.jpg](example-tree.jpg)


The purpose of this example is to show how simple is to draw 2D primitives and how to use vectors.

**Requires finegraphics and finemath module to run**


<pre><div class="lang-cpp"><span class="hljs-meta-keyword">#include &lt;<a href="">ffw/graphics.h</a>&gt;</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span><span class="hljs-meta-keyword">#include &lt;<a href="">ffw/math.h</a>&gt;</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span>
<span class="hljs-keyword">class </span><span class="hljs-normal">App : </span><span class="hljs-keyword">public</span><span class="hljs-normal"> <a href="ffw_GLFWRenderWindow.html">ffw::GLFWRenderWindow</a> &#123;</span>
<span class="hljs-normal"></span><span class="hljs-keyword">public</span><span class="hljs-normal">:</span>
<span class="hljs-normal">    App() &#123;</span>
<span class="hljs-normal">        rotStep = 0;</span>
<span class="hljs-normal">    &#125;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">    ~App() &#123;</span>
<span class="hljs-normal">    &#125;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">    </span><span class="hljs-title">bool</span><span class="hljs-normal"> <a href="ffw_GLFWRenderWindow.html#68554ce1">setup</a>()</span><span class="hljs-keyword"> override </span><span class="hljs-normal">&#123;</span>
<span class="hljs-normal">        glEnable(GL_BLEND);</span>
<span class="hljs-normal">        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);</span>
<span class="hljs-normal">        glClearColor(0.3f, 0.3f, 0.3f, 1.0f);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">        </span><span class="hljs-keyword">return</span><span class="hljs-normal"> </span><span class="hljs-keyword">true</span><span class="hljs-normal">;</span>
<span class="hljs-normal">    &#125;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">    </span><span class="hljs-title">void</span><span class="hljs-normal"> drawBranch(</span><span class="hljs-keyword">const</span><span class="hljs-normal"> <a href="ffw_Vec2.html">ffw::Vec2f</a>&amp; pos, </span><span class="hljs-title">float</span><span class="hljs-normal"> dir, </span><span class="hljs-title">float</span><span class="hljs-normal"> add, </span><span class="hljs-title">int</span><span class="hljs-normal"> steps, </span><span class="hljs-title">float</span><span class="hljs-normal"> length) &#123;</span>
<span class="hljs-normal">        </span><span class="hljs-keyword">if</span><span class="hljs-normal"> (steps &lt;= 0)</span><span class="hljs-keyword">return</span><span class="hljs-normal">;</span>
<span class="hljs-normal">        </span>
<span class="hljs-normal">        this-&gt;<a href="ffw_RenderContext.html#7acd1170">setOutlineSize</a>(steps);</span>
<span class="hljs-normal">        <a href="ffw_Vec2.html">ffw::Vec2f</a> end = pos + <a href="ffw.html#fcfaa6c5">ffw::Vec2f</a>(length, 0).<a href="ffw_Vec2.html#dd178631">rotate</a>(dir);</span>
<span class="hljs-normal">        this-&gt;<a href="ffw_RenderContext.html#5bb70248">drawLine</a>(pos.<a href="ffw_Vec2.html#b2ccd122">x</a>, pos.<a href="ffw_Vec2.html#370d6d90">y</a>, end.<a href="ffw_Vec2.html#b2ccd122">x</a>, end.<a href="ffw_Vec2.html#370d6d90">y</a>);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">        drawBranch(end, dir - add, add, steps - 1, length * 0.9f);</span>
<span class="hljs-normal">        drawBranch(end, dir + add, add, steps - 1, length * 0.9f);</span>
<span class="hljs-normal">    &#125;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">    </span><span class="hljs-title">void</span><span class="hljs-normal"> <a href="ffw_GLFWRenderWindow.html#93db1d16">render</a>()</span><span class="hljs-keyword"> override </span><span class="hljs-normal">&#123;</span>
<span class="hljs-normal">        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">        </span><span class="hljs-comment">// In the moddile horizontally</span><span class="hljs-normal"></span>
<span class="hljs-normal">        </span><span class="hljs-comment">// 1 fourth from the bottom vertically</span><span class="hljs-normal"></span>
<span class="hljs-normal">        </span><span class="hljs-keyword">auto</span><span class="hljs-normal"> pos = <a href="ffw.html#fcfaa6c5">ffw::Vec2f</a>(</span><span class="hljs-title">float</span><span class="hljs-normal">(this-&gt;<a href="ffw_GLFWRenderWindow.html#70919473">getSize</a>().x / 2), </span><span class="hljs-title">float</span><span class="hljs-normal">(this-&gt;<a href="ffw_GLFWRenderWindow.html#70919473">getSize</a>().y - this-&gt;<a href="ffw_GLFWRenderWindow.html#70919473">getSize</a>().y / 4));</span>
<span class="hljs-normal">        </span><span class="hljs-title">int</span><span class="hljs-normal"> length = std::min(this-&gt;<a href="ffw_GLFWRenderWindow.html#70919473">getSize</a>().x, this-&gt;<a href="ffw_GLFWRenderWindow.html#70919473">getSize</a>().y) / 10;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">        this-&gt;<a href="ffw_RenderContext.html#6b8df6af">setDrawColor</a>(<a href="ffw.html#e71e7885">ffw::rgb</a>(255, 255, 255));</span>
<span class="hljs-normal">        drawBranch(pos, 270.0f, rotStep, 10, length);</span>
<span class="hljs-normal">    &#125;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">    </span><span class="hljs-title">void</span><span class="hljs-normal"> <a href="ffw_GLFWRenderWindow.html#eb5dbf50">close</a>()</span><span class="hljs-keyword"> override </span><span class="hljs-normal">&#123;</span>
<span class="hljs-normal">    &#125;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">    </span><span class="hljs-title">void</span><span class="hljs-normal"> <a href="ffw_GLFWRenderWindow.html#707e5f61">textInputEvent</a>(</span><span class="hljs-title">unsigned</span><span class="hljs-normal"> </span><span class="hljs-title">int</span><span class="hljs-normal"> C)</span><span class="hljs-keyword"> override </span><span class="hljs-normal">&#123;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">    &#125;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">    </span><span class="hljs-title">void</span><span class="hljs-normal"> <a href="ffw_GLFWRenderWindow.html#ce25f297">keyPressedEvent</a>(<a href="ffw.html#23661d50">ffw::Key</a> key, <a href="ffw.html#e03b52d5">ffw::Mode</a> mode)</span><span class="hljs-keyword"> override </span><span class="hljs-normal">&#123;</span>
<span class="hljs-normal">    &#125;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">    </span><span class="hljs-title">void</span><span class="hljs-normal"> <a href="ffw_GLFWRenderWindow.html#eaa1a6c6">mouseMovedEvent</a>(</span><span class="hljs-title">int</span><span class="hljs-normal"> mousex, </span><span class="hljs-title">int</span><span class="hljs-normal"> mousey)</span><span class="hljs-keyword"> override </span><span class="hljs-normal">&#123;</span>
<span class="hljs-normal">        rotStep = <a href="ffw.html#e670592a">ffw::remap</a>((</span><span class="hljs-title">double</span><span class="hljs-normal">)mousex, 0.0, (</span><span class="hljs-title">double</span><span class="hljs-normal">)this-&gt;<a href="ffw_GLFWRenderWindow.html#70919473">getSize</a>().x, 0.0, 90.0);</span>
<span class="hljs-normal">    &#125;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">    </span><span class="hljs-title">void</span><span class="hljs-normal"> <a href="ffw_GLFWRenderWindow.html#fbe7329a">mouseScrollEvent</a>(</span><span class="hljs-title">int</span><span class="hljs-normal"> scroll)</span><span class="hljs-keyword"> override </span><span class="hljs-normal">&#123;</span>
<span class="hljs-normal">    &#125;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">    </span><span class="hljs-title">void</span><span class="hljs-normal"> <a href="ffw_GLFWRenderWindow.html#1e8d2373">mouseButtonEvent</a>(<a href="ffw.html#f80e46cc">ffw::MouseButton</a> button, <a href="ffw.html#e03b52d5">ffw::Mode</a> mode)</span><span class="hljs-keyword"> override </span><span class="hljs-normal">&#123;</span>
<span class="hljs-normal">    &#125;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">    </span><span class="hljs-title">void</span><span class="hljs-normal"> <a href="ffw_GLFWRenderWindow.html#e4b39662">windowResizedEvent</a>(</span><span class="hljs-title">int</span><span class="hljs-normal"> width, </span><span class="hljs-title">int</span><span class="hljs-normal"> height)</span><span class="hljs-keyword"> override </span><span class="hljs-normal">&#123;</span>
<span class="hljs-normal">    &#125;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">    </span><span class="hljs-title">void</span><span class="hljs-normal"> <a href="ffw_GLFWRenderWindow.html#e57c71a5">windowMovedEvent</a>(</span><span class="hljs-title">int</span><span class="hljs-normal"> windowx, </span><span class="hljs-title">int</span><span class="hljs-normal"> windowy)</span><span class="hljs-keyword"> override </span><span class="hljs-normal">&#123;</span>
<span class="hljs-normal">    &#125;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">    </span><span class="hljs-title">void</span><span class="hljs-normal"> <a href="ffw_GLFWRenderWindow.html#727ce05e">windowFocusEvent</a>(</span><span class="hljs-title">bool</span><span class="hljs-normal"> focus)</span><span class="hljs-keyword"> override </span><span class="hljs-normal">&#123;</span>
<span class="hljs-normal">    &#125;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">    </span><span class="hljs-title">void</span><span class="hljs-normal"> <a href="ffw_GLFWRenderWindow.html#d1e6b4ff">windowCloseEvent</a>()</span><span class="hljs-keyword"> override </span><span class="hljs-normal">&#123;</span>
<span class="hljs-normal">        this-&gt;<a href="ffw_GLFWRenderWindow.html#f26e03bc">shouldClose</a>(</span><span class="hljs-keyword">true</span><span class="hljs-normal">);</span>
<span class="hljs-normal">    &#125;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">    </span><span class="hljs-title">void</span><span class="hljs-normal"> <a href="ffw_GLFWRenderWindow.html#c02a201a">filesDroppedEvent</a>(std::vector&lt;std::string&gt; filelist)</span><span class="hljs-keyword"> override </span><span class="hljs-normal">&#123;</span>
<span class="hljs-normal">    &#125;</span>
<span class="hljs-normal"></span><span class="hljs-keyword">private</span><span class="hljs-normal">:</span>
<span class="hljs-normal">    </span><span class="hljs-title">float</span><span class="hljs-normal"> rotStep;</span>
<span class="hljs-normal">&#125;;</span>
<span class="hljs-normal"></span>
<span class="hljs-title">int</span><span class="hljs-normal"> main(</span><span class="hljs-title">int</span><span class="hljs-normal"> argc, </span><span class="hljs-title">char</span><span class="hljs-normal"> *argv[]) &#123;</span>
<span class="hljs-normal">    </span><span class="hljs-comment">// Instance to our app class</span><span class="hljs-normal"></span>
<span class="hljs-normal">    App app;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">    </span><span class="hljs-comment">// set arguments</span><span class="hljs-normal"></span>
<span class="hljs-normal">    <a href="ffw_GLFWRenderWindowArgs.html">ffw::GLFWRenderWindowArgs</a> args;</span>
<span class="hljs-normal">    args.<a href="ffw_GLFWRenderWindowArgs.html#427706b8">size</a>.<a href="ffw_Vec2.html#e49a9b9e">set</a>(800, 600);</span>
<span class="hljs-normal">    args.<a href="ffw_GLFWRenderWindowArgs.html#b1b7d616">title</a> = </span><span class="hljs-string">"Tree Example"</span><span class="hljs-normal">;</span>
<span class="hljs-normal">    args.<a href="ffw_GLFWRenderWindowArgs.html#17443f00">samples</a> = 4;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">    </span><span class="hljs-comment">// create window</span><span class="hljs-normal"></span>
<span class="hljs-normal">    </span><span class="hljs-keyword">if</span><span class="hljs-normal"> (!app.create(args, NULL)) &#123;</span>
<span class="hljs-normal">        std::cerr &lt;&lt; </span><span class="hljs-string">"Failed to create window!"</span><span class="hljs-normal"> &lt;&lt; std::endl;</span>
<span class="hljs-normal">        </span><span class="hljs-keyword">return</span><span class="hljs-normal"> 1;</span>
<span class="hljs-normal">    &#125;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">    </span><span class="hljs-comment">// Run setup</span><span class="hljs-normal"></span>
<span class="hljs-normal">    </span><span class="hljs-keyword">if</span><span class="hljs-normal"> (!app.setup()) &#123;</span>
<span class="hljs-normal">        std::cerr &lt;&lt; </span><span class="hljs-string">"Failed to setup window!"</span><span class="hljs-normal"> &lt;&lt; std::endl;</span>
<span class="hljs-normal">        </span><span class="hljs-keyword">return</span><span class="hljs-normal"> 1;</span>
<span class="hljs-normal">    &#125;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">    </span><span class="hljs-comment">// The main window loop</span><span class="hljs-normal"></span>
<span class="hljs-normal">    </span><span class="hljs-keyword">while</span><span class="hljs-normal"> (app.shouldRender()) &#123;</span>
<span class="hljs-normal">        app.renderFrame();</span>
<span class="hljs-normal">        app.waitForEvents();</span>
<span class="hljs-normal">    &#125;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">    </span><span class="hljs-comment">// destroy window, this will delete all graphics data used by the window.</span><span class="hljs-normal"></span>
<span class="hljs-normal">    </span><span class="hljs-comment">// Must be called after the setup and before the graphics</span><span class="hljs-normal"></span>
<span class="hljs-normal">    </span><span class="hljs-comment">// is terminated</span><span class="hljs-normal"></span>
<span class="hljs-normal">    app.destroy();</span>
<span class="hljs-normal">    </span><span class="hljs-keyword">return</span><span class="hljs-normal"> 0;</span>
<span class="hljs-normal">&#125;</span>
</div></pre>

 

