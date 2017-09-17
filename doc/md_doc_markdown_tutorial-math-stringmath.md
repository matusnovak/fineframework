Extra string functions
=================

This tutorial will explain how to use some of the additional components of math module regarding string manipulation. The tokenizer is inside of [math module](group__math.html) which is a header only library. All you need to do is to add `#include <[ffw/math.h]()>` into your project.

#### Extract filename/path information


Suppose you have a path to a file and you would like to get its filename and extension.


<pre><div class="lang-cpp" style="white-space: nowrap;"><span class="hljs-normal">std::string path = </span><span class="hljs-string">"C:\Some\Path\To\file.txt"</span><span class="hljs-normal">;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">std::cout &lt;&lt; </span><span class="hljs-string">"Directory: "</span><span class="hljs-normal"> &lt;&lt; <a href="ffw.html#b0d25873">ffw::dirname</a>(path) &lt;&lt; std::endl;</span>
<span class="hljs-normal">std::cout &lt;&lt; </span><span class="hljs-string">"Basename: "</span><span class="hljs-normal"> &lt;&lt; <a href="ffw.html#faaecb7e">ffw::basename</a>(path) &lt;&lt; std::endl;</span>
<span class="hljs-normal">std::cout &lt;&lt; </span><span class="hljs-string">"Extension: "</span><span class="hljs-normal"> &lt;&lt; <a href="ffw.html#9c775320">ffw::extension</a>(path) &lt;&lt; std::endl;</span>
<span class="hljs-normal"></span><span class="hljs-comment">// Prints:</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span><span class="hljs-comment">// Directory: C:\Some\Path\To</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span><span class="hljs-comment">// Basename: file</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span><span class="hljs-comment">// Extension: txt</span>
</div></pre>




<pre><div class="lang-cpp" style="white-space: nowrap;"><span class="hljs-comment">// The following does exactly the same thing as above:</span><span class="hljs-normal"></span>
<span class="hljs-normal">std::string path = </span><span class="hljs-string">"C:\Some\Path\To\file.txt"</span><span class="hljs-normal">;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal"></span><span class="hljs-keyword">auto</span><span class="hljs-normal"> info = <a href="ffw.html#0391411c">ffw::getFileInfo</a>(path);</span>
<span class="hljs-normal">std::cout &lt;&lt; </span><span class="hljs-string">"Directory: "</span><span class="hljs-normal"> &lt;&lt; info.dir &lt;&lt; std::endl;</span>
<span class="hljs-normal">std::cout &lt;&lt; </span><span class="hljs-string">"Basename: "</span><span class="hljs-normal"> &lt;&lt; info.base &lt;&lt; std::endl;</span>
<span class="hljs-normal">std::cout &lt;&lt; </span><span class="hljs-string">"Extension: "</span><span class="hljs-normal"> &lt;&lt; info.ext &lt;&lt; std::endl;</span>
<span class="hljs-normal"></span><span class="hljs-comment">// Prints:</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span><span class="hljs-comment">// Directory: C:\Some\Path\To</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span><span class="hljs-comment">// Basename: file</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span><span class="hljs-comment">// Extension: txt</span>
</div></pre>



#### Convert value to string and back


The [ffw::stringToVal](ffw.html#eebabb4c) works only on integers and floating points!


<pre><div class="lang-cpp" style="white-space: nowrap;"><span class="hljs-normal">std::string msg = </span><span class="hljs-string">"The value is: "</span><span class="hljs-normal">;</span>
<span class="hljs-normal">msg += <a href="ffw.html#c771be1a">ffw::valToString</a>(42.05f);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">std::cout &lt;&lt; msg &lt;&lt; std::endl;</span>
<span class="hljs-normal"></span><span class="hljs-comment">// Prints: "The value is: 42.05"</span>
</div></pre>



To convert from string to any integer/float use [ffw::valToString](ffw.html#c771be1a). Note that you have to supply a data type as a template parameter!


<pre><div class="lang-cpp" style="white-space: nowrap;"><span class="hljs-title">int</span><span class="hljs-normal"> val = <a href="ffw.html#709a0897">ffw::stringToVal<int></a>(</span><span class="hljs-string">"-123456"</span><span class="hljs-normal">);</span>
<span class="hljs-normal">std::cout &lt;&lt; val &lt;&lt; std::endl;</span>
<span class="hljs-normal"></span><span class="hljs-comment">// Prints: "-123456"</span>
</div></pre>



#### Convert from hexadecimal string to int



<pre><div class="lang-cpp" style="white-space: nowrap;"><span class="hljs-title">int</span><span class="hljs-normal"> val = ffw::hexToVal&lt;int&gt;(</span><span class="hljs-string">"FFFF"</span><span class="hljs-normal">);</span>
<span class="hljs-normal">std::cout &lt;&lt; val &lt;&lt; std::endl;</span>
<span class="hljs-normal"></span><span class="hljs-comment">// Prints: "65535"</span>
</div></pre>



#### Convert UTF-8 to std::wstring and back


The std::wstring is not directly meant to be UTF-16 string. However, because wchar can hold up to 65535 (even more on Unix) it is perfect storage for decoding UTF-8 string.


<pre><div class="lang-cpp" style="white-space: nowrap;"><span class="hljs-comment">// String containing 24 UTF-8 enchoded characters </span><span class="hljs-normal"></span>
<span class="hljs-normal">std::string str = </span><span class="hljs-string">"\x48\x65\x69\x7A\xC3\xB6\x6C\x72\xC3\xBC\x63\x6B\x73\x74\x6F\xC3\x9F\x61\x62\x64\xC3\xA4\x6D\x70\x66\x75\x6E\x67"</span><span class="hljs-normal">;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal"></span><span class="hljs-comment">// Convert to multi byte string std::wstring</span><span class="hljs-normal"></span>
<span class="hljs-normal">std::wstring wstr = <a href="ffw.html#e6d56e70">ffw::utf8ToWstr</a>(str);</span>
<span class="hljs-normal">std::cout &lt;&lt; </span><span class="hljs-string">"Size: "</span><span class="hljs-normal"> &lt;&lt; wstr.size() &lt;&lt; std::endl;</span>
<span class="hljs-normal">std::cout &lt;&lt; </span><span class="hljs-string">"5th symbol: "</span><span class="hljs-normal"> &lt;&lt; (int)wstr[4] &lt;&lt; std::endl;</span>
<span class="hljs-normal"></span><span class="hljs-comment">// Prints:</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span><span class="hljs-comment">// Size: 24</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span><span class="hljs-comment">// 5th symbol: 246</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span>
<span class="hljs-normal"></span><span class="hljs-comment">// The 5th symbol is composed of two UTf-8 chars: 0xC3 0xB6</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span><span class="hljs-comment">// Which is O-umlaut unicode character U+00F6</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span><span class="hljs-comment">// https://en.wikipedia.org/wiki/%C3%96</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span>
<span class="hljs-normal"></span><span class="hljs-comment">// To convert back, use ffw::wstrToUtf8</span><span class="hljs-normal"></span>
<span class="hljs-normal">std::string test = <a href="ffw.html#4896137e">ffw::wstrToUtf8</a>(wstr);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal"></span><span class="hljs-comment">// Both the source string of UTF-8 characters and the</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span><span class="hljs-comment">// "test" are equal!</span><span class="hljs-normal"></span>
<span class="hljs-normal">std::cout &lt;&lt; </span><span class="hljs-string">"Test: "</span><span class="hljs-normal"> &lt;&lt; (test == str) &lt;&lt; std::endl;</span>
<span class="hljs-normal"></span><span class="hljs-comment">// Prints "1"</span>
</div></pre>

 

