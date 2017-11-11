Vectors
=================

This tutorial will explain the basics hidden behind vectors. However, you are expected to know basics of linear algebra, such as vector addition.

There are four vector classes you can use: [ffw::Vec2](ffw_Vec2.html) [ffw::Vec3](ffw_Vec3.html) [ffw::Vec4](ffw_Vec4.html) and [ffw::Vec](ffw_Vec.html). All of these classes are templates and can hold any data type you choose to use. For example, if you want 3 component vector, for example to represent a position in 3D space, you might use **[ffw::Vec3](ffw_Vec3.html)<double>** or **[ffw::Vec3](ffw_Vec3.html)<float>**. For less typing, multiple typedefs are provided to you such as [ffw::Vec3d](ffw.html#4a8d738f) (double) [ffw::Vec3f](ffw.html#f1b9b946) (float) [ffw::Vec3i](ffw.html#1bc00754) (int), this also applies for 2D and 4D vectors: **[ffw::Vec2d](ffw.html#c75035bf), [ffw::Vec2f](ffw.html#fcfaa6c5), [ffw::Vec2i](ffw.html#e4e07ebe), [ffw::Vec4d](ffw.html#fcd214ba), [ffw::Vec4f](ffw.html#397c4d39), [ffw::Vec4i](ffw.html#fd5627df).**

The [ffw::Vec](ffw_Vec.html) (notice no number) is a special vector, as it can hold any number of components. Do you need 1000 component vector? No problem. The maximum number of components it can hold is the limit of std::size_t (or SIZE_MAX) which is more than plenty. Note that when declaring your massive vector, you have to provide data type (same as [ffw::Vec2](ffw_Vec2.html)<double> etc...) but also number of components. For example: **[ffw::Vec](ffw_Vec.html)<double, 1000>**

The **[ffw::Vec](ffw_Vec.html)<double, 1000>** does not have a constructor that acceps 1000 parameters. However, it acceps an initializer list, which is a curly bracket list such as: `[ffw::Vec](ffw_Vec.html)<double, 6> vec({1, 2, 3, 4, 5, 6})`. You can also use the [ ] operator to access individual elements: `vec[0] = 2.0; // 1st component is now 2.0`

_Please note, do not mistake `a * b` operation as a dot product! The asterisk will multiply all components in component wise order and return a new vector. To use dot use `ffw::dot(a, b)` instead._

#### The basic operations


Initializing vector can be done via the constructor, or via set() function. Note that the [ffw::Vec](ffw_Vec.html)<T, S> does not have a typical constructor!


<pre><div class="lang-cpp" style="white-space: pre-wrap;"><span class="hljs-comment">// Initializing vector</span><span class="hljs-normal"></span>
<span class="hljs-normal"><a href="ffw_Vec2.html">ffw::Vec2f</a> a;               </span><span class="hljs-comment">// Will be initialized to [0, 0]</span><span class="hljs-normal"></span>
<span class="hljs-normal"><a href="ffw_Vec2.html">ffw::Vec2f</a> b(10.0f, 20.0f); </span><span class="hljs-comment">// Will be initialized to [10, 20]</span><span class="hljs-normal"></span>
<span class="hljs-normal"><a href="ffw_Vec2.html">ffw::Vec2f</a> c(20.0f);        </span><span class="hljs-comment">// Will be initialized to [20, 20]</span><span class="hljs-normal"></span>
<span class="hljs-normal"><a href="ffw_Vec.html">ffw::Vec<float, 6></a> d(&#123;1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f&#125;);</span>
<span class="hljs-normal">                            </span><span class="hljs-comment">// Will be initialized to [1, 2, 3, 4, 5, 6]</span>
</div></pre>




<pre><div class="lang-cpp" style="white-space: pre-wrap;"><span class="hljs-comment">// Casting to a different data type is done explicitly!</span><span class="hljs-normal"></span>
<span class="hljs-normal"><a href="ffw_Vec2.html">ffw::Vec2i</a> e = a; </span><span class="hljs-comment">// ERROR, will not work, cannot convert ffw::Vec2f to ffw::Vec2i</span><span class="hljs-normal"></span>
<span class="hljs-normal"><a href="ffw_Vec2.html">ffw::Vec2i</a> e = (int)a; </span><span class="hljs-comment">// ERROR, will not work, cannot cast ffw::Vec2f to int</span><span class="hljs-normal"></span>
<span class="hljs-normal"><a href="ffw_Vec2.html">ffw::Vec2i</a> e = (<a href="ffw.html#e4e07ebe">ffw::Vec2i</a>)a; </span><span class="hljs-comment">// OK!</span>
</div></pre>




<pre><div class="lang-cpp" style="white-space: pre-wrap;"><span class="hljs-comment">// Setting it to a different value</span><span class="hljs-normal"></span>
<span class="hljs-normal">a.<a href="ffw_Vec2.html#e49a9b9e">set</a>(0.5f, 0.7f);          </span><span class="hljs-comment">// A is now [0.5, 0.7]</span><span class="hljs-normal"></span>
<span class="hljs-normal">b.<a href="ffw_Var.html#27fd904e">set</a>(1.0f);                </span><span class="hljs-comment">// B is now [1.0, 1.0]</span><span class="hljs-normal"></span>
<span class="hljs-normal">c = a;                      </span><span class="hljs-comment">// Copy A to C</span><span class="hljs-normal"></span>
<span class="hljs-normal">c.<a href="ffw_Vec2.html#e49a9b9e">set</a>(a);                   </span><span class="hljs-comment">// Copy A to C</span><span class="hljs-normal"></span>
<span class="hljs-normal">d.set(1.0f);                </span><span class="hljs-comment">// D is now [1, 1, 1, 1, 1, 1]</span><span class="hljs-normal"></span>
<span class="hljs-normal">d.set(&#123;0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f&#125;); </span><span class="hljs-comment">// D is now [0, 1, 0, 0, 0, 0]</span>
</div></pre>




<pre><div class="lang-cpp" style="white-space: pre-wrap;"><span class="hljs-comment">// Accessing individual elements</span><span class="hljs-normal"></span>
<span class="hljs-normal">c.x = 55.0f;</span>
<span class="hljs-normal">c.y = 66.0f;</span>
<span class="hljs-normal"></span><span class="hljs-comment">// C is now [55, 66]</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span>
<span class="hljs-normal">d[5] = 10.0f;</span>
<span class="hljs-normal"></span><span class="hljs-comment">// D's 6th component is set to 10</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span>
<span class="hljs-normal">std::cout &lt;&lt; a.<a href="ffw_Vec2.html#b2ccd122">x</a> &lt;&lt; </span><span class="hljs-string">", "</span><span class="hljs-normal"> &lt;&lt; a.<a href="ffw_Vec2.html#370d6d90">y</a> &lt;&lt; std::endl; </span><span class="hljs-comment">// Prints "0.5, 0.7"</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span><span class="hljs-comment">// Same as std::cout &lt;&lt; a &lt;&lt; std::endl;</span>
</div></pre>




<pre><div class="lang-cpp" style="white-space: pre-wrap;"><span class="hljs-comment">// Scalling</span><span class="hljs-normal"></span>
<span class="hljs-normal">c.scale(2.0);               </span><span class="hljs-comment">// C is now [110, 132]</span>
</div></pre>




<pre><div class="lang-cpp" style="white-space: pre-wrap;"><span class="hljs-comment">// Unary operator</span><span class="hljs-normal"></span>
<span class="hljs-normal">b = -b;                     </span><span class="hljs-comment">// B is now [-1.0, -1.0]</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span>
<span class="hljs-normal"></span><span class="hljs-comment">// Addition (component wise)</span><span class="hljs-normal"></span>
<span class="hljs-normal">std::cout &lt;&lt; (a + b) &lt;&lt; std::endl; </span><span class="hljs-comment">// Prints "-0.5, -0.3"</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span><span class="hljs-comment">// 'a' and 'b' remains unmodified!</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span>
<span class="hljs-normal">c = a + b;                  </span><span class="hljs-comment">// C is now [-0.5, -0.3]</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span>
<span class="hljs-normal"></span><span class="hljs-comment">// All other operators (+, -, *, /) follow same principle </span><span class="hljs-normal"></span>
<span class="hljs-normal"></span><span class="hljs-comment">// They can be also used as += -= *= /= </span><span class="hljs-normal"></span>
<span class="hljs-normal"></span>
<span class="hljs-normal">a += b;</span>
<span class="hljs-normal"></span><span class="hljs-comment">// Is same as</span><span class="hljs-normal"></span>
<span class="hljs-normal">a = a + b;</span>
</div></pre>



All operations (addition, subtraction, multiplication, division) are component wise. Meaning that computing addition of 3 componet vector follows:


<pre><div class="lang-cpp" style="white-space: pre-wrap;"><span class="hljs-comment">// Given a, b, and c are 3D vectors</span><span class="hljs-normal"></span>
<span class="hljs-normal">c.x = a.<a href="ffw_Vec2.html#b2ccd122">x</a> + b.x;</span>
<span class="hljs-normal">c.y = a.<a href="ffw_Vec2.html#370d6d90">y</a> + b.y;</span>
<span class="hljs-normal">c.z = a.z + b.z;</span>
</div></pre>



#### Magnitude (length)


From linear algebra, we know that magnitude of a vector is sqrt(x^2 + y^2 + ...). Magnitude is also the length of a vector. To scale the vector so the magnitude/lengths equals 1.0 you can use **[vec.normalize()](ffw.html#3ae66aa1)**. Additionally, you can use **[ffw::normalize()](ffw.html#3ae66aa1)** (won't modify the original vector) which returns a copy of a normalized vector.


<pre><div class="lang-cpp" style="white-space: pre-wrap;"><span class="hljs-normal"><a href="ffw_Vec3.html">ffw::Vec3f</a> a(1.0f, 0.0f, 0.0f);</span>
<span class="hljs-normal">std::cout &lt;&lt; a.<a href="ffw_Vec2.html#38c7d4a7">length</a>() &lt;&lt; std::endl; </span><span class="hljs-comment">// Prints "1.0"</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span>
<span class="hljs-normal"><a href="ffw_Vec3.html">ffw::Vec3f</a> b(2.0f, 0.0f, 0.0f);</span>
<span class="hljs-normal">std::cout &lt;&lt; b.length() &lt;&lt; std::endl; </span><span class="hljs-comment">// Prints "2.0"</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span>
<span class="hljs-normal">b.normalize(); </span><span class="hljs-comment">// B is now normalized</span><span class="hljs-normal"></span>
<span class="hljs-normal">std::cout &lt;&lt; b &lt;&lt; </span><span class="hljs-string">" length: "</span><span class="hljs-normal"> &lt;&lt; b.length() &lt;&lt; std::endl; </span><span class="hljs-comment">// Prints: "1, 0, 0 length: 1"</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span>
<span class="hljs-normal"><a href="ffw_Vec3.html">ffw::Vec3f</a> c(1.0f, 1.0f, 1.0f);</span>
<span class="hljs-normal">std::cout &lt;&lt; c.length() &lt;&lt; std::endl; </span><span class="hljs-comment">// Prints "1.73205080757" (also known as sqrt(3))</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span>
<span class="hljs-normal"><a href="ffw_Vec.html">ffw::Vec<float, 7></a> d(&#123;1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f&#125;);</span>
<span class="hljs-normal">std::cout &lt;&lt; d.<a href="ffw_Vec.html#4c411e47">length</a>() &lt;&lt; std::endl; </span><span class="hljs-comment">// Prints "11.8321595662"</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span>
<span class="hljs-normal"></span><span class="hljs-comment">// Optionally, you can use lengthSqrd() to get squared length.</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span><span class="hljs-comment">// It is faster to compare two lengths of vectors via lengthSqrd() rather than</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span><span class="hljs-comment">// length() because length() uses expensive sqrd() operation.</span>
</div></pre>



#### Rotation


All rotation is done in clockwise, as all vectors should do. Rotation can be done either on [ffw::Vec2](ffw_Vec2.html) in one axis or on [ffw::Vec3](ffw_Vec3.html) in X, Y, and Z axis.


<pre><div class="lang-cpp" style="white-space: pre-wrap;"><span class="hljs-normal"><a href="ffw_Vec3.html">ffw::Vec3f</a> a(1.0f, 0.0f, 0.0f);</span>
<span class="hljs-normal">a.rotateZ(90.0); </span><span class="hljs-comment">// Rotate by 90 degrees clockwise</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span>
<span class="hljs-normal">std::cout &lt;&lt; a &lt;&lt; std::endl; </span><span class="hljs-comment">// Prints "0, 1, 0"</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span><span class="hljs-comment">// Might also print: "8.94897e-10, 1, 0" which is essentially 0, 1, 0</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span><span class="hljs-comment">// due to the floating point precision</span>
</div></pre>



#### Angle between vectors


You can use [ffw::angle](ffw.html#b81562f6) or [ffw::angleRad](ffw.html#117a45b2) (for radians) on [ffw::Vec2](ffw_Vec2.html) and [ffw::Vec3](ffw_Vec3.html) which will give you an angle between those two vectors


<pre><div class="lang-cpp" style="white-space: pre-wrap;"><span class="hljs-normal"><a href="ffw_Vec3.html">ffw::Vec3f</a> a(1.0f, 0.0f, 0.0f);</span>
<span class="hljs-normal"><a href="ffw_Vec3.html">ffw::Vec3f</a> b(0.0f, 1.0f, 0.0f);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">std::cout &lt;&lt; <a href="ffw.html#b81562f6">ffw::angle</a>(a, b) &lt;&lt; std::endl; </span><span class="hljs-comment">// Prints "90"</span><span class="hljs-normal"></span>
<span class="hljs-normal">std::cout &lt;&lt; <a href="ffw.html#117a45b2">ffw::angleRad</a>(a, b) &lt;&lt; std::endl; </span><span class="hljs-comment">// Prints "1.5708"</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span><span class="hljs-comment">// Both 'a' and 'b' remain unmodified!</span>
</div></pre>



#### Dot and cross product


Cross and dot product is provided, using [ffw::dot](ffw.html#71f5aa67) and [ffw::cross](ffw.html#9aaaf389). Note that dot product can be used with all vectors, but cross product can be used only with [ffw::Vec3](ffw_Vec3.html). However, you can not


<pre><div class="lang-cpp" style="white-space: pre-wrap;"><span class="hljs-normal"><a href="ffw_Vec3.html">ffw::Vec3f</a> a(1.0f, -0.5f, 0.0f); </span><span class="hljs-comment">// Float</span><span class="hljs-normal"></span>
<span class="hljs-normal"><a href="ffw_Vec3.html">ffw::Vec3f</a> b(-0.2f, 1.0f, 0.5f); </span><span class="hljs-comment">// Float</span><span class="hljs-normal"></span>
<span class="hljs-normal"><a href="ffw_Vec3.html">ffw::Vec3d</a> c(-0.2, 1.0, 0.5); </span><span class="hljs-comment">// Double equivalent of 'b'</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span>
<span class="hljs-normal"></span><span class="hljs-comment">// std::cout &lt;&lt; "dot: " &lt;&lt; ffw::dot(a, c) &lt;&lt; std::endl;</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span><span class="hljs-comment">// Will give you compile error due to the reason that 'a' and 'c'</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span><span class="hljs-comment">// are different data types!</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span>
<span class="hljs-normal">std::cout &lt;&lt; </span><span class="hljs-string">"dot: "</span><span class="hljs-normal"> &lt;&lt; <a href="ffw.html#71f5aa67">ffw::dot</a>(a, b) &lt;&lt; std::endl;</span>
<span class="hljs-normal">std::cout &lt;&lt; </span><span class="hljs-string">"cross: "</span><span class="hljs-normal"> &lt;&lt; <a href="ffw.html#9aaaf389">ffw::cross</a>(a, b) &lt;&lt; std::endl;</span>
<span class="hljs-normal"></span><span class="hljs-comment">// 'a' and 'b' remain unmodified!</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span>
<span class="hljs-normal"></span><span class="hljs-comment">// Prints:</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span><span class="hljs-comment">// dot: -0.7</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span><span class="hljs-comment">// cross: -0.25, -0.5, 0.9</span>
</div></pre>



As a proof a links to symbolab.com for [cross product](https://www.symbolab.com/solver/vector-cross-product-calculator/%5Cbegin%7Bpmatrix%7D1%26-0.5%260%5Cend%7Bpmatrix%7D%5Ctimes%5Cbegin%7Bpmatrix%7D-0.2%261%260.5%5Cend%7Bpmatrix%7D) and [dot product](https://www.symbolab.com/solver/vector-dot-product-calculator/%5Cleft(1%2C%20-0.5%2C%200%5Cright)%5Ccdot%5Cleft(-0.2%2C%201%2C%200.5%5Cright)) 

