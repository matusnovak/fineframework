Example: Bitmap Font
=================

![example-bitmap-font.jpg](example-bitmap-font.jpg)


The purpose of this example is to show capability of loading and rendering a bitmap based font. It's up to the user how they decide to load and fill character data. The code below should be simple enough to understand. Similary to [True Type Font](md_doc_markdown_example-true-type-font.html), this example uses an image instead of an True Type fonts.

**Requires finegraphics and finemath module to run**

The following texture is used (in RAW format) as a bitmap font:

![ubuntu-mono-rgba8.png](ubuntu-mono-rgba8.png)



<pre><div class="lang-cpp" style="white-space: pre-wrap;"><span class="hljs-meta-keyword">#include &lt;<a href="">ffw/graphics.h</a>&gt;</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span><span class="hljs-meta-keyword">#include &lt;fstream&gt;</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span><span class="hljs-meta-keyword">#include &lt;cstring&gt;</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span><span class="hljs-meta-keyword">#define NUM_OF_LINES (8)</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span><span class="hljs-meta-keyword">#define TEXTURE_SIZE (512*512*4)</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span>
<span class="hljs-normal"></span><span class="hljs-comment">// There values are extracted from the image ubuntu-mono-rgba8.raw</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span><span class="hljs-meta-keyword">#define CHAR_WIDTH 24</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span><span class="hljs-meta-keyword">#define CHAR_HEIGHT 30</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span><span class="hljs-meta-keyword">#define CHAR_ADVANCE 16</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span><span class="hljs-meta-keyword">#define CHAR_BEARING 23</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span>
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
<span class="hljs-normal">        </span><span class="hljs-comment">// Load ubuntu-mono-rgba8.raw image</span><span class="hljs-normal"></span>
<span class="hljs-normal">        </span><span class="hljs-comment">// We use *.RAW format for the purpose of the example</span><span class="hljs-normal"></span>
<span class="hljs-normal">        std::ifstream input(</span><span class="hljs-string">"ubuntu-mono-rgba8.raw"</span><span class="hljs-normal">, std::ios::in | std::ios::binary);</span>
<span class="hljs-normal">        </span><span class="hljs-keyword">if</span><span class="hljs-normal">(!input) &#123;</span>
<span class="hljs-normal">            std::cerr &lt;&lt; </span><span class="hljs-string">"Failed to open 'ubuntu-mono-rgba8.raw' File is missing?"</span><span class="hljs-normal"> &lt;&lt; std::endl;</span>
<span class="hljs-normal">            </span><span class="hljs-keyword">return</span><span class="hljs-normal"> </span><span class="hljs-keyword">false</span><span class="hljs-normal">;</span>
<span class="hljs-normal">        &#125;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">        </span><span class="hljs-comment">// Check file size</span><span class="hljs-normal"></span>
<span class="hljs-normal">        input.seekg(0, std::ios::end);</span>
<span class="hljs-normal">        </span><span class="hljs-title">size_t</span><span class="hljs-normal"> size = (size_t)input.tellg();</span>
<span class="hljs-normal">        </span><span class="hljs-keyword">if</span><span class="hljs-normal">(size != TEXTURE_SIZE) &#123;</span>
<span class="hljs-normal">            std::cerr &lt;&lt; </span><span class="hljs-string">"File 'ubuntu-mono-rgba8.raw' has wrong size! Expected 512x512 pixels RGB_ALPHA_8888!"</span><span class="hljs-normal"> &lt;&lt; std::endl;</span>
<span class="hljs-normal">            </span><span class="hljs-keyword">return</span><span class="hljs-normal"> </span><span class="hljs-keyword">false</span><span class="hljs-normal">;</span>
<span class="hljs-normal">        &#125;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">        memset(pixels, 0xCC, TEXTURE_SIZE);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">        </span><span class="hljs-comment">// Load pixels</span><span class="hljs-normal"></span>
<span class="hljs-normal">        input.seekg(0, std::ios::beg);</span>
<span class="hljs-normal">        input.read((</span><span class="hljs-title">char</span><span class="hljs-normal">*)pixels, TEXTURE_SIZE);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">        </span><span class="hljs-comment">// Load font 28pt at 72 DPI</span><span class="hljs-normal"></span>
<span class="hljs-normal">        </span><span class="hljs-comment">// Chars starting from 0 to 255</span><span class="hljs-normal"></span>
<span class="hljs-normal">        </span><span class="hljs-keyword">if</span><span class="hljs-normal">(!font.createFromData(</span><span class="hljs-keyword">this</span><span class="hljs-normal">, pixels, 512, 512, <a href="ffw_ImageType.html#3a8727be">ffw::ImageType::RGB_ALPHA_8888</a>, 28, 72, 0, 255))&#123;</span>
<span class="hljs-normal">            std::cerr &lt;&lt; </span><span class="hljs-string">"Failed to create font from pixel data!"</span><span class="hljs-normal"> &lt;&lt; std::endl;</span>
<span class="hljs-normal">            </span><span class="hljs-keyword">return</span><span class="hljs-normal"> </span><span class="hljs-keyword">false</span><span class="hljs-normal">;</span>
<span class="hljs-normal">        &#125;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">        </span><span class="hljs-comment">// Fill data</span><span class="hljs-normal"></span>
<span class="hljs-normal">        </span><span class="hljs-comment">// Since the font is mono (Ubuntu Mono Regular) then all characters have the same data!</span><span class="hljs-normal"></span>
<span class="hljs-normal">        </span><span class="hljs-comment">// It is up to the user how the data is filled. There is no prefered container/data set!</span><span class="hljs-normal"></span>
<span class="hljs-normal">        </span><span class="hljs-keyword">for</span><span class="hljs-normal">(</span><span class="hljs-title">int</span><span class="hljs-normal"> i = 0; i &lt; 256; i++) &#123;</span>
<span class="hljs-normal">            </span><span class="hljs-title">int</span><span class="hljs-normal"> y = i / 16;</span>
<span class="hljs-normal">            </span><span class="hljs-title">int</span><span class="hljs-normal"> x = i - (y * 16);</span>
<span class="hljs-normal">            </span><span class="hljs-keyword">auto</span><span class="hljs-normal">&amp; chr = font.setCharData((</span><span class="hljs-title">wchar_t</span><span class="hljs-normal">)i);</span>
<span class="hljs-normal">            chr.x = x * 32;</span>
<span class="hljs-normal">            chr.y = y * 32;</span>
<span class="hljs-normal">            chr.width = CHAR_WIDTH;</span>
<span class="hljs-normal">            chr.height = CHAR_HEIGHT;</span>
<span class="hljs-normal">            chr.advance = CHAR_ADVANCE;</span>
<span class="hljs-normal">            chr.bearingX = 0;</span>
<span class="hljs-normal">            chr.bearingY = CHAR_BEARING;</span>
<span class="hljs-normal">        &#125;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">        </span><span class="hljs-comment">// Required for font blending</span><span class="hljs-normal"></span>
<span class="hljs-normal">        glEnable(GL_BLEND);</span>
<span class="hljs-normal">        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">        </span><span class="hljs-comment">// Background color</span><span class="hljs-normal"></span>
<span class="hljs-normal">        glClearColor(0.9f, 0.9f, 0.9f, 1.0f);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">        </span><span class="hljs-keyword">return</span><span class="hljs-normal"> </span><span class="hljs-keyword">true</span><span class="hljs-normal">;</span>
<span class="hljs-normal">    &#125;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">    </span><span class="hljs-title">void</span><span class="hljs-normal"> <a href="ffw_GLFWRenderWindow.html#93db1d16">render</a>()</span><span class="hljs-keyword"> override </span><span class="hljs-normal">&#123;</span>
<span class="hljs-normal">        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">        </span><span class="hljs-title">int</span><span class="hljs-normal"> height = 0;</span>
<span class="hljs-normal">        </span><span class="hljs-keyword">for</span><span class="hljs-normal">(</span><span class="hljs-title">int</span><span class="hljs-normal"> i = 0; i &lt; NUM_OF_LINES; i++)&#123;</span>
<span class="hljs-normal">            this-&gt;<a href="ffw_RenderContext.html#6b8df6af">setDrawColor</a>(<a href="ffw.html#e71e7885">ffw::rgb</a>(255 - i*(256 / NUM_OF_LINES), i*(256 / NUM_OF_LINES), 0));</span>
<span class="hljs-normal">            this-&gt;<a href="ffw_RenderContext.html#a583cfdb">drawString</a>(10, 10 + height, &amp;font, </span><span class="hljs-string">"Lorem ipsum dolor sit amet, consectetur adipiscing elit."</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            </span><span class="hljs-comment">// Line height is a simple formula of (height * weight)</span><span class="hljs-normal"></span>
<span class="hljs-normal">            </span><span class="hljs-comment">// wehre height is the height of the font</span><span class="hljs-normal"></span>
<span class="hljs-normal">            </span><span class="hljs-comment">// and weight is line spacing (1.0 and more)</span><span class="hljs-normal"></span>
<span class="hljs-normal">            height += int(font.getSizePixels() * 1.5f);</span>
<span class="hljs-normal">        &#125;</span>
<span class="hljs-normal">    &#125;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">    </span><span class="hljs-title">void</span><span class="hljs-normal"> <a href="ffw_GLFWRenderWindow.html#eb5dbf50">close</a>()</span><span class="hljs-keyword"> override </span><span class="hljs-normal">&#123;</span>
<span class="hljs-normal">        std::cout &lt;&lt; </span><span class="hljs-string">"Window is closing!"</span><span class="hljs-normal"> &lt;&lt; std::endl;</span>
<span class="hljs-normal">        font.destroy();</span>
<span class="hljs-normal">    &#125;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">    </span><span class="hljs-title">void</span><span class="hljs-normal"> <a href="ffw_GLFWRenderWindow.html#d1e6b4ff">windowCloseEvent</a>()</span><span class="hljs-keyword"> override </span><span class="hljs-normal">&#123;</span>
<span class="hljs-normal">        std::cout &lt;&lt; </span><span class="hljs-string">"Window close button pressed!"</span><span class="hljs-normal"> &lt;&lt; std::endl;</span>
<span class="hljs-normal">        this-&gt;<a href="ffw_GLFWRenderWindow.html#f26e03bc">shouldClose</a>(</span><span class="hljs-keyword">true</span><span class="hljs-normal">);</span>
<span class="hljs-normal">    &#125;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal"></span><span class="hljs-keyword">private</span><span class="hljs-normal">:</span>
<span class="hljs-normal">    <a href="ffw_BitmapFont.html">ffw::BitmapFont</a> font;</span>
<span class="hljs-normal">&#125;;</span>
<span class="hljs-normal"></span>
<span class="hljs-title">int</span><span class="hljs-normal"> main(</span><span class="hljs-title">int</span><span class="hljs-normal"> argc, </span><span class="hljs-title">char</span><span class="hljs-normal"> *argv[])&#123;</span>
<span class="hljs-normal">    </span><span class="hljs-comment">// Instance to our app class</span><span class="hljs-normal"></span>
<span class="hljs-normal">    App app;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">    </span><span class="hljs-comment">// set arguments</span><span class="hljs-normal"></span>
<span class="hljs-normal">    <a href="ffw_GLFWRenderWindowArgs.html">ffw::GLFWRenderWindowArgs</a> args;</span>
<span class="hljs-normal">    args.<a href="ffw_GLFWRenderWindowArgs.html#427706b8">size</a>.<a href="ffw_Vec2.html#e49a9b9e">set</a>(800, 400);</span>
<span class="hljs-normal">    args.<a href="ffw_GLFWRenderWindowArgs.html#b1b7d616">title</a> = </span><span class="hljs-string">"Bitmap Font Example"</span><span class="hljs-normal">;</span>
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
<span class="hljs-normal">        system(</span><span class="hljs-string">"pause"</span><span class="hljs-normal">);</span>
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
<span class="hljs-normal">&#125;</span>
</div></pre>

 

