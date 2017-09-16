Tutorial: Var - JSON-like data structure
=================

This tutorial will explain how the [ffw::Var](ffw_Var.html) class can accept and hold any data type, including creating JSON like data structures via key value pairs and arrays.

#### Basics


Before we start, make sure to add this to your project:


<pre><div class="lang-cpp"><span class="hljs-meta-keyword">#include &lt;iostream&gt;</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span><span class="hljs-meta-keyword">#include &lt;<a href="">ffw/math.h</a>&gt;</span>
</div></pre>



A [ffw::Var](ffw_Var.html) can be initialized as any other variable and can be re-assigned into a different data type at runtime. There is not limit on what it can hold.


<pre><div class="lang-cpp"><span class="hljs-normal"><a href="ffw_Var.html">ffw::Var</a> a;</span>
<span class="hljs-normal">a = 123; </span>
<span class="hljs-normal"></span><span class="hljs-comment">// Now holds an integer</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span>
<span class="hljs-normal">std::cout &lt;&lt; </span><span class="hljs-string">"Value of var: "</span><span class="hljs-normal"> &lt;&lt; a.<a href="ffw_Var.html#1be6ba0e">getAs</a>&lt;</span><span class="hljs-title">int</span><span class="hljs-normal">&gt;() &lt;&lt; std::endl;</span>
<span class="hljs-normal"></span><span class="hljs-comment">// prints: "Value of var: 123"</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span>
<span class="hljs-normal">a = -0.0042f;</span>
<span class="hljs-normal"></span><span class="hljs-comment">// Now holds a float</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span>
<span class="hljs-normal">std::cout &lt;&lt; </span><span class="hljs-string">"Value of var: "</span><span class="hljs-normal"> &lt;&lt; a.<a href="ffw_Var.html#1be6ba0e">getAs</a>&lt;</span><span class="hljs-title">float</span><span class="hljs-normal">&gt;() &lt;&lt; std::endl;</span>
<span class="hljs-normal"></span><span class="hljs-comment">// Prints: "Value of var: -0.0042"</span>
</div></pre>



At any time, you check which data type it holds.


<pre><div class="lang-cpp"><span class="hljs-normal"><a href="ffw_Var.html">ffw::Var</a> a = -0.0042f;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal"></span><span class="hljs-keyword">if</span><span class="hljs-normal">(a.<a href="ffw_Var.html#b1a50abb">empty</a>())&#123;</span>
<span class="hljs-normal">  std::cout &lt;&lt; </span><span class="hljs-string">"a holds nothing!"</span><span class="hljs-normal"> &lt;&lt; std::endl;</span>
<span class="hljs-normal">&#125;</span>
<span class="hljs-normal"></span><span class="hljs-keyword">else</span><span class="hljs-normal"> </span><span class="hljs-keyword">if</span><span class="hljs-normal">(a.<a href="ffw_Var.html#2e070581">is</a>&lt;</span><span class="hljs-title">int</span><span class="hljs-normal">&gt;())&#123;</span>
<span class="hljs-normal">  std::cout &lt;&lt; </span><span class="hljs-string">"a holds an integer!"</span><span class="hljs-normal"> &lt;&lt; std::endl;</span>
<span class="hljs-normal">&#125;</span>
<span class="hljs-normal"></span><span class="hljs-keyword">else</span><span class="hljs-normal"> </span><span class="hljs-keyword">if</span><span class="hljs-normal">(a.<a href="ffw_Var.html#2e070581">is</a>&lt;</span><span class="hljs-title">float</span><span class="hljs-normal">&gt;())&#123;</span>
<span class="hljs-normal">  std::cout &lt;&lt; </span><span class="hljs-string">"a holds a float!"</span><span class="hljs-normal"> &lt;&lt; std::endl;</span>
<span class="hljs-normal">&#125;</span>
<span class="hljs-normal"></span><span class="hljs-keyword">else</span><span class="hljs-normal"> </span><span class="hljs-keyword">if</span><span class="hljs-normal">(a.<a href="ffw_Var.html#2e070581">is</a>&lt;</span><span class="hljs-title">char</span><span class="hljs-normal">&gt;())&#123;</span>
<span class="hljs-normal">  std::cout &lt;&lt; </span><span class="hljs-string">"a holds a char!"</span><span class="hljs-normal"> &lt;&lt; std::endl;</span>
<span class="hljs-normal">&#125;</span>
<span class="hljs-normal"></span><span class="hljs-comment">// Prints: "a holds a float!"</span>
</div></pre>



The [ffw::Var](ffw_Var.html) holds exactly the data type you put into it. This might raise some issues such as handling unsigned and signed integers


<pre><div class="lang-cpp"><span class="hljs-normal"><a href="ffw_Var.html">ffw::Var</a> a = (int)123;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal"></span><span class="hljs-keyword">if</span><span class="hljs-normal">(a.<a href="ffw_Var.html#2e070581">is</a>&lt;</span><span class="hljs-title">int</span><span class="hljs-normal">&gt;())&#123;</span>
<span class="hljs-normal">  std::cout &lt;&lt; </span><span class="hljs-string">"a holds an signed integer!"</span><span class="hljs-normal"> &lt;&lt; std::endl;</span>
<span class="hljs-normal">&#125; </span>
<span class="hljs-normal"></span><span class="hljs-keyword">else</span><span class="hljs-normal"> </span><span class="hljs-keyword">if</span><span class="hljs-normal">(a.<a href="ffw_Var.html#2e070581">is</a>&lt;</span><span class="hljs-title">unsigned</span><span class="hljs-normal"> </span><span class="hljs-title">int</span><span class="hljs-normal">&gt;())&#123;</span>
<span class="hljs-normal">  std::cout &lt;&lt; </span><span class="hljs-string">"a holds an unsigned integer!"</span><span class="hljs-normal"> &lt;&lt; std::endl;</span>
<span class="hljs-normal">&#125;</span>
<span class="hljs-normal"></span><span class="hljs-comment">// Prints: "a holds an signed integer!"</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span>
<span class="hljs-normal">a = (</span><span class="hljs-title">unsigned</span><span class="hljs-normal"> int)123;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal"></span><span class="hljs-keyword">if</span><span class="hljs-normal">(a.<a href="ffw_Var.html#2e070581">is</a>&lt;</span><span class="hljs-title">int</span><span class="hljs-normal">&gt;())&#123;</span>
<span class="hljs-normal">  std::cout &lt;&lt; </span><span class="hljs-string">"a holds an signed integer!"</span><span class="hljs-normal"> &lt;&lt; std::endl;</span>
<span class="hljs-normal">&#125; </span>
<span class="hljs-normal"></span><span class="hljs-keyword">else</span><span class="hljs-normal"> </span><span class="hljs-keyword">if</span><span class="hljs-normal">(a.<a href="ffw_Var.html#2e070581">is</a>&lt;</span><span class="hljs-title">unsigned</span><span class="hljs-normal"> </span><span class="hljs-title">int</span><span class="hljs-normal">&gt;())&#123;</span>
<span class="hljs-normal">  std::cout &lt;&lt; </span><span class="hljs-string">"a holds an unsigned integer!"</span><span class="hljs-normal"> &lt;&lt; std::endl;</span>
<span class="hljs-normal">&#125;</span>
<span class="hljs-normal"></span><span class="hljs-comment">// Prints: "a holds an unsigned integer!"</span>
</div></pre>



You can also modify the stored value. The [ffw::Var::getAs](ffw_Var.html#1be6ba0e) method will return a reference to the stored value.


<pre><div class="lang-cpp"><span class="hljs-normal"><a href="ffw_Var.html">ffw::Var</a> a = -0.0042f;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">a.<a href="ffw_Var.html#1be6ba0e">getAs</a>&lt;</span><span class="hljs-title">float</span><span class="hljs-normal">&gt;() = 100.0f;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">std::cout &lt;&lt; </span><span class="hljs-string">"Value of var: "</span><span class="hljs-normal"> &lt;&lt; a.<a href="ffw_Var.html#1be6ba0e">getAs</a>&lt;</span><span class="hljs-title">float</span><span class="hljs-normal">&gt;() &lt;&lt; std::endl;</span>
<span class="hljs-normal"></span><span class="hljs-comment">// Prints: "Value of var: 100"</span>
</div></pre>



Note that storing a reference might be usefull, but after you re-assign a new value, the reference will be invalid! Imagine it as a pointer, you set a pointer to `float& ref = a.getAs<float>();` and when you create a new value `a = 200.0f` the address will change!


<pre><div class="lang-cpp"><span class="hljs-normal"><a href="ffw_Var.html">ffw::Var</a> a = -0.0042f;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal"></span><span class="hljs-title">float</span><span class="hljs-normal">&amp; ref = a.<a href="ffw_Var.html#1be6ba0e">getAs</a>&lt;</span><span class="hljs-title">float</span><span class="hljs-normal">&gt;();</span>
<span class="hljs-normal">ref = 100.0f;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">std::cout &lt;&lt; </span><span class="hljs-string">"Value of var: "</span><span class="hljs-normal"> &lt;&lt; a.<a href="ffw_Var.html#1be6ba0e">getAs</a>&lt;</span><span class="hljs-title">float</span><span class="hljs-normal">&gt;() &lt;&lt; std::endl;</span>
<span class="hljs-normal"></span><span class="hljs-comment">// Prints: "Value of var: 100"</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span>
<span class="hljs-normal">a = 200.0f;</span>
<span class="hljs-normal"></span><span class="hljs-comment">// New float assigned to a, the old one is gone forever!</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span>
<span class="hljs-normal">ref = 100.0f;</span>
<span class="hljs-normal"></span><span class="hljs-comment">// Will result in undefined behaviour!</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span><span class="hljs-comment">// Prefer to access the value via a.getAs&lt;float&gt;()</span>
</div></pre>



Trying to get a different data type than is stored inside of [ffw::Var](ffw_Var.html) will throw you an std::bad_cast


<pre><div class="lang-cpp"><span class="hljs-normal"><a href="ffw_Var.html">ffw::Var</a> a = -0.0042f;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">std::cout &lt;&lt; </span><span class="hljs-string">"Value of var: "</span><span class="hljs-normal"> &lt;&lt; a.<a href="ffw_Var.html#1be6ba0e">getAs</a>&lt;</span><span class="hljs-title">float</span><span class="hljs-normal">&gt;() &lt;&lt; std::endl;</span>
<span class="hljs-normal"></span><span class="hljs-comment">// OK Prints: "Value of var: 100"</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span>
<span class="hljs-normal">std::cout &lt;&lt; </span><span class="hljs-string">"Value of var: "</span><span class="hljs-normal"> &lt;&lt; a.<a href="ffw_Var.html#1be6ba0e">getAs</a>&lt;</span><span class="hljs-title">int</span><span class="hljs-normal">&gt;() &lt;&lt; std::endl;</span>
<span class="hljs-normal"></span><span class="hljs-comment">// ERROR: std::bad_cast</span>
</div></pre>



The [ffw::Var::getAs](ffw_Var.html#1be6ba0e) has to know the explicit type you are trying to retrieve!

#### With great power comes great responsibility


The [ffw::Var](ffw_Var.html) can tell you what data it holds via [ffw::Var::getTypeid](ffw_Var.html#faa85b7e) method. This can only tell you what is inside but it will never ever give you the true data. It simply can not, this is limited by the C++ language.

You have to know what are you storing and you have to know exactly what are you looking for when trying to retrieve the value behind [ffw::Var](ffw_Var.html)

#### The problem with strings


Because [ffw::Var](ffw_Var.html) stores explicit type (if you store double, it's double, not float... if you store int, it's not unsigned int, nor long, it's just an int...) there is an issue with C style strings (const char*), string arrays (const char[N]), and C++ std::strings.

For example:


<pre><div class="lang-cpp"><span class="hljs-normal"><a href="ffw_Var.html">ffw::Var</a> a = </span><span class="hljs-string">"Hello World!"</span><span class="hljs-normal">;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal"></span><span class="hljs-keyword">if</span><span class="hljs-normal">(a.<a href="ffw_Var.html#2e070581">is</a>&lt;std::string&gt;())&#123;</span>
<span class="hljs-normal">  std::cout &lt;&lt; </span><span class="hljs-string">"a holds std::string!"</span><span class="hljs-normal"> &lt;&lt; std::endl;</span>
<span class="hljs-normal">&#125;</span>
<span class="hljs-normal"></span><span class="hljs-keyword">else</span><span class="hljs-normal"> </span><span class="hljs-keyword">if</span><span class="hljs-normal">(a.<a href="ffw_Var.html#2e070581">is</a>&lt;</span><span class="hljs-keyword">const</span><span class="hljs-normal"> </span><span class="hljs-title">char</span><span class="hljs-normal">*&gt;())&#123;</span>
<span class="hljs-normal">  std::cout &lt;&lt; </span><span class="hljs-string">"a holds const char*!"</span><span class="hljs-normal"> &lt;&lt; std::endl;</span>
<span class="hljs-normal">&#125;</span>
<span class="hljs-normal"></span><span class="hljs-comment">// Prints: "a holds const char*!"</span>
</div></pre>



A simple workaround is to always store value as std::string


<pre><div class="lang-cpp"><span class="hljs-normal"><a href="ffw_Var.html">ffw::Var</a> a = std::string(</span><span class="hljs-string">"Hello World!"</span><span class="hljs-normal">);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal"></span><span class="hljs-keyword">if</span><span class="hljs-normal">(a.<a href="ffw_Var.html#2e070581">is</a>&lt;std::string&gt;())&#123;</span>
<span class="hljs-normal">  std::cout &lt;&lt; </span><span class="hljs-string">"a holds std::string!"</span><span class="hljs-normal"> &lt;&lt; std::endl;</span>
<span class="hljs-normal">&#125;</span>
<span class="hljs-normal"></span><span class="hljs-keyword">else</span><span class="hljs-normal"> </span><span class="hljs-keyword">if</span><span class="hljs-normal">(a.<a href="ffw_Var.html#2e070581">is</a>&lt;</span><span class="hljs-keyword">const</span><span class="hljs-normal"> </span><span class="hljs-title">char</span><span class="hljs-normal">*&gt;())&#123;</span>
<span class="hljs-normal">  std::cout &lt;&lt; </span><span class="hljs-string">"a holds const char*!"</span><span class="hljs-normal"> &lt;&lt; std::endl;</span>
<span class="hljs-normal">&#125;</span>
<span class="hljs-normal"></span><span class="hljs-comment">// Prints: "a holds std::string!"</span>
</div></pre>



If you are using both std::string and const char* then you might would like to use [ffw::Var::isString](ffw_Var.html#f587f1a0) and [ffw::Var::toString](ffw_Var.html#1804ed51) methods. Note that the toString method will always return a copy of the original string. **If the [ffw::Var](ffw_Var.html) does not hold any kind of string, it will return an empty string.**


<pre><div class="lang-cpp"><span class="hljs-normal"><a href="ffw_Var.html">ffw::Var</a> a = </span><span class="hljs-string">"Hello World!"</span><span class="hljs-normal">;</span>
<span class="hljs-normal"><a href="ffw_Var.html">ffw::Var</a> b = std::string(</span><span class="hljs-string">"Hello World!"</span><span class="hljs-normal">);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal"></span><span class="hljs-comment">// Always true, even though they are different data types</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span><span class="hljs-keyword">if</span><span class="hljs-normal">(a.<a href="ffw_Var.html#f587f1a0">isString</a>() &amp;&amp; b.<a href="ffw_Var.html#f587f1a0">isString</a>())&#123;</span>
<span class="hljs-normal">  std::cout &lt;&lt; </span><span class="hljs-string">"a and b are strings!"</span><span class="hljs-normal"> &lt;&lt; std::endl;</span>
<span class="hljs-normal">  std::cout &lt;&lt; </span><span class="hljs-string">"a: "</span><span class="hljs-normal"> &lt;&lt; a.<a href="ffw_Var.html#1804ed51">toString</a>() &lt;&lt; </span><span class="hljs-string">" b: "</span><span class="hljs-normal"> &lt;&lt; b.<a href="ffw_Var.html#1804ed51">toString</a>() &lt;&lt; std::endl;</span>
<span class="hljs-normal">&#125;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal"></span><span class="hljs-comment">// Prints: "a: Hello World! b: Hello World!"</span>
</div></pre>



#### The problem with inetegers, floats, booleans


As mentioned above, storing an signed integer and then asking for unsigned integer will throw a std::bad_cast exception.


<pre><div class="lang-cpp"><span class="hljs-normal"><a href="ffw_Var.html">ffw::Var</a> a = (</span><span class="hljs-title">unsigned</span><span class="hljs-normal"> int)123;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">std::cout &lt;&lt; </span><span class="hljs-string">"a: "</span><span class="hljs-normal"> &lt;&lt; a.<a href="ffw_Var.html#1be6ba0e">getAs</a>&lt;</span><span class="hljs-title">int</span><span class="hljs-normal">&gt;() &lt;&lt; std::endl; </span><span class="hljs-comment">// Error! std::bad_cast</span><span class="hljs-normal"></span>
<span class="hljs-normal">std::cout &lt;&lt; </span><span class="hljs-string">"a: "</span><span class="hljs-normal"> &lt;&lt; a.<a href="ffw_Var.html#1be6ba0e">getAs</a>&lt;</span><span class="hljs-title">unsigned</span><span class="hljs-normal"> </span><span class="hljs-title">int</span><span class="hljs-normal">&gt;() &lt;&lt; std::endl; </span><span class="hljs-comment">// OK!</span>
</div></pre>



The [ffw::Var](ffw_Var.html) offers the following methods, similarly to [ffw::Var::toString](ffw_Var.html#1804ed51) as explained above. All of the following methods do not throw an exception. For example, if the stored data type is std::string and you will call [ffw::Var::toInt](ffw_Var.html#4321ba77) it will return an integer of value of zero. This applies to toBool (will return false) and toFloat (will return 0.0f).


* [ffw::Var::toInt](ffw_Var.html#4321ba77) and [ffw::Var::isInt](ffw_Var.html#95faec1d) for all integer data types (int, short, unsigned long, uint32_t, etc...)

* [ffw::Var::toFloat](ffw_Var.html#5d2999ad) and [ffw::Var::isFloat](ffw_Var.html#5bc85c4d) for all floating point data types (float, double, etc...)

* [ffw::Var::toBool](ffw_Var.html#70753066) and [ffw::Var::isBool](ffw_Var.html#8b978a46) for booleans, will also work if any integer is stored




#### Key value mapping


If you heard about JSON, you will know what is this about. The [ffw::Object](ffw_Object.html) is a fancy std::unordered_map structure that contains keys as std::string and values as [ffw::Var](ffw_Var.html). With this, we can create a JSON-like object:


<pre><div class="lang-cpp"><span class="hljs-normal"><a href="ffw_Object.html">ffw::Object</a> obj;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal"></span><span class="hljs-comment">// Insert into object</span><span class="hljs-normal"></span>
<span class="hljs-normal">obj.<a href="ffw_Object.html#dc1d6d5e">insert</a>(std::make_pair(</span><span class="hljs-string">"value"</span><span class="hljs-normal">, 123));</span>
<span class="hljs-normal"></span>
<span class="hljs-normal"></span><span class="hljs-comment">// This works as well</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span><span class="hljs-comment">// The operator [] will insert a new key pair if the key does not exist</span><span class="hljs-normal"></span>
<span class="hljs-normal">obj[</span><span class="hljs-string">"boolean"</span><span class="hljs-normal">] = </span><span class="hljs-keyword">true</span><span class="hljs-normal">;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">obj.<a href="ffw_Object.html#49739af4">has_key</a>(</span><span class="hljs-string">"boolean"</span><span class="hljs-normal">); </span><span class="hljs-comment">// Returns true</span>
</div></pre>



You can then use the mapped values as any other [ffw::Var](ffw_Var.html)


<pre><div class="lang-cpp"><span class="hljs-keyword">if</span><span class="hljs-normal">(obj[</span><span class="hljs-string">"value"</span><span class="hljs-normal">].isInt())&#123;</span>
<span class="hljs-normal">  std::cout &lt;&lt; </span><span class="hljs-string">"value: "</span><span class="hljs-normal"> &lt;&lt; obj[</span><span class="hljs-string">"value"</span><span class="hljs-normal">].toInt() &lt;&lt; std::endl;</span>
<span class="hljs-normal">  </span><span class="hljs-comment">// obj["value"].getAs&lt;int&gt;() also works</span><span class="hljs-normal"></span>
<span class="hljs-normal">&#125;</span>
<span class="hljs-normal"></span><span class="hljs-keyword">if</span><span class="hljs-normal">(obj[</span><span class="hljs-string">"boolean"</span><span class="hljs-normal">].isBool())&#123;</span>
<span class="hljs-normal">  std::cout &lt;&lt; </span><span class="hljs-string">"boolean: "</span><span class="hljs-normal"> &lt;&lt; obj[</span><span class="hljs-string">"value"</span><span class="hljs-normal">].toBool() &lt;&lt; std::endl;</span>
<span class="hljs-normal">  </span><span class="hljs-comment">// obj["value"].getAs&lt;bool&gt;() also works</span><span class="hljs-normal"></span>
<span class="hljs-normal">&#125;</span>
<span class="hljs-normal"></span><span class="hljs-comment">// Prints: "value: 123"</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span><span class="hljs-comment">//         "boolean: 1"</span>
</div></pre>



The [ffw::Object](ffw_Object.html) offers a braced list constructor which simplifies things even further:


<pre><div class="lang-cpp"><span class="hljs-normal"><a href="ffw_Object.html">ffw::Object</a> obj = &#123;</span>
<span class="hljs-normal">  &#123;</span><span class="hljs-string">"integer"</span><span class="hljs-normal">, 123&#125;,</span>
<span class="hljs-normal">  &#123;</span><span class="hljs-string">"float"</span><span class="hljs-normal">, 456.7f&#125;,</span>
<span class="hljs-normal">  &#123;</span><span class="hljs-string">"double"</span><span class="hljs-normal">, 456.7&#125;,</span>
<span class="hljs-normal">  &#123;</span><span class="hljs-string">"boolean"</span><span class="hljs-normal">, </span><span class="hljs-keyword">true</span><span class="hljs-normal">&#125;,</span>
<span class="hljs-normal">  &#123;</span><span class="hljs-string">"object"</span><span class="hljs-normal">, <a href="ffw_Object.html">ffw::Object</a> </span>
<span class="hljs-normal">    &#123;</span>
<span class="hljs-normal">      &#123;</span><span class="hljs-string">"first"</span><span class="hljs-normal">, 10&#125;,</span>
<span class="hljs-normal">      &#123;</span><span class="hljs-string">"second"</span><span class="hljs-normal">, 20&#125;</span>
<span class="hljs-normal">    &#125;</span>
<span class="hljs-normal">  &#125;</span>
<span class="hljs-normal">&#125;;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal"></span><span class="hljs-comment">// Access object -&gt; first -&gt; int</span><span class="hljs-normal"></span>
<span class="hljs-normal">std::cout &lt;&lt; </span><span class="hljs-string">"object/first: "</span><span class="hljs-normal"> &lt;&lt; obj[</span><span class="hljs-string">"object"</span><span class="hljs-normal">][</span><span class="hljs-string">"first"</span><span class="hljs-normal">].toInt() &lt;&lt; std::endl;</span>
<span class="hljs-normal"></span><span class="hljs-comment">// Prints "object/first: 10"</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span>
<span class="hljs-normal">std::cout &lt;&lt; </span><span class="hljs-string">"object/invalid: "</span><span class="hljs-normal"> &lt;&lt; obj[</span><span class="hljs-string">"object"</span><span class="hljs-normal">][</span><span class="hljs-string">"invalid"</span><span class="hljs-normal">].toInt() &lt;&lt; std::endl;</span>
<span class="hljs-normal"></span><span class="hljs-comment">// Prints "object/first: 0"</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span><span class="hljs-comment">// Why zero ? Because operator [] creates a new empty value, so the following:</span><span class="hljs-normal"></span>
<span class="hljs-normal">std::cout &lt;&lt; </span><span class="hljs-string">"object/new: "</span><span class="hljs-normal"> &lt;&lt; obj[</span><span class="hljs-string">"object"</span><span class="hljs-normal">][</span><span class="hljs-string">"new"</span><span class="hljs-normal">].<a href="ffw_Object.html#ac7b4816">empty</a>() &lt;&lt; std::endl;</span>
<span class="hljs-normal"></span><span class="hljs-comment">// Prints "object/new: 1"</span>
</div></pre>



Note that [operator[] will insert a new value if the key does not exist](http://en.cppreference.com/w/cpp/container/unordered_map/operator_at) If you wish the program to throw an exception if the key does not exist, you might want to use [ffw::Object::at](ffw_Object.html#a7ec28a3) For example: `obj.at("invalid-key").isBool()` will throw [std::out_of_range](http://en.cppreference.com/w/cpp/error/out_of_range)

Also, when having an object inside of an object, you might think of doing this:


<pre><div class="lang-cpp"><span class="hljs-comment">// Access object -&gt; first -&gt; int</span><span class="hljs-normal"></span>
<span class="hljs-normal">std::cout &lt;&lt; </span><span class="hljs-string">"object/first: "</span><span class="hljs-normal"> &lt;&lt; </span>
<span class="hljs-normal">  obj[</span><span class="hljs-string">"object"</span><span class="hljs-normal">].getAs&lt;<a href="ffw_Object.html">ffw::Object</a>&gt;()[</span><span class="hljs-string">"first"</span><span class="hljs-normal">].toInt()</span>
<span class="hljs-normal">  &lt;&lt; std::endl;</span>
<span class="hljs-normal"></span><span class="hljs-comment">// Prints "object/first: 10"</span>
</div></pre>



So how come the previous section does not have `getAs` and it still works? The [ffw::Var](ffw_Var.html) offers two [] operators. If you supply std::string, it will assume that you are treating it as [ffw::Object](ffw_Object.html), if you supply an integer, it will assume you are treating it as [ffw::Array](ffw_Array.html)


<pre><div class="lang-cpp"><span class="hljs-normal"><a href="ffw_Var.html">ffw::Var</a> a = 123;</span>
<span class="hljs-normal">a[</span><span class="hljs-string">"something"</span><span class="hljs-normal">] = 456; </span><span class="hljs-comment">// std::bad_cast the a is not an object</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span>
<span class="hljs-normal">a = <a href="ffw_Object.html">ffw::Object</a>();</span>
<span class="hljs-normal"></span>
<span class="hljs-normal"></span><span class="hljs-comment">// Both are exactly same:</span><span class="hljs-normal"></span>
<span class="hljs-normal">a[</span><span class="hljs-string">"something"</span><span class="hljs-normal">] = 456; </span><span class="hljs-comment">// OK new value inserted</span><span class="hljs-normal"></span>
<span class="hljs-normal">a.<a href="ffw_Var.html#1be6ba0e">getAs</a>&lt;<a href="ffw_Object.html">ffw::Object</a>&gt;()[</span><span class="hljs-string">"something"</span><span class="hljs-normal">] = 456; </span><span class="hljs-comment">// Also OK value modyfied</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span>
<span class="hljs-normal">a[0] = 456; </span><span class="hljs-comment">// std::bad_cast the a is not an Array</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span>
<span class="hljs-normal">a = <a href="ffw_Array.html">ffw::Array</a>();</span>
<span class="hljs-normal">a[0] = 456; </span><span class="hljs-comment">// Segmentation fault, array is empty!</span><span class="hljs-normal"></span>
<span class="hljs-normal">a.push_back(123);</span>
<span class="hljs-normal">a[0] = 456; </span><span class="hljs-comment">// OK!</span><span class="hljs-normal"></span>
<span class="hljs-normal">a.getAs&lt;<a href="ffw_Array.html">ffw::Array</a>&gt;()[0] = 456; </span><span class="hljs-comment">// OK!</span>
</div></pre>



#### Arrays


Alongside [ffw::Object](ffw_Object.html) we have [ffw::Array](ffw_Array.html) which is fancy std::vector that holds [ffw::Var](ffw_Var.html). It works exactly such as a normal std::vector


<pre><div class="lang-cpp"><span class="hljs-normal"><a href="ffw_Array.html">ffw::Array</a> a;</span>
<span class="hljs-normal">a.<a href="ffw_Array.html#805fb16c">push_back</a>(123); </span><span class="hljs-comment">// int</span><span class="hljs-normal"></span>
<span class="hljs-normal">a.<a href="ffw_Array.html#805fb16c">push_back</a>(456.7f); </span><span class="hljs-comment">// float</span><span class="hljs-normal"></span>
<span class="hljs-normal">a.<a href="ffw_Array.html#805fb16c">push_back</a>(456.7); </span><span class="hljs-comment">// double</span><span class="hljs-normal"></span>
<span class="hljs-normal">a.<a href="ffw_Array.html#805fb16c">push_back</a>(<a href="ffw_Array.html">ffw::Array</a>&#123;10, 20, 30&#125;); </span><span class="hljs-comment">// array of 3 ints</span><span class="hljs-normal"></span>
<span class="hljs-normal">a.<a href="ffw_Array.html#805fb16c">push_back</a>(</span><span class="hljs-keyword">true</span><span class="hljs-normal">); </span><span class="hljs-comment">// bool</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span>
<span class="hljs-normal">std::cout &lt;&lt; </span><span class="hljs-string">"int: "</span><span class="hljs-normal"> &lt;&lt; a[0].toInt() &lt;&lt; std::endl;</span>
<span class="hljs-normal">std::cout &lt;&lt; </span><span class="hljs-string">"float: "</span><span class="hljs-normal"> &lt;&lt; a[1].toFloat() &lt;&lt; std::endl;</span>
<span class="hljs-normal">std::cout &lt;&lt; </span><span class="hljs-string">"double: "</span><span class="hljs-normal"> &lt;&lt; a[2].getAs&lt;</span><span class="hljs-title">double</span><span class="hljs-normal">&gt;() &lt;&lt; std::endl;</span>
<span class="hljs-normal">std::cout &lt;&lt; </span><span class="hljs-string">"array: "</span><span class="hljs-normal"> &lt;&lt; </span>
<span class="hljs-normal">  a[3][0].toInt() &lt;&lt; </span><span class="hljs-string">", "</span><span class="hljs-normal"> &lt;&lt; </span>
<span class="hljs-normal">  a[3][1].toInt() &lt;&lt; </span><span class="hljs-string">", "</span><span class="hljs-normal"> &lt;&lt;</span>
<span class="hljs-normal">  a[3][2].toInt() &lt;&lt; std::endl;</span>
<span class="hljs-normal">std::cout &lt;&lt; </span><span class="hljs-string">"bool: "</span><span class="hljs-normal"> &lt;&lt; a[4].toBool() &lt;&lt; std::endl;</span>
<span class="hljs-normal"></span><span class="hljs-comment">// Prints: "int: 123"</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span><span class="hljs-comment">//         "float: 456.7"</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span><span class="hljs-comment">//         "double: 456.7"</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span><span class="hljs-comment">//         "array: 10, 20, 30"</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span><span class="hljs-comment">//         "bool: 1"</span>
</div></pre>



#### Putting it all together


With both arrays and objects, you can create some fancy looking data structures:


<pre><div class="lang-cpp"><span class="hljs-normal"><a href="ffw_Object.html">ffw::Object</a> example1 = &#123; </span>
<span class="hljs-normal">    </span><span class="hljs-string">"menu"</span><span class="hljs-normal">, <a href="ffw_Object.html">ffw::Object</a>&#123;</span>
<span class="hljs-normal">        &#123;</span><span class="hljs-string">"id"</span><span class="hljs-normal">, </span><span class="hljs-string">"file"</span><span class="hljs-normal">,&#125;,</span>
<span class="hljs-normal">        &#123;</span><span class="hljs-string">"value"</span><span class="hljs-normal">, </span><span class="hljs-string">"File"</span><span class="hljs-normal">,&#125;,</span>
<span class="hljs-normal">        &#123;</span><span class="hljs-string">"popup"</span><span class="hljs-normal">, <a href="ffw_Object.html">ffw::Object</a>&#123;</span>
<span class="hljs-normal">            &#123;</span><span class="hljs-string">"menuitem"</span><span class="hljs-normal">, <a href="ffw_Array.html">ffw::Array</a>&#123;</span>
<span class="hljs-normal">                <a href="ffw_Object.html">ffw::Object</a>&#123;&#123;</span><span class="hljs-string">"value"</span><span class="hljs-normal">, </span><span class="hljs-string">"New"</span><span class="hljs-normal">&#125;, &#123;</span><span class="hljs-string">"onclick"</span><span class="hljs-normal">, </span><span class="hljs-string">"CreateNewDoc()"</span><span class="hljs-normal">&#125;&#125;,</span>
<span class="hljs-normal">                <a href="ffw_Object.html">ffw::Object</a>&#123;&#123;</span><span class="hljs-string">"value"</span><span class="hljs-normal">, </span><span class="hljs-string">"Open"</span><span class="hljs-normal">&#125;, &#123;</span><span class="hljs-string">"onclick"</span><span class="hljs-normal">, </span><span class="hljs-string">"OpenDoc()"</span><span class="hljs-normal">&#125;&#125;,</span>
<span class="hljs-normal">                <a href="ffw_Object.html">ffw::Object</a>&#123;&#123;</span><span class="hljs-string">"value"</span><span class="hljs-normal">, </span><span class="hljs-string">"Close"</span><span class="hljs-normal">&#125;, &#123;</span><span class="hljs-string">"onclick"</span><span class="hljs-normal">, </span><span class="hljs-string">"CloseDoc()"</span><span class="hljs-normal">&#125;&#125;</span>
<span class="hljs-normal">            &#125;&#125;,</span>
<span class="hljs-normal">        &#125;&#125;,</span>
<span class="hljs-normal">    &#125; </span>
<span class="hljs-normal">&#125;;</span>
</div></pre>



Which is equivalent to the following JSON:


<pre><div class="lang-cpp"><span class="hljs-normal">&#123;</span>
<span class="hljs-normal">  "menu": &#123;</span>
<span class="hljs-normal">    "id": "file",</span>
<span class="hljs-normal">    "value": "File",</span>
<span class="hljs-normal">    "popup": &#123;</span>
<span class="hljs-normal">      "menuitem": [</span>
<span class="hljs-normal">        &#123;"value": "New", "onclick": "CreateNewDoc()"&#125;,</span>
<span class="hljs-normal">        &#123;"value": "Open", "onclick": "OpenDoc()"&#125;,</span>
<span class="hljs-normal">        &#123;"value": "Close", "onclick": "CloseDoc()"&#125;</span>
<span class="hljs-normal">      ]</span>
<span class="hljs-normal">    &#125;</span>
<span class="hljs-normal">  &#125;</span>
<span class="hljs-normal">&#125;</span>
</div></pre>



#### What about JSON or XML?


Yes, you can use [ffw::Var](ffw_Var.html) [ffw::Object](ffw_Object.html) and [ffw::Array](ffw_Array.html) to encode (serialize) or decode (deserialize) JSON and XML.

See **[Encode and decode JSON](md_doc_markdown_tutorial-json.html)** and **[Encode and decode XML](md_doc_markdown_tutorial-xml.html)** tutorials. 

