String tokenizer
=================

This tutorial will explain how to use string tokenizer using [ffw::Tokenizer](ffw_Tokenizer.html) class and [ffw::getTokens](ffw.html#07be8e2c) function. The tokenizer is inside of [math module](group__math.html) which is a header only library. All you need to do is to add `#include <[ffw/math.h]()>` into your project.

#### Tokenizing string with one call



<pre><div class="lang-cpp" style="white-space: nowrap;"><span class="hljs-comment">// The second parameter is the delimiter, based on which the tokenizer</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span><span class="hljs-comment">// will split the source string.</span><span class="hljs-normal"></span>
<span class="hljs-normal">std::vector&lt;std::string&gt; tokens = <a href="ffw.html#07be8e2c">ffw::getTokens</a>(</span><span class="hljs-string">"  Hello    World!  "</span><span class="hljs-normal">, </span><span class="hljs-string">" "</span><span class="hljs-normal">);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal"></span><span class="hljs-comment">// Will return two tokens</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span>
<span class="hljs-normal"></span><span class="hljs-comment">// Do something with tokens</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span><span class="hljs-keyword">for</span><span class="hljs-normal">(</span><span class="hljs-keyword">const</span><span class="hljs-normal"> </span><span class="hljs-keyword">auto</span><span class="hljs-normal">&amp; token : tokens)&#123;</span>
<span class="hljs-normal">  std::cout &lt;&lt; token &lt;&lt; std::endl;</span>
<span class="hljs-normal">&#125;</span>
<span class="hljs-normal"></span><span class="hljs-comment">// Prints:</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span><span class="hljs-comment">// Hello</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span><span class="hljs-comment">// World!</span>
</div></pre>




<pre><div class="lang-cpp" style="white-space: nowrap;"><span class="hljs-comment">// Also works with std::wstring!</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span><span class="hljs-comment">// Will work with any std::basic_string </span><span class="hljs-normal"></span>
<span class="hljs-normal">std::vector&lt;std::wstring&gt; tokens = <a href="ffw.html#07be8e2c">ffw::getTokens</a>(L</span><span class="hljs-string">"xyzHelloxyzWorld!xyzxyz"</span><span class="hljs-normal">, L</span><span class="hljs-string">"xyz"</span><span class="hljs-normal">);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal"></span><span class="hljs-comment">// Returns exactly two tokens</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span>
<span class="hljs-normal"></span><span class="hljs-comment">// Do something with tokens</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span><span class="hljs-keyword">for</span><span class="hljs-normal">(</span><span class="hljs-keyword">const</span><span class="hljs-normal"> </span><span class="hljs-keyword">auto</span><span class="hljs-normal">&amp; token : tokens)&#123;</span>
<span class="hljs-normal">  std::wcout &lt;&lt; token &lt;&lt; std::endl;</span>
<span class="hljs-normal">&#125;</span>
<span class="hljs-normal"></span><span class="hljs-comment">// Prints:</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span><span class="hljs-comment">// Hello</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span><span class="hljs-comment">// World!</span>
</div></pre>



#### Tokenizing with [ffw::Tokenizer](ffw_Tokenizer.html)



<pre><div class="lang-cpp" style="white-space: nowrap;"><span class="hljs-normal">std::string source = </span><span class="hljs-string">"  Hello    World!  "</span><span class="hljs-normal">;</span>
<span class="hljs-normal">std::string delim = </span><span class="hljs-string">" "</span><span class="hljs-normal">;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal"></span><span class="hljs-comment">// Create instance of ffw::Tokenizer.</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span><span class="hljs-comment">// Note that std::string uses "char"!</span><span class="hljs-normal"></span>
<span class="hljs-normal"><a href="ffw_Tokenizer.html">ffw::Tokenizer<char></a> tokenizer(source, </span><span class="hljs-string">" "</span><span class="hljs-normal">);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal"></span><span class="hljs-comment">// Get all tokens</span><span class="hljs-normal"></span>
<span class="hljs-normal">std::string str;</span>
<span class="hljs-normal"></span><span class="hljs-keyword">while</span><span class="hljs-normal">(tokenizer.getNext(&amp;str))&#123;</span>
<span class="hljs-normal">  std::cout &lt;&lt; str &lt;&lt; std::endl;</span>
<span class="hljs-normal">&#125;</span>
<span class="hljs-normal"></span><span class="hljs-comment">// Prints:</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span><span class="hljs-comment">// Hello</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span><span class="hljs-comment">// World!</span>
</div></pre>

 

