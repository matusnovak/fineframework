Encode and decode XML
=================

This tutorial will explain how to decode and encode XML structure.

**The tutorial uses [ffw::Var](ffw_Var.html) which is essential in the following examples. You must read [Var - JSON-like data structure](md_doc_markdown_tutorial-var.html) tutorial first!**

Make sure you add `finedata` into your linker and add the following headers into your project:


<pre><div class="lang-cpp"></div></pre>



#### Decode XML the easy way


When decoding a XML, values are converted into C++ specific data types:


* All nested objects (object that has at least one child) are converted into [ffw::Object](ffw_Object.html)

* An object that has multiple children with a same tag name is converted into [ffw::Array](ffw_Array.html)

* An object that does not have a child but has at least one attribute is also converted into [ffw::Object](ffw_Object.html)

* An object that has children (or any kind of content) but also has attributes, all of it will go into [ffw::Object](ffw_Object.html), explained below

* Each value (both attributes and content) are tested if they represent a number (floating point or integer), or if they represent a boolean (true/false). However, in JSON, strings are explicitly encoded with quotes. In XML, that does not exist, so there is no simple way to delect if a value is supposed to be a string or something else. The algorithm tries to detect integers, floats, boolean, and if all that fails, it will mark a given value as string. For example: `<value>-123456</value>` is parsed as integer, but `<value>0x123456</value>` is treated as string.




All values (both attributes such as `id="file"` and content `<id>file</id>` ) are converted into C++ data types using [ffw::Var](ffw_Var.html)


| XML Value/Node | C++ data type   |
|------|------|
| <menu><popup>...</popup></menu> | [ffw::Object](ffw_Object.html)  |
| <popup><a></a><a></a><a></a></popup> | [ffw::Array](ffw_Array.html) *  |
| <value>Any kind of UTF-8 text</value> | std::string  |
| <value>-123456e+2</value> | int  |
| <value>-1234.56e+2</value> | float  |
| <value>true</value> | bool  |
| <value>null</value> | std::nullptr_t  |
| <value></value> | std::string **  |



* * An object that contains multiple child objects with a same tag is converted into [ffw::Array](ffw_Array.html)

* ** Empty node is converted into an empty std::string




Decoding can be done as the following:


<pre><div class="lang-cpp"><span class="hljs-normal"><a href="ffw_Var.html">ffw::Var</a> xml;</span>
<span class="hljs-normal"></span><span class="hljs-keyword">try</span><span class="hljs-normal"> &#123;</span>
<span class="hljs-normal">  xml = <a href="ffw.html#39a9cfe3">ffw::decodeXml</a>(</span>
<span class="hljs-normal">    </span><span class="hljs-string">"&lt;menu id=\"file\" value=\"File\"&gt;"</span><span class="hljs-normal"></span>
<span class="hljs-normal">      </span><span class="hljs-string">"&lt;popup&gt;"</span><span class="hljs-normal"></span>
<span class="hljs-normal">        </span><span class="hljs-string">"&lt;menuitem value=\"New\" onclick=\"CreateNewDoc()\" /&gt;"</span><span class="hljs-normal"></span>
<span class="hljs-normal">        </span><span class="hljs-string">"&lt;menuitem value=\"Open\" onclick=\"OpenDoc()\" /&gt;"</span><span class="hljs-normal"></span>
<span class="hljs-normal">        </span><span class="hljs-string">"&lt;menuitem value=\"Close\" onclick=\"CloseDoc()\" /&gt;"</span><span class="hljs-normal"></span>
<span class="hljs-normal">      </span><span class="hljs-string">"&lt;/popup&gt;"</span><span class="hljs-normal"></span>
<span class="hljs-normal">    </span><span class="hljs-string">"&lt;/menu&gt;"</span><span class="hljs-normal"></span>
<span class="hljs-normal">  );</span>
<span class="hljs-normal">&#125; </span><span class="hljs-keyword">catch</span><span class="hljs-normal"> (<a href="ffw_XmlDecodeException.html">ffw::XmlDecodeException</a>&amp; e)&#123;</span>
<span class="hljs-normal">  std::cerr &lt;&lt; </span><span class="hljs-string">"Error while decoding XML: "</span><span class="hljs-normal"> &lt;&lt; e.what() &lt;&lt; std::endl;</span>
<span class="hljs-normal">  </span><span class="hljs-keyword">return</span><span class="hljs-normal">;</span>
<span class="hljs-normal">&#125;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal"></span><span class="hljs-keyword">try</span><span class="hljs-normal"> &#123;</span>
<span class="hljs-normal">  </span><span class="hljs-comment">// Check if the root element is an object</span><span class="hljs-normal"></span>
<span class="hljs-normal">  std::cout &lt;&lt; xml.<a href="ffw_Var.html#2e070581">is</a>&lt;<a href="ffw_Object.html">ffw::Object</a>&gt;() &lt;&lt; std::endl;</span>
<span class="hljs-normal">  </span><span class="hljs-comment">// Prints: "1"</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span>
<span class="hljs-normal">  </span><span class="hljs-comment">// Access key (returns a reference)</span><span class="hljs-normal"></span>
<span class="hljs-normal">  std::cout &lt;&lt; xml[</span><span class="hljs-string">"menu"</span><span class="hljs-normal">][</span><span class="hljs-string">"id"</span><span class="hljs-normal">].<a href="ffw_Var.html#1be6ba0e">getAs</a>&lt;std::string&gt;() &lt;&lt; std::endl;</span>
<span class="hljs-normal">  </span><span class="hljs-comment">// Prints: "file"</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span>
<span class="hljs-normal">  </span><span class="hljs-comment">// Exactly same as above, but returns a copy instead</span><span class="hljs-normal"></span>
<span class="hljs-normal">  std::cout &lt;&lt; xml[</span><span class="hljs-string">"menu"</span><span class="hljs-normal">][</span><span class="hljs-string">"id"</span><span class="hljs-normal">].<a href="ffw_Var.html#1804ed51">toString</a>() &lt;&lt; std::endl;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">  </span><span class="hljs-comment">// Exactly same as above:</span><span class="hljs-normal"></span>
<span class="hljs-normal">  std::cout &lt;&lt; xml.<a href="ffw_Var.html#1be6ba0e">getAs</a>&lt;<a href="ffw_Object.html">ffw::Object</a>&gt;()[</span><span class="hljs-string">"menu"</span><span class="hljs-normal">].getAs&lt;ffw::Object&gt;()[</span><span class="hljs-string">"id"</span><span class="hljs-normal">].toString() &lt;&lt; std::endl;</span>
<span class="hljs-normal">  </span><span class="hljs-comment">// In the previous example, using ["key"] on ffw::Var </span><span class="hljs-normal"></span>
<span class="hljs-normal">  </span><span class="hljs-comment">// will automatically call getAs&lt;ffw::Object&gt;()</span><span class="hljs-normal"></span>
<span class="hljs-normal">  </span><span class="hljs-comment">// Also, using [integer] on ffw::Var will do the same but will cast to ffw::Array</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span>
<span class="hljs-normal">  </span><span class="hljs-comment">// Access a chain of keys</span><span class="hljs-normal"></span>
<span class="hljs-normal">  std::cout &lt;&lt; xml[</span><span class="hljs-string">"menu"</span><span class="hljs-normal">][</span><span class="hljs-string">"popup"</span><span class="hljs-normal">][</span><span class="hljs-string">"menuitem"</span><span class="hljs-normal">][2][</span><span class="hljs-string">"value"</span><span class="hljs-normal">].<a href="ffw_Var.html#1be6ba0e">getAs</a>&lt;std::string&gt;() &lt;&lt; std::endl;</span>
<span class="hljs-normal">  </span><span class="hljs-comment">// Prints: "Close"</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span>
<span class="hljs-normal">  </span><span class="hljs-comment">// Check if a specific value is array (can be used to detect int, float, etc...)</span><span class="hljs-normal"></span>
<span class="hljs-normal">  std::cout &lt;&lt; xml[</span><span class="hljs-string">"menu"</span><span class="hljs-normal">][</span><span class="hljs-string">"popup"</span><span class="hljs-normal">][</span><span class="hljs-string">"menuitem"</span><span class="hljs-normal">].<a href="ffw_Var.html#2e070581">is</a>&lt;<a href="ffw_Array.html">ffw::Array</a>&gt;() &lt;&lt; std::endl;</span>
<span class="hljs-normal">  </span><span class="hljs-comment">// Prints: "1"</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span>
<span class="hljs-normal">  </span><span class="hljs-comment">// Get a reference for easier access</span><span class="hljs-normal"></span>
<span class="hljs-normal">  <a href="ffw_Array.html">ffw::Array</a>&amp; arr = xml[</span><span class="hljs-string">"menu"</span><span class="hljs-normal">][</span><span class="hljs-string">"popup"</span><span class="hljs-normal">][</span><span class="hljs-string">"menuitem"</span><span class="hljs-normal">].<a href="ffw_Var.html#1be6ba0e">getAs</a>&lt;<a href="ffw_Array.html">ffw::Array</a>&gt;();</span>
<span class="hljs-normal">  </span><span class="hljs-comment">// Would throw std::bad_cast if the menuitem is an object instead</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span>
<span class="hljs-normal">  </span><span class="hljs-comment">// Access a value from arr</span><span class="hljs-normal"></span>
<span class="hljs-normal">  std::cout &lt;&lt; arr[2][</span><span class="hljs-string">"value"</span><span class="hljs-normal">].getAs&lt;std::string&gt;() &lt;&lt; std::endl;</span>
<span class="hljs-normal">  </span><span class="hljs-comment">// Prints: "Close"</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span>
<span class="hljs-normal">  </span><span class="hljs-comment">// Access an incorrect data type from arr</span><span class="hljs-normal"></span>
<span class="hljs-normal">  std::cout &lt;&lt; arr[2][</span><span class="hljs-string">"value"</span><span class="hljs-normal">].getAs&lt;</span><span class="hljs-title">int</span><span class="hljs-normal">&gt;() &lt;&lt; std::endl;</span>
<span class="hljs-normal">  </span><span class="hljs-comment">// Throws std::bad_cast</span><span class="hljs-normal"></span>
<span class="hljs-normal">  </span><span class="hljs-comment">// Why? because 2nd menuitem's</span><span class="hljs-normal"></span>
<span class="hljs-normal">  </span><span class="hljs-comment">// "value" inside of &lt;menuitem value="Open" onclick="OpenDoc()" /&gt;</span><span class="hljs-normal"></span>
<span class="hljs-normal">  </span><span class="hljs-comment">// is not an integer!</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span>
<span class="hljs-normal">  </span><span class="hljs-comment">// To use exceptions while getting keys, use at("key")</span><span class="hljs-normal"></span>
<span class="hljs-normal">  </span><span class="hljs-comment">// Throws std::out_of_range !!!!!</span><span class="hljs-normal"></span>
<span class="hljs-normal">  std::cout &lt;&lt; xml.<a href="ffw_Var.html#1be6ba0e">getAs</a>&lt;<a href="ffw_Object.html">ffw::Object</a>&gt;().at(</span><span class="hljs-string">"menu"</span><span class="hljs-normal">).getAs&lt;<a href="ffw_Object.html">ffw::Object</a>&gt;().at(</span><span class="hljs-string">"invalid"</span><span class="hljs-normal">).getAs&lt;std::string&gt;() &lt;&lt; std::endl;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">&#125; </span><span class="hljs-keyword">catch</span><span class="hljs-normal"> (std::exception&amp; e)&#123;</span>
<span class="hljs-normal">  std::cerr &lt;&lt; </span><span class="hljs-string">"Something went wrong while accessing data: "</span><span class="hljs-normal"> &lt;&lt; e.what() &lt;&lt; std::endl;</span>
<span class="hljs-normal">&#125;</span>
</div></pre>



Please note:


* If the decoding fails, an [ffw::XmlDecodeException](ffw_XmlDecodeException.html) is thrown

* The [] operator with std::string assumes that you are trying to get [ffw::Object](ffw_Object.html)

* The [] operator with int assumes that you are trying to get [ffw::Array](ffw_Array.html)




#### Encode XML the wasy way


The following code is a simple way to create a data structure using [ffw::Var](ffw_Var.html) and encoding it as XML. Note that an exception can be thrown if:


* the root node of the data structure is not object, XML has to start with an object!

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
<span class="hljs-normal">  std::string str = <a href="ffw.html#80464558">ffw::encodeXml</a>(obj, </span><span class="hljs-string">"    "</span><span class="hljs-normal">, </span><span class="hljs-keyword">false</span><span class="hljs-normal">);</span>
<span class="hljs-normal">  </span><span class="hljs-comment">// If you wish to create compact XML (no new lines, no indent)</span><span class="hljs-normal"></span>
<span class="hljs-normal">  </span><span class="hljs-comment">// pass NULL as a second parameter!</span><span class="hljs-normal"></span>
<span class="hljs-normal">  </span><span class="hljs-comment">// To escape UTF-8 into unicode &amp;#xXXXX; symbols, pass 'true'</span><span class="hljs-normal"></span>
<span class="hljs-normal">  </span><span class="hljs-comment">// as a third parameter</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span>
<span class="hljs-normal">&#125; </span><span class="hljs-keyword">catch</span><span class="hljs-normal"> (<a href="ffw_XmlEncodeException.html">ffw::XmlEncodeException</a>&amp; e)&#123;</span>
<span class="hljs-normal">  std::cerr &lt;&lt; </span><span class="hljs-string">"Something went wrong: "</span><span class="hljs-normal"> &lt;&lt; e.what() &lt;&lt; std::endl;</span>
<span class="hljs-normal">&#125;</span>
</div></pre>



Will create the following equivalent XML structure:


<pre><div class="lang-cpp"><span class="hljs-normal">&lt;</span><span class="hljs-title">menu</span><span class="hljs-normal">&gt;</span>
<span class="hljs-normal">    &lt;</span><span class="hljs-title">id</span><span class="hljs-normal">&gt;</span><span class="hljs-keyword">file</span><span class="hljs-normal">&lt;/</span><span class="hljs-title">id</span><span class="hljs-normal">&gt;</span>
<span class="hljs-normal">    &lt;</span><span class="hljs-title">value</span><span class="hljs-normal">&gt;</span><span class="hljs-keyword">File</span><span class="hljs-normal">&lt;/</span><span class="hljs-title">value</span><span class="hljs-normal">&gt;</span>
<span class="hljs-normal">    &lt;</span><span class="hljs-title">popup</span><span class="hljs-normal">&gt;</span>
<span class="hljs-normal">        &lt;</span><span class="hljs-title">menuitem</span><span class="hljs-normal">&gt;</span>
<span class="hljs-normal">            &lt;</span><span class="hljs-title">value</span><span class="hljs-normal">&gt;</span><span class="hljs-keyword">New</span><span class="hljs-normal">&lt;/</span><span class="hljs-title">value</span><span class="hljs-normal">&gt;</span>
<span class="hljs-normal">            &lt;</span><span class="hljs-title">onclick</span><span class="hljs-normal">&gt;</span><span class="hljs-keyword">CreateNewDoc</span><span class="hljs-normal">()&lt;/</span><span class="hljs-title">onclick</span><span class="hljs-normal">&gt;</span>
<span class="hljs-normal">        &lt;/</span><span class="hljs-title">menuitem</span><span class="hljs-normal">&gt;</span>
<span class="hljs-normal">        &lt;</span><span class="hljs-title">menuitem</span><span class="hljs-normal">&gt;</span>
<span class="hljs-normal">            &lt;</span><span class="hljs-title">value</span><span class="hljs-normal">&gt;</span><span class="hljs-keyword">Open</span><span class="hljs-normal">&lt;/</span><span class="hljs-title">value</span><span class="hljs-normal">&gt;</span>
<span class="hljs-normal">            &lt;</span><span class="hljs-title">onclick</span><span class="hljs-normal">&gt;</span><span class="hljs-keyword">OpenDoc</span><span class="hljs-normal">()&lt;/</span><span class="hljs-title">onclick</span><span class="hljs-normal">&gt;</span>
<span class="hljs-normal">        &lt;/</span><span class="hljs-title">menuitem</span><span class="hljs-normal">&gt;</span>
<span class="hljs-normal">        &lt;</span><span class="hljs-title">menuitem</span><span class="hljs-normal">&gt;</span>
<span class="hljs-normal">            &lt;</span><span class="hljs-title">value</span><span class="hljs-normal">&gt;</span><span class="hljs-keyword">Close</span><span class="hljs-normal">&lt;/</span><span class="hljs-title">value</span><span class="hljs-normal">&gt;</span>
<span class="hljs-normal">            &lt;</span><span class="hljs-title">onclick</span><span class="hljs-normal">&gt;</span><span class="hljs-keyword">CloseDoc</span><span class="hljs-normal">()&lt;/</span><span class="hljs-title">onclick</span><span class="hljs-normal">&gt;</span>
<span class="hljs-normal">        &lt;/</span><span class="hljs-title">menuitem</span><span class="hljs-normal">&gt;</span>
<span class="hljs-normal">    &lt;/</span><span class="hljs-title">popup</span><span class="hljs-normal">&gt;</span>
<span class="hljs-normal">&lt;/</span><span class="hljs-title">menu</span><span class="hljs-normal">&gt;</span>
</div></pre>



#### Decode XML the complicated way


With this method, you can decode XML by step by step without using [ffw::Var](ffw_Var.html) at all. It grants you the freedom you need. Any of the following commands (including constructor!) can throw [ffw::XmlDecodeException](ffw_XmlDecodeException.html) at any time if the XML string is broken in any way. Exception is thrown if:


* XML syntax error

* trying to cast from into c++ data type when the XML value is something completely else (for example, XML value is clearly a string: <ket>Something</key> but you try to use node.toInt() when clearly node.isInt() gives you false)




Also, note that there is difference between integer, number, float:


* [ffw::XmlReader::Node::isNumber](ffw_XmlReader_Value.html#174680c9) returns true if the XML value is any kind of number (integer or float)

* [ffw::XmlReader::Node::isInteger](ffw_XmlReader_Value.html#ccfb3120) returns true if the number is not floating point (no decimal point)

* [ffw::XmlReader::Node::isFloat](ffw_XmlReader_Value.html#31b732b6) returns true if the number is floating point (has decimal point)




Also, note that [ffw::XmlReader::Node::isString](ffw_XmlReader_Value.html#05622955) returns always true, (but returns false if isEmptr() returns true!) even if toInteger returns true. This is due to the reason that in XML strings are not explicitly written (in syntax form) compared to JSON where we can exactly tell the value is a string.


<pre><div class="lang-cpp"><span class="hljs-normal"><a href="ffw_XmlReader.html">ffw::XmlReader</a> xml(</span>
<span class="hljs-normal">  </span><span class="hljs-string">"&lt;menu id=\"file\" value=\"\"&gt;"</span><span class="hljs-normal"></span>
<span class="hljs-normal">    </span><span class="hljs-string">"&lt;popup&gt;"</span><span class="hljs-normal"></span>
<span class="hljs-normal">      </span><span class="hljs-string">"&lt;menuitem value=\"New\" onclick=\"CreateNewDoc()\" /&gt;"</span><span class="hljs-normal"></span>
<span class="hljs-normal">      </span><span class="hljs-string">"&lt;menuitem value=\"Open\" onclick=\"OpenDoc()\" /&gt;"</span><span class="hljs-normal"></span>
<span class="hljs-normal">      </span><span class="hljs-string">"&lt;menuitem value=\"Close\" onclick=\"CloseDoc()\" /&gt;"</span><span class="hljs-normal"></span>
<span class="hljs-normal">    </span><span class="hljs-string">"&lt;/popup&gt;"</span><span class="hljs-normal"></span>
<span class="hljs-normal">  </span><span class="hljs-string">"&lt;/menu&gt;"</span><span class="hljs-normal"></span>
<span class="hljs-normal">);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal"></span><span class="hljs-keyword">try</span><span class="hljs-normal"> &#123;</span>
<span class="hljs-normal">  <a href="ffw_XmlReader_Node.html">ffw::XmlReader::Node</a> node;</span>
<span class="hljs-normal">  <a href="ffw_XmlReader_Attribute.html">ffw::XmlReader::Attribute</a> attr;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">  </span><span class="hljs-comment">// Get "menu"</span><span class="hljs-normal"></span>
<span class="hljs-normal">  xml.getNext(&amp;node);</span>
<span class="hljs-normal">  std::cout &lt;&lt; node.<a href="ffw_XmlReader_Node.html#caf37a16">name</a>() &lt;&lt; std::endl; </span><span class="hljs-comment">// Prints "menu"</span><span class="hljs-normal"></span>
<span class="hljs-normal">  node.<a href="ffw_XmlReader_Node.html#329452d5">hasAttributes</a>(); </span><span class="hljs-comment">// Returns true</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span>
<span class="hljs-normal">  node.<a href="ffw_XmlReader_Node.html#209ff6f2">getNextAttribute</a>(&amp;attr);</span>
<span class="hljs-normal">  attr.<a href="ffw_XmlReader_Value.html#05622955">isString</a>(); </span><span class="hljs-comment">// Returns true</span><span class="hljs-normal"></span>
<span class="hljs-normal">  attr.<a href="ffw_XmlReader_Value.html#955a5a59">isEmpty</a>(); </span><span class="hljs-comment">// Returns false</span><span class="hljs-normal"></span>
<span class="hljs-normal">  std::cout &lt;&lt; attr.<a href="ffw_XmlReader_Attribute.html#b7a13cc2">name</a>() &lt;&lt; </span><span class="hljs-string">"="</span><span class="hljs-normal"> &lt;&lt; attr.<a href="ffw_XmlReader_Value.html#67029414">toString</a>() &lt;&lt; std::endl; </span>
<span class="hljs-normal">  </span><span class="hljs-comment">// Prints "id=file"</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span>
<span class="hljs-normal">  node.<a href="ffw_XmlReader_Node.html#209ff6f2">getNextAttribute</a>(&amp;attr);</span>
<span class="hljs-normal">  std::cout &lt;&lt; attr.<a href="ffw_XmlReader_Value.html#955a5a59">isEmpty</a>() &lt;&lt; </span><span class="hljs-string">", "</span><span class="hljs-normal"> &lt;&lt; attr.<a href="ffw_XmlReader_Value.html#05622955">isString</a>() &lt;&lt; std::endl;</span>
<span class="hljs-normal">  attr.<a href="ffw_XmlReader_Value.html#05622955">isString</a>(); </span><span class="hljs-comment">// Returns false</span><span class="hljs-normal"></span>
<span class="hljs-normal">  attr.<a href="ffw_XmlReader_Value.html#955a5a59">isEmpty</a>(); </span><span class="hljs-comment">// Returns true</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span>
<span class="hljs-normal">  </span><span class="hljs-comment">// Go inside of "menu"</span><span class="hljs-normal"></span>
<span class="hljs-normal">  xml.stepInto(&amp;node);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">  </span><span class="hljs-comment">// Find "popup"</span><span class="hljs-normal"></span>
<span class="hljs-normal">  xml.getNext(&amp;node);</span>
<span class="hljs-normal">  std::cout &lt;&lt; node.<a href="ffw_XmlReader_Node.html#caf37a16">name</a>() &lt;&lt; std::endl; </span><span class="hljs-comment">// Prints "popup"</span><span class="hljs-normal"></span>
<span class="hljs-normal">  node.<a href="ffw_XmlReader_Node.html#646813f4">isObject</a>(); </span><span class="hljs-comment">// Returns true because it has many child nodes</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span>
<span class="hljs-normal">  </span><span class="hljs-comment">// Go inside of "popup"</span><span class="hljs-normal"></span>
<span class="hljs-normal">  xml.stepInto(&amp;node);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">  </span><span class="hljs-comment">// Find first "menuitem"</span><span class="hljs-normal"></span>
<span class="hljs-normal">  xml.getNext(&amp;node);</span>
<span class="hljs-normal">  std::cout &lt;&lt; node.<a href="ffw_XmlReader_Node.html#caf37a16">name</a>() &lt;&lt; std::endl; </span><span class="hljs-comment">// Prints "menuitem"</span><span class="hljs-normal"></span>
<span class="hljs-normal">  node.<a href="ffw_XmlReader_Node.html#646813f4">isObject</a>(); </span><span class="hljs-comment">// Returns false, no child nodes</span><span class="hljs-normal"></span>
<span class="hljs-normal">  node.<a href="ffw_XmlReader_Value.html#955a5a59">isEmpty</a>(); </span><span class="hljs-comment">// Returns true, does not contain anything</span><span class="hljs-normal"></span>
<span class="hljs-normal">  node.<a href="ffw_XmlReader_Node.html#329452d5">hasAttributes</a>(); </span><span class="hljs-comment">// Returns true, the node has 2 attributes</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span>
<span class="hljs-normal">  node.<a href="ffw_XmlReader_Node.html#209ff6f2">getNextAttribute</a>(&amp;attr);</span>
<span class="hljs-normal">  attr.<a href="ffw_XmlReader_Value.html#05622955">isString</a>(); </span><span class="hljs-comment">// Returns true</span><span class="hljs-normal"></span>
<span class="hljs-normal">  std::cout &lt;&lt; attr.<a href="ffw_XmlReader_Attribute.html#b7a13cc2">name</a>() &lt;&lt; </span><span class="hljs-string">"="</span><span class="hljs-normal"> &lt;&lt; attr.<a href="ffw_XmlReader_Value.html#67029414">toString</a>() &lt;&lt; std::endl; </span>
<span class="hljs-normal">  </span><span class="hljs-comment">// Prints "value=New"</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span>
<span class="hljs-normal">  node.<a href="ffw_XmlReader_Node.html#209ff6f2">getNextAttribute</a>(&amp;attr);</span>
<span class="hljs-normal">  attr.<a href="ffw_XmlReader_Value.html#05622955">isString</a>(); </span><span class="hljs-comment">// Returns true</span><span class="hljs-normal"></span>
<span class="hljs-normal">  std::cout &lt;&lt; attr.<a href="ffw_XmlReader_Attribute.html#b7a13cc2">name</a>() &lt;&lt; </span><span class="hljs-string">"="</span><span class="hljs-normal"> &lt;&lt; attr.<a href="ffw_XmlReader_Value.html#67029414">toString</a>() &lt;&lt; std::endl; </span>
<span class="hljs-normal">  </span><span class="hljs-comment">// Prints "onclick=CreateNewDoc()"</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span>
<span class="hljs-normal">  node.<a href="ffw_XmlReader_Node.html#209ff6f2">getNextAttribute</a>(&amp;attr); </span><span class="hljs-comment">// Returns false, no another attribute</span><span class="hljs-normal"></span>
<span class="hljs-normal">  </span><span class="hljs-comment">// attr remains unmodified!</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span>
<span class="hljs-normal">  </span><span class="hljs-comment">// Go back into the parent node</span><span class="hljs-normal"></span>
<span class="hljs-normal">  xml.stepOut();</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">  </span><span class="hljs-comment">// Find second "menuitem"</span><span class="hljs-normal"></span>
<span class="hljs-normal">  xml.getNext(&amp;node);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">  </span><span class="hljs-comment">// Find third (last) "menuitem"</span><span class="hljs-normal"></span>
<span class="hljs-normal">  xml.getNext(&amp;node);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">  xml.getNext(&amp;node); </span><span class="hljs-comment">// Returns false, no more neighbour nodes</span><span class="hljs-normal"></span>
<span class="hljs-normal">&#125; </span><span class="hljs-keyword">catch</span><span class="hljs-normal"> (<a href="ffw_XmlEncodeException.html">ffw::XmlEncodeException</a>&amp; e)&#123;</span>
<span class="hljs-normal">  std::cerr &lt;&lt; </span><span class="hljs-string">"Something went wrong: "</span><span class="hljs-normal"> &lt;&lt; e.what() &lt;&lt; std::endl;</span>
<span class="hljs-normal">&#125;</span>
</div></pre>



#### Encode XML the complicated way


This method si very similar to the one above and again, it does not use [ffw::Var](ffw_Var.html) at all. An exception is thrown if:


* xml tag name is invalid

* you call xml.stepOut() too many times

* you do not call xml.beginContent() before adding new object

* when there has been an error with the stream




[ffw::XmlWriter](ffw_XmlWriter.html) supports arbitary stream, you can create one based on [ffw::XmlWriter::Stream](ffw_XmlWriter_Stream.html) when you override one simple method. However, [ffw::XmlWriter::StringStream](ffw_XmlWriter_StringStream.html) and [ffw::XmlWriter::FileStream](ffw_XmlWriter_FileStream.html) are provided to you.


<pre><div class="lang-cpp"><span class="hljs-keyword">try</span><span class="hljs-normal"> &#123;</span>
<span class="hljs-normal">  <a href="ffw_XmlWriter_StringStream.html">ffw::XmlWriter::StringStream</a> stream;</span>
<span class="hljs-normal">  <a href="ffw_XmlWriter.html">ffw::XmlWriter</a> xml(&amp;stream, </span><span class="hljs-string">"    "</span><span class="hljs-normal">, </span><span class="hljs-keyword">false</span><span class="hljs-normal">);</span>
<span class="hljs-normal">  </span><span class="hljs-comment">// If you wish to create compact XML (no new lines, no indent)</span><span class="hljs-normal"></span>
<span class="hljs-normal">  </span><span class="hljs-comment">// pass NULL as a second parameter!</span><span class="hljs-normal"></span>
<span class="hljs-normal">  </span><span class="hljs-comment">// To escape UTF-8 into unicode &amp;#xXXXX; symbols, pass 'true'</span><span class="hljs-normal"></span>
<span class="hljs-normal">  </span><span class="hljs-comment">// as a third parameter</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span>
<span class="hljs-normal">  </span><span class="hljs-comment">// Constructs &lt;menu&gt; with two attributes</span><span class="hljs-normal"></span>
<span class="hljs-normal">  xml.addObject(</span><span class="hljs-string">"menu"</span><span class="hljs-normal">);</span>
<span class="hljs-normal">  xml.addString(</span><span class="hljs-string">"file"</span><span class="hljs-normal">, </span><span class="hljs-string">"id"</span><span class="hljs-normal">);</span>
<span class="hljs-normal">  </span><span class="hljs-comment">// Ensures that the &lt;menu&gt; tag is properly closed!</span><span class="hljs-normal"></span>
<span class="hljs-normal">  xml.beginContent();</span>
<span class="hljs-normal">  xml.addString(</span><span class="hljs-string">"File"</span><span class="hljs-normal">, </span><span class="hljs-string">"value"</span><span class="hljs-normal">);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">  </span><span class="hljs-comment">// Constructs &lt;popup&gt; tag</span><span class="hljs-normal"></span>
<span class="hljs-normal">  xml.addObject(</span><span class="hljs-string">"popup"</span><span class="hljs-normal">);</span>
<span class="hljs-normal">  xml.beginContent();</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">  </span><span class="hljs-comment">// Constricts first &lt;menuitem&gt; tag</span><span class="hljs-normal"></span>
<span class="hljs-normal">  xml.addObject(</span><span class="hljs-string">"menuitem"</span><span class="hljs-normal">);</span>
<span class="hljs-normal">  xml.addString(</span><span class="hljs-string">"New"</span><span class="hljs-normal">, </span><span class="hljs-string">"value"</span><span class="hljs-normal">);</span>
<span class="hljs-normal">  xml.addString(</span><span class="hljs-string">"CreateNewDoc()"</span><span class="hljs-normal">, </span><span class="hljs-string">"onclick"</span><span class="hljs-normal">);</span>
<span class="hljs-normal">  xml.stepOut();</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">  </span><span class="hljs-comment">// Constricts second &lt;menuitem&gt; tag</span><span class="hljs-normal"></span>
<span class="hljs-normal">  xml.addObject(</span><span class="hljs-string">"menuitem"</span><span class="hljs-normal">);</span>
<span class="hljs-normal">  xml.addString(</span><span class="hljs-string">"Open"</span><span class="hljs-normal">, </span><span class="hljs-string">"value"</span><span class="hljs-normal">);</span>
<span class="hljs-normal">  xml.addString(</span><span class="hljs-string">"OpenDoc()"</span><span class="hljs-normal">, </span><span class="hljs-string">"onclick"</span><span class="hljs-normal">);</span>
<span class="hljs-normal">  xml.stepOut();</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">  </span><span class="hljs-comment">// Constricts third &lt;menuitem&gt; tag</span><span class="hljs-normal"></span>
<span class="hljs-normal">  xml.addObject(</span><span class="hljs-string">"menuitem"</span><span class="hljs-normal">);</span>
<span class="hljs-normal">  xml.addString(</span><span class="hljs-string">"Close"</span><span class="hljs-normal">, </span><span class="hljs-string">"value"</span><span class="hljs-normal">);</span>
<span class="hljs-normal">  xml.addString(</span><span class="hljs-string">"CloseDoc()"</span><span class="hljs-normal">, </span><span class="hljs-string">"onclick"</span><span class="hljs-normal">);</span>
<span class="hljs-normal">  xml.stepOut();</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">  </span><span class="hljs-comment">// Ends &lt;popup&gt; tag</span><span class="hljs-normal"></span>
<span class="hljs-normal">  xml.stepOut();</span>
<span class="hljs-normal">  </span><span class="hljs-comment">// Ends &lt;menu&gt; tag</span><span class="hljs-normal"></span>
<span class="hljs-normal">  xml.stepOut();</span>
<span class="hljs-normal">  </span><span class="hljs-comment">// We are done!</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span>
<span class="hljs-normal">  </span><span class="hljs-comment">// Any further call to xml.stepOut() would result in exception</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span>
<span class="hljs-normal">  std::cout &lt;&lt; stream.<a href="ffw_XmlWriter_StringStream.html#a594c552">get</a>() &lt;&lt; std::endl;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">&#125; </span><span class="hljs-keyword">catch</span><span class="hljs-normal"> (<a href="ffw_XmlEncodeException.html">ffw::XmlEncodeException</a>&amp; e)&#123;</span>
<span class="hljs-normal">  std::cerr &lt;&lt; </span><span class="hljs-string">"Something went wrong: "</span><span class="hljs-normal"> &lt;&lt; e.what() &lt;&lt; std::endl;</span>
<span class="hljs-normal">&#125;</span>
</div></pre>



Creates the following XML structure:


<pre><div class="lang-cpp"><span class="hljs-normal">&lt;</span><span class="hljs-title">menu</span><span class="hljs-normal"> </span><span class="hljs-keyword">id</span><span class="hljs-normal">=</span><span class="hljs-string">"file"</span><span class="hljs-normal">&gt;</span>
<span class="hljs-normal">    &lt;</span><span class="hljs-title">value</span><span class="hljs-normal">&gt;</span><span class="hljs-keyword">File</span><span class="hljs-normal">&lt;/</span><span class="hljs-title">value</span><span class="hljs-normal">&gt;</span>
<span class="hljs-normal">    &lt;</span><span class="hljs-title">popup</span><span class="hljs-normal">&gt;</span>
<span class="hljs-normal">        &lt;</span><span class="hljs-title">menuitem</span><span class="hljs-normal"> </span><span class="hljs-keyword">value</span><span class="hljs-normal">=</span><span class="hljs-string">"New"</span><span class="hljs-normal"> </span><span class="hljs-keyword">onclick</span><span class="hljs-normal">=</span><span class="hljs-string">"CreateNewDoc()"</span><span class="hljs-normal">/&gt;</span>
<span class="hljs-normal">        &lt;</span><span class="hljs-title">menuitem</span><span class="hljs-normal"> </span><span class="hljs-keyword">value</span><span class="hljs-normal">=</span><span class="hljs-string">"Open"</span><span class="hljs-normal"> </span><span class="hljs-keyword">onclick</span><span class="hljs-normal">=</span><span class="hljs-string">"OpenDoc()"</span><span class="hljs-normal">/&gt;</span>
<span class="hljs-normal">        &lt;</span><span class="hljs-title">menuitem</span><span class="hljs-normal"> </span><span class="hljs-keyword">value</span><span class="hljs-normal">=</span><span class="hljs-string">"Close"</span><span class="hljs-normal"> </span><span class="hljs-keyword">onclick</span><span class="hljs-normal">=</span><span class="hljs-string">"CloseDoc()"</span><span class="hljs-normal">/&gt;</span>
<span class="hljs-normal">    &lt;/</span><span class="hljs-title">popup</span><span class="hljs-normal">&gt;</span>
<span class="hljs-normal">&lt;/</span><span class="hljs-title">menu</span><span class="hljs-normal">&gt;</span>
</div></pre>

 

