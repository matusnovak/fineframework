Example: Gui All Widgets
=================

![example-gui-all-widgets.jpg](example-gui-all-widgets.jpg)


The purpose of this example is to show all pre-defined GUI widgets inside of the fine gui module. This example uses OpenGL as an backend engine. The [ffw::GuiWindowOpenGL](ffw_GuiWindowOpenGL.html) class is provided for the user but **has to be manually included as `#include <[ffw/gui/guiwindowopengl.h]()>` after importing graphics module.** The user is free to choose any backend they wishes to use. To implement one, follow [ffw::GuiBackend](ffw_GuiBackend.html) and [ffw::GuiWindowOpenGL](ffw_GuiWindowOpenGL.html) documentation.

**Requires finegraphics, finegui, and finemath module to run**


<pre><div class="lang-cpp" style="white-space: pre-wrap;"><span class="hljs-meta-keyword">#include &lt;<a href="">ffw/graphics.h</a>&gt;</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span><span class="hljs-meta-keyword">#include &lt;<a href="">ffw/gui.h</a>&gt;</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span><span class="hljs-meta-keyword">#include &lt;<a href="">ffw/gui/guiwindowopengl.h</a>&gt;</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span><span class="hljs-meta-keyword">#include &lt;regex&gt;</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span><span class="hljs-meta-keyword">#include &lt;fstream&gt;</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span><span class="hljs-meta-keyword">#include &lt;memory&gt;</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span>
<span class="hljs-keyword">class </span><span class="hljs-normal">App: </span><span class="hljs-keyword">public</span><span class="hljs-normal"> <a href="ffw_GLFWRenderWindow.html">ffw::GLFWRenderWindow</a> &#123;</span>
<span class="hljs-normal"></span><span class="hljs-keyword">public</span><span class="hljs-normal">:</span>
<span class="hljs-normal">    App()&#123;</span>
<span class="hljs-normal">    &#125;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">    ~App()&#123;</span>
<span class="hljs-normal">    &#125;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">    </span><span class="hljs-title">void</span><span class="hljs-normal"> widgetEvent(<a href="ffw_GuiEvent.html">ffw::GuiEvent</a> e)&#123;</span>
<span class="hljs-normal">    &#125;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">    <a href="ffw_GuiLayout.html">ffw::GuiLayout</a>* makeBox(<a href="ffw_GuiWindow.html">ffw::GuiWindow</a>* window, <a href="ffw_GuiLayout.html">ffw::GuiLayout</a>* parent, </span><span class="hljs-keyword">const</span><span class="hljs-normal"> std::string&amp; str) &#123;</span>
<span class="hljs-normal">        </span><span class="hljs-keyword">auto</span><span class="hljs-normal"> box = </span><span class="hljs-keyword">new</span><span class="hljs-normal"> <a href="ffw_GuiVerticalLayout.html">ffw::GuiVerticalLayout</a>(&amp;gui);</span>
<span class="hljs-normal">        box-&gt;setSize(<a href="ffw.html#3107a022">ffw::guiPercent</a>(33.33333f), <a href="ffw.html#9eb691c9">ffw::guiWrap</a>());</span>
<span class="hljs-normal">        box-&gt;setPadding(5);</span>
<span class="hljs-normal">        parent-&gt;<a href="ffw_GuiLayout.html#34aa50c1">addWidget</a>(box);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">        </span><span class="hljs-keyword">auto</span><span class="hljs-normal"> label = </span><span class="hljs-keyword">new</span><span class="hljs-normal"> <a href="ffw_GuiLabel.html">ffw::GuiLabel</a>(window, str);</span>
<span class="hljs-normal">        box-&gt;addWidget(label);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">        </span><span class="hljs-keyword">auto</span><span class="hljs-normal"> layout = </span><span class="hljs-keyword">new</span><span class="hljs-normal"> <a href="ffw_GuiVerticalLayout.html">ffw::GuiVerticalLayout</a>(window);</span>
<span class="hljs-normal">        layout-&gt;setStyleGroup(&amp;boxStyle);</span>
<span class="hljs-normal">        layout-&gt;setSize(<a href="ffw.html#3107a022">ffw::guiPercent</a>(100), <a href="ffw.html#9eb691c9">ffw::guiWrap</a>());</span>
<span class="hljs-normal">        layout-&gt;setPadding(5);</span>
<span class="hljs-normal">        box-&gt;addWidget(layout);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">        </span><span class="hljs-keyword">return</span><span class="hljs-normal"> layout;</span>
<span class="hljs-normal">    &#125;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">    </span><span class="hljs-title">bool</span><span class="hljs-normal"> <a href="ffw_GLFWRenderWindow.html#68554ce1">setup</a>()</span><span class="hljs-keyword"> override </span><span class="hljs-normal">&#123;</span>
<span class="hljs-normal">        glEnable(GL_BLEND);</span>
<span class="hljs-normal">        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);</span>
<span class="hljs-normal">        </span><span class="hljs-comment">// PLEASE READ!!!</span><span class="hljs-normal"></span>
<span class="hljs-normal">        </span><span class="hljs-comment">// If you get artefacts around the font letters, uncomment "glBlendFuncSeparate"</span><span class="hljs-normal"></span>
<span class="hljs-normal">        </span><span class="hljs-comment">// and remove the "glBlendFunc" above!</span><span class="hljs-normal"></span>
<span class="hljs-normal">        </span><span class="hljs-comment">// glBlendFuncSeparate(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA, GL_ONE, GL_ONE_MINUS_SRC_ALPHA);</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span>
<span class="hljs-normal">        gui.setTheme(&amp;<a href="ffw_GuiTheme.html#fdd54264">ffw::GuiTheme::simpleLight</a>);</span>
<span class="hljs-normal">        gui.create(</span><span class="hljs-keyword">this</span><span class="hljs-normal">);</span>
<span class="hljs-normal">        gui.setSize(<a href="ffw_GLFWRenderWindow.html#70919473">getSize</a>().x, <a href="ffw_GLFWRenderWindow.html#70919473">getSize</a>().y);</span>
<span class="hljs-normal">        gui.setPos(0, 0);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">        </span><span class="hljs-comment">// The last two values indicate start and the end of the unicode</span><span class="hljs-normal"></span>
<span class="hljs-normal">        </span><span class="hljs-comment">// table to load.</span><span class="hljs-normal"></span>
<span class="hljs-normal">        </span><span class="hljs-comment">// To load ASCII only characters, enter 0 - 0x100</span><span class="hljs-normal"></span>
<span class="hljs-normal">        </span><span class="hljs-comment">// To load ASCII and Latin Extended-A, enter 0 - 0x17F</span><span class="hljs-normal"></span>
<span class="hljs-normal">        </span><span class="hljs-comment">// See "range" in: https://en.wikipedia.org/wiki/Latin_Extended-A</span><span class="hljs-normal"></span>
<span class="hljs-normal">        </span><span class="hljs-keyword">if</span><span class="hljs-normal"> (!fontBold.createFromFile(</span><span class="hljs-keyword">this</span><span class="hljs-normal">, </span><span class="hljs-string">"FreeSansBold.ttf"</span><span class="hljs-normal">, 12, 72, 0, 0x17F)) &#123;</span>
<span class="hljs-normal">            std::cout &lt;&lt; </span><span class="hljs-string">"Failed to create GUI font!"</span><span class="hljs-normal"> &lt;&lt; std::endl;</span>
<span class="hljs-normal">        &#125;</span>
<span class="hljs-normal">        </span><span class="hljs-keyword">if</span><span class="hljs-normal"> (!fontItalic.createFromFile(</span><span class="hljs-keyword">this</span><span class="hljs-normal">, </span><span class="hljs-string">"FreeSansOblique.ttf"</span><span class="hljs-normal">, 12, 72, 0, 0x17F)) &#123;</span>
<span class="hljs-normal">            std::cout &lt;&lt; </span><span class="hljs-string">"Failed to create GUI font!"</span><span class="hljs-normal"> &lt;&lt; std::endl;</span>
<span class="hljs-normal">        &#125;</span>
<span class="hljs-normal">        </span><span class="hljs-keyword">if</span><span class="hljs-normal"> (!fontRegular.createFromFile(</span><span class="hljs-keyword">this</span><span class="hljs-normal">, </span><span class="hljs-string">"FreeSans.ttf"</span><span class="hljs-normal">, 12, 72, 0, 0x17F)) &#123;</span>
<span class="hljs-normal">            std::cout &lt;&lt; </span><span class="hljs-string">"Failed to create GUI font!"</span><span class="hljs-normal"> &lt;&lt; std::endl;</span>
<span class="hljs-normal">        &#125;</span>
<span class="hljs-normal">        </span><span class="hljs-keyword">else</span><span class="hljs-normal"> &#123;</span>
<span class="hljs-normal">            gui.setDefaultFont(&amp;fontRegular);</span>
<span class="hljs-normal">        &#125;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">        boxStyle = gui.getTheme()-&gt;getStyleGroup(</span><span class="hljs-string">"GUI_LAYOUT"</span><span class="hljs-normal">);</span>
<span class="hljs-normal">        boxStyle.normal.border.color = <a href="ffw.html#efcb64d9">ffw::rgba</a>(0x80808050);</span>
<span class="hljs-normal">        boxStyle.normal.border.size = 1;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">        gui.getLayout()-&gt;setPadding(0);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">        </span><span class="hljs-keyword">auto</span><span class="hljs-normal"> scroll = </span><span class="hljs-keyword">new</span><span class="hljs-normal"> <a href="ffw_GuiScrollableLayout.html">ffw::GuiScrollableLayout</a>(&amp;gui, <a href="ffw_GuiWidget_Orientation.html#dd5a00a1">ffw::GuiLayout::Orientation::HORIZONTAL</a>, </span><span class="hljs-keyword">false</span><span class="hljs-normal">, </span><span class="hljs-keyword">true</span><span class="hljs-normal">);</span>
<span class="hljs-normal">        scroll-&gt;setSize(<a href="ffw.html#3107a022">ffw::guiPercent</a>(100), <a href="ffw.html#3107a022">ffw::guiPercent</a>(100));</span>
<span class="hljs-normal">        gui.getLayout()-&gt;addWidget(scroll);</span>
<span class="hljs-normal">        scroll-&gt;getInner()-&gt;setWrap(</span><span class="hljs-keyword">true</span><span class="hljs-normal">);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">        </span><span class="hljs-comment">// Buttons</span><span class="hljs-normal"></span>
<span class="hljs-normal">        &#123;</span>
<span class="hljs-normal">            </span><span class="hljs-keyword">auto</span><span class="hljs-normal"> box = makeBox(&amp;gui, scroll-&gt;getInner(), </span><span class="hljs-string">"Button"</span><span class="hljs-normal">);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">            </span><span class="hljs-keyword">auto</span><span class="hljs-normal"> button = </span><span class="hljs-keyword">new</span><span class="hljs-normal"> <a href="ffw_GuiButton.html">ffw::GuiButton</a>(&amp;gui, </span><span class="hljs-string">"Normal"</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            box-&gt;addWidget(button);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">            button = </span><span class="hljs-keyword">new</span><span class="hljs-normal"> <a href="ffw_GuiButton.html">ffw::GuiButton</a>(&amp;gui, </span><span class="hljs-string">"Hover"</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            button-&gt;setHover(</span><span class="hljs-keyword">true</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            button-&gt;setIgnoreUserInput(</span><span class="hljs-keyword">true</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            box-&gt;addWidget(button);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">            button = </span><span class="hljs-keyword">new</span><span class="hljs-normal"> <a href="ffw_GuiButton.html">ffw::GuiButton</a>(&amp;gui, </span><span class="hljs-string">"Focus"</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            button-&gt;setFocus(</span><span class="hljs-keyword">true</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            button-&gt;setIgnoreUserInput(</span><span class="hljs-keyword">true</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            box-&gt;addWidget(button);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">            button = </span><span class="hljs-keyword">new</span><span class="hljs-normal"> <a href="ffw_GuiButton.html">ffw::GuiButton</a>(&amp;gui, </span><span class="hljs-string">"Disabled"</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            button-&gt;setDisabled(</span><span class="hljs-keyword">true</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            box-&gt;addWidget(button);</span>
<span class="hljs-normal">        &#125;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">        </span><span class="hljs-comment">// Toogle buttons</span><span class="hljs-normal"></span>
<span class="hljs-normal">        &#123;</span>
<span class="hljs-normal">            </span><span class="hljs-keyword">auto</span><span class="hljs-normal"> box = makeBox(&amp;gui, scroll-&gt;getInner(), </span><span class="hljs-string">"Toggle Button"</span><span class="hljs-normal">);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">            </span><span class="hljs-keyword">auto</span><span class="hljs-normal"> button = </span><span class="hljs-keyword">new</span><span class="hljs-normal"> <a href="ffw_GuiButtonToggle.html">ffw::GuiButtonToggle</a>(&amp;gui, </span><span class="hljs-string">"Normal"</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            box-&gt;addWidget(button);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">            button = </span><span class="hljs-keyword">new</span><span class="hljs-normal"> <a href="ffw_GuiButtonToggle.html">ffw::GuiButtonToggle</a>(&amp;gui, </span><span class="hljs-string">"Hover"</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            button-&gt;setHover(</span><span class="hljs-keyword">true</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            button-&gt;setIgnoreUserInput(</span><span class="hljs-keyword">true</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            box-&gt;addWidget(button);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">            button = </span><span class="hljs-keyword">new</span><span class="hljs-normal"> <a href="ffw_GuiButtonToggle.html">ffw::GuiButtonToggle</a>(&amp;gui, </span><span class="hljs-string">"Focus"</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            button-&gt;setFocus(</span><span class="hljs-keyword">true</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            button-&gt;setIgnoreUserInput(</span><span class="hljs-keyword">true</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            box-&gt;addWidget(button);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">            button = </span><span class="hljs-keyword">new</span><span class="hljs-normal"> <a href="ffw_GuiButtonToggle.html">ffw::GuiButtonToggle</a>(&amp;gui, </span><span class="hljs-string">"Disabled"</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            button-&gt;setDisabled(</span><span class="hljs-keyword">true</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            box-&gt;addWidget(button);</span>
<span class="hljs-normal">        &#125;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">        </span><span class="hljs-comment">// Primary Buttons</span><span class="hljs-normal"></span>
<span class="hljs-normal">        &#123;</span>
<span class="hljs-normal">            </span><span class="hljs-keyword">auto</span><span class="hljs-normal"> box = makeBox(&amp;gui, scroll-&gt;getInner(), </span><span class="hljs-string">"Primary Button"</span><span class="hljs-normal">);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">            </span><span class="hljs-keyword">auto</span><span class="hljs-normal"> button = </span><span class="hljs-keyword">new</span><span class="hljs-normal"> <a href="ffw_GuiButtonPrimary.html">ffw::GuiButtonPrimary</a>(&amp;gui, </span><span class="hljs-string">"Normal"</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            box-&gt;addWidget(button);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">            button = </span><span class="hljs-keyword">new</span><span class="hljs-normal"> <a href="ffw_GuiButtonPrimary.html">ffw::GuiButtonPrimary</a>(&amp;gui, </span><span class="hljs-string">"Hover"</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            button-&gt;setHover(</span><span class="hljs-keyword">true</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            button-&gt;setIgnoreUserInput(</span><span class="hljs-keyword">true</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            box-&gt;addWidget(button);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">            button = </span><span class="hljs-keyword">new</span><span class="hljs-normal"> <a href="ffw_GuiButtonPrimary.html">ffw::GuiButtonPrimary</a>(&amp;gui, </span><span class="hljs-string">"Focus"</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            button-&gt;setFocus(</span><span class="hljs-keyword">true</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            button-&gt;setIgnoreUserInput(</span><span class="hljs-keyword">true</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            box-&gt;addWidget(button);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">            button = </span><span class="hljs-keyword">new</span><span class="hljs-normal"> <a href="ffw_GuiButtonPrimary.html">ffw::GuiButtonPrimary</a>(&amp;gui, </span><span class="hljs-string">"Disabled"</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            button-&gt;setDisabled(</span><span class="hljs-keyword">true</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            box-&gt;addWidget(button);</span>
<span class="hljs-normal">        &#125;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">        </span><span class="hljs-comment">// Labels</span><span class="hljs-normal"></span>
<span class="hljs-normal">        &#123;</span>
<span class="hljs-normal">            </span><span class="hljs-keyword">auto</span><span class="hljs-normal"> box = makeBox(&amp;gui, scroll-&gt;getInner(), </span><span class="hljs-string">"Labels"</span><span class="hljs-normal">);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">            </span><span class="hljs-keyword">auto</span><span class="hljs-normal"> label = </span><span class="hljs-keyword">new</span><span class="hljs-normal"> <a href="ffw_GuiLabel.html">ffw::GuiLabel</a>(&amp;gui, </span><span class="hljs-string">"Left align"</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            label-&gt;setAlign(<a href="ffw_GuiStyle_Align.html#846eca00">ffw::GuiStyle::Align::LEFT</a>);</span>
<span class="hljs-normal">            box-&gt;addWidget(label);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">            label = </span><span class="hljs-keyword">new</span><span class="hljs-normal"> <a href="ffw_GuiLabel.html">ffw::GuiLabel</a>(&amp;gui, </span><span class="hljs-string">"Center align"</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            label-&gt;setAlign(<a href="ffw_GuiStyle_Align.html#8f5dfeb5">ffw::GuiStyle::Align::CENTER</a>);</span>
<span class="hljs-normal">            box-&gt;addWidget(label);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">            label = </span><span class="hljs-keyword">new</span><span class="hljs-normal"> <a href="ffw_GuiLabel.html">ffw::GuiLabel</a>(&amp;gui, </span><span class="hljs-string">"Right align"</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            label-&gt;setAlign(<a href="ffw_GuiStyle_Align.html#a9dcd5fc">ffw::GuiStyle::Align::RIGHT</a>);</span>
<span class="hljs-normal">            box-&gt;addWidget(label);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">            label = </span><span class="hljs-keyword">new</span><span class="hljs-normal"> <a href="ffw_GuiLabel.html">ffw::GuiLabel</a>(&amp;gui, </span><span class="hljs-string">"First line\nSecond line"</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            box-&gt;addWidget(label);</span>
<span class="hljs-normal">        &#125;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">        </span><span class="hljs-comment">// Radios</span><span class="hljs-normal"></span>
<span class="hljs-normal">        &#123;</span>
<span class="hljs-normal">            </span><span class="hljs-keyword">auto</span><span class="hljs-normal"> box = makeBox(&amp;gui, scroll-&gt;getInner(), </span><span class="hljs-string">"Radio"</span><span class="hljs-normal">);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">            </span><span class="hljs-keyword">auto</span><span class="hljs-normal"> radio = </span><span class="hljs-keyword">new</span><span class="hljs-normal"> <a href="ffw_GuiRadio.html">ffw::GuiRadio</a>(&amp;gui, </span><span class="hljs-string">"Normal"</span><span class="hljs-normal">, 0, NULL);</span>
<span class="hljs-normal">            box-&gt;addWidget(radio);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">            radio = </span><span class="hljs-keyword">new</span><span class="hljs-normal"> <a href="ffw_GuiRadio.html">ffw::GuiRadio</a>(&amp;gui, </span><span class="hljs-string">"Hover"</span><span class="hljs-normal">, 0, NULL);</span>
<span class="hljs-normal">            radio-&gt;setHover(</span><span class="hljs-keyword">true</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            radio-&gt;setIgnoreUserInput(</span><span class="hljs-keyword">true</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            box-&gt;addWidget(radio);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">            radio = </span><span class="hljs-keyword">new</span><span class="hljs-normal"> <a href="ffw_GuiRadio.html">ffw::GuiRadio</a>(&amp;gui, </span><span class="hljs-string">"Focus"</span><span class="hljs-normal">, 0, NULL);</span>
<span class="hljs-normal">            radio-&gt;setFocus(</span><span class="hljs-keyword">true</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            radio-&gt;setIgnoreUserInput(</span><span class="hljs-keyword">true</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            box-&gt;addWidget(radio);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">            radio = </span><span class="hljs-keyword">new</span><span class="hljs-normal"> <a href="ffw_GuiRadio.html">ffw::GuiRadio</a>(&amp;gui, </span><span class="hljs-string">"Disabled"</span><span class="hljs-normal">, 0, NULL);</span>
<span class="hljs-normal">            radio-&gt;setDisabled(</span><span class="hljs-keyword">true</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            box-&gt;addWidget(radio);</span>
<span class="hljs-normal">        &#125;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">        </span><span class="hljs-comment">// Checkboxes</span><span class="hljs-normal"></span>
<span class="hljs-normal">        &#123;</span>
<span class="hljs-normal">            </span><span class="hljs-keyword">auto</span><span class="hljs-normal"> box = makeBox(&amp;gui, scroll-&gt;getInner(), </span><span class="hljs-string">"Checkbox"</span><span class="hljs-normal">);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">            </span><span class="hljs-keyword">auto</span><span class="hljs-normal"> checkbox = </span><span class="hljs-keyword">new</span><span class="hljs-normal"> <a href="ffw_GuiCheckbox.html">ffw::GuiCheckbox</a>(&amp;gui, </span><span class="hljs-string">"Normal"</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            box-&gt;addWidget(checkbox);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">            checkbox = </span><span class="hljs-keyword">new</span><span class="hljs-normal"> <a href="ffw_GuiCheckbox.html">ffw::GuiCheckbox</a>(&amp;gui, </span><span class="hljs-string">"Hover"</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            checkbox-&gt;setHover(</span><span class="hljs-keyword">true</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            checkbox-&gt;setIgnoreUserInput(</span><span class="hljs-keyword">true</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            box-&gt;addWidget(checkbox);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">            checkbox = </span><span class="hljs-keyword">new</span><span class="hljs-normal"> <a href="ffw_GuiCheckbox.html">ffw::GuiCheckbox</a>(&amp;gui, </span><span class="hljs-string">"Focus"</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            checkbox-&gt;setFocus(</span><span class="hljs-keyword">true</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            checkbox-&gt;setIgnoreUserInput(</span><span class="hljs-keyword">true</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            box-&gt;addWidget(checkbox);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">            checkbox = </span><span class="hljs-keyword">new</span><span class="hljs-normal"> <a href="ffw_GuiCheckbox.html">ffw::GuiCheckbox</a>(&amp;gui, </span><span class="hljs-string">"Disabled"</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            checkbox-&gt;setDisabled(</span><span class="hljs-keyword">true</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            box-&gt;addWidget(checkbox);</span>
<span class="hljs-normal">        &#125;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">        </span><span class="hljs-comment">// Sliders</span><span class="hljs-normal"></span>
<span class="hljs-normal">        &#123;</span>
<span class="hljs-normal">            </span><span class="hljs-keyword">auto</span><span class="hljs-normal"> box = makeBox(&amp;gui, scroll-&gt;getInner(), </span><span class="hljs-string">"Horizontal Sliders"</span><span class="hljs-normal">);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">            </span><span class="hljs-keyword">auto</span><span class="hljs-normal"> label = </span><span class="hljs-keyword">new</span><span class="hljs-normal"> <a href="ffw_GuiLabel.html">ffw::GuiLabel</a>(&amp;gui, </span><span class="hljs-string">"Normal:"</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            box-&gt;addWidget(label);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">            </span><span class="hljs-keyword">auto</span><span class="hljs-normal"> slider = </span><span class="hljs-keyword">new</span><span class="hljs-normal"> <a href="ffw_GuiSlider.html">ffw::GuiSlider</a>(&amp;gui, </span><span class="hljs-keyword">false</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            box-&gt;addWidget(slider);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">            label = </span><span class="hljs-keyword">new</span><span class="hljs-normal"> <a href="ffw_GuiLabel.html">ffw::GuiLabel</a>(&amp;gui, </span><span class="hljs-string">"Normal inversed:"</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            box-&gt;addWidget(label);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">            slider = </span><span class="hljs-keyword">new</span><span class="hljs-normal"> <a href="ffw_GuiSlider.html">ffw::GuiSlider</a>(&amp;gui, </span><span class="hljs-keyword">false</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            slider-&gt;setInversed(</span><span class="hljs-keyword">true</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            box-&gt;addWidget(slider);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">            label = </span><span class="hljs-keyword">new</span><span class="hljs-normal"> <a href="ffw_GuiLabel.html">ffw::GuiLabel</a>(&amp;gui, </span><span class="hljs-string">"Hover:"</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            box-&gt;addWidget(label);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">            slider = </span><span class="hljs-keyword">new</span><span class="hljs-normal"> <a href="ffw_GuiSlider.html">ffw::GuiSlider</a>(&amp;gui, </span><span class="hljs-keyword">false</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            slider-&gt;setHover(</span><span class="hljs-keyword">true</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            slider-&gt;setIgnoreUserInput(</span><span class="hljs-keyword">true</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            box-&gt;addWidget(slider);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">            label = </span><span class="hljs-keyword">new</span><span class="hljs-normal"> <a href="ffw_GuiLabel.html">ffw::GuiLabel</a>(&amp;gui, </span><span class="hljs-string">"Focus:"</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            box-&gt;addWidget(label);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">            slider = </span><span class="hljs-keyword">new</span><span class="hljs-normal"> <a href="ffw_GuiSlider.html">ffw::GuiSlider</a>(&amp;gui, </span><span class="hljs-keyword">false</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            slider-&gt;setFocus(</span><span class="hljs-keyword">true</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            slider-&gt;setIgnoreUserInput(</span><span class="hljs-keyword">true</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            box-&gt;addWidget(slider);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">            label = </span><span class="hljs-keyword">new</span><span class="hljs-normal"> <a href="ffw_GuiLabel.html">ffw::GuiLabel</a>(&amp;gui, </span><span class="hljs-string">"Disabled:"</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            box-&gt;addWidget(label);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">            slider = </span><span class="hljs-keyword">new</span><span class="hljs-normal"> <a href="ffw_GuiSlider.html">ffw::GuiSlider</a>(&amp;gui, </span><span class="hljs-keyword">false</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            slider-&gt;setDisabled(</span><span class="hljs-keyword">true</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            box-&gt;addWidget(slider);</span>
<span class="hljs-normal">        &#125;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">        </span><span class="hljs-comment">// Vertical sliders</span><span class="hljs-normal"></span>
<span class="hljs-normal">        &#123;</span>
<span class="hljs-normal">            </span><span class="hljs-keyword">auto</span><span class="hljs-normal"> box = makeBox(&amp;gui, scroll-&gt;getInner(), </span><span class="hljs-string">"Vertical Sliders"</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            box-&gt;setSize(box-&gt;getSize().x, <a href="ffw.html#66baed55">ffw::guiPixels</a>(235));</span>
<span class="hljs-normal">            box-&gt;setOrientation(<a href="ffw_GuiWidget_Orientation.html#dd5a00a1">ffw::GuiLayout::Orientation::HORIZONTAL</a>);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">            </span><span class="hljs-keyword">auto</span><span class="hljs-normal"> slider = </span><span class="hljs-keyword">new</span><span class="hljs-normal"> <a href="ffw_GuiSlider.html">ffw::GuiSlider</a>(&amp;gui, </span><span class="hljs-keyword">true</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            box-&gt;addWidget(slider);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">            slider = </span><span class="hljs-keyword">new</span><span class="hljs-normal"> <a href="ffw_GuiSlider.html">ffw::GuiSlider</a>(&amp;gui, </span><span class="hljs-keyword">true</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            slider-&gt;setInversed(</span><span class="hljs-keyword">true</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            box-&gt;addWidget(slider);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">            slider = </span><span class="hljs-keyword">new</span><span class="hljs-normal"> <a href="ffw_GuiSlider.html">ffw::GuiSlider</a>(&amp;gui, </span><span class="hljs-keyword">true</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            slider-&gt;setHover(</span><span class="hljs-keyword">true</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            slider-&gt;setIgnoreUserInput(</span><span class="hljs-keyword">true</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            box-&gt;addWidget(slider);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">            slider = </span><span class="hljs-keyword">new</span><span class="hljs-normal"> <a href="ffw_GuiSlider.html">ffw::GuiSlider</a>(&amp;gui, </span><span class="hljs-keyword">true</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            slider-&gt;setFocus(</span><span class="hljs-keyword">true</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            slider-&gt;setIgnoreUserInput(</span><span class="hljs-keyword">true</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            box-&gt;addWidget(slider);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">            slider = </span><span class="hljs-keyword">new</span><span class="hljs-normal"> <a href="ffw_GuiSlider.html">ffw::GuiSlider</a>(&amp;gui, </span><span class="hljs-keyword">true</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            slider-&gt;setDisabled(</span><span class="hljs-keyword">true</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            box-&gt;addWidget(slider);</span>
<span class="hljs-normal">        &#125;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">        </span><span class="hljs-comment">// Scrollbars</span><span class="hljs-normal"></span>
<span class="hljs-normal">        &#123;</span>
<span class="hljs-normal">            </span><span class="hljs-keyword">auto</span><span class="hljs-normal"> box = makeBox(&amp;gui, scroll-&gt;getInner(), </span><span class="hljs-string">"Scrollbars"</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            box-&gt;setSize(box-&gt;getSize().x, <a href="ffw.html#66baed55">ffw::guiPixels</a>(235));</span>
<span class="hljs-normal">            box-&gt;setOrientation(<a href="ffw_GuiWidget_Orientation.html#dd5a00a1">ffw::GuiLayout::Orientation::HORIZONTAL</a>);</span>
<span class="hljs-normal">            box-&gt;setWrap(</span><span class="hljs-keyword">true</span><span class="hljs-normal">);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">            </span><span class="hljs-keyword">auto</span><span class="hljs-normal"> label = </span><span class="hljs-keyword">new</span><span class="hljs-normal"> <a href="ffw_GuiLabel.html">ffw::GuiLabel</a>(&amp;gui, </span><span class="hljs-string">"Normal:"</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            box-&gt;addWidget(label);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">            </span><span class="hljs-keyword">auto</span><span class="hljs-normal"> scrollbar = </span><span class="hljs-keyword">new</span><span class="hljs-normal"> <a href="ffw_GuiScrollBar.html">ffw::GuiScrollBar</a>(&amp;gui, </span><span class="hljs-keyword">false</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            box-&gt;addWidget(scrollbar);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">            label = </span><span class="hljs-keyword">new</span><span class="hljs-normal"> <a href="ffw_GuiLabel.html">ffw::GuiLabel</a>(&amp;gui, </span><span class="hljs-string">"Hover:"</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            box-&gt;addWidget(label);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">            scrollbar = </span><span class="hljs-keyword">new</span><span class="hljs-normal"> <a href="ffw_GuiScrollBar.html">ffw::GuiScrollBar</a>(&amp;gui, </span><span class="hljs-keyword">false</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            scrollbar-&gt;setHover(</span><span class="hljs-keyword">true</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            scrollbar-&gt;setIgnoreUserInput(</span><span class="hljs-keyword">true</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            box-&gt;addWidget(scrollbar);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">            label = </span><span class="hljs-keyword">new</span><span class="hljs-normal"> <a href="ffw_GuiLabel.html">ffw::GuiLabel</a>(&amp;gui, </span><span class="hljs-string">"Focus:"</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            box-&gt;addWidget(label);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">            scrollbar = </span><span class="hljs-keyword">new</span><span class="hljs-normal"> <a href="ffw_GuiScrollBar.html">ffw::GuiScrollBar</a>(&amp;gui, </span><span class="hljs-keyword">false</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            scrollbar-&gt;setFocus(</span><span class="hljs-keyword">true</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            scrollbar-&gt;setIgnoreUserInput(</span><span class="hljs-keyword">true</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            box-&gt;addWidget(scrollbar);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">            label = </span><span class="hljs-keyword">new</span><span class="hljs-normal"> <a href="ffw_GuiLabel.html">ffw::GuiLabel</a>(&amp;gui, </span><span class="hljs-string">"Disabled:"</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            box-&gt;addWidget(label);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">            scrollbar = </span><span class="hljs-keyword">new</span><span class="hljs-normal"> <a href="ffw_GuiScrollBar.html">ffw::GuiScrollBar</a>(&amp;gui, </span><span class="hljs-keyword">false</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            scrollbar-&gt;setDisabled(</span><span class="hljs-keyword">true</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            box-&gt;addWidget(scrollbar);</span>
<span class="hljs-normal">        &#125;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">        </span><span class="hljs-comment">// Scrollbars</span><span class="hljs-normal"></span>
<span class="hljs-normal">        &#123;</span>
<span class="hljs-normal">            </span><span class="hljs-keyword">auto</span><span class="hljs-normal"> box = makeBox(&amp;gui, scroll-&gt;getInner(), </span><span class="hljs-string">"Image Viewer"</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            box-&gt;setSize(box-&gt;getSize().x, <a href="ffw.html#66baed55">ffw::guiPixels</a>(198));</span>
<span class="hljs-normal">            box-&gt;setOrientation(<a href="ffw_GuiWidget_Orientation.html#dd5a00a1">ffw::GuiLayout::Orientation::HORIZONTAL</a>);</span>
<span class="hljs-normal">            box-&gt;setWrap(</span><span class="hljs-keyword">true</span><span class="hljs-normal">);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">            </span><span class="hljs-comment">// 360x240 RGB (8-bit per channel)</span><span class="hljs-normal"></span>
<span class="hljs-normal">            std::unique_ptr&lt;unsigned char&gt; pixels(</span><span class="hljs-keyword">new</span><span class="hljs-normal"> </span><span class="hljs-title">unsigned</span><span class="hljs-normal"> </span><span class="hljs-title">char</span><span class="hljs-normal">[360 * 240 * 3]);</span>
<span class="hljs-normal">            std::ifstream input(</span><span class="hljs-string">"owl.raw"</span><span class="hljs-normal">, std::ios::in | std::ios::binary);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">            </span><span class="hljs-comment">// Checks needs to be done but none are written,</span><span class="hljs-normal"></span>
<span class="hljs-normal">            </span><span class="hljs-comment">// just for the purpose of the example</span><span class="hljs-normal"></span>
<span class="hljs-normal">            input.read((</span><span class="hljs-title">char</span><span class="hljs-normal">*)pixels.get(), 360 * 240 * 3);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">            </span><span class="hljs-comment">// Custom GuiImageOpenGL wrapper around GuiImage interface</span><span class="hljs-normal"></span>
<span class="hljs-normal">            image.create(</span><span class="hljs-keyword">this</span><span class="hljs-normal">, 360, 240, GL_RGB8, GL_RGB, GL_UNSIGNED_BYTE);</span>
<span class="hljs-normal">            image.setPixels(0, 0, 0, 360, 240, pixels.get());</span>
<span class="hljs-normal">            </span>
<span class="hljs-normal">            </span><span class="hljs-keyword">auto</span><span class="hljs-normal"> viewer = </span><span class="hljs-keyword">new</span><span class="hljs-normal"> <a href="ffw_GuiImageViewer.html">ffw::GuiImageViewer</a>(&amp;gui, &amp;image);</span>
<span class="hljs-normal">            box-&gt;addWidget(viewer);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">            </span><span class="hljs-keyword">auto</span><span class="hljs-normal"> label = </span><span class="hljs-keyword">new</span><span class="hljs-normal"> <a href="ffw_GuiLabel.html">ffw::GuiLabel</a>(&amp;gui, </span><span class="hljs-string">"Subsection:"</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            box-&gt;addWidget(label);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">            viewer = </span><span class="hljs-keyword">new</span><span class="hljs-normal"> <a href="ffw_GuiImageViewer.html">ffw::GuiImageViewer</a>(&amp;gui, &amp;image);</span>
<span class="hljs-normal">            box-&gt;addWidget(viewer);</span>
<span class="hljs-normal">            viewer-&gt;setSize(<a href="ffw.html#66baed55">ffw::guiPixels</a>(80), <a href="ffw.html#9eb691c9">ffw::guiWrap</a>());</span>
<span class="hljs-normal">            viewer-&gt;setSubsection(140, 40, 130, 80);</span>
<span class="hljs-normal">            viewer-&gt;setMirror(</span><span class="hljs-keyword">true</span><span class="hljs-normal">, </span><span class="hljs-keyword">false</span><span class="hljs-normal">);</span>
<span class="hljs-normal">        &#125;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">        </span><span class="hljs-comment">// Text Input</span><span class="hljs-normal"></span>
<span class="hljs-normal">        &#123;</span>
<span class="hljs-normal">            </span><span class="hljs-keyword">auto</span><span class="hljs-normal"> box = makeBox(&amp;gui, scroll-&gt;getInner(), </span><span class="hljs-string">"Text Input"</span><span class="hljs-normal">);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">            </span><span class="hljs-keyword">auto</span><span class="hljs-normal"> label = </span><span class="hljs-keyword">new</span><span class="hljs-normal"> <a href="ffw_GuiLabel.html">ffw::GuiLabel</a>(&amp;gui, </span><span class="hljs-string">"Normal:"</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            box-&gt;addWidget(label);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">            </span><span class="hljs-keyword">auto</span><span class="hljs-normal"> input = </span><span class="hljs-keyword">new</span><span class="hljs-normal"> <a href="ffw_GuiTextInput.html">ffw::GuiTextInput</a>(&amp;gui, </span><span class="hljs-keyword">false</span><span class="hljs-normal">, </span><span class="hljs-keyword">true</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            input-&gt;setValue(L</span><span class="hljs-string">"Hello World!"</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            box-&gt;addWidget(input);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">            label = </span><span class="hljs-keyword">new</span><span class="hljs-normal"> <a href="ffw_GuiLabel.html">ffw::GuiLabel</a>(&amp;gui, </span><span class="hljs-string">"Hover:"</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            box-&gt;addWidget(label);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">            input = </span><span class="hljs-keyword">new</span><span class="hljs-normal"> <a href="ffw_GuiTextInput.html">ffw::GuiTextInput</a>(&amp;gui, </span><span class="hljs-keyword">false</span><span class="hljs-normal">, </span><span class="hljs-keyword">true</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            input-&gt;setValue(L</span><span class="hljs-string">"Hello World!"</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            input-&gt;setHover(</span><span class="hljs-keyword">true</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            input-&gt;setIgnoreUserInput(</span><span class="hljs-keyword">true</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            box-&gt;addWidget(input);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">            label = </span><span class="hljs-keyword">new</span><span class="hljs-normal"> <a href="ffw_GuiLabel.html">ffw::GuiLabel</a>(&amp;gui, </span><span class="hljs-string">"Focus:"</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            box-&gt;addWidget(label);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">            input = </span><span class="hljs-keyword">new</span><span class="hljs-normal"> <a href="ffw_GuiTextInput.html">ffw::GuiTextInput</a>(&amp;gui, </span><span class="hljs-keyword">false</span><span class="hljs-normal">, </span><span class="hljs-keyword">true</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            input-&gt;setValue(L</span><span class="hljs-string">"Hello World!"</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            input-&gt;setFocus(</span><span class="hljs-keyword">true</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            input-&gt;setIgnoreUserInput(</span><span class="hljs-keyword">true</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            box-&gt;addWidget(input);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">            label = </span><span class="hljs-keyword">new</span><span class="hljs-normal"> <a href="ffw_GuiLabel.html">ffw::GuiLabel</a>(&amp;gui, </span><span class="hljs-string">"Disabled:"</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            box-&gt;addWidget(label);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">            input = </span><span class="hljs-keyword">new</span><span class="hljs-normal"> <a href="ffw_GuiTextInput.html">ffw::GuiTextInput</a>(&amp;gui, </span><span class="hljs-keyword">false</span><span class="hljs-normal">, </span><span class="hljs-keyword">true</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            input-&gt;setValue(L</span><span class="hljs-string">"Hello World!"</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            input-&gt;setDisabled(</span><span class="hljs-keyword">true</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            box-&gt;addWidget(input);</span>
<span class="hljs-normal">        &#125;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">        </span><span class="hljs-comment">// Text Input</span><span class="hljs-normal"></span>
<span class="hljs-normal">        &#123;</span>
<span class="hljs-normal">            </span><span class="hljs-keyword">auto</span><span class="hljs-normal"> box = makeBox(&amp;gui, scroll-&gt;getInner(), </span><span class="hljs-string">"Text Input + match"</span><span class="hljs-normal">);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">            </span><span class="hljs-keyword">auto</span><span class="hljs-normal"> label = </span><span class="hljs-keyword">new</span><span class="hljs-normal"> <a href="ffw_GuiLabel.html">ffw::GuiLabel</a>(&amp;gui, </span><span class="hljs-string">"Integers:"</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            box-&gt;addWidget(label);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">            </span><span class="hljs-keyword">auto</span><span class="hljs-normal"> input = </span><span class="hljs-keyword">new</span><span class="hljs-normal"> <a href="ffw_GuiTextInput.html">ffw::GuiTextInput</a>(&amp;gui, </span><span class="hljs-keyword">false</span><span class="hljs-normal">, </span><span class="hljs-keyword">true</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            input-&gt;setValue(L</span><span class="hljs-string">"-0123"</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            </span><span class="hljs-comment">// Zero or one '-' following by any number of digits</span><span class="hljs-normal"></span>
<span class="hljs-normal">            input-&gt;setMatch(L</span><span class="hljs-string">"^-?[0-9]*$"</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            box-&gt;addWidget(input);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">            label = </span><span class="hljs-keyword">new</span><span class="hljs-normal"> <a href="ffw_GuiLabel.html">ffw::GuiLabel</a>(&amp;gui, </span><span class="hljs-string">"Decimals:"</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            box-&gt;addWidget(label);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">            input = </span><span class="hljs-keyword">new</span><span class="hljs-normal"> <a href="ffw_GuiTextInput.html">ffw::GuiTextInput</a>(&amp;gui, </span><span class="hljs-keyword">false</span><span class="hljs-normal">, </span><span class="hljs-keyword">true</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            input-&gt;setValue(L</span><span class="hljs-string">"-0.6662"</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            </span><span class="hljs-comment">// Zero or one '-' following by any number of digits</span><span class="hljs-normal"></span>
<span class="hljs-normal">            </span><span class="hljs-comment">// then zero or one dot then again, any digit.</span><span class="hljs-normal"></span>
<span class="hljs-normal">            input-&gt;setMatch(L</span><span class="hljs-string">"^-?[0-9]*\\.?[0-9]*$"</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            box-&gt;addWidget(input);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">            label = </span><span class="hljs-keyword">new</span><span class="hljs-normal"> <a href="ffw_GuiLabel.html">ffw::GuiLabel</a>(&amp;gui, </span><span class="hljs-string">"Capitals:"</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            box-&gt;addWidget(label);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">            input = </span><span class="hljs-keyword">new</span><span class="hljs-normal"> <a href="ffw_GuiTextInput.html">ffw::GuiTextInput</a>(&amp;gui, </span><span class="hljs-keyword">false</span><span class="hljs-normal">, </span><span class="hljs-keyword">true</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            input-&gt;setValue(L</span><span class="hljs-string">"HELLO WORLD"</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            </span><span class="hljs-comment">// Any capital character and whitespace</span><span class="hljs-normal"></span>
<span class="hljs-normal">            input-&gt;setMatch(L</span><span class="hljs-string">"[A-Z\\s]*"</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            box-&gt;addWidget(input);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">            label = </span><span class="hljs-keyword">new</span><span class="hljs-normal"> <a href="ffw_GuiLabel.html">ffw::GuiLabel</a>(&amp;gui, </span><span class="hljs-string">"No special characters:"</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            box-&gt;addWidget(label);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">            input = </span><span class="hljs-keyword">new</span><span class="hljs-normal"> <a href="ffw_GuiTextInput.html">ffw::GuiTextInput</a>(&amp;gui, </span><span class="hljs-keyword">false</span><span class="hljs-normal">, </span><span class="hljs-keyword">true</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            input-&gt;setValue(L</span><span class="hljs-string">"Hello World"</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            </span><span class="hljs-comment">// Any capital or lowercase character including digit and whitespace</span><span class="hljs-normal"></span>
<span class="hljs-normal">            input-&gt;setMatch(L</span><span class="hljs-string">"[A-Z|a-z|0-9|\\s]*"</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            box-&gt;addWidget(input);</span>
<span class="hljs-normal">        &#125;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">        </span><span class="hljs-comment">// Text Input Multiline</span><span class="hljs-normal"></span>
<span class="hljs-normal">        &#123;</span>
<span class="hljs-normal">            </span><span class="hljs-keyword">auto</span><span class="hljs-normal"> box = makeBox(&amp;gui, scroll-&gt;getInner(), </span><span class="hljs-string">"Multiline Text Input"</span><span class="hljs-normal">);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">            </span><span class="hljs-keyword">auto</span><span class="hljs-normal"> area = </span><span class="hljs-keyword">new</span><span class="hljs-normal"> <a href="ffw_GuiTextInput.html">ffw::GuiTextInput</a>(&amp;gui, </span><span class="hljs-keyword">true</span><span class="hljs-normal">, </span><span class="hljs-keyword">true</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            area-&gt;setValue(L</span><span class="hljs-string">"Lorem ipsum dolor sit amet, consectetur adipiscing elit.\nEtiam cursus odio ut dui malesuada imperdiet.\nNullam ac augue volutpat, aliquam ante sit amet, efficitur ipsum."</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            box-&gt;addWidget(area);</span>
<span class="hljs-normal">        &#125;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">        </span><span class="hljs-comment">// Text Area</span><span class="hljs-normal"></span>
<span class="hljs-normal">        &#123;</span>
<span class="hljs-normal">            </span><span class="hljs-keyword">auto</span><span class="hljs-normal"> box = makeBox(&amp;gui, scroll-&gt;getInner(), </span><span class="hljs-string">"Text Area"</span><span class="hljs-normal">);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">            </span><span class="hljs-keyword">auto</span><span class="hljs-normal"> area = </span><span class="hljs-keyword">new</span><span class="hljs-normal"> <a href="ffw_GuiTextArea.html">ffw::GuiTextArea</a>(&amp;gui, </span><span class="hljs-keyword">true</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            area-&gt;setSize(<a href="ffw.html#3107a022">ffw::guiPercent</a>(100), <a href="ffw.html#66baed55">ffw::guiPixels</a>(75));</span>
<span class="hljs-normal">            area-&gt;setValue(L</span><span class="hljs-string">"Lorem ipsum dolor sit amet, consectetur adipiscing elit.\nEtiam cursus odio ut dui malesuada imperdiet. "</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            box-&gt;addWidget(area);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">            area = </span><span class="hljs-keyword">new</span><span class="hljs-normal"> <a href="ffw_GuiTextArea.html">ffw::GuiTextArea</a>(&amp;gui, </span><span class="hljs-keyword">true</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            area-&gt;setSize(<a href="ffw.html#3107a022">ffw::guiPercent</a>(100), <a href="ffw.html#66baed55">ffw::guiPixels</a>(75));</span>
<span class="hljs-normal">            area-&gt;setDisabled(</span><span class="hljs-keyword">true</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            area-&gt;setValue(L</span><span class="hljs-string">"Lorem ipsum dolor sit amet, consectetur adipiscing elit.\nEtiam cursus odio ut dui malesuada imperdiet. "</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            box-&gt;addWidget(area);</span>
<span class="hljs-normal">        &#125;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">        </span><span class="hljs-comment">// List</span><span class="hljs-normal"></span>
<span class="hljs-normal">        &#123;</span>
<span class="hljs-normal">            </span><span class="hljs-keyword">auto</span><span class="hljs-normal"> box = makeBox(&amp;gui, scroll-&gt;getInner(), </span><span class="hljs-string">"List"</span><span class="hljs-normal">);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">            </span><span class="hljs-keyword">auto</span><span class="hljs-normal"> list = </span><span class="hljs-keyword">new</span><span class="hljs-normal"> <a href="ffw_GuiList.html">ffw::GuiList</a>(&amp;gui);</span>
<span class="hljs-normal">            list-&gt;setSize(<a href="ffw.html#3107a022">ffw::guiPercent</a>(100), <a href="ffw.html#66baed55">ffw::guiPixels</a>(75));</span>
<span class="hljs-normal">            list-&gt;addItem(</span><span class="hljs-string">"First"</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            </span><span class="hljs-keyword">auto</span><span class="hljs-normal"> item = list-&gt;addItem(</span><span class="hljs-string">"Second"</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            item-&gt;setDisabled(</span><span class="hljs-keyword">true</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            </span><span class="hljs-keyword">auto</span><span class="hljs-normal"> selected = list-&gt;addItem(</span><span class="hljs-string">"Third"</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            list-&gt;addItem(</span><span class="hljs-string">"Fourth"</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            list-&gt;addItem(</span><span class="hljs-string">"Fifth"</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            list-&gt;setSelected(selected);</span>
<span class="hljs-normal">            box-&gt;addWidget(list);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">            list = </span><span class="hljs-keyword">new</span><span class="hljs-normal"> <a href="ffw_GuiList.html">ffw::GuiList</a>(&amp;gui);</span>
<span class="hljs-normal">            list-&gt;setSize(<a href="ffw.html#3107a022">ffw::guiPercent</a>(100), <a href="ffw.html#66baed55">ffw::guiPixels</a>(75));</span>
<span class="hljs-normal">            list-&gt;addItem(</span><span class="hljs-string">"First"</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            list-&gt;addItem(</span><span class="hljs-string">"Second"</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            list-&gt;addItem(</span><span class="hljs-string">"Third"</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            list-&gt;addItem(</span><span class="hljs-string">"Fourth"</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            list-&gt;addItem(</span><span class="hljs-string">"Fifth"</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            list-&gt;setDisabled(</span><span class="hljs-keyword">true</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            box-&gt;addWidget(list);</span>
<span class="hljs-normal">        &#125;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">        </span><span class="hljs-comment">// Switch</span><span class="hljs-normal"></span>
<span class="hljs-normal">        &#123;</span>
<span class="hljs-normal">            </span><span class="hljs-keyword">auto</span><span class="hljs-normal"> box = makeBox(&amp;gui, scroll-&gt;getInner(), </span><span class="hljs-string">"Switch"</span><span class="hljs-normal">);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">            </span><span class="hljs-keyword">auto</span><span class="hljs-normal"> label = </span><span class="hljs-keyword">new</span><span class="hljs-normal"> <a href="ffw_GuiLabel.html">ffw::GuiLabel</a>(&amp;gui, </span><span class="hljs-string">"Normal:"</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            box-&gt;addWidget(label);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">            </span><span class="hljs-keyword">auto</span><span class="hljs-normal"> button = </span><span class="hljs-keyword">new</span><span class="hljs-normal"> <a href="ffw_GuiSwitch.html">ffw::GuiSwitch</a>(&amp;gui);</span>
<span class="hljs-normal">            box-&gt;addWidget(button);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">            label = </span><span class="hljs-keyword">new</span><span class="hljs-normal"> <a href="ffw_GuiLabel.html">ffw::GuiLabel</a>(&amp;gui, </span><span class="hljs-string">"Hover:"</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            box-&gt;addWidget(label);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">            button = </span><span class="hljs-keyword">new</span><span class="hljs-normal"> <a href="ffw_GuiSwitch.html">ffw::GuiSwitch</a>(&amp;gui);</span>
<span class="hljs-normal">            button-&gt;setHover(</span><span class="hljs-keyword">true</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            button-&gt;setIgnoreUserInput(</span><span class="hljs-keyword">true</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            box-&gt;addWidget(button);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">            label = </span><span class="hljs-keyword">new</span><span class="hljs-normal"> <a href="ffw_GuiLabel.html">ffw::GuiLabel</a>(&amp;gui, </span><span class="hljs-string">"Focus:"</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            box-&gt;addWidget(label);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">            button = </span><span class="hljs-keyword">new</span><span class="hljs-normal"> <a href="ffw_GuiSwitch.html">ffw::GuiSwitch</a>(&amp;gui);</span>
<span class="hljs-normal">            button-&gt;setFocus(</span><span class="hljs-keyword">true</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            button-&gt;setIgnoreUserInput(</span><span class="hljs-keyword">true</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            box-&gt;addWidget(button);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">            label = </span><span class="hljs-keyword">new</span><span class="hljs-normal"> <a href="ffw_GuiLabel.html">ffw::GuiLabel</a>(&amp;gui, </span><span class="hljs-string">"Disabled:"</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            box-&gt;addWidget(label);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">            button = </span><span class="hljs-keyword">new</span><span class="hljs-normal"> <a href="ffw_GuiSwitch.html">ffw::GuiSwitch</a>(&amp;gui);</span>
<span class="hljs-normal">            button-&gt;setDisabled(</span><span class="hljs-keyword">true</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            box-&gt;addWidget(button);</span>
<span class="hljs-normal">        &#125;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">        </span><span class="hljs-comment">// Progress bar</span><span class="hljs-normal"></span>
<span class="hljs-normal">        &#123;</span>
<span class="hljs-normal">            </span><span class="hljs-keyword">auto</span><span class="hljs-normal"> box = makeBox(&amp;gui, scroll-&gt;getInner(), </span><span class="hljs-string">"Progress Bar"</span><span class="hljs-normal">);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">            </span><span class="hljs-keyword">auto</span><span class="hljs-normal"> label = </span><span class="hljs-keyword">new</span><span class="hljs-normal"> <a href="ffw_GuiLabel.html">ffw::GuiLabel</a>(&amp;gui, </span><span class="hljs-string">"Normal 0%:"</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            box-&gt;addWidget(label);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">            </span><span class="hljs-keyword">auto</span><span class="hljs-normal"> progress = </span><span class="hljs-keyword">new</span><span class="hljs-normal"> <a href="ffw_GuiProgressBar.html">ffw::GuiProgressBar</a>(&amp;gui);</span>
<span class="hljs-normal">            progress-&gt;setValue(0);</span>
<span class="hljs-normal">            box-&gt;addWidget(progress);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">            label = </span><span class="hljs-keyword">new</span><span class="hljs-normal"> <a href="ffw_GuiLabel.html">ffw::GuiLabel</a>(&amp;gui, </span><span class="hljs-string">"Normal 50%:"</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            box-&gt;addWidget(label);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">            progress = </span><span class="hljs-keyword">new</span><span class="hljs-normal"> <a href="ffw_GuiProgressBar.html">ffw::GuiProgressBar</a>(&amp;gui);</span>
<span class="hljs-normal">            progress-&gt;setValue(50);</span>
<span class="hljs-normal">            box-&gt;addWidget(progress);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">            label = </span><span class="hljs-keyword">new</span><span class="hljs-normal"> <a href="ffw_GuiLabel.html">ffw::GuiLabel</a>(&amp;gui, </span><span class="hljs-string">"Normal 100%:"</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            box-&gt;addWidget(label);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">            progress = </span><span class="hljs-keyword">new</span><span class="hljs-normal"> <a href="ffw_GuiProgressBar.html">ffw::GuiProgressBar</a>(&amp;gui);</span>
<span class="hljs-normal">            progress-&gt;setValue(75);</span>
<span class="hljs-normal">            box-&gt;addWidget(progress);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">            label = </span><span class="hljs-keyword">new</span><span class="hljs-normal"> <a href="ffw_GuiLabel.html">ffw::GuiLabel</a>(&amp;gui, </span><span class="hljs-string">"Disabled 50%:"</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            box-&gt;addWidget(label);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">            progress = </span><span class="hljs-keyword">new</span><span class="hljs-normal"> <a href="ffw_GuiProgressBar.html">ffw::GuiProgressBar</a>(&amp;gui);</span>
<span class="hljs-normal">            progress-&gt;setValue(50);</span>
<span class="hljs-normal">            progress-&gt;setDisabled(</span><span class="hljs-keyword">true</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            box-&gt;addWidget(progress);</span>
<span class="hljs-normal">        &#125;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">        </span><span class="hljs-comment">// Progress circle</span><span class="hljs-normal"></span>
<span class="hljs-normal">        &#123;</span>
<span class="hljs-normal">            </span><span class="hljs-keyword">auto</span><span class="hljs-normal"> box = makeBox(&amp;gui, scroll-&gt;getInner(), </span><span class="hljs-string">"Progress Circle"</span><span class="hljs-normal">);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">            </span><span class="hljs-keyword">auto</span><span class="hljs-normal"> label = </span><span class="hljs-keyword">new</span><span class="hljs-normal"> <a href="ffw_GuiLabel.html">ffw::GuiLabel</a>(&amp;gui, </span><span class="hljs-string">"Normal 75%:"</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            box-&gt;addWidget(label);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">            </span><span class="hljs-keyword">auto</span><span class="hljs-normal"> progress = </span><span class="hljs-keyword">new</span><span class="hljs-normal"> <a href="ffw_GuiProgressCircle.html">ffw::GuiProgressCircle</a>(&amp;gui);</span>
<span class="hljs-normal">            progress-&gt;setValue(75);</span>
<span class="hljs-normal">            box-&gt;addWidget(progress);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">            label = </span><span class="hljs-keyword">new</span><span class="hljs-normal"> <a href="ffw_GuiLabel.html">ffw::GuiLabel</a>(&amp;gui, </span><span class="hljs-string">"Disabled 33%:"</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            box-&gt;addWidget(label);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">            progress = </span><span class="hljs-keyword">new</span><span class="hljs-normal"> <a href="ffw_GuiProgressCircle.html">ffw::GuiProgressCircle</a>(&amp;gui);</span>
<span class="hljs-normal">            progress-&gt;setValue(33);</span>
<span class="hljs-normal">            progress-&gt;setDisabled(</span><span class="hljs-keyword">true</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            box-&gt;addWidget(progress);</span>
<span class="hljs-normal">        &#125;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">        </span><span class="hljs-comment">// Scrollable</span><span class="hljs-normal"></span>
<span class="hljs-normal">        &#123;</span>
<span class="hljs-normal">            </span><span class="hljs-keyword">auto</span><span class="hljs-normal"> box = makeBox(&amp;gui, scroll-&gt;getInner(), </span><span class="hljs-string">"Scrollable"</span><span class="hljs-normal">);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">            </span><span class="hljs-keyword">auto</span><span class="hljs-normal"> scrollable = </span><span class="hljs-keyword">new</span><span class="hljs-normal"> <a href="ffw_GuiScrollableLayout.html">ffw::GuiScrollableLayout</a>(&amp;gui, <a href="ffw_GuiWidget_Orientation.html#dd2779dc">ffw::GuiLayout::Orientation::VERTICAL</a>, </span><span class="hljs-keyword">true</span><span class="hljs-normal">, </span><span class="hljs-keyword">true</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            box-&gt;addWidget(scrollable);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">            </span><span class="hljs-keyword">for</span><span class="hljs-normal"> (</span><span class="hljs-title">int</span><span class="hljs-normal"> i = 0; i &lt; 8; i++) &#123;</span>
<span class="hljs-normal">                </span><span class="hljs-keyword">auto</span><span class="hljs-normal"> button = </span><span class="hljs-keyword">new</span><span class="hljs-normal"> <a href="ffw_GuiButton.html">ffw::GuiButton</a>(&amp;gui, </span><span class="hljs-string">"Button"</span><span class="hljs-normal">);</span>
<span class="hljs-normal">                scrollable-&gt;getInner()-&gt;addWidget(button);</span>
<span class="hljs-normal">            &#125;</span>
<span class="hljs-normal">        &#125;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">        </span><span class="hljs-comment">// Tabs</span><span class="hljs-normal"></span>
<span class="hljs-normal">        &#123;</span>
<span class="hljs-normal">            </span><span class="hljs-keyword">auto</span><span class="hljs-normal"> box = makeBox(&amp;gui, scroll-&gt;getInner(), </span><span class="hljs-string">"Tabs"</span><span class="hljs-normal">);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">            </span><span class="hljs-keyword">auto</span><span class="hljs-normal"> tabs = </span><span class="hljs-keyword">new</span><span class="hljs-normal"> <a href="ffw_GuiTabs.html">ffw::GuiTabs</a>(&amp;gui);</span>
<span class="hljs-normal">            box-&gt;addWidget(tabs);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">            </span><span class="hljs-keyword">auto</span><span class="hljs-normal"> layout = </span><span class="hljs-keyword">new</span><span class="hljs-normal"> <a href="ffw_GuiVerticalLayout.html">ffw::GuiVerticalLayout</a>(&amp;gui);</span>
<span class="hljs-normal">            tabs-&gt;addTab(</span><span class="hljs-string">"First"</span><span class="hljs-normal">, layout);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">            layout-&gt;addWidget(</span><span class="hljs-keyword">new</span><span class="hljs-normal"> <a href="ffw_GuiLabel.html">ffw::GuiLabel</a>(&amp;gui, </span><span class="hljs-string">"This is the first tab."</span><span class="hljs-normal">));</span>
<span class="hljs-normal">            layout-&gt;addWidget(</span><span class="hljs-keyword">new</span><span class="hljs-normal"> <a href="ffw_GuiLabel.html">ffw::GuiLabel</a>(&amp;gui, </span><span class="hljs-string">"You can put any widget\nin here!\n\nWorks like a charm!"</span><span class="hljs-normal">));</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">            layout = </span><span class="hljs-keyword">new</span><span class="hljs-normal"> <a href="ffw_GuiVerticalLayout.html">ffw::GuiVerticalLayout</a>(&amp;gui);</span>
<span class="hljs-normal">            tabs-&gt;addTab(</span><span class="hljs-string">"Second"</span><span class="hljs-normal">, layout);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">            layout-&gt;addWidget(</span><span class="hljs-keyword">new</span><span class="hljs-normal"> <a href="ffw_GuiLabel.html">ffw::GuiLabel</a>(&amp;gui, </span><span class="hljs-string">"This is the second tab."</span><span class="hljs-normal">));</span>
<span class="hljs-normal">            layout-&gt;addWidget(</span><span class="hljs-keyword">new</span><span class="hljs-normal"> <a href="ffw_GuiLabel.html">ffw::GuiLabel</a>(&amp;gui, </span><span class="hljs-string">"With some more text.\nWith some more text.\nWith some more text.\nWith some more text.\n"</span><span class="hljs-normal">));</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">            layout = </span><span class="hljs-keyword">new</span><span class="hljs-normal"> <a href="ffw_GuiVerticalLayout.html">ffw::GuiVerticalLayout</a>(&amp;gui);</span>
<span class="hljs-normal">            tabs-&gt;addTab(</span><span class="hljs-string">"Third"</span><span class="hljs-normal">, layout);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">            layout-&gt;addWidget(</span><span class="hljs-keyword">new</span><span class="hljs-normal"> <a href="ffw_GuiLabel.html">ffw::GuiLabel</a>(&amp;gui, </span><span class="hljs-string">"This is the last tab.\nWith extra button:"</span><span class="hljs-normal">));</span>
<span class="hljs-normal">            layout-&gt;addWidget(</span><span class="hljs-keyword">new</span><span class="hljs-normal"> <a href="ffw_GuiButton.html">ffw::GuiButton</a>(&amp;gui, </span><span class="hljs-string">"button"</span><span class="hljs-normal">));</span>
<span class="hljs-normal">        &#125;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">        </span><span class="hljs-comment">// Rich Text</span><span class="hljs-normal"></span>
<span class="hljs-normal">        &#123;</span>
<span class="hljs-normal">            </span><span class="hljs-keyword">auto</span><span class="hljs-normal"> box = makeBox(&amp;gui, scroll-&gt;getInner(), </span><span class="hljs-string">"Rich Text"</span><span class="hljs-normal">);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">            </span><span class="hljs-keyword">auto</span><span class="hljs-normal"> richText = </span><span class="hljs-keyword">new</span><span class="hljs-normal"> <a href="ffw_GuiRichText.html">ffw::GuiRichText</a>(&amp;gui);</span>
<span class="hljs-normal">            box-&gt;addWidget(richText);</span>
<span class="hljs-normal">            </span>
<span class="hljs-normal">            richText-&gt;addParagraph();</span>
<span class="hljs-normal">            richText-&gt;addSectionDefault();</span>
<span class="hljs-normal">            richText-&gt;addText(L</span><span class="hljs-string">"This is a rich text widget which can have "</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            richText-&gt;addSection(<a href="ffw.html#e71e7885">ffw::rgb</a>(0xFF0000), NULL);</span>
<span class="hljs-normal">            richText-&gt;addText(L</span><span class="hljs-string">"different "</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            richText-&gt;addSection(<a href="ffw.html#e71e7885">ffw::rgb</a>(0x0000FF), NULL);</span>
<span class="hljs-normal">            richText-&gt;addText(L</span><span class="hljs-string">"colors "</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            richText-&gt;addSectionDefault();</span>
<span class="hljs-normal">            richText-&gt;addText(L</span><span class="hljs-string">"and wraps based on whitespace!"</span><span class="hljs-normal">);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">            richText-&gt;addParagraph();</span>
<span class="hljs-normal">            richText-&gt;addSectionDefault();</span>
<span class="hljs-normal">            richText-&gt;addText(L</span><span class="hljs-string">"And even can have "</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            richText-&gt;addSection(&amp;fontBold);</span>
<span class="hljs-normal">            richText-&gt;addText(L</span><span class="hljs-string">"different fonts "</span><span class="hljs-normal">);</span>
<span class="hljs-normal">            richText-&gt;addSection(<a href="ffw.html#e71e7885">ffw::rgb</a>(0x007F00), &amp;fontItalic);</span>
<span class="hljs-normal">            richText-&gt;addText(L</span><span class="hljs-string">"or even with colors!"</span><span class="hljs-normal">);</span>
<span class="hljs-normal">        &#125;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">        </span><span class="hljs-keyword">return</span><span class="hljs-normal"> </span><span class="hljs-keyword">true</span><span class="hljs-normal">;</span>
<span class="hljs-normal">    &#125;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">    </span><span class="hljs-title">void</span><span class="hljs-normal"> <a href="ffw_GLFWRenderWindow.html#93db1d16">render</a>()</span><span class="hljs-keyword"> override </span><span class="hljs-normal">&#123;</span>
<span class="hljs-normal">        gui.update();</span>
<span class="hljs-normal">        gui.poolEvents();</span>
<span class="hljs-normal">        gui.render();</span>
<span class="hljs-normal">        </span><span class="hljs-comment">// Uncomment this to see what's being updated</span><span class="hljs-normal"></span>
<span class="hljs-normal">        </span><span class="hljs-comment">// and what isn't</span><span class="hljs-normal"></span>
<span class="hljs-normal">        </span><span class="hljs-comment">// this-&gt;setDrawColor(ffw::rgba(0x00000001));</span><span class="hljs-normal"></span>
<span class="hljs-normal">        </span><span class="hljs-comment">// this-&gt;drawRectangle(0, 0, getSize().x, getSize().y);</span><span class="hljs-normal"></span>
<span class="hljs-normal">    &#125;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">    </span><span class="hljs-title">void</span><span class="hljs-normal"> <a href="ffw_GLFWRenderWindow.html#eb5dbf50">close</a>()</span><span class="hljs-keyword"> override </span><span class="hljs-normal">&#123;</span>
<span class="hljs-normal">        gui.destroy();</span>
<span class="hljs-normal">        fontRegular.destroy();</span>
<span class="hljs-normal">        fontItalic.destroy();</span>
<span class="hljs-normal">        fontBold.destroy();</span>
<span class="hljs-normal">    &#125;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">    </span><span class="hljs-title">void</span><span class="hljs-normal"> <a href="ffw_GLFWRenderWindow.html#707e5f61">textInputEvent</a>(</span><span class="hljs-title">unsigned</span><span class="hljs-normal"> </span><span class="hljs-title">int</span><span class="hljs-normal"> c)</span><span class="hljs-keyword"> override </span><span class="hljs-normal">&#123;</span>
<span class="hljs-normal">        gui.injectText(c);</span>
<span class="hljs-normal">    &#125;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">    </span><span class="hljs-title">void</span><span class="hljs-normal"> <a href="ffw_GLFWRenderWindow.html#ce25f297">keyPressedEvent</a>(<a href="ffw.html#23661d50">ffw::Key</a> key, <a href="ffw.html#e03b52d5">ffw::Mode</a> mode)</span><span class="hljs-keyword"> override </span><span class="hljs-normal">&#123;</span>
<span class="hljs-normal">        gui.injectKey(key, mode);</span>
<span class="hljs-normal">    &#125;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">    </span><span class="hljs-title">void</span><span class="hljs-normal"> <a href="ffw_GLFWRenderWindow.html#eaa1a6c6">mouseMovedEvent</a>(</span><span class="hljs-title">int</span><span class="hljs-normal"> mousex, </span><span class="hljs-title">int</span><span class="hljs-normal"> mousey)</span><span class="hljs-keyword"> override </span><span class="hljs-normal">&#123;</span>
<span class="hljs-normal">        gui.injectMousePos(mousex, mousey);</span>
<span class="hljs-normal">    &#125;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">    </span><span class="hljs-title">void</span><span class="hljs-normal"> <a href="ffw_GLFWRenderWindow.html#fbe7329a">mouseScrollEvent</a>(</span><span class="hljs-title">int</span><span class="hljs-normal"> scroll)</span><span class="hljs-keyword"> override </span><span class="hljs-normal">&#123;</span>
<span class="hljs-normal">        gui.injectScroll(0, scroll);</span>
<span class="hljs-normal">    &#125;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">    </span><span class="hljs-title">void</span><span class="hljs-normal"> <a href="ffw_GLFWRenderWindow.html#1e8d2373">mouseButtonEvent</a>(<a href="ffw.html#f80e46cc">ffw::MouseButton</a> button, <a href="ffw.html#e03b52d5">ffw::Mode</a> mode)</span><span class="hljs-keyword"> override </span><span class="hljs-normal">&#123;</span>
<span class="hljs-normal">        gui.injectMouseButton(button, mode);</span>
<span class="hljs-normal">    &#125;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">    </span><span class="hljs-title">void</span><span class="hljs-normal"> <a href="ffw_GLFWRenderWindow.html#e4b39662">windowResizedEvent</a>(</span><span class="hljs-title">int</span><span class="hljs-normal"> width, </span><span class="hljs-title">int</span><span class="hljs-normal"> height)</span><span class="hljs-keyword"> override </span><span class="hljs-normal">&#123;</span>
<span class="hljs-normal">        gui.setSize(width, height);</span>
<span class="hljs-normal">        gui.redraw();</span>
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
<span class="hljs-normal"></span>
<span class="hljs-normal"></span><span class="hljs-keyword">private</span><span class="hljs-normal">:</span>
<span class="hljs-normal">    <a href="ffw_GuiWindowOpenGL.html">ffw::GuiWindowOpenGL</a> gui;</span>
<span class="hljs-normal">    <a href="ffw_GuiFontOpenGL.html">ffw::GuiFontOpenGL</a> fontRegular;</span>
<span class="hljs-normal">    <a href="ffw_GuiFontOpenGL.html">ffw::GuiFontOpenGL</a> fontItalic;</span>
<span class="hljs-normal">    <a href="ffw_GuiFontOpenGL.html">ffw::GuiFontOpenGL</a> fontBold;</span>
<span class="hljs-normal">    <a href="ffw_GuiStyleGroup.html">ffw::GuiStyleGroup</a> boxStyle;</span>
<span class="hljs-normal">    <a href="ffw_GuiImageOpenGL.html">ffw::GuiImageOpenGL</a> image;</span>
<span class="hljs-normal">&#125;;</span>
<span class="hljs-normal"></span>
<span class="hljs-title">int</span><span class="hljs-normal"> main(</span><span class="hljs-title">int</span><span class="hljs-normal"> argc, </span><span class="hljs-title">char</span><span class="hljs-normal"> *argv[])&#123;</span>
<span class="hljs-normal">    </span><span class="hljs-comment">// Instance to our app class</span><span class="hljs-normal"></span>
<span class="hljs-normal">    App app;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">    </span><span class="hljs-comment">// set arguments</span><span class="hljs-normal"></span>
<span class="hljs-normal">    <a href="ffw_GLFWRenderWindowArgs.html">ffw::GLFWRenderWindowArgs</a> args;</span>
<span class="hljs-normal">    args.<a href="ffw_GLFWRenderWindowArgs.html#427706b8">size</a>.<a href="ffw_Vec2.html#e49a9b9e">set</a>(600, 600);</span>
<span class="hljs-normal">    args.<a href="ffw_GLFWRenderWindowArgs.html#b1b7d616">title</a> = </span><span class="hljs-string">"Example GUI With OpenGL"</span><span class="hljs-normal">;</span>
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
<span class="hljs-normal">        </span><span class="hljs-comment">//std::this_thread::sleep_for(std::chrono::milliseconds(10));</span><span class="hljs-normal"></span>
<span class="hljs-normal">    &#125;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">    </span><span class="hljs-comment">// destroy window, this will delete all graphics data used by the window.</span><span class="hljs-normal"></span>
<span class="hljs-normal">    </span><span class="hljs-comment">// Must be called after the setup and before the graphics</span><span class="hljs-normal"></span>
<span class="hljs-normal">    </span><span class="hljs-comment">// is terminated</span><span class="hljs-normal"></span>
<span class="hljs-normal">    app.destroy();</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">    </span><span class="hljs-comment">// Needs to be called at the end of the program if ffw::initGraphics() succeeds</span><span class="hljs-normal"></span>
<span class="hljs-normal">    system(</span><span class="hljs-string">"pause"</span><span class="hljs-normal">);</span>
<span class="hljs-normal">    </span><span class="hljs-keyword">return</span><span class="hljs-normal"> 0;</span>
<span class="hljs-normal">&#125;</span>
</div></pre>

 

