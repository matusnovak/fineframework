Tutorial: Decode CSV
=================

This tutorial will explain how to decode CSV structure.

**The tutorial uses [ffw::Var](ffw_Var.html) which is essential in the following examples. You must read [Var - JSON-like data structure](md_doc_markdown_tutorial-var.html) tutorial first!**

Make sure you add `finedata` into your linker and add the following headers into your project:


<pre><div class="lang-cpp"><span class="hljs-meta-keyword">#include &lt;<a href="">ffw/math.h</a>&gt;</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span><span class="hljs-meta-keyword">#include &lt;<a href="">ffw/data.h</a>&gt;</span>
</div></pre>



#### Decode CSV with one function



<pre><div class="lang-cpp"><span class="hljs-comment">// Make sure the lines are separated by \n !!!</span><span class="hljs-normal"></span>
<span class="hljs-normal">std::string str =</span>
<span class="hljs-normal">    </span><span class="hljs-string">"Year,Make,Model,length\n\</span>
<span class="hljs-string">    1997,Ford,E350,2.34\n\</span>
<span class="hljs-string">    2000,Mercury,Cougar,2.38"</span><span class="hljs-normal">;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal"><a href="ffw_Array.html">ffw::Array</a> arr = <a href="ffw.html#b7bf6532">ffw::decodeCsv</a>(str);</span>
<span class="hljs-normal"></span><span class="hljs-comment">// No exceptions here!</span>
</div></pre>



This will return an [ffw::Array](ffw_Array.html) that contains multiple [ffw::Array](ffw_Array.html) (s).


<pre><div class="lang-cpp"><span class="hljs-normal">std::cout &lt;&lt; arr.<a href="ffw_Array.html#d6795244">size</a>() &lt;&lt; std::endl;</span>
</div></pre>



This will print number 3 as there are only 3 lines in the source CSV. it is guaranteed that each element of the `arr` will contain [ffw::Array](ffw_Array.html) and nothing else!


<pre><div class="lang-cpp"><span class="hljs-normal">std::cout &lt;&lt; arr[0].<a href="ffw_Array.html#d6795244">size</a>() &lt;&lt; std::endl;</span>
</div></pre>



This will print number 4 becuase there are 4 items in the first row. Now, to access individual items...


<pre><div class="lang-cpp"><span class="hljs-comment">// We do not care about the first row, it's a header... </span><span class="hljs-normal"></span>
<span class="hljs-normal"></span><span class="hljs-comment">// Most CSV files contain a header</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span>
<span class="hljs-normal"></span><span class="hljs-comment">// Returns false becuase the "1997" is not a string</span><span class="hljs-normal"></span>
<span class="hljs-normal">arr[1][0].is&lt;std::string&gt;(); </span><span class="hljs-comment">// arr[1][0].isString(); also works!</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span>
<span class="hljs-normal"></span><span class="hljs-comment">// This returns true:</span><span class="hljs-normal"></span>
<span class="hljs-normal">arr[1][0].is&lt;</span><span class="hljs-title">int</span><span class="hljs-normal">&gt;(); </span><span class="hljs-comment">// arr[1][0].isInt(); also works!</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span>
<span class="hljs-normal"></span><span class="hljs-comment">// Prints "Cougar length: 2.38"</span><span class="hljs-normal"></span>
<span class="hljs-normal">std::cout &lt;&lt; </span><span class="hljs-string">"Cougar length: "</span><span class="hljs-normal"> &lt;&lt; arr[2][3].getAs&lt;</span><span class="hljs-title">float</span><span class="hljs-normal">&gt;() &lt;&lt; std::endl;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal"></span><span class="hljs-comment">// However, this will throw std::bad_cast</span><span class="hljs-normal"></span>
<span class="hljs-normal">std::cout &lt;&lt; </span><span class="hljs-string">"Cougar length: "</span><span class="hljs-normal"> &lt;&lt; arr[2][3].getAs&lt;</span><span class="hljs-title">int</span><span class="hljs-normal">&gt;() &lt;&lt; std::endl;</span>
</div></pre>



Why the following two lines below are equal?


<pre><div class="lang-cpp"><span class="hljs-normal">std::cout &lt;&lt; arr[2].getAs&lt;<a href="ffw_Array.html">ffw::Array</a>&gt;()[3].getAs&lt;float&gt;() &lt;&lt; std::endl;</span>
<span class="hljs-normal">std::cout &lt;&lt; arr[2][3].getAs&lt;</span><span class="hljs-title">float</span><span class="hljs-normal">&gt;() &lt;&lt; std::endl;</span>
</div></pre>



In the first line, `arr` is already [ffw::Array](ffw_Array.html). However, [ffw::Array](ffw_Array.html) holds [ffw::Var](ffw_Var.html) which can hold any c++ data type. We know that [ffw::decodeCsv](ffw.html#b7bf6532) returns array of arrays, so it is safe to explicitly call `getAs<[ffw::Array](ffw_Array.html)>()`. The `[3]` returns 4th element and `getAs<float>()` gives us a reference to the float.

The second line does exactly same thing. The [ffw::Var](ffw_Var.html) contains two [ ] operators, one for integers, one for strings. If you call the operator with an integer, it will assume you are trying to get [ffw::Array](ffw_Array.html) and it will call `getAs<[ffw::Array](ffw_Array.html)>()` and `[int]` at the same time for you... it's just for simplicitly. If you would put a string inside the [ ] operator, it will call `getAs<[ffw::Object](ffw_Object.html)>()` which throws std::bad_cast because in this example we are dealing with arrays only, no objects.

#### Decode CSV line by line



<pre><div class="lang-cpp"><span class="hljs-normal"><a href="ffw_Array.html">ffw::Array</a> output;</span>
<span class="hljs-normal"><a href="ffw_CsvLoader.html">ffw::CsvLoader</a> loader;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal"></span><span class="hljs-comment">// First param: file path</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span><span class="hljs-comment">// Second param: delimiter (some CSV use ;) default: ,</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span><span class="hljs-comment">// Third param: how are string represented? default: "</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span><span class="hljs-keyword">if</span><span class="hljs-normal">(!loader.<a href="ffw_CsvLoader.html#b4b6bc9e">openFromFile</a>(</span><span class="hljs-string">"file.csv"</span><span class="hljs-normal">, </span><span class="hljs-string">','</span><span class="hljs-normal">, </span><span class="hljs-string">'\"'</span><span class="hljs-normal">))&#123;</span>
<span class="hljs-normal">  std::cerr &lt;&lt; </span><span class="hljs-string">"File failed to open!"</span><span class="hljs-normal"> &lt;&lt; std::endl;</span>
<span class="hljs-normal">&#125;</span>
<span class="hljs-normal"></span><span class="hljs-keyword">else</span><span class="hljs-normal"> &#123;</span>
<span class="hljs-normal">  </span><span class="hljs-keyword">while</span><span class="hljs-normal">(!loader.<a href="ffw_CsvLoader.html#68e8a838">eof</a>())&#123;</span>
<span class="hljs-normal">    output = loader.<a href="ffw_CsvLoader.html#f16edf3b">getRow</a>(</span><span class="hljs-keyword">true</span><span class="hljs-normal">);</span>
<span class="hljs-normal">  &#125;</span>
<span class="hljs-normal">&#125;</span>
</div></pre>



You can also use `openFromData` which acceps a string instead. The `getRow` acceps one parameter, a boolean. If you pass true, it will convert all items into their type (integer, float, std::string, bool). If you pass false, no conversion is performed and everything is stored in [ffw::Array](ffw_Array.html) as std::string.

#### Decode CSV one line only



<pre><div class="lang-cpp"><span class="hljs-normal">std::string str = </span><span class="hljs-string">"1999,Chevy,\"Venture \"\"Extended Edition, Very Large\"\"\",,5000.00"</span><span class="hljs-normal">;</span>
<span class="hljs-normal"><a href="ffw_Array.html">ffw::Array</a> arr = <a href="ffw_CsvLoader.html#1dd92eb0">ffw::CsvLoader::tokenize</a>(str, 0, str.size(), </span><span class="hljs-keyword">true</span><span class="hljs-normal">, </span><span class="hljs-string">','</span><span class="hljs-normal">, </span><span class="hljs-string">'\"'</span><span class="hljs-normal">);</span>
</div></pre>



The function (static function!) acceps std::string in which you specify the start and the end. Via the 4th parameter you tell it to either decode (true) values into integers, floats, string, etc... or leave everything (false) into std::string. The 5th and 6th specify how are items separated from each other and how are string expressed. Usually in CSV files the items are separated with a comma and strings are enclosed in quotation marks. 

