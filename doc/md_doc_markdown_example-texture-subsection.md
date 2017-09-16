Example: Texture Subsection
=================

![example-texture-subsection.jpg](example-texture-subsection.jpg)


The purpose of this example is to show how to render images/textures on the screen, including subsection and mirroring.

**Requires finegraphics and finemath module to run**


<pre><div class="lang-cpp"><span class="hljs-meta-keyword">#include &lt;<a href="">ffw/graphics.h</a>&gt;</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span><span class="hljs-meta-keyword">#include &lt;<a href="">ffw/math.h</a>&gt;</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span><span class="hljs-meta-keyword">#include &lt;fstream&gt;</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span>
<span class="hljs-normal"></span><span class="hljs-meta-keyword">#define TEXTURE_SIZE (512*512*3)</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span><span class="hljs-keyword">static</span><span class="hljs-normal"> </span><span class="hljs-title">unsigned</span><span class="hljs-normal"> </span><span class="hljs-title">char</span><span class="hljs-normal"> pixels[TEXTURE_SIZE];</span>
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
<span class="hljs-normal">        </span><span class="hljs-keyword">if</span><span class="hljs-normal"> (!font.createFromFile(</span><span class="hljs-keyword">this</span><span class="hljs-normal">, </span><span class="hljs-string">"FreeSans.ttf"</span><span class="hljs-normal">, 16, 72)) &#123;</span>
<span class="hljs-normal">            std::cerr &lt;&lt; </span><span class="hljs-string">"Failed to create font from: \'FreeSans.ttf\' File is missing?"</span><span class="hljs-normal"> &lt;&lt; std::endl;</span>
<span class="hljs-normal">            </span><span class="hljs-keyword">return</span><span class="hljs-normal"> </span><span class="hljs-keyword">false</span><span class="hljs-normal">;</span>
<span class="hljs-normal">        &#125;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">        std::ifstream input(</span><span class="hljs-string">"grid-rgb8.raw"</span><span class="hljs-normal">, std::ios::in | std::ios::binary);</span>
<span class="hljs-normal">        </span><span class="hljs-keyword">if</span><span class="hljs-normal"> (!input) &#123;</span>
<span class="hljs-normal">            std::cerr &lt;&lt; </span><span class="hljs-string">"Failed to open 'grid-rgb8.raw' File is missing?"</span><span class="hljs-normal"> &lt;&lt; std::endl;</span>
<span class="hljs-normal">            </span><span class="hljs-keyword">return</span><span class="hljs-normal"> </span><span class="hljs-keyword">false</span><span class="hljs-normal">;</span>
<span class="hljs-normal">        &#125;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">        </span><span class="hljs-keyword">if</span><span class="hljs-normal">(!texture.create(</span><span class="hljs-keyword">this</span><span class="hljs-normal">, 512, 512, GL_RGB8, GL_RGB, GL_UNSIGNED_BYTE)) &#123;</span>
<span class="hljs-normal">            std::cerr &lt;&lt; </span><span class="hljs-string">"Failed to create texture!"</span><span class="hljs-normal"> &lt;&lt; std::endl;</span>
<span class="hljs-normal">            </span><span class="hljs-keyword">return</span><span class="hljs-normal"> </span><span class="hljs-keyword">false</span><span class="hljs-normal">;</span>
<span class="hljs-normal">        &#125;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">        </span><span class="hljs-comment">// We expect 512 * 512 * 3 bytes, we should check for the file size first.</span><span class="hljs-normal"></span>
<span class="hljs-normal">        </span><span class="hljs-comment">// For the purpose of the example we are not going to do checks.</span><span class="hljs-normal"></span>
<span class="hljs-normal">        input.read((</span><span class="hljs-title">char</span><span class="hljs-normal">*)pixels, TEXTURE_SIZE);</span>
<span class="hljs-normal">        input.close();</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">        texture.setPixels(0, 0, 0, 512, 512, pixels);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">        </span><span class="hljs-comment">// Required for font blending</span><span class="hljs-normal"></span>
<span class="hljs-normal">        glEnable(GL_BLEND);</span>
<span class="hljs-normal">        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">        </span><span class="hljs-comment">// Background color</span><span class="hljs-normal"></span>
<span class="hljs-normal">        glClearColor(0.3f, 0.3f, 0.3f, 1.0f);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">        </span><span class="hljs-keyword">return</span><span class="hljs-normal"> </span><span class="hljs-keyword">true</span><span class="hljs-normal">;</span>
<span class="hljs-normal">    &#125;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">    </span><span class="hljs-title">void</span><span class="hljs-normal"> <a href="ffw_GLFWRenderWindow.html#93db1d16">render</a>()</span><span class="hljs-keyword"> override </span><span class="hljs-normal">&#123;</span>
<span class="hljs-normal">        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">        this-&gt;<a href="ffw_RenderContext.html#6b8df6af">setDrawColor</a>(<a href="ffw.html#e71e7885">ffw::rgb</a>(0xFFFFFF)); </span><span class="hljs-comment">// White color</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span>
<span class="hljs-normal">        </span><span class="hljs-comment">// In OpenGL, textures are mirrored vertically</span><span class="hljs-normal"></span>
<span class="hljs-normal">        this-&gt;<a href="ffw_RenderContext.html#a583cfdb">drawString</a>(10, 5, &amp;font, </span><span class="hljs-string">"Original image:"</span><span class="hljs-normal">);</span>
<span class="hljs-normal">        this-&gt;<a href="ffw_RenderContext.html#cc8d1ac9">drawTexture2D</a>(10, 30, 256, 256, &amp;texture);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">        </span><span class="hljs-comment">// Zoomed image</span><span class="hljs-normal"></span>
<span class="hljs-normal">        this-&gt;<a href="ffw_RenderContext.html#a583cfdb">drawString</a>(10, 291, &amp;font, </span><span class="hljs-string">"Zoomed:"</span><span class="hljs-normal">);</span>
<span class="hljs-normal">        </span><span class="hljs-keyword">if</span><span class="hljs-normal">(mousePos.x &gt;= 10 &amp;&amp; mousePos.x &lt;= 266 &amp;&amp; mousePos.y &gt;= 30 &amp;&amp; mousePos.y &lt;= 286) &#123;</span>
<span class="hljs-normal">            <a href="ffw_Vec2.html">ffw::Vec2i</a> offset;</span>
<span class="hljs-normal">            offset.<a href="ffw_Vec2.html#b2ccd122">x</a> = <a href="ffw.html#e670592a">ffw::remap</a>(mousePos.x, 10, 266, 0, 512);</span>
<span class="hljs-normal">            offset.<a href="ffw_Vec2.html#370d6d90">y</a> = <a href="ffw.html#e670592a">ffw::remap</a>(mousePos.y, 30, 286, 0, 512);</span>
<span class="hljs-normal">            this-&gt;<a href="ffw_RenderContext.html#e7341ced">drawTexture2DSub</a>(10, 316, 256, 256, &amp;texture, offset.<a href="ffw_Vec2.html#b2ccd122">x</a> - 16, offset.<a href="ffw_Vec2.html#370d6d90">y</a> - 16, 32, 32);</span>
<span class="hljs-normal">        &#125; </span>
<span class="hljs-normal">        </span><span class="hljs-keyword">else</span><span class="hljs-normal"> &#123;</span>
<span class="hljs-normal">            this-&gt;<a href="ffw_RenderContext.html#a583cfdb">drawString</a>(10, 291 + 128, &amp;font, </span><span class="hljs-string">"Hover over original\nimage for zoom"</span><span class="hljs-normal">);</span>
<span class="hljs-normal">        &#125;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">        </span><span class="hljs-comment">// [256, 256] subsection at pos [0, 0]</span><span class="hljs-normal"></span>
<span class="hljs-normal">        this-&gt;<a href="ffw_RenderContext.html#a583cfdb">drawString</a>(276, 5, &amp;font, </span><span class="hljs-string">"Left top corner:"</span><span class="hljs-normal">);</span>
<span class="hljs-normal">        this-&gt;<a href="ffw_RenderContext.html#d35d4e67">drawTexture2DSubMirror</a>(276, 30, 256, 256, &amp;texture, 0, 0, 256, 256, </span><span class="hljs-keyword">false</span><span class="hljs-normal">, </span><span class="hljs-keyword">false</span><span class="hljs-normal">);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">        </span><span class="hljs-comment">// [256, 256] subsection at pos [256, 0]</span><span class="hljs-normal"></span>
<span class="hljs-normal">        this-&gt;<a href="ffw_RenderContext.html#a583cfdb">drawString</a>(542, 5, &amp;font, </span><span class="hljs-string">"Right top corner:"</span><span class="hljs-normal">);</span>
<span class="hljs-normal">        this-&gt;<a href="ffw_RenderContext.html#d35d4e67">drawTexture2DSubMirror</a>(542, 30, 256, 256, &amp;texture, 256, 0, 256, 256, </span><span class="hljs-keyword">false</span><span class="hljs-normal">, </span><span class="hljs-keyword">false</span><span class="hljs-normal">);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">        </span><span class="hljs-comment">// [256, 256] subsection at pos [0, 256] mirrored horizontally</span><span class="hljs-normal"></span>
<span class="hljs-normal">        this-&gt;<a href="ffw_RenderContext.html#a583cfdb">drawString</a>(276, 291, &amp;font, </span><span class="hljs-string">"Left bottom mirrored:"</span><span class="hljs-normal">);</span>
<span class="hljs-normal">        this-&gt;<a href="ffw_RenderContext.html#d35d4e67">drawTexture2DSubMirror</a>(276, 316, 256, 256, &amp;texture, 0, 256, 256, 256, </span><span class="hljs-keyword">true</span><span class="hljs-normal">, </span><span class="hljs-keyword">false</span><span class="hljs-normal">);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">        </span><span class="hljs-comment">// [256, 256] subsection at pos [256, 256] mirrored vertically</span><span class="hljs-normal"></span>
<span class="hljs-normal">        this-&gt;<a href="ffw_RenderContext.html#a583cfdb">drawString</a>(542, 291, &amp;font, </span><span class="hljs-string">"Right bottom mirrored:"</span><span class="hljs-normal">);</span>
<span class="hljs-normal">        this-&gt;<a href="ffw_RenderContext.html#d35d4e67">drawTexture2DSubMirror</a>(542, 316, 256, 256, &amp;texture, 256, 256, 256, 256, </span><span class="hljs-keyword">false</span><span class="hljs-normal">, </span><span class="hljs-keyword">true</span><span class="hljs-normal">);</span>
<span class="hljs-normal">    &#125;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">    </span><span class="hljs-title">void</span><span class="hljs-normal"> <a href="ffw_GLFWRenderWindow.html#eb5dbf50">close</a>()</span><span class="hljs-keyword"> override </span><span class="hljs-normal">&#123;</span>
<span class="hljs-normal">        texture.destroy();</span>
<span class="hljs-normal">    &#125;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">    </span><span class="hljs-title">void</span><span class="hljs-normal"> <a href="ffw_GLFWRenderWindow.html#707e5f61">textInputEvent</a>(</span><span class="hljs-title">unsigned</span><span class="hljs-normal"> </span><span class="hljs-title">int</span><span class="hljs-normal"> C)</span><span class="hljs-keyword"> override </span><span class="hljs-normal">&#123;</span>
<span class="hljs-normal">    &#125;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">    </span><span class="hljs-title">void</span><span class="hljs-normal"> <a href="ffw_GLFWRenderWindow.html#ce25f297">keyPressedEvent</a>(<a href="ffw.html#23661d50">ffw::Key</a> key, <a href="ffw.html#e03b52d5">ffw::Mode</a> mode)</span><span class="hljs-keyword"> override </span><span class="hljs-normal">&#123;</span>
<span class="hljs-normal">    &#125;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">    </span><span class="hljs-title">void</span><span class="hljs-normal"> <a href="ffw_GLFWRenderWindow.html#eaa1a6c6">mouseMovedEvent</a>(</span><span class="hljs-title">int</span><span class="hljs-normal"> mousex, </span><span class="hljs-title">int</span><span class="hljs-normal"> mousey)</span><span class="hljs-keyword"> override </span><span class="hljs-normal">&#123;</span>
<span class="hljs-normal">        mousePos.set(mousex, mousey);</span>
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
<span class="hljs-normal">    <a href="ffw_TrueTypeFont.html">ffw::TrueTypeFont</a> font;</span>
<span class="hljs-normal">    <a href="ffw_Texture2D.html">ffw::Texture2D</a> texture;</span>
<span class="hljs-normal">    <a href="ffw_Vec2.html">ffw::Vec2i</a> mousePos;</span>
<span class="hljs-normal">&#125;;</span>
<span class="hljs-normal"></span>
<span class="hljs-title">int</span><span class="hljs-normal"> main(</span><span class="hljs-title">int</span><span class="hljs-normal"> argc, </span><span class="hljs-title">char</span><span class="hljs-normal"> *argv[])&#123;</span>
<span class="hljs-normal">    </span><span class="hljs-comment">// Instance to our app class</span><span class="hljs-normal"></span>
<span class="hljs-normal">    App app;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">    </span><span class="hljs-comment">// set arguments</span><span class="hljs-normal"></span>
<span class="hljs-normal">    <a href="ffw_GLFWRenderWindowArgs.html">ffw::GLFWRenderWindowArgs</a> args;</span>
<span class="hljs-normal">    args.<a href="ffw_GLFWRenderWindowArgs.html#427706b8">size</a>.<a href="ffw_Vec2.html#e49a9b9e">set</a>(800, 600);</span>
<span class="hljs-normal">    args.<a href="ffw_GLFWRenderWindowArgs.html#b1b7d616">title</a> = </span><span class="hljs-string">"Texture Subsection Example"</span><span class="hljs-normal">;</span>
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

 

