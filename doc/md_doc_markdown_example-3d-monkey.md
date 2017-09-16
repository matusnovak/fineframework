Example: 3D Monkey
=================

![example-3d-monkey.jpg](example-3d-monkey.jpg)


The purpose of this example is to show how to load an obj model, texture, and a shader in order to render a 3D object using OpenGL.

**Requires finegraphics, finemedia, and finemath module to run**


<pre><div class="lang-cpp"><span class="hljs-meta-keyword">#include &lt;<a href="">ffw/graphics.h</a>&gt;</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span><span class="hljs-meta-keyword">#include &lt;<a href="">ffw/media.h</a>&gt;</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span><span class="hljs-meta-keyword">#include &lt;<a href="">ffw/math.h</a>&gt;</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span>
<span class="hljs-keyword">class </span><span class="hljs-normal">App: </span><span class="hljs-keyword">public</span><span class="hljs-normal"> <a href="ffw_GLFWRenderWindow.html">ffw::GLFWRenderWindow</a> &#123;</span>
<span class="hljs-normal"></span><span class="hljs-keyword">public</span><span class="hljs-normal">:</span>
<span class="hljs-normal">    App()&#123;</span>
<span class="hljs-normal">        mouseDown = </span><span class="hljs-keyword">false</span><span class="hljs-normal">;</span>
<span class="hljs-normal">    &#125;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">    ~App()&#123;</span>
<span class="hljs-normal">    &#125;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">    </span><span class="hljs-title">bool</span><span class="hljs-normal"> <a href="ffw_GLFWRenderWindow.html#68554ce1">setup</a>()</span><span class="hljs-keyword"> override </span><span class="hljs-normal">&#123;</span>
<span class="hljs-normal">        </span><span class="hljs-comment">// Check if graphics components are compatible with OpenGL</span><span class="hljs-normal"></span>
<span class="hljs-normal">        </span><span class="hljs-keyword">if</span><span class="hljs-normal">(!<a href="ffw_BufferObject.html#a098027f">ffw::Vbo::checkCompability</a>(</span><span class="hljs-keyword">this</span><span class="hljs-normal">))&#123;</span>
<span class="hljs-normal">            std::cerr &lt;&lt; </span><span class="hljs-string">"OpenGL used on this machine is too old! Vbo is not compatible!"</span><span class="hljs-normal"> &lt;&lt; std::endl; </span><span class="hljs-keyword">return</span><span class="hljs-normal"> </span><span class="hljs-keyword">false</span><span class="hljs-normal">;</span>
<span class="hljs-normal">        &#125;</span>
<span class="hljs-normal">        </span><span class="hljs-keyword">if</span><span class="hljs-normal">(!<a href="ffw_Shader.html#8e08f5b2">ffw::Shader::checkCompability</a>(</span><span class="hljs-keyword">this</span><span class="hljs-normal">))&#123;</span>
<span class="hljs-normal">            std::cerr &lt;&lt; </span><span class="hljs-string">"OpenGL used on this machine is too old! Shader is not compatible!"</span><span class="hljs-normal"> &lt;&lt; std::endl; </span><span class="hljs-keyword">return</span><span class="hljs-normal"> </span><span class="hljs-keyword">false</span><span class="hljs-normal">;</span>
<span class="hljs-normal">        &#125;</span>
<span class="hljs-normal">        </span><span class="hljs-keyword">if</span><span class="hljs-normal">(!<a href="ffw_Texture2D.html#e9dc30f1">ffw::Texture2D::checkCompability</a>(</span><span class="hljs-keyword">this</span><span class="hljs-normal">))&#123;</span>
<span class="hljs-normal">            std::cerr &lt;&lt; </span><span class="hljs-string">"OpenGL used on this machine is too old! Texture2D is not compatible!"</span><span class="hljs-normal"> &lt;&lt; std::endl; </span><span class="hljs-keyword">return</span><span class="hljs-normal"> </span><span class="hljs-keyword">false</span><span class="hljs-normal">;</span>
<span class="hljs-normal">        &#125;</span>
<span class="hljs-normal">        </span><span class="hljs-keyword">if</span><span class="hljs-normal">(!<a href="ffw_Font.html#2107f8ab">ffw::Font::checkCompability</a>(</span><span class="hljs-keyword">this</span><span class="hljs-normal">))&#123;</span>
<span class="hljs-normal">            std::cerr &lt;&lt; </span><span class="hljs-string">"OpenGL used on this machine is too old! Font is not compatible!"</span><span class="hljs-normal"> &lt;&lt; std::endl; </span><span class="hljs-keyword">return</span><span class="hljs-normal"> </span><span class="hljs-keyword">false</span><span class="hljs-normal">;</span>
<span class="hljs-normal">        &#125;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">        </span><span class="hljs-comment">// Start with mode: lightning</span><span class="hljs-normal"></span>
<span class="hljs-normal">        </span><span class="hljs-comment">// mode 2 = lightning</span><span class="hljs-normal"></span>
<span class="hljs-normal">        </span><span class="hljs-comment">// mode 1 = solid colors</span><span class="hljs-normal"></span>
<span class="hljs-normal">        </span><span class="hljs-comment">// mode 0 = normals</span><span class="hljs-normal"></span>
<span class="hljs-normal">        viewMode = 2;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">        </span><span class="hljs-comment">// Load font</span><span class="hljs-normal"></span>
<span class="hljs-normal">        </span><span class="hljs-comment">// Default font included in FFW</span><span class="hljs-normal"></span>
<span class="hljs-normal">        </span><span class="hljs-keyword">if</span><span class="hljs-normal">(!font.createFromData(</span><span class="hljs-keyword">this</span><span class="hljs-normal">, <a href="ffw.html#2012b23d">ffw::defaultFont</a>, <a href="ffw.html#384c1040">ffw::defaultFontSize</a>, 18, 72))&#123;</span>
<span class="hljs-normal">            std::cerr &lt;&lt; </span><span class="hljs-string">"Failed to create font!"</span><span class="hljs-normal"> &lt;&lt; std::endl;</span>
<span class="hljs-normal">            </span><span class="hljs-keyword">return</span><span class="hljs-normal"> </span><span class="hljs-keyword">false</span><span class="hljs-normal">;</span>
<span class="hljs-normal">        &#125;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">        </span><span class="hljs-comment">// Load shader</span><span class="hljs-normal"></span>
<span class="hljs-normal">        </span><span class="hljs-keyword">try</span><span class="hljs-normal"> &#123;</span>
<span class="hljs-normal">            shader.createFromFile(</span><span class="hljs-keyword">this</span><span class="hljs-normal">, </span><span class="hljs-string">""</span><span class="hljs-normal">, </span><span class="hljs-string">"monkeyshader.vert"</span><span class="hljs-normal">, </span><span class="hljs-string">"monkeyshader.frag"</span><span class="hljs-normal">);</span>
<span class="hljs-normal">        &#125; </span><span class="hljs-keyword">catch</span><span class="hljs-normal">(std::exception&amp; e)&#123;</span>
<span class="hljs-normal">            </span><span class="hljs-comment">// Error while loading shader</span><span class="hljs-normal"></span>
<span class="hljs-normal">            std::cerr &lt;&lt; </span><span class="hljs-string">"Failed to create shader!"</span><span class="hljs-normal"> &lt;&lt; std::endl &lt;&lt; e.what() &lt;&lt; std::endl;</span>
<span class="hljs-normal">            </span><span class="hljs-keyword">return</span><span class="hljs-normal"> </span><span class="hljs-keyword">false</span><span class="hljs-normal">;</span>
<span class="hljs-normal">        &#125;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">        </span><span class="hljs-comment">// Load texture</span><span class="hljs-normal"></span>
<span class="hljs-normal">        </span><span class="hljs-keyword">if</span><span class="hljs-normal">(!texture.createFromBuffer(</span><span class="hljs-keyword">this</span><span class="hljs-normal">, <a href="ffw.html#9f3c979a">ffw::readImage</a>(</span><span class="hljs-string">"uvgrid.png"</span><span class="hljs-normal">)))&#123;</span>
<span class="hljs-normal">            </span><span class="hljs-comment">// Error while loading shader</span><span class="hljs-normal"></span>
<span class="hljs-normal">            std::cerr &lt;&lt; </span><span class="hljs-string">"Failed to create texture from: uvgrid.bmp!"</span><span class="hljs-normal"> &lt;&lt; std::endl;</span>
<span class="hljs-normal">        &#125;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">        </span><span class="hljs-comment">// Load OBJ directly into VBO</span><span class="hljs-normal"></span>
<span class="hljs-normal">        </span><span class="hljs-keyword">if</span><span class="hljs-normal">(!<a href="ffw.html#d3cfdde0">ffw::readObj</a>(</span><span class="hljs-string">"monkey.obj"</span><span class="hljs-normal">, </span><span class="hljs-keyword">this</span><span class="hljs-normal">, &amp;vbo))&#123;</span>
<span class="hljs-normal">            std::cerr &lt;&lt; </span><span class="hljs-string">"Failed to load monkey.obj!"</span><span class="hljs-normal"> &lt;&lt; std::endl;</span>
<span class="hljs-normal">            </span><span class="hljs-keyword">return</span><span class="hljs-normal"> </span><span class="hljs-keyword">false</span><span class="hljs-normal">;</span>
<span class="hljs-normal">        &#125;</span>
<span class="hljs-normal">        </span>
<span class="hljs-normal">        eyesPos.set(0.0f, 0.0f, 1.5f);</span>
<span class="hljs-normal">        </span>
<span class="hljs-normal">        </span><span class="hljs-comment">// This is not the most efficient way to calculate </span><span class="hljs-normal"></span>
<span class="hljs-normal">        </span><span class="hljs-comment">// Model-View-Projection</span><span class="hljs-normal"></span>
<span class="hljs-normal">        </span><span class="hljs-comment">// We are doing it this way just for the purpose</span><span class="hljs-normal"></span>
<span class="hljs-normal">        </span><span class="hljs-comment">// of the example...</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span>
<span class="hljs-normal">        </span><span class="hljs-comment">// get the aspect ratio of the window</span><span class="hljs-normal"></span>
<span class="hljs-normal">        <a href="ffw_Vec2.html">ffw::Vec2i</a> windowSize = this-&gt;<a href="ffw_GLFWRenderWindow.html#70919473">getSize</a>();</span>
<span class="hljs-normal">        </span><span class="hljs-title">float</span><span class="hljs-normal"> aspectRatio = windowSize.<a href="ffw_Vec2.html#b2ccd122">x</a> / float(windowSize.<a href="ffw_Vec2.html#370d6d90">y</a>);</span>
<span class="hljs-normal">        </span><span class="hljs-comment">// create the projection matrix</span><span class="hljs-normal"></span>
<span class="hljs-normal">        </span><span class="hljs-comment">// 60 deg field of view</span><span class="hljs-normal"></span>
<span class="hljs-normal">        </span><span class="hljs-comment">// 0.1 near distance of frustum</span><span class="hljs-normal"></span>
<span class="hljs-normal">        </span><span class="hljs-comment">// 1000.0 far distance of frustum</span><span class="hljs-normal"></span>
<span class="hljs-normal">        projectionMatrix = <a href="ffw.html#c6652302">ffw::makeProjectionMatrix</a>(60.0f, aspectRatio, 0.05f, 1000.0f);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">        </span><span class="hljs-comment">// set the view matrix</span><span class="hljs-normal"></span>
<span class="hljs-normal">        </span><span class="hljs-comment">//viewMatrix = ffw::Mat4x4f(1.0f);</span><span class="hljs-normal"></span>
<span class="hljs-normal">        viewMatrix = <a href="ffw.html#c9109de4">ffw::makeLookAtMatrix</a>(eyesPos, <a href="ffw_Vec3.html">ffw::Vec3f</a>(0.0f, 0.0f, 0.0f), <a href="ffw_Vec3.html">ffw::Vec3f</a>(0.0f, 1.0f, 0.0f));</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">        </span><span class="hljs-comment">// set the model matrix</span><span class="hljs-normal"></span>
<span class="hljs-normal">        modelMatrix = <a href="ffw.html#029b468c">ffw::Mat4x4f</a>(1.0f);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">        glEnable(GL_BLEND);</span>
<span class="hljs-normal">        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">        </span><span class="hljs-keyword">return</span><span class="hljs-normal"> </span><span class="hljs-keyword">true</span><span class="hljs-normal">;</span>
<span class="hljs-normal">    &#125;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">    </span><span class="hljs-title">void</span><span class="hljs-normal"> <a href="ffw_GLFWRenderWindow.html#93db1d16">render</a>()</span><span class="hljs-keyword"> override </span><span class="hljs-normal">&#123;</span>
<span class="hljs-normal">        </span><span class="hljs-comment">// Blending is needed by the font</span><span class="hljs-normal"></span>
<span class="hljs-normal">        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);</span>
<span class="hljs-normal">        </span><span class="hljs-comment">// Enable depth test</span><span class="hljs-normal"></span>
<span class="hljs-normal">        glEnable(GL_DEPTH_TEST);</span>
<span class="hljs-normal">        </span><span class="hljs-comment">// Begin shader program</span><span class="hljs-normal"></span>
<span class="hljs-normal">        shader.bind();</span>
<span class="hljs-normal">        </span><span class="hljs-comment">// bind monkey object</span><span class="hljs-normal"></span>
<span class="hljs-normal">        vbo.bind();</span>
<span class="hljs-normal">        </span><span class="hljs-comment">// bind grid texture</span><span class="hljs-normal"></span>
<span class="hljs-normal">        texture.bind();</span>
<span class="hljs-normal">        </span><span class="hljs-comment">// set uniforms and attribute pointers</span><span class="hljs-normal"></span>
<span class="hljs-normal">        </span><span class="hljs-comment">// set the texture sampler to 0 (GL_TEXTURE0)</span><span class="hljs-normal"></span>
<span class="hljs-normal">        shader.setUniform1i(shader.getUniformLocation(</span><span class="hljs-string">"sampler"</span><span class="hljs-normal">), 0);</span>
<span class="hljs-normal">        </span><span class="hljs-comment">// set the position attribute to length 3 starting at position 0 in the vertex buffer</span><span class="hljs-normal"></span>
<span class="hljs-normal">        </span><span class="hljs-comment">// Each vertex has 8 floats total: &#123;Px, Py, Pz, Nx, Ny, Nz, U, V&#125;</span><span class="hljs-normal"></span>
<span class="hljs-normal">        </span><span class="hljs-comment">// Where P is position, N is normal and UV are texture coordinates</span><span class="hljs-normal"></span>
<span class="hljs-normal">        shader.setAttributePointerf(shader.getAttributeLocation(</span><span class="hljs-string">"position"</span><span class="hljs-normal">), 3, 8*</span><span class="hljs-keyword">sizeof</span><span class="hljs-normal">(float), (</span><span class="hljs-title">void</span><span class="hljs-normal">*)(0*</span><span class="hljs-keyword">sizeof</span><span class="hljs-normal">(float)));</span>
<span class="hljs-normal">        </span><span class="hljs-comment">// set the normal attribute to length 3 starting at position 3 in the vertex buffer</span><span class="hljs-normal"></span>
<span class="hljs-normal">        shader.setAttributePointerf(shader.getAttributeLocation(</span><span class="hljs-string">"normals"</span><span class="hljs-normal">), 3, 8*</span><span class="hljs-keyword">sizeof</span><span class="hljs-normal">(float), (</span><span class="hljs-title">void</span><span class="hljs-normal">*)(3*</span><span class="hljs-keyword">sizeof</span><span class="hljs-normal">(float)));</span>
<span class="hljs-normal">        </span><span class="hljs-comment">// set the texture coordinates attribute to length 2 starting at position 6 in the vertex buffer</span><span class="hljs-normal"></span>
<span class="hljs-normal">        shader.setAttributePointerf(shader.getAttributeLocation(</span><span class="hljs-string">"texCoords"</span><span class="hljs-normal">), 2, 8*</span><span class="hljs-keyword">sizeof</span><span class="hljs-normal">(float), (</span><span class="hljs-title">void</span><span class="hljs-normal">*)(6*</span><span class="hljs-keyword">sizeof</span><span class="hljs-normal">(float)));</span>
<span class="hljs-normal">        </span><span class="hljs-comment">// set the model, view and projection matrices</span><span class="hljs-normal"></span>
<span class="hljs-normal">        shader.setUniformMatrix4fv(shader.getUniformLocation(</span><span class="hljs-string">"model"</span><span class="hljs-normal">), &amp;modelMatrix[0], 1);</span>
<span class="hljs-normal">        shader.setUniformMatrix4fv(shader.getUniformLocation(</span><span class="hljs-string">"view"</span><span class="hljs-normal">), &amp;viewMatrix[0], 1);</span>
<span class="hljs-normal">        shader.setUniformMatrix4fv(shader.getUniformLocation(</span><span class="hljs-string">"projection"</span><span class="hljs-normal">), &amp;projectionMatrix[0], 1);</span>
<span class="hljs-normal">        </span><span class="hljs-comment">// set integer uniform mode</span><span class="hljs-normal"></span>
<span class="hljs-normal">        </span><span class="hljs-comment">// Used to switch between the normal color, solid color, or lightning</span><span class="hljs-normal"></span>
<span class="hljs-normal">        shader.setUniform1i(shader.getUniformLocation(</span><span class="hljs-string">"mode"</span><span class="hljs-normal">), viewMode);</span>
<span class="hljs-normal">        </span><span class="hljs-comment">// draw whole object</span><span class="hljs-normal"></span>
<span class="hljs-normal">        shader.drawArrays(GL_TRIANGLES, 0, vbo.getSize()/24);</span>
<span class="hljs-normal">        </span><span class="hljs-comment">// Stop object shader</span><span class="hljs-normal"></span>
<span class="hljs-normal">        shader.unbind();</span>
<span class="hljs-normal">        vbo.unbind();</span>
<span class="hljs-normal">        </span><span class="hljs-comment">// Disable depth test</span><span class="hljs-normal"></span>
<span class="hljs-normal">        </span><span class="hljs-comment">// Depth test needs to be disabled in order to</span><span class="hljs-normal"></span>
<span class="hljs-normal">        </span><span class="hljs-comment">// draw user interface or any other 2D graphics components</span><span class="hljs-normal"></span>
<span class="hljs-normal">        glDisable(GL_DEPTH_TEST);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">        </span><span class="hljs-comment">// draw debug information</span><span class="hljs-normal"></span>
<span class="hljs-normal">        this-&gt;<a href="ffw_RenderContext.html#6b8df6af">setDrawColor</a>(<a href="ffw.html#e71e7885">ffw::rgb</a>(0xFFFFFF));</span>
<span class="hljs-normal">        this-&gt;<a href="ffw_RenderContext.html#a583cfdb">drawString</a>(10, 10, &amp;font, </span><span class="hljs-string">"Keyboard shortcuts:\n'Q' - Normals\n'W' - Albedo\n'E' - Lightning"</span><span class="hljs-normal">);</span>
<span class="hljs-normal">    &#125;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">    </span><span class="hljs-title">void</span><span class="hljs-normal"> <a href="ffw_GLFWRenderWindow.html#eb5dbf50">close</a>()</span><span class="hljs-keyword"> override </span><span class="hljs-normal">&#123;</span>
<span class="hljs-normal">        font.destroy();</span>
<span class="hljs-normal">        texture.destroy();</span>
<span class="hljs-normal">        shader.destroy();</span>
<span class="hljs-normal">        vbo.destroy();</span>
<span class="hljs-normal">    &#125;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">    </span><span class="hljs-title">void</span><span class="hljs-normal"> <a href="ffw_GLFWRenderWindow.html#707e5f61">textInputEvent</a>(</span><span class="hljs-title">unsigned</span><span class="hljs-normal"> </span><span class="hljs-title">int</span><span class="hljs-normal"> c)</span><span class="hljs-keyword"> override </span><span class="hljs-normal">&#123;</span>
<span class="hljs-normal">    &#125;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">    </span><span class="hljs-title">void</span><span class="hljs-normal"> <a href="ffw_GLFWRenderWindow.html#ce25f297">keyPressedEvent</a>(<a href="ffw.html#23661d50">ffw::Key</a> key, <a href="ffw.html#e03b52d5">ffw::Mode</a> mode)</span><span class="hljs-keyword"> override </span><span class="hljs-normal">&#123;</span>
<span class="hljs-normal">        </span><span class="hljs-keyword">if</span><span class="hljs-normal">(mode == <a href="ffw_Mode.html#0d56c1de">ffw::Mode::PRESSED</a>)&#123;</span>
<span class="hljs-normal">            </span><span class="hljs-keyword">switch</span><span class="hljs-normal">(key)&#123;</span>
<span class="hljs-normal">                </span><span class="hljs-keyword">case</span><span class="hljs-normal"> <a href="ffw_Key.html#126e2c77">ffw::Key::LETTER_Q</a>: viewMode = 0; </span><span class="hljs-keyword">break</span><span class="hljs-normal">;</span>
<span class="hljs-normal">                </span><span class="hljs-keyword">case</span><span class="hljs-normal"> <a href="ffw_Key.html#a31a1bfb">ffw::Key::LETTER_W</a>: viewMode = 1; </span><span class="hljs-keyword">break</span><span class="hljs-normal">;</span>
<span class="hljs-normal">                </span><span class="hljs-keyword">case</span><span class="hljs-normal"> <a href="ffw_Key.html#af95b83b">ffw::Key::LETTER_E</a>: viewMode = 2; </span><span class="hljs-keyword">break</span><span class="hljs-normal">;</span>
<span class="hljs-normal">                </span><span class="hljs-keyword">default</span><span class="hljs-normal">: </span><span class="hljs-keyword">break</span><span class="hljs-normal">;</span>
<span class="hljs-normal">            &#125;;</span>
<span class="hljs-normal">        &#125;</span>
<span class="hljs-normal">    &#125;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">    </span><span class="hljs-title">void</span><span class="hljs-normal"> <a href="ffw_GLFWRenderWindow.html#eaa1a6c6">mouseMovedEvent</a>(</span><span class="hljs-title">int</span><span class="hljs-normal"> mousex, </span><span class="hljs-title">int</span><span class="hljs-normal"> mousey)</span><span class="hljs-keyword"> override </span><span class="hljs-normal">&#123;</span>
<span class="hljs-normal">        </span><span class="hljs-keyword">if</span><span class="hljs-normal">(mouseDown)&#123;</span>
<span class="hljs-normal">            </span><span class="hljs-title">int</span><span class="hljs-normal"> diff = mousex - oldmousex;</span>
<span class="hljs-normal">            oldmousex = mousex;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">            eyesPos = eyesPos.rotateY(-diff);</span>
<span class="hljs-normal">            viewMatrix = <a href="ffw.html#c9109de4">ffw::makeLookAtMatrix</a>(eyesPos, <a href="ffw_Vec3.html">ffw::Vec3f</a>(0.0f, 0.0f, 0.0f), <a href="ffw_Vec3.html">ffw::Vec3f</a>(0.0f, 1.0f, 0.0f));</span>
<span class="hljs-normal">        &#125; </span><span class="hljs-keyword">else</span><span class="hljs-normal"> &#123;</span>
<span class="hljs-normal">            oldmousex = mousex;</span>
<span class="hljs-normal">        &#125;</span>
<span class="hljs-normal">    &#125;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">    </span><span class="hljs-title">void</span><span class="hljs-normal"> <a href="ffw_GLFWRenderWindow.html#fbe7329a">mouseScrollEvent</a>(</span><span class="hljs-title">int</span><span class="hljs-normal"> scroll)</span><span class="hljs-keyword"> override </span><span class="hljs-normal">&#123;</span>
<span class="hljs-normal">    &#125;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">    </span><span class="hljs-title">void</span><span class="hljs-normal"> <a href="ffw_GLFWRenderWindow.html#1e8d2373">mouseButtonEvent</a>(<a href="ffw.html#f80e46cc">ffw::MouseButton</a> button, <a href="ffw.html#e03b52d5">ffw::Mode</a> mode)</span><span class="hljs-keyword"> override </span><span class="hljs-normal">&#123;</span>
<span class="hljs-normal">    &#125;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">    </span><span class="hljs-title">void</span><span class="hljs-normal"> <a href="ffw_GLFWRenderWindow.html#e4b39662">windowResizedEvent</a>(</span><span class="hljs-title">int</span><span class="hljs-normal"> width, </span><span class="hljs-title">int</span><span class="hljs-normal"> height)</span><span class="hljs-keyword"> override </span><span class="hljs-normal">&#123;</span>
<span class="hljs-normal">        </span><span class="hljs-comment">// Get the aspect ratio of the window</span><span class="hljs-normal"></span>
<span class="hljs-normal">        </span><span class="hljs-title">float</span><span class="hljs-normal"> aspectRatio = width / float(height);</span>
<span class="hljs-normal">        </span><span class="hljs-comment">// create the projection matrix</span><span class="hljs-normal"></span>
<span class="hljs-normal">        </span><span class="hljs-comment">// 60 deg field of view</span><span class="hljs-normal"></span>
<span class="hljs-normal">        </span><span class="hljs-comment">// 0.1 near distance of frustum</span><span class="hljs-normal"></span>
<span class="hljs-normal">        </span><span class="hljs-comment">// 1000.0 far distance of frustum</span><span class="hljs-normal"></span>
<span class="hljs-normal">        projectionMatrix = <a href="ffw.html#c6652302">ffw::makeProjectionMatrix</a>(60.0f, aspectRatio, 0.05f, 1000.0f);</span>
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
<span class="hljs-normal">    </span><span class="hljs-comment">// Object vertex buffer</span><span class="hljs-normal"></span>
<span class="hljs-normal">    <a href="ffw_Vbo.html">ffw::Vbo</a> vbo;</span>
<span class="hljs-normal">    </span><span class="hljs-comment">// Object shader</span><span class="hljs-normal"></span>
<span class="hljs-normal">    <a href="ffw_Shader.html">ffw::Shader</a> shader;</span>
<span class="hljs-normal">    </span><span class="hljs-comment">// Grid texture</span><span class="hljs-normal"></span>
<span class="hljs-normal">    <a href="ffw_Texture2D.html">ffw::Texture2D</a> texture;</span>
<span class="hljs-normal">    </span><span class="hljs-comment">// Model, view and projection matrices used in shader</span><span class="hljs-normal"></span>
<span class="hljs-normal">    <a href="ffw_Mat4x4.html">ffw::Mat4x4f</a> projectionMatrix;</span>
<span class="hljs-normal">    <a href="ffw_Mat4x4.html">ffw::Mat4x4f</a> viewMatrix;</span>
<span class="hljs-normal">    <a href="ffw_Mat4x4.html">ffw::Mat4x4f</a> modelMatrix;</span>
<span class="hljs-normal">    </span><span class="hljs-comment">// Font</span><span class="hljs-normal"></span>
<span class="hljs-normal">    <a href="ffw_TrueTypeFont.html">ffw::TrueTypeFont</a> font;</span>
<span class="hljs-normal">    <a href="ffw_Vec3.html">ffw::Vec3f</a> eyesPos;</span>
<span class="hljs-normal">    </span><span class="hljs-title">bool</span><span class="hljs-normal"> mouseDown;</span>
<span class="hljs-normal">    </span><span class="hljs-title">int</span><span class="hljs-normal"> oldmousex;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">    </span><span class="hljs-title">int</span><span class="hljs-normal"> viewMode;</span>
<span class="hljs-normal">&#125;;</span>
<span class="hljs-normal"></span>
<span class="hljs-title">int</span><span class="hljs-normal"> main(</span><span class="hljs-title">int</span><span class="hljs-normal"> argc, </span><span class="hljs-title">char</span><span class="hljs-normal"> *argv[])&#123;</span>
<span class="hljs-normal">    </span><span class="hljs-comment">// Instance to our app class</span><span class="hljs-normal"></span>
<span class="hljs-normal">    App app;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">    </span><span class="hljs-comment">// set arguments</span><span class="hljs-normal"></span>
<span class="hljs-normal">    <a href="ffw_GLFWRenderWindowArgs.html">ffw::GLFWRenderWindowArgs</a> args;</span>
<span class="hljs-normal">    args.<a href="ffw_GLFWRenderWindowArgs.html#427706b8">size</a>.<a href="ffw_Vec2.html#e49a9b9e">set</a>(800, 400);</span>
<span class="hljs-normal">    args.<a href="ffw_GLFWRenderWindowArgs.html#b1b7d616">title</a> = </span><span class="hljs-string">"Example 3D Monkey"</span><span class="hljs-normal">;</span>
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
<span class="hljs-normal">        system(</span><span class="hljs-string">"pause"</span><span class="hljs-normal">);</span>
<span class="hljs-normal">        </span><span class="hljs-keyword">return</span><span class="hljs-normal"> 1;</span>
<span class="hljs-normal">    &#125;</span>
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
<span class="hljs-normal">    </span><span class="hljs-keyword">return</span><span class="hljs-normal"> 0;</span>
<span class="hljs-normal">&#125;</span>
</div></pre>

 

