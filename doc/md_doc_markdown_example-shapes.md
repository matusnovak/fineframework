Example: Shapes
=================

![example-shapes.jpg](example-shapes.jpg)


The purpose of this example is to show various 2D primitives included in graphics module.

**Requires finegraphics and finemath module to run**


<pre><div class="lang-cpp"><span class="hljs-meta-keyword">#include &lt;<a href="">ffw/graphics.h</a>&gt;</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span><span class="hljs-meta-keyword">#include &lt;<a href="">math.h</a>&gt;</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span>
<span class="hljs-normal"></span><span class="hljs-keyword">inline</span><span class="hljs-normal"> </span><span class="hljs-title">int</span><span class="hljs-normal"> RandomRange(</span><span class="hljs-title">int</span><span class="hljs-normal"> min, </span><span class="hljs-title">int</span><span class="hljs-normal"> max) &#123;</span>
<span class="hljs-normal">    </span><span class="hljs-keyword">return</span><span class="hljs-normal"> (std::rand() % (max - min)) + min;</span>
<span class="hljs-normal">&#125;</span>
<span class="hljs-normal">    </span>
<span class="hljs-normal"></span>
<span class="hljs-keyword">class </span><span class="hljs-normal">App : </span><span class="hljs-keyword">public</span><span class="hljs-normal"> <a href="ffw_GLFWRenderWindow.html">ffw::GLFWRenderWindow</a> &#123;</span>
<span class="hljs-normal"></span><span class="hljs-keyword">public</span><span class="hljs-normal">:</span>
<span class="hljs-normal">    App() &#123;</span>
<span class="hljs-normal">    &#125;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">    ~App() &#123;</span>
<span class="hljs-normal">    &#125;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">    </span><span class="hljs-title">bool</span><span class="hljs-normal"> <a href="ffw_GLFWRenderWindow.html#68554ce1">setup</a>()</span><span class="hljs-keyword"> override </span><span class="hljs-normal">&#123;</span>
<span class="hljs-normal">        </span><span class="hljs-keyword">if</span><span class="hljs-normal"> (!font.createFromFile(</span><span class="hljs-keyword">this</span><span class="hljs-normal">, </span><span class="hljs-string">"FreeSans.ttf"</span><span class="hljs-normal">, 14, 72)) &#123;</span>
<span class="hljs-normal">            std::cerr &lt;&lt; </span><span class="hljs-string">"Failed to create font from: \'FreeSans.ttf\' File is missing?"</span><span class="hljs-normal"> &lt;&lt; std::endl;</span>
<span class="hljs-normal">            </span><span class="hljs-keyword">return</span><span class="hljs-normal"> </span><span class="hljs-keyword">false</span><span class="hljs-normal">;</span>
<span class="hljs-normal">        &#125;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">        glEnable(GL_BLEND);</span>
<span class="hljs-normal">        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">        </span><span class="hljs-keyword">return</span><span class="hljs-normal"> </span><span class="hljs-keyword">true</span><span class="hljs-normal">;</span>
<span class="hljs-normal">    &#125;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">    </span><span class="hljs-title">void</span><span class="hljs-normal"> <a href="ffw_GLFWRenderWindow.html#93db1d16">render</a>()</span><span class="hljs-keyword"> override </span><span class="hljs-normal">&#123;</span>
<span class="hljs-normal">        </span><span class="hljs-comment">//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);</span><span class="hljs-normal"></span>
<span class="hljs-normal">        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">        this-&gt;<a href="ffw_RenderContext.html#6b8df6af">setDrawColor</a>(<a href="ffw.html#e71e7885">ffw::rgb</a>(0xFFFFFF)); </span><span class="hljs-comment">// White color</span><span class="hljs-normal"></span>
<span class="hljs-normal">        this-&gt;<a href="ffw_RenderContext.html#9279a9aa">setOutlineMode</a>(</span><span class="hljs-keyword">false</span><span class="hljs-normal">);</span>
<span class="hljs-normal">        this-&gt;<a href="ffw_RenderContext.html#7acd1170">setOutlineSize</a>(1);</span>
<span class="hljs-normal">        </span><span class="hljs-comment">//this-&gt;drawRectangleRounded(10, 10, 800 - 20, 600 - 20, 10, 20, 30, 40, 32);</span><span class="hljs-normal"></span>
<span class="hljs-normal">        </span><span class="hljs-comment">//return;</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span>
<span class="hljs-normal">        this-&gt;<a href="ffw_RenderContext.html#a583cfdb">drawString</a>(10 + 0, 10, &amp;font, </span><span class="hljs-string">"Rectangle:"</span><span class="hljs-normal">);</span>
<span class="hljs-normal">        this-&gt;<a href="ffw_RenderContext.html#a583cfdb">drawString</a>(10 + 260, 10, &amp;font, </span><span class="hljs-string">"Rectangle rounded:"</span><span class="hljs-normal">);</span>
<span class="hljs-normal">        this-&gt;<a href="ffw_RenderContext.html#a583cfdb">drawString</a>(10 + 520, 10, &amp;font, </span><span class="hljs-string">"Triangles:"</span><span class="hljs-normal">);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">        this-&gt;<a href="ffw_RenderContext.html#a583cfdb">drawString</a>(10 + 0, 10 + 190, &amp;font, </span><span class="hljs-string">"Circle:"</span><span class="hljs-normal">);</span>
<span class="hljs-normal">        this-&gt;<a href="ffw_RenderContext.html#a583cfdb">drawString</a>(10 + 260, 10 + 190, &amp;font, </span><span class="hljs-string">"Arc:"</span><span class="hljs-normal">);</span>
<span class="hljs-normal">        this-&gt;<a href="ffw_RenderContext.html#a583cfdb">drawString</a>(10 + 520, 10 + 190, &amp;font, </span><span class="hljs-string">"Lines:"</span><span class="hljs-normal">);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">        this-&gt;<a href="ffw_RenderContext.html#a583cfdb">drawString</a>(10 + 0, 10 + 380, &amp;font, </span><span class="hljs-string">"Bezier:"</span><span class="hljs-normal">);</span>
<span class="hljs-normal">        this-&gt;<a href="ffw_RenderContext.html#a583cfdb">drawString</a>(10 + 260, 10 + 380, &amp;font, </span><span class="hljs-string">"Bezier thick:"</span><span class="hljs-normal">);</span>
<span class="hljs-normal">        this-&gt;<a href="ffw_RenderContext.html#a583cfdb">drawString</a>(10 + 520, 10 + 380, &amp;font, </span><span class="hljs-string">"Quad:"</span><span class="hljs-normal">);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">        </span><span class="hljs-comment">// Rectangles</span><span class="hljs-normal"></span>
<span class="hljs-normal">        this-&gt;<a href="ffw_RenderContext.html#6b8df6af">setDrawColor</a>(<a href="ffw.html#efcb64d9">ffw::rgba</a>(0xFF000080));</span>
<span class="hljs-normal">        this-&gt;<a href="ffw_RenderContext.html#e04aedbb">drawRectangle</a>(10, 30, 100, 100);</span>
<span class="hljs-normal">        this-&gt;<a href="ffw_RenderContext.html#6b8df6af">setDrawColor</a>(<a href="ffw.html#efcb64d9">ffw::rgba</a>(0x00FF0080));</span>
<span class="hljs-normal">        this-&gt;<a href="ffw_RenderContext.html#e04aedbb">drawRectangle</a>(10 + 53, 30 + 23, 100, 100);</span>
<span class="hljs-normal">        this-&gt;<a href="ffw_RenderContext.html#6b8df6af">setDrawColor</a>(<a href="ffw.html#efcb64d9">ffw::rgba</a>(0x0000FF80));</span>
<span class="hljs-normal">        this-&gt;<a href="ffw_RenderContext.html#9279a9aa">setOutlineMode</a>(</span><span class="hljs-keyword">true</span><span class="hljs-normal">);</span>
<span class="hljs-normal">        this-&gt;<a href="ffw_RenderContext.html#7acd1170">setOutlineSize</a>(5);</span>
<span class="hljs-normal">        this-&gt;<a href="ffw_RenderContext.html#e04aedbb">drawRectangle</a>(10 + 106, 30 + 46, 100, 100);</span>
<span class="hljs-normal">        this-&gt;<a href="ffw_RenderContext.html#9279a9aa">setOutlineMode</a>(</span><span class="hljs-keyword">false</span><span class="hljs-normal">);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">        </span><span class="hljs-comment">// Rounded rectangles</span><span class="hljs-normal"></span>
<span class="hljs-normal">        this-&gt;<a href="ffw_RenderContext.html#6b8df6af">setDrawColor</a>(<a href="ffw.html#efcb64d9">ffw::rgba</a>(0xFF000080));</span>
<span class="hljs-normal">        this-&gt;<a href="ffw_RenderContext.html#651eec48">drawRectangleRounded</a>(10 + 260, 30, 100, 100, 10, 10, 10, 10);</span>
<span class="hljs-normal">        this-&gt;<a href="ffw_RenderContext.html#6b8df6af">setDrawColor</a>(<a href="ffw.html#efcb64d9">ffw::rgba</a>(0x00FF0080));</span>
<span class="hljs-normal">        this-&gt;<a href="ffw_RenderContext.html#651eec48">drawRectangleRounded</a>(10 + 260 + 53, 30 + 23, 100, 100, 20, 20, 20, 20);</span>
<span class="hljs-normal">        this-&gt;<a href="ffw_RenderContext.html#6b8df6af">setDrawColor</a>(<a href="ffw.html#efcb64d9">ffw::rgba</a>(0x0000FF80));</span>
<span class="hljs-normal">        this-&gt;<a href="ffw_RenderContext.html#9279a9aa">setOutlineMode</a>(</span><span class="hljs-keyword">true</span><span class="hljs-normal">);</span>
<span class="hljs-normal">        this-&gt;<a href="ffw_RenderContext.html#651eec48">drawRectangleRounded</a>(10 + 260 + 106, 30 + 46, 100, 100, 10, 20, 30, 40);</span>
<span class="hljs-normal">        this-&gt;<a href="ffw_RenderContext.html#9279a9aa">setOutlineMode</a>(</span><span class="hljs-keyword">false</span><span class="hljs-normal">);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">        </span><span class="hljs-comment">// Triangles</span><span class="hljs-normal"></span>
<span class="hljs-normal">        this-&gt;<a href="ffw_RenderContext.html#6b8df6af">setDrawColor</a>(<a href="ffw.html#efcb64d9">ffw::rgba</a>(0xFF000080));</span>
<span class="hljs-normal">        this-&gt;<a href="ffw_RenderContext.html#79fc47bb">drawTriangle</a>(10 + 520, 30,</span>
<span class="hljs-normal">                                       10 + 520 + 260, 30,</span>
<span class="hljs-normal">                                       10 + 520 + 260/2, 30 + 170/2);</span>
<span class="hljs-normal">        this-&gt;<a href="ffw_RenderContext.html#6b8df6af">setDrawColor</a>(<a href="ffw.html#efcb64d9">ffw::rgba</a>(0x00FF0080));</span>
<span class="hljs-normal">        this-&gt;<a href="ffw_RenderContext.html#79fc47bb">drawTriangle</a>(10 + 520, 30, </span>
<span class="hljs-normal">                                       10 + 520 + 260 / 2, 30 + 170 / 2,</span>
<span class="hljs-normal">                                       10 + 520, 30 + 170);</span>
<span class="hljs-normal">        this-&gt;<a href="ffw_RenderContext.html#6b8df6af">setDrawColor</a>(<a href="ffw.html#efcb64d9">ffw::rgba</a>(0x0000FF80));</span>
<span class="hljs-normal">        this-&gt;<a href="ffw_RenderContext.html#79fc47bb">drawTriangle</a>(10 + 520 + 260, 30,</span>
<span class="hljs-normal">                                       10 + 520 + 260 / 2, 30 + 170 / 2,</span>
<span class="hljs-normal">                                       10 + 520 + 260, 30 + 170);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">        </span><span class="hljs-comment">// Circles</span><span class="hljs-normal"></span>
<span class="hljs-normal">        this-&gt;<a href="ffw_RenderContext.html#6b8df6af">setDrawColor</a>(<a href="ffw.html#efcb64d9">ffw::rgba</a>(0xFF000080));</span>
<span class="hljs-normal">        this-&gt;<a href="ffw_RenderContext.html#a99be3f4">drawCircle</a>(60, 80 + 190, 50);</span>
<span class="hljs-normal">        this-&gt;<a href="ffw_RenderContext.html#6b8df6af">setDrawColor</a>(<a href="ffw.html#efcb64d9">ffw::rgba</a>(0x00FF0080));</span>
<span class="hljs-normal">        this-&gt;<a href="ffw_RenderContext.html#a99be3f4">drawCircle</a>(60 + 53, 80 + 190 + 23, 50);</span>
<span class="hljs-normal">        this-&gt;<a href="ffw_RenderContext.html#6b8df6af">setDrawColor</a>(<a href="ffw.html#efcb64d9">ffw::rgba</a>(0x0000FF80));</span>
<span class="hljs-normal">        this-&gt;<a href="ffw_RenderContext.html#9279a9aa">setOutlineMode</a>(</span><span class="hljs-keyword">true</span><span class="hljs-normal">);</span>
<span class="hljs-normal">        this-&gt;<a href="ffw_RenderContext.html#a99be3f4">drawCircle</a>(60 + 106, 80 + 190 + 46, 50);</span>
<span class="hljs-normal">        this-&gt;<a href="ffw_RenderContext.html#9279a9aa">setOutlineMode</a>(</span><span class="hljs-keyword">false</span><span class="hljs-normal">);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">        </span><span class="hljs-comment">// Arc</span><span class="hljs-normal"></span>
<span class="hljs-normal">        this-&gt;<a href="ffw_RenderContext.html#6b8df6af">setDrawColor</a>(<a href="ffw.html#efcb64d9">ffw::rgba</a>(0xFF000080));</span>
<span class="hljs-normal">        this-&gt;<a href="ffw_RenderContext.html#df89b764">drawArc</a>(60 + 260, 80 + 190, 25, 50, 0.0, 270.0);</span>
<span class="hljs-normal">        this-&gt;<a href="ffw_RenderContext.html#6b8df6af">setDrawColor</a>(<a href="ffw.html#efcb64d9">ffw::rgba</a>(0x00FF0080));</span>
<span class="hljs-normal">        this-&gt;<a href="ffw_RenderContext.html#df89b764">drawArc</a>(60 + 260 + 53, 80 + 190 + 23, 15, 50, 90.0, 235.0);</span>
<span class="hljs-normal">        this-&gt;<a href="ffw_RenderContext.html#6b8df6af">setDrawColor</a>(<a href="ffw.html#efcb64d9">ffw::rgba</a>(0x0000FF80));</span>
<span class="hljs-normal">        this-&gt;<a href="ffw_RenderContext.html#df89b764">drawArc</a>(60 + 260 + 106, 80 + 190 + 46, 35, 50, -90.0, 90.0);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">        </span><span class="hljs-comment">// Lines</span><span class="hljs-normal"></span>
<span class="hljs-normal">        this-&gt;<a href="ffw_RenderContext.html#7acd1170">setOutlineSize</a>(1);</span>
<span class="hljs-normal">        </span><span class="hljs-keyword">for</span><span class="hljs-normal"> (</span><span class="hljs-title">int</span><span class="hljs-normal"> i = 0; i &lt; 32; i++) &#123;</span>
<span class="hljs-normal">            this-&gt;<a href="ffw_RenderContext.html#6b8df6af">setDrawColor</a>(<a href="ffw.html#e71e7885">ffw::rgb</a>(i*8, 255 - i*8, 0));</span>
<span class="hljs-normal">            this-&gt;<a href="ffw_RenderContext.html#5bb70248">drawLine</a>(</span>
<span class="hljs-normal">                10 + 520 + i * (260 / 32), 30 + 190,</span>
<span class="hljs-normal">                10 + 520 + (32 - i) * (260 / 32), 30 + 190 + 170</span>
<span class="hljs-normal">            );</span>
<span class="hljs-normal">        &#125;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">        this-&gt;<a href="ffw_RenderContext.html#7acd1170">setOutlineSize</a>(5);</span>
<span class="hljs-normal">        </span><span class="hljs-keyword">for</span><span class="hljs-normal"> (</span><span class="hljs-title">int</span><span class="hljs-normal"> i = 0; i &lt; 8; i++) &#123;</span>
<span class="hljs-normal">            this-&gt;<a href="ffw_RenderContext.html#6b8df6af">setDrawColor</a>(<a href="ffw.html#e71e7885">ffw::rgb</a>(0, 255 - i * 32, i * 32));</span>
<span class="hljs-normal">            this-&gt;<a href="ffw_RenderContext.html#5bb70248">drawLine</a>(</span>
<span class="hljs-normal">                10 + 520, 30 + 190 + (i) * (170 / 8),</span>
<span class="hljs-normal">                10 + 520 + 260, 30 + 190 + (8 - i) * (170 / 8)</span>
<span class="hljs-normal">            );</span>
<span class="hljs-normal">        &#125;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">        </span><span class="hljs-comment">// Bezier</span><span class="hljs-normal"></span>
<span class="hljs-normal">        this-&gt;<a href="ffw_RenderContext.html#7acd1170">setOutlineSize</a>(1);</span>
<span class="hljs-normal">        this-&gt;<a href="ffw_RenderContext.html#6b8df6af">setDrawColor</a>(<a href="ffw.html#efcb64d9">ffw::rgba</a>(0xFF000080));</span>
<span class="hljs-normal">        this-&gt;<a href="ffw_RenderContext.html#b36a1802">drawBezier</a>(</span>
<span class="hljs-normal">            10 + 5,       30 + 380 + 85, </span><span class="hljs-comment">// Start</span><span class="hljs-normal"></span>
<span class="hljs-normal">            10 + 5,       30 + 380,      </span><span class="hljs-comment">// CP 0</span><span class="hljs-normal"></span>
<span class="hljs-normal">            10 + 250 - 5, 30 + 380,      </span><span class="hljs-comment">// CP 1</span><span class="hljs-normal"></span>
<span class="hljs-normal">            10 + 250 - 5, 30 + 380 + 85  </span><span class="hljs-comment">// End</span><span class="hljs-normal"></span>
<span class="hljs-normal">        );</span>
<span class="hljs-normal">        this-&gt;<a href="ffw_RenderContext.html#6b8df6af">setDrawColor</a>(<a href="ffw.html#efcb64d9">ffw::rgba</a>(0x00FF0080));</span>
<span class="hljs-normal">        this-&gt;<a href="ffw_RenderContext.html#b36a1802">drawBezier</a>(</span>
<span class="hljs-normal">            10 + 5, 30 + 380 + 85,       </span><span class="hljs-comment">// Start</span><span class="hljs-normal"></span>
<span class="hljs-normal">            10 + 5, 30 + 380 + 170,      </span><span class="hljs-comment">// CP 0</span><span class="hljs-normal"></span>
<span class="hljs-normal">            10 + 250 - 5, 30 + 380 + 170,</span><span class="hljs-comment">// CP 1</span><span class="hljs-normal"></span>
<span class="hljs-normal">            10 + 250 - 5, 30 + 380 + 85  </span><span class="hljs-comment">// End</span><span class="hljs-normal"></span>
<span class="hljs-normal">        );</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">        </span><span class="hljs-comment">// Bezier thick</span><span class="hljs-normal"></span>
<span class="hljs-normal">        this-&gt;<a href="ffw_RenderContext.html#7acd1170">setOutlineSize</a>(10);</span>
<span class="hljs-normal">        this-&gt;<a href="ffw_RenderContext.html#6b8df6af">setDrawColor</a>(<a href="ffw.html#efcb64d9">ffw::rgba</a>(0xFF000080));</span>
<span class="hljs-normal">        this-&gt;<a href="ffw_RenderContext.html#b36a1802">drawBezier</a>(</span>
<span class="hljs-normal">            10 + 270 + 5, 30 + 380 + 85, </span><span class="hljs-comment">// Start</span><span class="hljs-normal"></span>
<span class="hljs-normal">            10 + 270 + 5, 30 + 380,      </span><span class="hljs-comment">// CP 0</span><span class="hljs-normal"></span>
<span class="hljs-normal">            10 + 510 - 5, 30 + 380,      </span><span class="hljs-comment">// CP 1</span><span class="hljs-normal"></span>
<span class="hljs-normal">            10 + 510 - 5, 30 + 380 + 85  </span><span class="hljs-comment">// End</span><span class="hljs-normal"></span>
<span class="hljs-normal">        );</span>
<span class="hljs-normal">        this-&gt;<a href="ffw_RenderContext.html#6b8df6af">setDrawColor</a>(<a href="ffw.html#efcb64d9">ffw::rgba</a>(0x00FF0080));</span>
<span class="hljs-normal">        this-&gt;<a href="ffw_RenderContext.html#b36a1802">drawBezier</a>(</span>
<span class="hljs-normal">            10 + 270 + 5, 30 + 380 + 85, </span><span class="hljs-comment">// Start</span><span class="hljs-normal"></span>
<span class="hljs-normal">            10 + 270 + 5, 30 + 380 + 170,</span><span class="hljs-comment">// CP 0</span><span class="hljs-normal"></span>
<span class="hljs-normal">            10 + 510 - 5, 30 + 380 + 170,</span><span class="hljs-comment">// CP 1</span><span class="hljs-normal"></span>
<span class="hljs-normal">            10 + 510 - 5, 30 + 380 + 85  </span><span class="hljs-comment">// End</span><span class="hljs-normal"></span>
<span class="hljs-normal">        );</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">        </span><span class="hljs-comment">// To compare thick bezier, we draw normal one on top of thick one</span><span class="hljs-normal"></span>
<span class="hljs-normal">        this-&gt;<a href="ffw_RenderContext.html#7acd1170">setOutlineSize</a>(1);</span>
<span class="hljs-normal">        this-&gt;<a href="ffw_RenderContext.html#6b8df6af">setDrawColor</a>(<a href="ffw.html#efcb64d9">ffw::rgba</a>(0xFF000080));</span>
<span class="hljs-normal">        this-&gt;<a href="ffw_RenderContext.html#b36a1802">drawBezier</a>(</span>
<span class="hljs-normal">            10 + 270 + 5, 30 + 380 + 85, </span><span class="hljs-comment">// Start</span><span class="hljs-normal"></span>
<span class="hljs-normal">            10 + 270 + 5, 30 + 380,      </span><span class="hljs-comment">// CP 0</span><span class="hljs-normal"></span>
<span class="hljs-normal">            10 + 510 - 5, 30 + 380,      </span><span class="hljs-comment">// CP 1</span><span class="hljs-normal"></span>
<span class="hljs-normal">            10 + 510 - 5, 30 + 380 + 85  </span><span class="hljs-comment">// End</span><span class="hljs-normal"></span>
<span class="hljs-normal">        );</span>
<span class="hljs-normal">        this-&gt;<a href="ffw_RenderContext.html#6b8df6af">setDrawColor</a>(<a href="ffw.html#efcb64d9">ffw::rgba</a>(0x00FF0080));</span>
<span class="hljs-normal">        this-&gt;<a href="ffw_RenderContext.html#b36a1802">drawBezier</a>(</span>
<span class="hljs-normal">            10 + 270 + 5, 30 + 380 + 85, </span><span class="hljs-comment">// Start</span><span class="hljs-normal"></span>
<span class="hljs-normal">            10 + 270 + 5, 30 + 380 + 170,</span><span class="hljs-comment">// CP 0</span><span class="hljs-normal"></span>
<span class="hljs-normal">            10 + 510 - 5, 30 + 380 + 170,</span><span class="hljs-comment">// CP 1</span><span class="hljs-normal"></span>
<span class="hljs-normal">            10 + 510 - 5, 30 + 380 + 85  </span><span class="hljs-comment">// End</span><span class="hljs-normal"></span>
<span class="hljs-normal">        );</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">        </span><span class="hljs-comment">// Quad</span><span class="hljs-normal"></span>
<span class="hljs-normal">        this-&gt;<a href="ffw_RenderContext.html#6b8df6af">setDrawColor</a>(<a href="ffw.html#efcb64d9">ffw::rgba</a>(0xFF000080));</span>
<span class="hljs-normal">        this-&gt;<a href="ffw_RenderContext.html#98c11b5c">drawQuad</a>(</span>
<span class="hljs-normal">            10 + 520 + 50, 30 + 380 + 0,</span>
<span class="hljs-normal">            10 + 520 + 100, 30 + 380 + 50,</span>
<span class="hljs-normal">            10 + 520 + 50, 30 + 380 + 100,</span>
<span class="hljs-normal">            10 + 520 + 0, 30 + 380 + 50</span>
<span class="hljs-normal">        );</span>
<span class="hljs-normal">        this-&gt;<a href="ffw_RenderContext.html#6b8df6af">setDrawColor</a>(<a href="ffw.html#efcb64d9">ffw::rgba</a>(0x00FF0080));</span>
<span class="hljs-normal">        this-&gt;<a href="ffw_RenderContext.html#98c11b5c">drawQuad</a>(</span>
<span class="hljs-normal">            10 + 520 + 53 + 50, 30 + 380 + 23 + 0,</span>
<span class="hljs-normal">            10 + 520 + 53 + 100, 30 + 380 + 23 + 50,</span>
<span class="hljs-normal">            10 + 520 + 53 + 50, 30 + 380 + 23 + 100,</span>
<span class="hljs-normal">            10 + 520 + 53 + 0, 30 + 380 + 23 + 50</span>
<span class="hljs-normal">        );</span>
<span class="hljs-normal">        this-&gt;<a href="ffw_RenderContext.html#6b8df6af">setDrawColor</a>(<a href="ffw.html#efcb64d9">ffw::rgba</a>(0x0000FF80));</span>
<span class="hljs-normal">        this-&gt;<a href="ffw_RenderContext.html#98c11b5c">drawQuad</a>(</span>
<span class="hljs-normal">            10 + 520 + 106 + 50, 30 + 380 + 46 + 0,</span>
<span class="hljs-normal">            10 + 520 + 106 + 100, 30 + 380 + 46 + 50,</span>
<span class="hljs-normal">            10 + 520 + 106 + 50, 30 + 380 + 46 + 100,</span>
<span class="hljs-normal">            10 + 520 + 106 + 0, 30 + 380 + 46 + 50</span>
<span class="hljs-normal">        );</span>
<span class="hljs-normal">    &#125;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">    </span><span class="hljs-title">void</span><span class="hljs-normal"> <a href="ffw_GLFWRenderWindow.html#eb5dbf50">close</a>()</span><span class="hljs-keyword"> override </span><span class="hljs-normal">&#123;</span>
<span class="hljs-normal">        std::cout &lt;&lt; </span><span class="hljs-string">"Window is closing!"</span><span class="hljs-normal"> &lt;&lt; std::endl;</span>
<span class="hljs-normal">    &#125;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">    </span><span class="hljs-title">void</span><span class="hljs-normal"> <a href="ffw_GLFWRenderWindow.html#d1e6b4ff">windowCloseEvent</a>()</span><span class="hljs-keyword"> override </span><span class="hljs-normal">&#123;</span>
<span class="hljs-normal">        std::cout &lt;&lt; </span><span class="hljs-string">"Window close button pressed!"</span><span class="hljs-normal"> &lt;&lt; std::endl;</span>
<span class="hljs-normal">        this-&gt;<a href="ffw_GLFWRenderWindow.html#f26e03bc">shouldClose</a>(</span><span class="hljs-keyword">true</span><span class="hljs-normal">);</span>
<span class="hljs-normal">    &#125;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal"></span><span class="hljs-keyword">private</span><span class="hljs-normal">:</span>
<span class="hljs-normal">    <a href="ffw_TrueTypeFont.html">ffw::TrueTypeFont</a> font;</span>
<span class="hljs-normal">&#125;;</span>
<span class="hljs-normal"></span>
<span class="hljs-title">int</span><span class="hljs-normal"> main(</span><span class="hljs-title">int</span><span class="hljs-normal"> argc, </span><span class="hljs-title">char</span><span class="hljs-normal"> *argv[]) &#123;</span>
<span class="hljs-normal">    </span><span class="hljs-comment">// Instance to our app class</span><span class="hljs-normal"></span>
<span class="hljs-normal">    App app;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">    </span><span class="hljs-comment">// set arguments</span><span class="hljs-normal"></span>
<span class="hljs-normal">    <a href="ffw_GLFWRenderWindowArgs.html">ffw::GLFWRenderWindowArgs</a> args;</span>
<span class="hljs-normal">    args.<a href="ffw_GLFWRenderWindowArgs.html#427706b8">size</a>.<a href="ffw_Vec2.html#e49a9b9e">set</a>(800, 600);</span>
<span class="hljs-normal">    args.<a href="ffw_GLFWRenderWindowArgs.html#b1b7d616">title</a> = </span><span class="hljs-string">"Font Example"</span><span class="hljs-normal">;</span>
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
<span class="hljs-normal">        system(</span><span class="hljs-string">"pause"</span><span class="hljs-normal">);</span>
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
<span class="hljs-normal">&#125;</span>
</div></pre>

 

