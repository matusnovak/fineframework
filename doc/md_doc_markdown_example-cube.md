Example: Cube
=================

![example-cube.jpg](example-cube.jpg)


The purpose of this example is to show capability of rendering a very simple 3D object on the screen using OpenGL. The code shows how to easily create model view and projection matrices and some of the other vector operations.

**Requires finegraphics and finemath module to run**


<pre><div class="lang-cpp" style="white-space: nowrap;"><span class="hljs-meta-keyword">#include &lt;<a href="">ffw/graphics.h</a>&gt;</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span><span class="hljs-meta-keyword">#include &lt;<a href="">ffw/math.h</a>&gt;</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span>
<span class="hljs-normal"></span><span class="hljs-meta-keyword">#define EYES_DEFAULT_POS 1.7f, 1.7f, 1.7f</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span><span class="hljs-meta-keyword">#define STRINGIFY(x) #x</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span>
<span class="hljs-keyword">static</span><span class="hljs-normal"> </span><span class="hljs-keyword">const</span><span class="hljs-normal"> std::string vertexShaderCode = </span><span class="hljs-string">"#version 130\n"</span><span class="hljs-normal"> STRINGIFY(</span>
<span class="hljs-normal">in vec3 position;</span>
<span class="hljs-normal">in vec3 color;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">out vec3 out_color;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">uniform mat4 model;</span>
<span class="hljs-normal">uniform mat4 view;</span>
<span class="hljs-normal">uniform mat4 projection;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal"></span><span class="hljs-title">void</span><span class="hljs-normal"> main() &#123;</span>
<span class="hljs-normal">    out_color = color;</span>
<span class="hljs-normal">    gl_Position = projection * view * model * vec4(position, 1.0f);</span>
<span class="hljs-normal">&#125;</span>
<span class="hljs-normal">);</span>
<span class="hljs-normal"></span>
<span class="hljs-keyword">static</span><span class="hljs-normal"> </span><span class="hljs-keyword">const</span><span class="hljs-normal"> std::string fragmentShaderCode = </span><span class="hljs-string">"#version 130\n"</span><span class="hljs-normal"> STRINGIFY(</span>
<span class="hljs-normal">in vec3 out_color;</span>
<span class="hljs-normal"></span><span class="hljs-title">void</span><span class="hljs-normal"> main() &#123;</span>
<span class="hljs-normal">    gl_FragColor = vec4(out_color, 1.0f);</span>
<span class="hljs-normal">&#125;</span>
<span class="hljs-normal">);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal"></span><span class="hljs-keyword">static</span><span class="hljs-normal"> </span><span class="hljs-keyword">const</span><span class="hljs-normal"> </span><span class="hljs-title">float</span><span class="hljs-normal"> cubeVertices[] = &#123;</span>
<span class="hljs-normal">    -1.0f, -1.0f, -1.0f, 0.0f, 0.0f, 0.0f,</span>
<span class="hljs-normal">    -1.0f, -1.0f,  1.0f, 0.0f, 1.0f, 0.0f,</span>
<span class="hljs-normal">     1.0f, -1.0f,  1.0f, 0.0f, 1.0f, 1.0f,</span>
<span class="hljs-normal">     1.0f, -1.0f, -1.0f, 0.0f, 0.0f, 1.0f,</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">    -1.0f, -1.0f, -1.0f, 0.0f, 0.0f, 0.0f,</span>
<span class="hljs-normal">    -1.0f,  1.0f, -1.0f, 1.0f, 0.0f, 0.0f,</span>
<span class="hljs-normal">     1.0f,  1.0f, -1.0f, 1.0f, 0.0f, 1.0f,</span>
<span class="hljs-normal">     1.0f, -1.0f, -1.0f, 0.0f, 0.0f, 1.0f,</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">    -1.0f, -1.0f,  1.0f, 0.0f, 1.0f, 0.0f,</span>
<span class="hljs-normal">    -1.0f,  1.0f,  1.0f, 1.0f, 1.0f, 0.0f,</span>
<span class="hljs-normal">    -1.0f,  1.0f, -1.0f, 1.0f, 0.0f, 0.0f,</span>
<span class="hljs-normal">    -1.0f, -1.0f, -1.0f, 0.0f, 0.0f, 0.0f,</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">    -1.0f, -1.0f,  1.0f, 0.0f, 1.0f, 0.0f,</span>
<span class="hljs-normal">     1.0f, -1.0f,  1.0f, 0.0f, 1.0f, 1.0f,</span>
<span class="hljs-normal">     1.0f,  1.0f,  1.0f, 1.0f, 1.0f, 1.0f,</span>
<span class="hljs-normal">    -1.0f,  1.0f,  1.0f, 1.0f, 1.0f, 0.0f,</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">     1.0f, -1.0f,  1.0f, 0.0f, 1.0f, 1.0f,</span>
<span class="hljs-normal">     1.0f, -1.0f, -1.0f, 0.0f, 0.0f, 1.0f,</span>
<span class="hljs-normal">     1.0f,  1.0f, -1.0f, 1.0f, 0.0f, 1.0f,</span>
<span class="hljs-normal">     1.0f,  1.0f,  1.0f, 1.0f, 1.0f, 1.0f,</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">     1.0f,  1.0f, -1.0f, 1.0f, 0.0f, 1.0f,</span>
<span class="hljs-normal">     1.0f,  1.0f,  1.0f, 1.0f, 1.0f, 1.0f,</span>
<span class="hljs-normal">    -1.0f,  1.0f,  1.0f, 1.0f, 1.0f, 0.0f,</span>
<span class="hljs-normal">    -1.0f,  1.0f, -1.0f, 1.0f, 0.0f, 0.0f,</span>
<span class="hljs-normal">&#125;;</span>
<span class="hljs-normal"></span>
<span class="hljs-keyword">class </span><span class="hljs-normal">App : </span><span class="hljs-keyword">public</span><span class="hljs-normal"> <a href="ffw_GLFWRenderWindow.html">ffw::GLFWRenderWindow</a> &#123;</span>
<span class="hljs-normal"></span><span class="hljs-keyword">public</span><span class="hljs-normal">:</span>
<span class="hljs-normal">    App() &#123;</span>
<span class="hljs-normal">        mouseDown = </span><span class="hljs-keyword">false</span><span class="hljs-normal">;</span>
<span class="hljs-normal">        mouseOld = 0;</span>
<span class="hljs-normal">        eyesRot = 0;</span>
<span class="hljs-normal">    &#125;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">    ~App() &#123;</span>
<span class="hljs-normal">    &#125;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">    </span><span class="hljs-title">bool</span><span class="hljs-normal"> <a href="ffw_GLFWRenderWindow.html#68554ce1">setup</a>()</span><span class="hljs-keyword"> override </span><span class="hljs-normal">&#123;</span>
<span class="hljs-normal">        </span><span class="hljs-comment">// Check if graphics components are compatible with OpenGL</span><span class="hljs-normal"></span>
<span class="hljs-normal">        </span><span class="hljs-keyword">if</span><span class="hljs-normal"> (!<a href="ffw_BufferObject.html#a098027f">ffw::Vbo::checkCompability</a>(</span><span class="hljs-keyword">this</span><span class="hljs-normal">)) &#123;</span>
<span class="hljs-normal">            std::cerr &lt;&lt; </span><span class="hljs-string">"OpenGL used on this machine is too old! Vbo is not compatible!"</span><span class="hljs-normal"> &lt;&lt; std::endl; </span><span class="hljs-keyword">return</span><span class="hljs-normal"> </span><span class="hljs-keyword">false</span><span class="hljs-normal">;</span>
<span class="hljs-normal">        &#125;</span>
<span class="hljs-normal">        </span><span class="hljs-keyword">if</span><span class="hljs-normal"> (!<a href="ffw_Shader.html#8e08f5b2">ffw::Shader::checkCompability</a>(</span><span class="hljs-keyword">this</span><span class="hljs-normal">)) &#123;</span>
<span class="hljs-normal">            std::cerr &lt;&lt; </span><span class="hljs-string">"OpenGL used on this machine is too old! Shader is not compatible!"</span><span class="hljs-normal"> &lt;&lt; std::endl; </span><span class="hljs-keyword">return</span><span class="hljs-normal"> </span><span class="hljs-keyword">false</span><span class="hljs-normal">;</span>
<span class="hljs-normal">        &#125;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">        </span><span class="hljs-comment">// Load shader</span><span class="hljs-normal"></span>
<span class="hljs-normal">        </span><span class="hljs-keyword">try</span><span class="hljs-normal"> &#123;</span>
<span class="hljs-normal">            shader.createFromData(</span><span class="hljs-keyword">this</span><span class="hljs-normal">, </span><span class="hljs-string">""</span><span class="hljs-normal">, vertexShaderCode, fragmentShaderCode);</span>
<span class="hljs-normal">        &#125;</span>
<span class="hljs-normal">        </span><span class="hljs-keyword">catch</span><span class="hljs-normal"> (std::exception&amp; e) &#123;</span>
<span class="hljs-normal">            </span><span class="hljs-comment">// Error while loading shader</span><span class="hljs-normal"></span>
<span class="hljs-normal">            std::cerr &lt;&lt; </span><span class="hljs-string">"Failed to create shader!"</span><span class="hljs-normal"> &lt;&lt; std::endl &lt;&lt; e.what() &lt;&lt; std::endl;</span>
<span class="hljs-normal">            </span><span class="hljs-keyword">return</span><span class="hljs-normal"> </span><span class="hljs-keyword">false</span><span class="hljs-normal">;</span>
<span class="hljs-normal">        &#125;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">        vbo.create(</span><span class="hljs-keyword">this</span><span class="hljs-normal">, cubeVertices, </span><span class="hljs-keyword">sizeof</span><span class="hljs-normal">(cubeVertices), GL_STATIC_DRAW);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">        eyesPos.set(EYES_DEFAULT_POS);</span>
<span class="hljs-normal"></span>
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
<span class="hljs-normal">        glEnable(GL_DEPTH_TEST);</span>
<span class="hljs-normal">        glClearColor(0.3f, 0.3f, 0.3f, 1.0f);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">        </span><span class="hljs-keyword">return</span><span class="hljs-normal"> </span><span class="hljs-keyword">true</span><span class="hljs-normal">;</span>
<span class="hljs-normal">    &#125;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">    </span><span class="hljs-title">void</span><span class="hljs-normal"> <a href="ffw_GLFWRenderWindow.html#93db1d16">render</a>()</span><span class="hljs-keyword"> override </span><span class="hljs-normal">&#123;</span>
<span class="hljs-normal">        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);</span>
<span class="hljs-normal">        </span><span class="hljs-comment">// Begin shader program</span><span class="hljs-normal"></span>
<span class="hljs-normal">        shader.bind();</span>
<span class="hljs-normal">        </span><span class="hljs-comment">// bind cube object</span><span class="hljs-normal"></span>
<span class="hljs-normal">        vbo.bind();</span>
<span class="hljs-normal">        </span><span class="hljs-comment">// set uniforms and attribute pointers</span><span class="hljs-normal"></span>
<span class="hljs-normal">        </span><span class="hljs-comment">// set the position attribute to length 3 starting at position 0 in the vertex buffer</span><span class="hljs-normal"></span>
<span class="hljs-normal">        </span><span class="hljs-comment">// Each vertex has 8 floats total: &#123;Px, Py, Pz, Nx, Ny, Nz, U, V&#125;</span><span class="hljs-normal"></span>
<span class="hljs-normal">        </span><span class="hljs-comment">// Where P is position, N is normal and UV are texture coordinates</span><span class="hljs-normal"></span>
<span class="hljs-normal">        shader.setAttributePointerf(shader.getAttributeLocation(</span><span class="hljs-string">"position"</span><span class="hljs-normal">), 3, 6 * </span><span class="hljs-keyword">sizeof</span><span class="hljs-normal">(float), (</span><span class="hljs-title">void</span><span class="hljs-normal">*)(0 * </span><span class="hljs-keyword">sizeof</span><span class="hljs-normal">(float)));</span>
<span class="hljs-normal">        </span><span class="hljs-comment">// set the normal attribute to length 3 starting at position 3 in the vertex buffer</span><span class="hljs-normal"></span>
<span class="hljs-normal">        shader.setAttributePointerf(shader.getAttributeLocation(</span><span class="hljs-string">"color"</span><span class="hljs-normal">), 3, 6 * </span><span class="hljs-keyword">sizeof</span><span class="hljs-normal">(float), (</span><span class="hljs-title">void</span><span class="hljs-normal">*)(3 * </span><span class="hljs-keyword">sizeof</span><span class="hljs-normal">(float)));</span>
<span class="hljs-normal">        </span><span class="hljs-comment">// set the model, view and projection matrices</span><span class="hljs-normal"></span>
<span class="hljs-normal">        shader.setUniformMatrix4fv(shader.getUniformLocation(</span><span class="hljs-string">"model"</span><span class="hljs-normal">), &amp;modelMatrix[0], 1);</span>
<span class="hljs-normal">        shader.setUniformMatrix4fv(shader.getUniformLocation(</span><span class="hljs-string">"view"</span><span class="hljs-normal">), &amp;viewMatrix[0], 1);</span>
<span class="hljs-normal">        shader.setUniformMatrix4fv(shader.getUniformLocation(</span><span class="hljs-string">"projection"</span><span class="hljs-normal">), &amp;projectionMatrix[0], 1);</span>
<span class="hljs-normal">        </span><span class="hljs-comment">// draw whole object</span><span class="hljs-normal"></span>
<span class="hljs-normal">        shader.drawArrays(GL_QUADS, 0, vbo.getSize() / </span><span class="hljs-keyword">sizeof</span><span class="hljs-normal">(float) / 6); </span><span class="hljs-comment">// 6 floats per one vertex</span><span class="hljs-normal"></span>
<span class="hljs-normal">        </span><span class="hljs-comment">// Stop object shader</span><span class="hljs-normal"></span>
<span class="hljs-normal">        shader.unbind();</span>
<span class="hljs-normal">        vbo.unbind();</span>
<span class="hljs-normal">    &#125;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">    </span><span class="hljs-title">void</span><span class="hljs-normal"> <a href="ffw_GLFWRenderWindow.html#eb5dbf50">close</a>()</span><span class="hljs-keyword"> override </span><span class="hljs-normal">&#123;</span>
<span class="hljs-normal">        shader.destroy();</span>
<span class="hljs-normal">        vbo.destroy();</span>
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
<span class="hljs-normal">        </span><span class="hljs-keyword">if</span><span class="hljs-normal"> (mouseDown) &#123;</span>
<span class="hljs-normal">            </span><span class="hljs-title">int</span><span class="hljs-normal"> diffx = mousex - mouseOld.x;</span>
<span class="hljs-normal">            </span><span class="hljs-title">int</span><span class="hljs-normal"> diffy = mousey - mouseOld.y;</span>
<span class="hljs-normal">            mouseOld.x = mousex;</span>
<span class="hljs-normal">            mouseOld.y = mousey;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">            eyesRot.x += -diffx/2;</span>
<span class="hljs-normal">            eyesRot.y += -diffy/2;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">            eyesPos.set(EYES_DEFAULT_POS);</span>
<span class="hljs-normal">            eyesPos.rotateY(eyesRot.x);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">            </span><span class="hljs-comment">// get penpedicular vector</span><span class="hljs-normal"></span>
<span class="hljs-normal">            <a href="ffw_Vec3.html">ffw::Vec3f</a> axis((</span><span class="hljs-title">float</span><span class="hljs-normal">)eyesPos.z, 0.0f, (</span><span class="hljs-title">float</span><span class="hljs-normal">)-eyesPos.x);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">            axis.normalize();</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">            </span><span class="hljs-comment">//std::cout &lt;&lt; "axis: " &lt;&lt; axis &lt;&lt; std::endl;</span><span class="hljs-normal"></span>
<span class="hljs-normal">            eyesPos.rotateByAxis(eyesRot.y, axis);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">            viewMatrix = <a href="ffw.html#c9109de4">ffw::makeLookAtMatrix</a>(eyesPos, <a href="ffw_Vec3.html">ffw::Vec3f</a>(0.0f, 0.0f, 0.0f), <a href="ffw_Vec3.html">ffw::Vec3f</a>(0.0f, 1.0f, 0.0f));</span>
<span class="hljs-normal">        &#125;</span>
<span class="hljs-normal">        </span><span class="hljs-keyword">else</span><span class="hljs-normal"> &#123;</span>
<span class="hljs-normal">            mouseOld.x = mousex;</span>
<span class="hljs-normal">            mouseOld.y = mousey;</span>
<span class="hljs-normal">        &#125;</span>
<span class="hljs-normal">    &#125;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">    </span><span class="hljs-title">void</span><span class="hljs-normal"> <a href="ffw_GLFWRenderWindow.html#fbe7329a">mouseScrollEvent</a>(</span><span class="hljs-title">int</span><span class="hljs-normal"> scroll)</span><span class="hljs-keyword"> override </span><span class="hljs-normal">&#123;</span>
<span class="hljs-normal">    &#125;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">    </span><span class="hljs-title">void</span><span class="hljs-normal"> <a href="ffw_GLFWRenderWindow.html#1e8d2373">mouseButtonEvent</a>(<a href="ffw.html#f80e46cc">ffw::MouseButton</a> button, <a href="ffw.html#e03b52d5">ffw::Mode</a> mode)</span><span class="hljs-keyword"> override </span><span class="hljs-normal">&#123;</span>
<span class="hljs-normal">        </span><span class="hljs-keyword">if</span><span class="hljs-normal"> (mode == <a href="ffw_Mode.html#0d56c1de">ffw::Mode::PRESSED</a>)mouseDown = </span><span class="hljs-keyword">true</span><span class="hljs-normal">;</span>
<span class="hljs-normal">        </span><span class="hljs-keyword">else</span><span class="hljs-normal"> mouseDown = </span><span class="hljs-keyword">false</span><span class="hljs-normal">;</span>
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
<span class="hljs-normal"></span><span class="hljs-keyword">private</span><span class="hljs-normal">:</span>
<span class="hljs-normal">    <a href="ffw_Shader.html">ffw::Shader</a> shader;</span>
<span class="hljs-normal">    <a href="ffw_Vbo.html">ffw::Vbo</a> vbo;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">    </span><span class="hljs-comment">// Model, view and projection matrices used in shader</span><span class="hljs-normal"></span>
<span class="hljs-normal">    <a href="ffw_Mat4x4.html">ffw::Mat4x4f</a> projectionMatrix;</span>
<span class="hljs-normal">    <a href="ffw_Mat4x4.html">ffw::Mat4x4f</a> viewMatrix;</span>
<span class="hljs-normal">    <a href="ffw_Mat4x4.html">ffw::Mat4x4f</a> modelMatrix;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">    <a href="ffw_Vec3.html">ffw::Vec3f</a> eyesPos;</span>
<span class="hljs-normal">    </span><span class="hljs-title">bool</span><span class="hljs-normal"> mouseDown;</span>
<span class="hljs-normal">    <a href="ffw_Vec2.html">ffw::Vec2i</a> mouseOld;</span>
<span class="hljs-normal">    <a href="ffw_Vec2.html">ffw::Vec2f</a> eyesRot;</span>
<span class="hljs-normal">&#125;;</span>
<span class="hljs-normal"></span>
<span class="hljs-title">int</span><span class="hljs-normal"> main(</span><span class="hljs-title">int</span><span class="hljs-normal"> argc, </span><span class="hljs-title">char</span><span class="hljs-normal"> *argv[]) &#123;</span>
<span class="hljs-normal">    </span><span class="hljs-comment">// Instance to our app class</span><span class="hljs-normal"></span>
<span class="hljs-normal">    App app;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">    </span><span class="hljs-comment">// set arguments</span><span class="hljs-normal"></span>
<span class="hljs-normal">    <a href="ffw_GLFWRenderWindowArgs.html">ffw::GLFWRenderWindowArgs</a> args;</span>
<span class="hljs-normal">    args.<a href="ffw_GLFWRenderWindowArgs.html#427706b8">size</a>.<a href="ffw_Vec2.html#e49a9b9e">set</a>(800, 600);</span>
<span class="hljs-normal">    args.<a href="ffw_GLFWRenderWindowArgs.html#b1b7d616">title</a> = </span><span class="hljs-string">"Cube Example"</span><span class="hljs-normal">;</span>
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

 

