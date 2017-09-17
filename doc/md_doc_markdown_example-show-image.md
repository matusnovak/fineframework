Example: Show Image
=================

The purpose of this example is to show how to load and render an image loaded from a file. Drag and drop any image file into the window.

**Requires finegraphics, finemedia, and finemath module to run**


<pre><div class="lang-cpp" style="white-space: nowrap;"><span class="hljs-meta-keyword">#include &lt;<a href="">ffw/graphics.h</a>&gt;</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span><span class="hljs-meta-keyword">#include &lt;<a href="">ffw/media.h</a>&gt;</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span>
<span class="hljs-normal"></span><span class="hljs-meta-keyword">#define STRING_TO_SHOW "Drop image file here"</span><span class="hljs-normal"></span>
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
<span class="hljs-normal">        </span><span class="hljs-comment">// Blending is needed by the font</span><span class="hljs-normal"></span>
<span class="hljs-normal">        glEnable(GL_BLEND);</span>
<span class="hljs-normal">        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);</span>
<span class="hljs-normal">        </span>
<span class="hljs-normal">        </span><span class="hljs-comment">// Checks if 2D texture is supported by render context.</span><span class="hljs-normal"></span>
<span class="hljs-normal">        </span><span class="hljs-comment">// The render context uses highest OpenGL version of that is </span><span class="hljs-normal"></span>
<span class="hljs-normal">        </span><span class="hljs-comment">// available by video card.</span><span class="hljs-normal"></span>
<span class="hljs-normal">        </span><span class="hljs-keyword">if</span><span class="hljs-normal">(!<a href="ffw_Texture2D.html#e9dc30f1">ffw::Texture2D::checkCompability</a>(</span><span class="hljs-keyword">this</span><span class="hljs-normal">))&#123;</span>
<span class="hljs-normal">            std::cerr &lt;&lt; </span><span class="hljs-string">"OpenGL used on this machine is too old! Texture2D is not compatible!"</span><span class="hljs-normal"> &lt;&lt; std::endl;</span>
<span class="hljs-normal">            </span><span class="hljs-keyword">return</span><span class="hljs-normal"> </span><span class="hljs-keyword">false</span><span class="hljs-normal">;</span>
<span class="hljs-normal">        &#125;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">        </span><span class="hljs-keyword">if</span><span class="hljs-normal">(!<a href="ffw_Font.html#2107f8ab">ffw::Font::checkCompability</a>(</span><span class="hljs-keyword">this</span><span class="hljs-normal">))&#123;</span>
<span class="hljs-normal">            std::cerr &lt;&lt; </span><span class="hljs-string">"OpenGL used on this machine is too old! Font is not compatible!"</span><span class="hljs-normal"> &lt;&lt; std::endl;</span>
<span class="hljs-normal">            </span><span class="hljs-keyword">return</span><span class="hljs-normal"> </span><span class="hljs-keyword">false</span><span class="hljs-normal">;</span>
<span class="hljs-normal">        &#125;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">        </span><span class="hljs-keyword">if</span><span class="hljs-normal">(!font.createFromData(</span><span class="hljs-keyword">this</span><span class="hljs-normal">, <a href="ffw.html#2012b23d">ffw::defaultFont</a>, <a href="ffw.html#384c1040">ffw::defaultFontSize</a>, 18, 96))&#123;</span>
<span class="hljs-normal">            std::cerr &lt;&lt; </span><span class="hljs-string">"Failed to create font!"</span><span class="hljs-normal"> &lt;&lt; std::endl;</span>
<span class="hljs-normal">            </span><span class="hljs-keyword">return</span><span class="hljs-normal"> </span><span class="hljs-keyword">false</span><span class="hljs-normal">;</span>
<span class="hljs-normal">        &#125;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">        textSize = font.getStringSize(STRING_TO_SHOW);</span>
<span class="hljs-normal">        </span>
<span class="hljs-normal">        </span><span class="hljs-keyword">return</span><span class="hljs-normal"> </span><span class="hljs-keyword">true</span><span class="hljs-normal">;</span>
<span class="hljs-normal">    &#125;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">    </span><span class="hljs-title">void</span><span class="hljs-normal"> <a href="ffw_GLFWRenderWindow.html#93db1d16">render</a>()</span><span class="hljs-keyword"> override </span><span class="hljs-normal">&#123;</span>
<span class="hljs-normal">        </span><span class="hljs-comment">// clear the window</span><span class="hljs-normal"></span>
<span class="hljs-normal">        this-&gt;<a href="ffw_RenderContext.html#6b8df6af">setDrawColor</a>(<a href="ffw.html#e71e7885">ffw::rgb</a>(0x000000));</span>
<span class="hljs-normal">        this-&gt;<a href="ffw_RenderContext.html#e04aedbb">drawRectangle</a>(0, 0, this-&gt;<a href="ffw_GLFWRenderWindow.html#70919473">getSize</a>().x, this-&gt;<a href="ffw_GLFWRenderWindow.html#70919473">getSize</a>().y);</span>
<span class="hljs-normal">        this-&gt;<a href="ffw_RenderContext.html#6b8df6af">setDrawColor</a>(<a href="ffw.html#e71e7885">ffw::rgb</a>(0xFFFFFF));</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">        </span><span class="hljs-keyword">if</span><span class="hljs-normal">(imagePath != </span><span class="hljs-string">""</span><span class="hljs-normal">)&#123;</span>
<span class="hljs-normal">            texture.destroy();</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">            <a href="ffw_ImageBuffer.html">ffw::ImageBuffer</a> buffer;</span>
<span class="hljs-normal">            </span><span class="hljs-keyword">if</span><span class="hljs-normal">(<a href="ffw.html#9f3c979a">ffw::readImage</a>(imagePath, buffer))&#123;</span>
<span class="hljs-normal">                </span><span class="hljs-keyword">if</span><span class="hljs-normal"> (texture.createFromBuffer(</span><span class="hljs-keyword">this</span><span class="hljs-normal">, buffer)) &#123;</span>
<span class="hljs-normal">                    </span><span class="hljs-comment">// Image loaded</span><span class="hljs-normal"></span>
<span class="hljs-normal">                &#125; </span>
<span class="hljs-normal">                </span><span class="hljs-keyword">else</span><span class="hljs-normal"> &#123;</span>
<span class="hljs-normal">                    std::cerr &lt;&lt; </span><span class="hljs-string">"Texture failed to create from image: "</span><span class="hljs-normal"> &lt;&lt; imagePath </span>
<span class="hljs-normal">                        &lt;&lt; </span><span class="hljs-string">" OpenGL does not support this image format!"</span><span class="hljs-normal"> &lt;&lt; std::endl;</span>
<span class="hljs-normal">                &#125;</span>
<span class="hljs-normal">            &#125;</span>
<span class="hljs-normal">            </span><span class="hljs-keyword">else</span><span class="hljs-normal"> &#123;</span>
<span class="hljs-normal">                std::cerr &lt;&lt; </span><span class="hljs-string">"Image: "</span><span class="hljs-normal"> &lt;&lt; imagePath &lt;&lt; </span><span class="hljs-string">" failed to load!"</span><span class="hljs-normal"> &lt;&lt; std::endl;</span>
<span class="hljs-normal">            &#125;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">            imagePath = </span><span class="hljs-string">""</span><span class="hljs-normal">;</span>
<span class="hljs-normal">            texture.setFiltering(ffw::Texture::Filtering::LINEAR);</span>
<span class="hljs-normal">        &#125;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">        </span><span class="hljs-keyword">if</span><span class="hljs-normal">(texture.isCreated())&#123;</span>
<span class="hljs-normal">            </span><span class="hljs-comment">// Finds dimension so the texture can fit into the window</span><span class="hljs-normal"></span>
<span class="hljs-normal">            </span><span class="hljs-comment">// contain image - finds a largets size and position of an image</span><span class="hljs-normal"></span>
<span class="hljs-normal">            </span><span class="hljs-comment">//                 that can fit into the area.</span><span class="hljs-normal"></span>
<span class="hljs-normal">            </span><span class="hljs-comment">// cover image - finds a largets size and position of an image</span><span class="hljs-normal"></span>
<span class="hljs-normal">            </span><span class="hljs-comment">//               that will fill entire area with no space left.</span><span class="hljs-normal"></span>
<span class="hljs-normal">            </span><span class="hljs-comment">// You can see live demo of CSS equivalent at:</span><span class="hljs-normal"></span>
<span class="hljs-normal">            </span><span class="hljs-comment">// http://www.w3schools.com/cssref/playit.asp?filename=playcss_background-size&amp;preval=contain</span><span class="hljs-normal"></span>
<span class="hljs-normal">            <a href="ffw_Vec4.html">ffw::Vec4i</a> ret = <a href="ffw.html#f2841d25">ffw::containImage</a>(texture.getWidth(), texture.getHeight(), this-&gt;<a href="ffw_GLFWRenderWindow.html#70919473">getSize</a>().<a href="ffw_Vec2.html#b2ccd122">x</a>, this-&gt;<a href="ffw_GLFWRenderWindow.html#70919473">getSize</a>().<a href="ffw_Vec2.html#370d6d90">y</a>);</span>
<span class="hljs-normal">            </span><span class="hljs-comment">//ffw::vec4i ret = ffw::coverImage(texture.getWidth(), texture.getHeight(), this-&gt;getSize().x, this-&gt;getSize().y);</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span>
<span class="hljs-normal">            </span><span class="hljs-comment">// draw texture mirrored</span><span class="hljs-normal"></span>
<span class="hljs-normal">            </span><span class="hljs-comment">// Do not forget that the texture mapping starts from lower left bottom.</span><span class="hljs-normal"></span>
<span class="hljs-normal">            </span><span class="hljs-comment">// Positive Y of texture mapping coordinate system is up.</span><span class="hljs-normal"></span>
<span class="hljs-normal">            </span><span class="hljs-comment">// Positive Y of window coordinate system is down.</span><span class="hljs-normal"></span>
<span class="hljs-normal">            </span><span class="hljs-comment">// Therefore, we need to draw texture mirrored vertically.</span><span class="hljs-normal"></span>
<span class="hljs-normal">            this-&gt;<a href="ffw_RenderContext.html#cc8d1ac9">drawTexture2D</a>(ret.<a href="ffw_Vec4.html#a33aa52a">x</a>, ret.<a href="ffw_Vec4.html#5c9e82f0">y</a>, ret.<a href="ffw_Vec4.html#20bc5b4d">z</a>, ret.<a href="ffw_Vec4.html#e51ad539">w</a>, &amp;texture);</span>
<span class="hljs-normal">        &#125; </span>
<span class="hljs-normal">        </span><span class="hljs-keyword">else</span><span class="hljs-normal"> &#123;</span>
<span class="hljs-normal">            <a href="ffw_Vec2.html">ffw::Vec2i</a> textPos = this-&gt;<a href="ffw_GLFWRenderWindow.html#70919473">getSize</a>()/2 - textSize/2;</span>
<span class="hljs-normal">            this-&gt;<a href="ffw_RenderContext.html#a583cfdb">drawString</a>(textPos.<a href="ffw_Vec2.html#b2ccd122">x</a>, textPos.<a href="ffw_Vec2.html#370d6d90">y</a>, &amp;font, STRING_TO_SHOW);</span>
<span class="hljs-normal">        &#125;</span>
<span class="hljs-normal">    &#125;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">    </span><span class="hljs-title">void</span><span class="hljs-normal"> <a href="ffw_GLFWRenderWindow.html#eb5dbf50">close</a>()</span><span class="hljs-keyword"> override </span><span class="hljs-normal">&#123;</span>
<span class="hljs-normal">        font.destroy();</span>
<span class="hljs-normal">        texture.destroy();</span>
<span class="hljs-normal">    &#125;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">    </span><span class="hljs-title">void</span><span class="hljs-normal"> <a href="ffw_GLFWRenderWindow.html#707e5f61">textInputEvent</a>(</span><span class="hljs-title">unsigned</span><span class="hljs-normal"> </span><span class="hljs-title">int</span><span class="hljs-normal"> c)</span><span class="hljs-keyword"> override </span><span class="hljs-normal">&#123;</span>
<span class="hljs-normal">    &#125;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">    </span><span class="hljs-title">void</span><span class="hljs-normal"> <a href="ffw_GLFWRenderWindow.html#ce25f297">keyPressedEvent</a>(<a href="ffw.html#23661d50">ffw::Key</a> key, <a href="ffw.html#e03b52d5">ffw::Mode</a> mode)</span><span class="hljs-keyword"> override </span><span class="hljs-normal">&#123;</span>
<span class="hljs-normal">    &#125;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">    </span><span class="hljs-title">void</span><span class="hljs-normal"> <a href="ffw_GLFWRenderWindow.html#eaa1a6c6">mouseMovedEvent</a>(</span><span class="hljs-title">int</span><span class="hljs-normal"> mousex, </span><span class="hljs-title">int</span><span class="hljs-normal"> mousey)</span><span class="hljs-keyword"> override </span><span class="hljs-normal">&#123;</span>
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
<span class="hljs-normal">        </span><span class="hljs-comment">// There will be always at least one item in the vector</span><span class="hljs-normal"></span>
<span class="hljs-normal">        imagePath = filelist[0];</span>
<span class="hljs-normal">    &#125;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal"></span><span class="hljs-keyword">private</span><span class="hljs-normal">:</span>
<span class="hljs-normal">    <a href="ffw_Texture2D.html">ffw::Texture2D</a> texture;</span>
<span class="hljs-normal">    <a href="ffw_TrueTypeFont.html">ffw::TrueTypeFont</a> font;</span>
<span class="hljs-normal">    <a href="ffw_Vec2.html">ffw::Vec2i</a> textSize;</span>
<span class="hljs-normal">    std::string imagePath;</span>
<span class="hljs-normal">&#125;;</span>
<span class="hljs-normal"></span>
<span class="hljs-title">int</span><span class="hljs-normal"> main(</span><span class="hljs-title">int</span><span class="hljs-normal"> argc, </span><span class="hljs-title">char</span><span class="hljs-normal"> *argv[])&#123;</span>
<span class="hljs-normal">    </span><span class="hljs-comment">// Instance to our app class</span><span class="hljs-normal"></span>
<span class="hljs-normal">    App app;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">    </span><span class="hljs-comment">// set arguments</span><span class="hljs-normal"></span>
<span class="hljs-normal">    <a href="ffw_GLFWRenderWindowArgs.html">ffw::GLFWRenderWindowArgs</a> args;</span>
<span class="hljs-normal">    args.<a href="ffw_GLFWRenderWindowArgs.html#427706b8">size</a>.<a href="ffw_Vec2.html#e49a9b9e">set</a>(800, 400);</span>
<span class="hljs-normal">    args.<a href="ffw_GLFWRenderWindowArgs.html#b1b7d616">title</a> = </span><span class="hljs-string">"Example show Image"</span><span class="hljs-normal">;</span>
<span class="hljs-normal">    args.<a href="ffw_GLFWRenderWindowArgs.html#17443f00">samples</a> = 4;</span>
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
<span class="hljs-normal">    app.setSingleBufferMode(</span><span class="hljs-keyword">true</span><span class="hljs-normal">);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">    </span><span class="hljs-comment">// The main window loop</span><span class="hljs-normal"></span>
<span class="hljs-normal">    </span><span class="hljs-keyword">while</span><span class="hljs-normal">(app.shouldRender())&#123;</span>
<span class="hljs-normal">        app.renderFrame();</span>
<span class="hljs-normal">        app.waitForEvents();</span>
<span class="hljs-normal">    &#125;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">    </span><span class="hljs-comment">// destroy window, this will delete all graphics data used by the window.</span><span class="hljs-normal"></span>
<span class="hljs-normal">    </span><span class="hljs-comment">// Must be called after the setup and before the graphics</span><span class="hljs-normal"></span>
<span class="hljs-normal">    </span><span class="hljs-comment">// is terminated</span><span class="hljs-normal"></span>
<span class="hljs-normal">    app.destroy();</span>
<span class="hljs-normal">&#125;</span>
</div></pre>

 

