Tutorial: Encode and decode JSON
=================

This tutorial will explain how to decode and encode JSON structure.

**The tutorial uses [ffw::Var](ffw_Var.html) which is essential in the following examples. You must read [Var - JSON-like data structure](md_doc_markdown_tutorial-var.html) tutorial first!**

Make sure you add `finedata` into your linker and add the following headers into your project:


<pre><div class="lang-cpp"><span class="hljs-meta-keyword">#include &lt;<a href="">ffw/math.h</a>&gt;</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span><span class="hljs-meta-keyword">#include &lt;<a href="">ffw/data.h</a>&gt;</span>
</div></pre>



#### Decode JSON the easy way


When decoding a JSON, values are converted into C++ specific data types:


| JSON value | C++ data type   |
|------|------|
| { } | [ffw::Object](ffw_Object.html)  |
| [ ] | [ffw::Array](ffw_Array.html)  |
| "string" | [ffw::Var](ffw_Var.html) as std::string  |
| 123456 | [ffw::Var](ffw_Var.html) as int  |
| 123.456e-10 | [ffw::Var](ffw_Var.html) as float  |
| true false | [ffw::Var](ffw_Var.html) as bool  |
| null | [ffw::Var](ffw_Var.html) as std::nullptr_t  |


The strings that contain unicode characters encoded as '\uXXXX' will be converted into UTF-8

Decoding can be done as the following:


<pre><div class="lang-cpp"><span class="hljs-normal"><a href="ffw_Var.html">ffw::Var</a> json;</span>
<span class="hljs-normal"></span><span class="hljs-keyword">try</span><span class="hljs-normal"> &#123;</span>
<span class="hljs-normal">  json = <a href="ffw.html#6d044655">ffw::decodeJson</a>(</span>
<span class="hljs-normal">    </span><span class="hljs-string">"&#123;\"menu\": &#123;"</span><span class="hljs-normal"></span>
<span class="hljs-normal">    </span><span class="hljs-string">"  \"id\": \"file\","</span><span class="hljs-normal"></span>
<span class="hljs-normal">    </span><span class="hljs-string">"  \"value\": \"File\","</span><span class="hljs-normal"></span>
<span class="hljs-normal">    </span><span class="hljs-string">"  \"popup\": &#123;"</span><span class="hljs-normal"></span>
<span class="hljs-normal">    </span><span class="hljs-string">"     \"menuitem\": ["</span><span class="hljs-normal"></span>
<span class="hljs-normal">    </span><span class="hljs-string">"       &#123;\"value\": \"New\", \"onclick\": \"CreateNewDoc()\"&#125;,"</span><span class="hljs-normal"></span>
<span class="hljs-normal">    </span><span class="hljs-string">"       &#123;\"value\": \"Open\", \"onclick\": \"OpenDoc()\"&#125;,"</span><span class="hljs-normal"></span>
<span class="hljs-normal">    </span><span class="hljs-string">"       &#123;\"value\": \"Close\", \"onclick\": \"CloseDoc()\"&#125;"</span><span class="hljs-normal"></span>
<span class="hljs-normal">    </span><span class="hljs-string">"     ]"</span><span class="hljs-normal"></span>
<span class="hljs-normal">    </span><span class="hljs-string">"  &#125;"</span><span class="hljs-normal"></span>
<span class="hljs-normal">    </span><span class="hljs-string">"&#125;&#125;"</span><span class="hljs-normal"></span>
<span class="hljs-normal">  );</span>
<span class="hljs-normal">&#125; </span><span class="hljs-keyword">catch</span><span class="hljs-normal"> (<a href="ffw_JsonDecodeException.html">ffw::JsonDecodeException</a>&amp; e)&#123;</span>
<span class="hljs-normal">  std::cerr &lt;&lt; </span><span class="hljs-string">"Error while decoding JSON: "</span><span class="hljs-normal"> &lt;&lt; e.what() &lt;&lt; std::endl;</span>
<span class="hljs-normal">  </span><span class="hljs-keyword">return</span><span class="hljs-normal">;</span>
<span class="hljs-normal">&#125;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal"></span><span class="hljs-keyword">try</span><span class="hljs-normal"> &#123;</span>
<span class="hljs-normal">  </span><span class="hljs-comment">// Check if the root element is an object</span><span class="hljs-normal"></span>
<span class="hljs-normal">  std::cout &lt;&lt; json.<a href="ffw_Var.html#2e070581">is</a>&lt;<a href="ffw_Object.html">ffw::Object</a>&gt;() &lt;&lt; std::endl;</span>
<span class="hljs-normal">  </span><span class="hljs-comment">// Prints: "1"</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span>
<span class="hljs-normal">  </span><span class="hljs-comment">// Access key (returns a reference)</span><span class="hljs-normal"></span>
<span class="hljs-normal">  std::cout &lt;&lt; json[</span><span class="hljs-string">"menu"</span><span class="hljs-normal">][</span><span class="hljs-string">"id"</span><span class="hljs-normal">].<a href="ffw_Var.html#1be6ba0e">getAs</a>&lt;std::string&gt;() &lt;&lt; std::endl;</span>
<span class="hljs-normal">  </span><span class="hljs-comment">// Prints: "file"</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span>
<span class="hljs-normal">  </span><span class="hljs-comment">// Exactly same as above, but returns a copy instead</span><span class="hljs-normal"></span>
<span class="hljs-normal">  std::cout &lt;&lt; json[</span><span class="hljs-string">"menu"</span><span class="hljs-normal">][</span><span class="hljs-string">"id"</span><span class="hljs-normal">].<a href="ffw_Var.html#1804ed51">toString</a>() &lt;&lt; std::endl;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">  </span><span class="hljs-comment">// Exactly same as above:</span><span class="hljs-normal"></span>
<span class="hljs-normal">  std::cout &lt;&lt; json.<a href="ffw_Var.html#1be6ba0e">getAs</a>&lt;<a href="ffw_Object.html">ffw::Object</a>&gt;()[</span><span class="hljs-string">"menu"</span><span class="hljs-normal">].getAs&lt;ffw::Object&gt;()[</span><span class="hljs-string">"id"</span><span class="hljs-normal">].toString() &lt;&lt; std::endl;</span>
<span class="hljs-normal">  </span><span class="hljs-comment">// In the previous example, using ["key"] on ffw::Var </span><span class="hljs-normal"></span>
<span class="hljs-normal">  </span><span class="hljs-comment">// will automatically call getAs&lt;ffw::Object&gt;()</span><span class="hljs-normal"></span>
<span class="hljs-normal">  </span><span class="hljs-comment">// Also, using [integer] on ffw::Var will do the same but will cast to ffw::Array</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span>
<span class="hljs-normal">  </span><span class="hljs-comment">// Access a chain of keys</span><span class="hljs-normal"></span>
<span class="hljs-normal">  std::cout &lt;&lt; json[</span><span class="hljs-string">"menu"</span><span class="hljs-normal">][</span><span class="hljs-string">"popup"</span><span class="hljs-normal">][</span><span class="hljs-string">"menuitem"</span><span class="hljs-normal">][2][</span><span class="hljs-string">"value"</span><span class="hljs-normal">].<a href="ffw_Var.html#1be6ba0e">getAs</a>&lt;std::string&gt;() &lt;&lt; std::endl;</span>
<span class="hljs-normal">  </span><span class="hljs-comment">// Prints: "Close"</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span>
<span class="hljs-normal">  </span><span class="hljs-comment">// Check if a specific value is array (can be used to detect int, float, etc...)</span><span class="hljs-normal"></span>
<span class="hljs-normal">  std::cout &lt;&lt; json[</span><span class="hljs-string">"menu"</span><span class="hljs-normal">][</span><span class="hljs-string">"popup"</span><span class="hljs-normal">][</span><span class="hljs-string">"menuitem"</span><span class="hljs-normal">].<a href="ffw_Var.html#2e070581">is</a>&lt;<a href="ffw_Array.html">ffw::Array</a>&gt;() &lt;&lt; std::endl;</span>
<span class="hljs-normal">  </span><span class="hljs-comment">// Prints: "1"</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span>
<span class="hljs-normal">  </span><span class="hljs-comment">// Get a reference for easier access</span><span class="hljs-normal"></span>
<span class="hljs-normal">  <a href="ffw_Array.html">ffw::Array</a>&amp; arr = json[</span><span class="hljs-string">"menu"</span><span class="hljs-normal">][</span><span class="hljs-string">"popup"</span><span class="hljs-normal">][</span><span class="hljs-string">"menuitem"</span><span class="hljs-normal">].<a href="ffw_Var.html#1be6ba0e">getAs</a>&lt;<a href="ffw_Array.html">ffw::Array</a>&gt;();</span>
<span class="hljs-normal">  </span><span class="hljs-comment">// Would throw std::bad_cast if the menuitem is an object instead</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span>
<span class="hljs-normal">  </span><span class="hljs-comment">// Access a value from arr</span><span class="hljs-normal"></span>
<span class="hljs-normal">  std::cout &lt;&lt; arr[2][</span><span class="hljs-string">"value"</span><span class="hljs-normal">].getAs&lt;std::string&gt;() &lt;&lt; std::endl;</span>
<span class="hljs-normal">  </span><span class="hljs-comment">// Prints: "Close"</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span>
<span class="hljs-normal">  </span><span class="hljs-comment">// Access an incorrect data type from arr</span><span class="hljs-normal"></span>
<span class="hljs-normal">  std::cout &lt;&lt; arr[2][</span><span class="hljs-string">"value"</span><span class="hljs-normal">].getAs&lt;</span><span class="hljs-title">int</span><span class="hljs-normal">&gt;() &lt;&lt; std::endl;</span>
<span class="hljs-normal">  </span><span class="hljs-comment">// Throws std::bad_cast</span><span class="hljs-normal"></span>
<span class="hljs-normal">  </span><span class="hljs-comment">// Why? because 2nd menuitem's "value" inside of &#123;"value": "Close", "onclick": "CloseDoc()"&#125;</span><span class="hljs-normal"></span>
<span class="hljs-normal">  </span><span class="hljs-comment">// is not an integer!</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span>
<span class="hljs-normal">  </span><span class="hljs-comment">// To use exceptions while getting keys, use at("key")</span><span class="hljs-normal"></span>
<span class="hljs-normal">  </span><span class="hljs-comment">// Throws std::out_of_range  !!!!</span><span class="hljs-normal"></span>
<span class="hljs-normal">  std::cout &lt;&lt; json.<a href="ffw_Var.html#1be6ba0e">getAs</a>&lt;<a href="ffw_Object.html">ffw::Object</a>&gt;().at(</span><span class="hljs-string">"menu"</span><span class="hljs-normal">).getAs&lt;<a href="ffw_Object.html">ffw::Object</a>&gt;().at(</span><span class="hljs-string">"invalid"</span><span class="hljs-normal">).getAs&lt;std::string&gt;() &lt;&lt; std::endl;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">&#125; </span><span class="hljs-keyword">catch</span><span class="hljs-normal"> (std::exception&amp; e)&#123;</span>
<span class="hljs-normal">  std::cerr &lt;&lt; </span><span class="hljs-string">"Something went wrong while accessing data: "</span><span class="hljs-normal"> &lt;&lt; e.what() &lt;&lt; std::endl;</span>
<span class="hljs-normal">&#125;</span>
</div></pre>



Please note:


* If the decoding fails, an [ffw::JsonDecodeException](ffw_JsonDecodeException.html) is thrown

* The [] operator with std::string assumes that you are trying to get [ffw::Object](ffw_Object.html)

* The [] operator with int assumes that you are trying to get [ffw::Array](ffw_Array.html)




#### Encode JSON the easy way


The following code is a simple way to create a data structure using [ffw::Var](ffw_Var.html) and encoding it as JSON. Note that an exception can be thrown if:


* the root node of the data structure is not object or array

* any of the values contain invalid data type, only the following are valid: ([ffw::Object](ffw_Object.html), [ffw::Array](ffw_Array.html), any signed or unsigned integer, bool, std::string or const char*, any floating point). For example, you can not encode a C++ reference, or pointer, or class, etc...





<pre><div class="lang-cpp"><span class="hljs-normal"><a href="ffw_Object.html">ffw::Object</a> obj = &#123; </span>
<span class="hljs-normal">  </span><span class="hljs-string">"menu"</span><span class="hljs-normal">, <a href="ffw_Object.html">ffw::Object</a>&#123;</span>
<span class="hljs-normal">    &#123;</span><span class="hljs-string">"id"</span><span class="hljs-normal">, </span><span class="hljs-string">"file"</span><span class="hljs-normal">,&#125;,</span>
<span class="hljs-normal">    &#123;</span><span class="hljs-string">"value"</span><span class="hljs-normal">, </span><span class="hljs-string">"File"</span><span class="hljs-normal">,&#125;,</span>
<span class="hljs-normal">    &#123;</span><span class="hljs-string">"popup"</span><span class="hljs-normal">, <a href="ffw_Object.html">ffw::Object</a>&#123;</span>
<span class="hljs-normal">      &#123;</span><span class="hljs-string">"menuitem"</span><span class="hljs-normal">, <a href="ffw_Array.html">ffw::Array</a>&#123;</span>
<span class="hljs-normal">        <a href="ffw_Object.html">ffw::Object</a>&#123;&#123;</span><span class="hljs-string">"value"</span><span class="hljs-normal">, </span><span class="hljs-string">"New"</span><span class="hljs-normal">&#125;, &#123;</span><span class="hljs-string">"onclick"</span><span class="hljs-normal">, </span><span class="hljs-string">"CreateNewDoc()"</span><span class="hljs-normal">&#125;&#125;,</span>
<span class="hljs-normal">        <a href="ffw_Object.html">ffw::Object</a>&#123;&#123;</span><span class="hljs-string">"value"</span><span class="hljs-normal">, </span><span class="hljs-string">"Open"</span><span class="hljs-normal">&#125;, &#123;</span><span class="hljs-string">"onclick"</span><span class="hljs-normal">, </span><span class="hljs-string">"OpenDoc()"</span><span class="hljs-normal">&#125;&#125;,</span>
<span class="hljs-normal">        <a href="ffw_Object.html">ffw::Object</a>&#123;&#123;</span><span class="hljs-string">"value"</span><span class="hljs-normal">, </span><span class="hljs-string">"Close"</span><span class="hljs-normal">&#125;, &#123;</span><span class="hljs-string">"onclick"</span><span class="hljs-normal">, </span><span class="hljs-string">"CloseDoc()"</span><span class="hljs-normal">&#125;&#125;</span>
<span class="hljs-normal">      &#125;&#125;,</span>
<span class="hljs-normal">    &#125;&#125;,</span>
<span class="hljs-normal">  &#125; </span>
<span class="hljs-normal">&#125;;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal"></span><span class="hljs-keyword">try</span><span class="hljs-normal"> &#123;</span>
<span class="hljs-normal">  std::string str = <a href="ffw.html#3b2e9a26">ffw::encodeJson</a>(obj, </span><span class="hljs-string">"    "</span><span class="hljs-normal">, </span><span class="hljs-keyword">false</span><span class="hljs-normal">);</span>
<span class="hljs-normal">  </span><span class="hljs-comment">// If you wish to create compact JSON (no new lines, no indent)</span><span class="hljs-normal"></span>
<span class="hljs-normal">  </span><span class="hljs-comment">// pass NULL as a second parameter!</span><span class="hljs-normal"></span>
<span class="hljs-normal">  </span><span class="hljs-comment">// To escape UTF-8 into unicode \uXXXX symbols, pass 'true'</span><span class="hljs-normal"></span>
<span class="hljs-normal">  </span><span class="hljs-comment">// as a third parameter</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span>
<span class="hljs-normal">&#125; </span><span class="hljs-keyword">catch</span><span class="hljs-normal"> (<a href="ffw_JsonEncodeException.html">ffw::JsonEncodeException</a>&amp; e)&#123;</span>
<span class="hljs-normal">  std::cerr &lt;&lt; </span><span class="hljs-string">"Something went wrong: "</span><span class="hljs-normal"> &lt;&lt; e.what() &lt;&lt; std::endl;</span>
<span class="hljs-normal">  </span><span class="hljs-keyword">return</span><span class="hljs-normal">;</span>
<span class="hljs-normal">&#125;</span>
<span class="hljs-normal"></span><span class="hljs-comment">// To encode JSON in more compact way (no indent, no new lines) </span><span class="hljs-normal"></span>
<span class="hljs-normal"></span><span class="hljs-comment">// replace second parameter with NULL</span>
</div></pre>



Will create the following equivalent JSON structure:


<pre><div class="lang-cpp"><span class="hljs-normal">&#123;"menu": &#123;</span>
<span class="hljs-normal">  "id": "file",</span>
<span class="hljs-normal">  "value": "File",</span>
<span class="hljs-normal">  "popup": &#123;</span>
<span class="hljs-normal">    "menuitem": [</span>
<span class="hljs-normal">      &#123;"value": "New", "onclick": "CreateNewDoc()"&#125;,</span>
<span class="hljs-normal">      &#123;"value": "Open", "onclick": "OpenDoc()"&#125;,</span>
<span class="hljs-normal">      &#123;"value": "Close", "onclick": "CloseDoc()"&#125;</span>
<span class="hljs-normal">    ]</span>
<span class="hljs-normal">  &#125;</span>
<span class="hljs-normal">&#125;&#125;</span>
</div></pre>



Please note:


* Characters such as new-line, quote, apostrophe, cariage-return will be escaped into '\n', '\"', '\'', '\r' and so on.




#### Decode JSON the complicated way


With this method, you can decode JSON by step by step without using [ffw::Var](ffw_Var.html) at all. It grants you the freedom you need. Any of the following commands (except constructor!) can throw [ffw::JsonDecodeException](ffw_JsonDecodeException.html) at any time if the JSON string is broken in any way. Exception is thrown if:


* JSON syntax error

* Unpexpected control or reserved character (for example \p does not exist, but \n \t etc are all good)

* trying to cast from into c++ data type when the JSON value is something completely else (for example, JSON value is clearly a string: "key": "Hello World!" but you try to use value.toInteger() when clearly value.isInteger() gives you false)




Also, note that there is difference between integer, number, float:


* [ffw::JsonReader::Node::isNumber](ffw_JsonReader_Node.html#16955881) returns true if the JSON value is any kind of number (integer or float)

* [ffw::JsonReader::Node::isInteger](ffw_JsonReader_Node.html#4619b816) returns true if the number is not floating point (no decimal point)

* [ffw::JsonReader::Node::isFloat](ffw_JsonReader_Node.html#e80ad8c5) returns true if the number is floating point (has decimal point)





<pre><div class="lang-cpp"><span class="hljs-normal"><a href="ffw_JsonReader.html">ffw::JsonReader</a> json(</span>
<span class="hljs-normal">  </span><span class="hljs-string">"&#123;\"menu\": &#123;"</span><span class="hljs-normal"></span>
<span class="hljs-normal">  </span><span class="hljs-string">"  \"id\": \"file\","</span><span class="hljs-normal"></span>
<span class="hljs-normal">  </span><span class="hljs-string">"  \"value\": \"File\","</span><span class="hljs-normal"></span>
<span class="hljs-normal">  </span><span class="hljs-string">"  \"popup\": &#123;"</span><span class="hljs-normal"></span>
<span class="hljs-normal">  </span><span class="hljs-string">"   \"menuitem\": ["</span><span class="hljs-normal"></span>
<span class="hljs-normal">  </span><span class="hljs-string">"     &#123;\"value\": \"New\", \"onclick\": \"CreateNewDoc()\"&#125;,"</span><span class="hljs-normal"></span>
<span class="hljs-normal">  </span><span class="hljs-string">"     &#123;\"value\": \"Open\", \"onclick\": \"OpenDoc()\"&#125;,"</span><span class="hljs-normal"></span>
<span class="hljs-normal">  </span><span class="hljs-string">"     &#123;\"value\": \"Close\", \"onclick\": \"CloseDoc()\"&#125;"</span><span class="hljs-normal"></span>
<span class="hljs-normal">  </span><span class="hljs-string">"   ]"</span><span class="hljs-normal"></span>
<span class="hljs-normal">  </span><span class="hljs-string">"  &#125;"</span><span class="hljs-normal"></span>
<span class="hljs-normal">  </span><span class="hljs-string">"&#125;&#125;"</span><span class="hljs-normal"></span>
<span class="hljs-normal">);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal"></span><span class="hljs-keyword">try</span><span class="hljs-normal"> &#123;</span>
<span class="hljs-normal">  <a href="ffw_JsonReader_Node.html">ffw::JsonReader::Node</a> value, key;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">  </span><span class="hljs-comment">// Find next available child node, in this case the root element</span><span class="hljs-normal"></span>
<span class="hljs-normal">  json.getNext(&amp;value, &amp;key);</span>
<span class="hljs-normal">  </span><span class="hljs-comment">// key remains unmodified as the root node has no key, only a value: &#123;&#125;</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span>
<span class="hljs-normal">  </span><span class="hljs-comment">// Go inside the root node</span><span class="hljs-normal"></span>
<span class="hljs-normal">  json.stepInto(&amp;value);</span>
<span class="hljs-normal">  json.getCurrentType(); </span><span class="hljs-comment">// Returns ffw::JsonReader::Type::OBJECT</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span>
<span class="hljs-normal">  </span><span class="hljs-comment">// Find "menu" node</span><span class="hljs-normal"></span>
<span class="hljs-normal">  json.getNext(&amp;value, &amp;key);</span>
<span class="hljs-normal">  std::cout &lt;&lt; key.<a href="ffw_JsonReader_Node.html#f75e334c">toString</a>() &lt;&lt; std::endl; </span><span class="hljs-comment">// Prints: "menu"</span><span class="hljs-normal"></span>
<span class="hljs-normal">  value.<a href="ffw_JsonReader_Node.html#d5879ab6">isObject</a>(); </span><span class="hljs-comment">// Returns true</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span>
<span class="hljs-normal">  </span><span class="hljs-comment">// Go inside the "menu" node</span><span class="hljs-normal"></span>
<span class="hljs-normal">  json.stepInto(&amp;value);</span>
<span class="hljs-normal">  json.getCurrentType(); </span><span class="hljs-comment">// Returns ffw::JsonReader::Type::OBJECT</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span>
<span class="hljs-normal">  </span><span class="hljs-comment">// Find "id" node</span><span class="hljs-normal"></span>
<span class="hljs-normal">  json.getNext(&amp;value, &amp;key);</span>
<span class="hljs-normal">  std::cout &lt;&lt; key.<a href="ffw_JsonReader_Node.html#f75e334c">toString</a>() &lt;&lt; std::endl; </span><span class="hljs-comment">// Prints: "id"</span><span class="hljs-normal"></span>
<span class="hljs-normal">  value.<a href="ffw_JsonReader_Node.html#3f512abf">isString</a>(); </span><span class="hljs-comment">// Returns true</span><span class="hljs-normal"></span>
<span class="hljs-normal">  value.<a href="ffw_JsonReader_Node.html#4619b816">isInteger</a>(); </span><span class="hljs-comment">// Returns false</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span>
<span class="hljs-normal">  </span><span class="hljs-comment">// Find "value"</span><span class="hljs-normal"></span>
<span class="hljs-normal">  json.getNext(&amp;value, &amp;key);</span>
<span class="hljs-normal">  std::cout &lt;&lt; key.<a href="ffw_JsonReader_Node.html#f75e334c">toString</a>() &lt;&lt; std::endl; </span><span class="hljs-comment">// Prints: "value"</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span>
<span class="hljs-normal">  </span><span class="hljs-comment">// Find "popup"</span><span class="hljs-normal"></span>
<span class="hljs-normal">  json.getNext(&amp;value, &amp;key);</span>
<span class="hljs-normal">  std::cout &lt;&lt; key.<a href="ffw_JsonReader_Node.html#f75e334c">toString</a>() &lt;&lt; std::endl; </span><span class="hljs-comment">// Prints: "popup"</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span>
<span class="hljs-normal">  </span><span class="hljs-comment">// No next node... Returns FALSE!</span><span class="hljs-normal"></span>
<span class="hljs-normal">  </span><span class="hljs-comment">// The value and key remains unmodified</span><span class="hljs-normal"></span>
<span class="hljs-normal">  json.getNext(&amp;value, &amp;key);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">  </span><span class="hljs-comment">// Step inside of "popup"</span><span class="hljs-normal"></span>
<span class="hljs-normal">  json.stepInto(&amp;value);</span>
<span class="hljs-normal">  json.getCurrentType(); </span><span class="hljs-comment">// Returns ffw::JsonReader::Type::OBJECT</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span>
<span class="hljs-normal">  </span><span class="hljs-comment">// Find "menuitem"</span><span class="hljs-normal"></span>
<span class="hljs-normal">  json.getNext(&amp;value, &amp;key);</span>
<span class="hljs-normal">  std::cout &lt;&lt; key.<a href="ffw_JsonReader_Node.html#f75e334c">toString</a>() &lt;&lt; std::endl; </span><span class="hljs-comment">// Prints: "menuitem"</span><span class="hljs-normal"></span>
<span class="hljs-normal">  value.<a href="ffw_JsonReader_Node.html#03fb5cbc">isArray</a>(); </span><span class="hljs-comment">// Returns true</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span>
<span class="hljs-normal">  </span><span class="hljs-comment">// Step inside of "menuitem"</span><span class="hljs-normal"></span>
<span class="hljs-normal">  json.stepInto(&amp;value);</span>
<span class="hljs-normal">  json.getCurrentType(); </span><span class="hljs-comment">// Returns ffw::JsonReader::Type::ARRAY</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span>
<span class="hljs-normal">  </span><span class="hljs-comment">// Get next available node</span><span class="hljs-normal"></span>
<span class="hljs-normal">  </span><span class="hljs-comment">// Becuase we are inside of an array, the key remains unmodified!</span><span class="hljs-normal"></span>
<span class="hljs-normal">  json.getNext(&amp;value, &amp;key);</span>
<span class="hljs-normal">  </span><span class="hljs-comment">// json.getNext(&amp;value, NULL); // You can pass NULL as a second parameter</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span>
<span class="hljs-normal">  </span><span class="hljs-comment">// Step inside the first node</span><span class="hljs-normal"></span>
<span class="hljs-normal">  json.stepInto(&amp;value);</span>
<span class="hljs-normal">  json.getCurrentType(); </span><span class="hljs-comment">// Returns ffw::JsonReader::Type::OBJECT</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span>
<span class="hljs-normal">  </span><span class="hljs-comment">// Find first value, in this case it is "value"</span><span class="hljs-normal"></span>
<span class="hljs-normal">  json.getNext(&amp;value, &amp;key);</span>
<span class="hljs-normal">  std::cout &lt;&lt; key.<a href="ffw_JsonReader_Node.html#f75e334c">toString</a>() &lt;&lt; std::endl; </span><span class="hljs-comment">// Prints: "value"</span><span class="hljs-normal"></span>
<span class="hljs-normal">  value.<a href="ffw_JsonReader_Node.html#3f512abf">isString</a>(); </span><span class="hljs-comment">// Returns true</span><span class="hljs-normal"></span>
<span class="hljs-normal">  std::cout &lt;&lt; value.<a href="ffw_JsonReader_Node.html#f75e334c">toString</a>() &lt;&lt; std::endl; </span><span class="hljs-comment">// Prints: "New"</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span>
<span class="hljs-normal">  </span><span class="hljs-comment">// Go back one level up...</span><span class="hljs-normal"></span>
<span class="hljs-normal">  json.stepOut();</span>
<span class="hljs-normal">  </span><span class="hljs-comment">// We are back inside of "menuitem" array</span><span class="hljs-normal"></span>
<span class="hljs-normal">  </span><span class="hljs-comment">// The next call of getNext() will return value </span><span class="hljs-normal"></span>
<span class="hljs-normal">  </span><span class="hljs-comment">// pointing to &#123;"value": "Open", "onclick": "OpenDoc()"&#125;</span><span class="hljs-normal"></span>
<span class="hljs-normal">  </span><span class="hljs-comment">// Calling the getNext() would then return the last object in the array.</span><span class="hljs-normal"></span>
<span class="hljs-normal">  </span><span class="hljs-comment">// If you call it once more time, it will return false as there is nothing left.</span><span class="hljs-normal"></span>
<span class="hljs-normal">  </span><span class="hljs-comment">// You can then use json.stepOut() to get back to the "popup" node.</span><span class="hljs-normal"></span>
<span class="hljs-normal">&#125; </span><span class="hljs-keyword">catch</span><span class="hljs-normal"> (<a href="ffw_JsonDecodeException.html">ffw::JsonDecodeException</a>&amp; e)&#123;</span>
<span class="hljs-normal">  std::cerr &lt;&lt; </span><span class="hljs-string">"Something went wrong: "</span><span class="hljs-normal"> &lt;&lt; e.what() &lt;&lt; std::endl;</span>
<span class="hljs-normal">&#125;</span>
</div></pre>



#### Encode JSON the complicated way


This method si very similar to the one above and again, it does not use [ffw::Var](ffw_Var.html) at all. An exception is thrown if:


* adding a node into an object with NULL key

* you call xml.stepOut() too many times

* when there has been an error with the stream




[ffw::JsonWriter](ffw_JsonWriter.html) supports arbitary stream, you can create one based on [ffw::JsonWriter::Stream](ffw_JsonWriter_Stream.html) when you override one simple method. However, [ffw::JsonWriter::StringStream](ffw_JsonWriter_StringStream.html) and [ffw::JsonWriter::FileStream](ffw_JsonWriter_FileStream.html) are provided to you.


<pre><div class="lang-cpp"><span class="hljs-keyword">try</span><span class="hljs-normal"> &#123;</span>
<span class="hljs-normal">  <a href="ffw_JsonWriter_StringStream.html">ffw::JsonWriter::StringStream</a> stream;</span>
<span class="hljs-normal">  <a href="ffw_JsonWriter.html">ffw::JsonWriter</a> json(&amp;stream, </span><span class="hljs-string">"    "</span><span class="hljs-normal">, </span><span class="hljs-keyword">false</span><span class="hljs-normal">);</span>
<span class="hljs-normal">  </span><span class="hljs-comment">// If you wish to create compact JSON (no new lines, no indent)</span><span class="hljs-normal"></span>
<span class="hljs-normal">  </span><span class="hljs-comment">// pass NULL as a second parameter!</span><span class="hljs-normal"></span>
<span class="hljs-normal">  </span><span class="hljs-comment">// To escape UTF-8 into unicode \uXXXX symbols, pass 'true'</span><span class="hljs-normal"></span>
<span class="hljs-normal">  </span><span class="hljs-comment">// as a third parameter</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span>
<span class="hljs-normal">  </span><span class="hljs-comment">// The root object, has no key!</span><span class="hljs-normal"></span>
<span class="hljs-normal">  json.addObject(NULL);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">  </span><span class="hljs-comment">// Add menu object</span><span class="hljs-normal"></span>
<span class="hljs-normal">  json.addObject(</span><span class="hljs-string">"menu"</span><span class="hljs-normal">);</span>
<span class="hljs-normal">  json.addString(</span><span class="hljs-string">"file"</span><span class="hljs-normal">, </span><span class="hljs-string">"id"</span><span class="hljs-normal">);</span>
<span class="hljs-normal">  json.addString(</span><span class="hljs-string">"File"</span><span class="hljs-normal">, </span><span class="hljs-string">"value"</span><span class="hljs-normal">);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">  </span><span class="hljs-comment">// Add popup object</span><span class="hljs-normal"></span>
<span class="hljs-normal">  json.addObject(</span><span class="hljs-string">"popup"</span><span class="hljs-normal">);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">  </span><span class="hljs-comment">// Add menuitem array</span><span class="hljs-normal"></span>
<span class="hljs-normal">  json.addArray(</span><span class="hljs-string">"menuitem"</span><span class="hljs-normal">);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">  </span><span class="hljs-comment">// Add first object</span><span class="hljs-normal"></span>
<span class="hljs-normal">  json.addObject(NULL); </span><span class="hljs-comment">// Key is being ignored inside of array</span><span class="hljs-normal"></span>
<span class="hljs-normal">  json.addString(</span><span class="hljs-string">"New"</span><span class="hljs-normal">, </span><span class="hljs-string">"value"</span><span class="hljs-normal">);</span>
<span class="hljs-normal">  json.addString(</span><span class="hljs-string">"CreateNewDoc()"</span><span class="hljs-normal">, </span><span class="hljs-string">"onclick"</span><span class="hljs-normal">);</span>
<span class="hljs-normal">  json.stepOut(); </span><span class="hljs-comment">// Finish object</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span>
<span class="hljs-normal">  </span><span class="hljs-comment">// Add second object</span><span class="hljs-normal"></span>
<span class="hljs-normal">  json.addObject(NULL); </span><span class="hljs-comment">// Key is being ignored inside of array</span><span class="hljs-normal"></span>
<span class="hljs-normal">  json.addString(</span><span class="hljs-string">"Open"</span><span class="hljs-normal">, </span><span class="hljs-string">"value"</span><span class="hljs-normal">);</span>
<span class="hljs-normal">  json.addString(</span><span class="hljs-string">"OpenDoc()"</span><span class="hljs-normal">, </span><span class="hljs-string">"onclick"</span><span class="hljs-normal">);</span>
<span class="hljs-normal">  json.stepOut(); </span><span class="hljs-comment">// Finish object</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span>
<span class="hljs-normal">  </span><span class="hljs-comment">// Add third object</span><span class="hljs-normal"></span>
<span class="hljs-normal">  json.addObject(NULL); </span><span class="hljs-comment">// Key is being ignored inside of array</span><span class="hljs-normal"></span>
<span class="hljs-normal">  json.addString(</span><span class="hljs-string">"Close"</span><span class="hljs-normal">, </span><span class="hljs-string">"value"</span><span class="hljs-normal">);</span>
<span class="hljs-normal">  json.addString(</span><span class="hljs-string">"CloseDoc()"</span><span class="hljs-normal">, </span><span class="hljs-string">"onclick"</span><span class="hljs-normal">);</span>
<span class="hljs-normal">  json.stepOut(); </span><span class="hljs-comment">// Finish object</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span>
<span class="hljs-normal">  </span><span class="hljs-comment">// To properly finish decoding, we have to step back up to the root!</span><span class="hljs-normal"></span>
<span class="hljs-normal">  </span><span class="hljs-comment">// Otherwise the output would be invalid!</span><span class="hljs-normal"></span>
<span class="hljs-normal">  json.stepOut(); </span><span class="hljs-comment">// We are back at the "menuitem" array, close it</span><span class="hljs-normal"></span>
<span class="hljs-normal">  json.stepOut(); </span><span class="hljs-comment">// We are back at the "popup" object, close it</span><span class="hljs-normal"></span>
<span class="hljs-normal">  json.stepOut(); </span><span class="hljs-comment">// We are back at the "menu" object, close it</span><span class="hljs-normal"></span>
<span class="hljs-normal">  json.stepOut(); </span><span class="hljs-comment">// We are back at the the root, close it</span><span class="hljs-normal"></span>
<span class="hljs-normal">  </span><span class="hljs-comment">// We are done!</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span>
<span class="hljs-normal">  </span><span class="hljs-comment">// Any further call to json.stepOut() would result in exception</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span>
<span class="hljs-normal">  std::cout &lt;&lt; stream.<a href="ffw_JsonWriter_StringStream.html#b0bf021d">get</a>() &lt;&lt; std::endl;</span>
<span class="hljs-normal">&#125; </span><span class="hljs-keyword">catch</span><span class="hljs-normal"> (<a href="ffw_JsonEncodeException.html">ffw::JsonEncodeException</a>&amp; e)&#123;</span>
<span class="hljs-normal">  std::cerr &lt;&lt; </span><span class="hljs-string">"Something went wrong: "</span><span class="hljs-normal"> &lt;&lt; e.what() &lt;&lt; std::endl;</span>
<span class="hljs-normal">&#125;</span>
</div></pre>



Creates the following JSON structure:


<pre><div class="lang-cpp"><span class="hljs-normal">&#123;</span>
<span class="hljs-normal">    "menu":&#123;</span>
<span class="hljs-normal">        "id":"file",</span>
<span class="hljs-normal">        "value":"File",</span>
<span class="hljs-normal">        "popup":&#123;</span>
<span class="hljs-normal">            "menuitem":[</span>
<span class="hljs-normal">                &#123;</span>
<span class="hljs-normal">                    "value":"New",</span>
<span class="hljs-normal">                    "onclick":"CreateNewDoc()"</span>
<span class="hljs-normal">                &#125;,</span>
<span class="hljs-normal">                &#123;</span>
<span class="hljs-normal">                    "value":"Open",</span>
<span class="hljs-normal">                    "onclick":"OpenDoc()"</span>
<span class="hljs-normal">                &#125;,</span>
<span class="hljs-normal">                &#123;</span>
<span class="hljs-normal">                    "value":"Close",</span>
<span class="hljs-normal">                    "onclick":"CloseDoc()"</span>
<span class="hljs-normal">                &#125;</span>
<span class="hljs-normal">            ]</span>
<span class="hljs-normal">        &#125;</span>
<span class="hljs-normal">    &#125;</span>
<span class="hljs-normal">&#125;</span>
</div></pre>

 

