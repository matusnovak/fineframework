Promise
===================================

A simple promise class with chainable lambdas. 

**Inherits from:** [ffw::PromiseI](ffw_PromiseI.html)

The documentation for this class was generated from: `include/ffw/math/promise.h`

## Detailed description

This is a very simple implementation of JavaScript like [Promise](ffw_Promise.html). This promise can accept any kind of template type, including void. Any further chain links can be added by creating new [Promise](ffw_Promise.html) instances using "then" and "fail" (or "thenOrFail") methods. The template type of those new chain links is defined based on the return type of the lambda methods passed into "then" and "fail" methods. 
<pre><div class="lang-cpp" style="white-space: pre-wrap;"><span class="hljs-comment">// Using lambda for the first promise is optional! </span><span class="hljs-normal"></span>
<span class="hljs-normal"></span><span class="hljs-comment">// You can always resolve promise outside!</span><span class="hljs-normal"></span>
<span class="hljs-normal"><a href="ffw_Promise.html">ffw::Promise<void></a> promise([](<a href="ffw_Promise.html">ffw::Promise<void></a>&amp; </span><span class="hljs-keyword">self</span><span class="hljs-normal">) -&gt; </span><span class="hljs-title">void</span><span class="hljs-normal"> &#123;</span>
<span class="hljs-normal">    </span><span class="hljs-comment">// Do some work</span><span class="hljs-normal"></span>
<span class="hljs-normal">    </span><span class="hljs-keyword">self</span><span class="hljs-normal">.resolve();</span>
<span class="hljs-normal">&#125;);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal"><a href="ffw_Promise.html">ffw::Promise<float></a> last = promise.<a href="ffw_Promise.html#43e473b8">then</a>([]() &#123;</span>
<span class="hljs-normal">    </span><span class="hljs-comment">// I am the first chain block to be executed</span><span class="hljs-normal"></span>
<span class="hljs-normal">    </span><span class="hljs-comment">// and I will produce std::string</span><span class="hljs-normal"></span>
<span class="hljs-normal">    </span><span class="hljs-keyword">return</span><span class="hljs-normal"> std::string(</span><span class="hljs-string">"Hello World!"</span><span class="hljs-normal">);</span>
<span class="hljs-normal">&#125;).<a href="ffw_Promise.html#43e473b8">then</a>([](std::string str) &#123;</span>
<span class="hljs-normal">    </span><span class="hljs-comment">// I am the second block</span><span class="hljs-normal"></span>
<span class="hljs-normal">    </span><span class="hljs-comment">// and I must accept std::string because the previous</span><span class="hljs-normal"></span>
<span class="hljs-normal">    </span><span class="hljs-comment">// chain link produces std::string</span><span class="hljs-normal"></span>
<span class="hljs-normal">    </span><span class="hljs-comment">// But I will produce size_t</span><span class="hljs-normal"></span>
<span class="hljs-normal">    </span><span class="hljs-keyword">return</span><span class="hljs-normal"> str.size();</span>
<span class="hljs-normal">&#125;).<a href="ffw_Promise.html#43e473b8">then</a>([](</span><span class="hljs-title">size_t</span><span class="hljs-normal"> len) &#123;</span>
<span class="hljs-normal">    </span><span class="hljs-comment">// I am the third block</span><span class="hljs-normal"></span>
<span class="hljs-normal">    </span><span class="hljs-comment">// I must accept size_t but I will cast it to int for no reason</span><span class="hljs-normal"></span>
<span class="hljs-normal">    </span><span class="hljs-keyword">return</span><span class="hljs-normal"> </span><span class="hljs-keyword">static_cast&lt;</span><span class="hljs-title">int</span><span class="hljs-keyword">&gt;</span><span class="hljs-normal">(len);</span>
<span class="hljs-normal">&#125;).<a href="ffw_Promise.html#83e8d83b">fail</a>([](std::exception&amp; e)&#123;</span>
<span class="hljs-normal">    </span><span class="hljs-comment">// I am the fail block</span><span class="hljs-normal"></span>
<span class="hljs-normal">    </span><span class="hljs-comment">// I will be executed if any of the blocks above (or parent promise)</span><span class="hljs-normal"></span>
<span class="hljs-normal">    </span><span class="hljs-comment">// produces exception that matches my lambda argument!</span><span class="hljs-normal"></span>
<span class="hljs-normal">    </span><span class="hljs-comment">// However, I can't return anything! But the Promise chain link I produce</span><span class="hljs-normal"></span>
<span class="hljs-normal">    </span><span class="hljs-comment">// matches the one before me, so anything after me is type of integer!</span><span class="hljs-normal"></span>
<span class="hljs-normal">&#125;).<a href="ffw_Promise.html#43e473b8">then</a>([](</span><span class="hljs-title">int</span><span class="hljs-normal"> val) &#123;</span>
<span class="hljs-normal">    </span><span class="hljs-comment">// I am the last final block and I must accept integer!</span><span class="hljs-normal"></span>
<span class="hljs-normal">    </span><span class="hljs-comment">// However, I will produce float...</span><span class="hljs-normal"></span>
<span class="hljs-normal">    </span><span class="hljs-keyword">return</span><span class="hljs-normal"> float(val * val);</span>
<span class="hljs-normal">&#125;);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">promise.call(); </span><span class="hljs-comment">// Calls the promise lambda inside of it</span><span class="hljs-normal"></span>
<span class="hljs-normal">std::cout &lt;&lt; </span><span class="hljs-string">"Resolved with: "</span><span class="hljs-normal"> &lt;&lt; last.<a href="ffw_Promise.html#867c4ace">getResult</a>() &lt;&lt; std::endl;</span>
<span class="hljs-normal"></span><span class="hljs-comment">// Prints: "Resolved with: 144"</span>
</div></pre>

 


## Classes

| Name |
|:-----|
| struct [ffw::Promise::arg1_traits_impl](ffw_Promise_arg1_traits_impl.html) |
| struct [ffw::Promise::arg1_traits_impl< R(C::*)(A1) const  >](ffw_Promise_arg1_traits_impl__R_C_____A1__const___.html) |
| struct [ffw::Promise::arg1_traits_impl< R(C::*)(A1)>](ffw_Promise_arg1_traits_impl__R_C_____A1__.html) |
| struct [ffw::Promise::arg1_traits_impl< R(C::*)(void) const  >](ffw_Promise_arg1_traits_impl__R_C_____void__const___.html) |
| struct [ffw::Promise::arg1_traits_impl< R(C::*)(void)>](ffw_Promise_arg1_traits_impl__R_C_____void__.html) |
| struct [ffw::Promise::SharedData](ffw_Promise_SharedData.html) |


## Public Static Functions

| Type | Name |
| -------: | :------- |
|  [arg1_traits_impl](ffw_Promise_arg1_traits_impl.html)< TT >::arg1_type | [arg1_type_helper](#8a159389) (TT)  |


## Public Functions

| Type | Name |
| -------: | :------- |
|   | [Promise](#fc73ee8d) () <div style="opacity:0.8;">Default constructor with no lambda function. </div> |
|   | [Promise](#32e21e29) (F const & _lambda_) <div style="opacity:0.8;">Constructor that accepts lambda. </div> |
|   | [Promise](#06f4ff0a) (const [Promise](ffw_Promise.html)< T > & _other_) <div style="opacity:0.8;">Copy constructor. </div> |
|  [Promise](ffw_Promise.html)< T > & | [operator=](#73adf2a6) (const [Promise](ffw_Promise.html)< T > & _other_) <div style="opacity:0.8;">Copy operator. </div> |
|  const std::exception_ptr & | [getException](#da619b4e) () <div style="opacity:0.8;">Returns the exception associated with this promise. </div> |
|  void | [resolve](#f9f6ea9a) () <div style="opacity:0.8;">Resolves the promise with a default value of type T. </div> |
|  void | [resolve](#59d034e3) (const [PromiseResult](ffw_PromiseResult.html)< T > & _value_) <div style="opacity:0.8;">Resolves the promise with a value of type T. </div> |
|  virtual void | [reject](#57c902dd) (const std::exception_ptr & _eptr_) <div style="opacity:0.8;">Rejects the promise with an exception. </div> |
|  virtual void | [call](#24544a5f) () <div style="opacity:0.8;">Calls the function within this promise. </div> |
|  const [PromiseResult](ffw_PromiseResult.html)< T > & | [getResult](#867c4ace) () const  |
|  [Promise](ffw_Promise.html)< R > & | [then](#43e473b8) (Then const & _then_)  |
|  [Promise](ffw_Promise.html)< T > & | [fail](#83e8d83b) (Fail const & _fail_)  |
|  [Promise](ffw_Promise.html)< R > & | [thenOrFail](#d3dc6601) (Then const & _then_, Fail const & _fail_)  |
|  bool | [isResolved](#ad5042c0) () const <div style="opacity:0.8;">Returns true if the promise has been resolved. </div> |
|  bool | [isRejected](#5eddfa0a) () const <div style="opacity:0.8;">Returns true if the promise has been rejected. </div> |
|  bool | [isFinished](#a11bd247) () const <div style="opacity:0.8;">Returns true if the promise has been either resolved or rejected. </div> |
|  [Status](ffw_PromiseI.html#af35a7f5) | [getStatus](#c4e1a4c1) () const <div style="opacity:0.8;">Returns the status of the promise (REJECTED, RESOLVED, or WAITING) </div> |


## Public Static Functions Documentation

### <span style="opacity:0.5;">function</span> <a id="8a159389" href="#8a159389">arg1_type_helper</a>

```cpp
static arg1_traits_impl< TT >::arg1_type arg1_type_helper (
    TT
) 
```





## Public Functions Documentation

### <span style="opacity:0.5;">function</span> <a id="fc73ee8d" href="#fc73ee8d">Promise</a>

```cpp
inline  Promise () 
```

Default constructor with no lambda function. 

### <span style="opacity:0.5;">function</span> <a id="32e21e29" href="#32e21e29">Promise</a>

```cpp
inline  Promise (
    F const & lambda
) 
```

Constructor that accepts lambda. 

The lambda must accept one parameter, a reference to a promise, which is essentially a "this" pointer. You can use the parameter to either resolve or reject the promise. 
<pre><div class="lang-cpp" style="white-space: pre-wrap;"><span class="hljs-normal"><a href="ffw_Promise.html">ffw::Promise<int></a> p([](<a href="ffw_Promise.html">ffw::Promise<int></a>&amp; </span><span class="hljs-keyword">self</span><span class="hljs-normal">)&#123;</span>
<span class="hljs-normal">    </span><span class="hljs-keyword">self</span><span class="hljs-normal">.resolve(123456);</span>
<span class="hljs-normal">&#125;</span>
<span class="hljs-normal">p.call();</span>
</div></pre>

 
### <span style="opacity:0.5;">function</span> <a id="06f4ff0a" href="#06f4ff0a">Promise</a>

```cpp
inline  Promise (
    const Promise< T > & other
) 
```

Copy constructor. 

No real copy is being made. Instead, the data is shared between all copies. If you have two identical copies and one gets resolved/rejected, the second copy will also be resolved or rejected. 
### <span style="opacity:0.5;">function</span> <a id="73adf2a6" href="#73adf2a6">operator=</a>

```cpp
inline Promise< T > & operator= (
    const Promise< T > & other
) 
```

Copy operator. 

No real copy is being made. Instead, the data is shared between all copies. If you have two identical copies and one gets resolved/rejected, the second copy will also be resolved or rejected. 
### <span style="opacity:0.5;">function</span> <a id="da619b4e" href="#da619b4e">getException</a>

```cpp
inline const std::exception_ptr & getException () 
```

Returns the exception associated with this promise. 

### <span style="opacity:0.5;">function</span> <a id="f9f6ea9a" href="#f9f6ea9a">resolve</a>

```cpp
inline void resolve () 
```

Resolves the promise with a default value of type T. 

Use this parameter-less resolve function if the template argument is void 
### <span style="opacity:0.5;">function</span> <a id="59d034e3" href="#59d034e3">resolve</a>

```cpp
inline void resolve (
    const PromiseResult< T > & value
) 
```

Resolves the promise with a value of type T. 

### <span style="opacity:0.5;">function</span> <a id="57c902dd" href="#57c902dd">reject</a>

```cpp
inline virtual void reject (
    const std::exception_ptr & eptr
) 
```

Rejects the promise with an exception. 

**Overrides:** [reject](/doc/ffw_PromiseI.md#38460c5d) from class [PromiseI](/doc/ffw_PromiseI.md)


<pre><div class="lang-cpp" style="white-space: pre-wrap;"><span class="hljs-normal">Promise&lt;int&gt; p;</span>
<span class="hljs-normal"></span><span class="hljs-keyword">try</span><span class="hljs-normal"> &#123;</span>
<span class="hljs-normal">    </span><span class="hljs-keyword">throw</span><span class="hljs-normal"> std::runtime_error(</span><span class="hljs-string">"Something went wrong"</span><span class="hljs-normal">);</span>
<span class="hljs-normal">&#125; </span><span class="hljs-keyword">catch</span><span class="hljs-normal"> (...) &#123;</span>
<span class="hljs-normal">    p.reject(std::current_exception());</span>
<span class="hljs-normal">&#125;</span>
</div></pre>

 
### <span style="opacity:0.5;">function</span> <a id="24544a5f" href="#24544a5f">call</a>

```cpp
inline virtual void call () 
```

Calls the function within this promise. 

**Overrides:** [call](/doc/ffw_PromiseI.md#98ff0a8e) from class [PromiseI](/doc/ffw_PromiseI.md)


<pre><div class="lang-cpp" style="white-space: pre-wrap;"><span class="hljs-normal"><a href="ffw_Promise.html">ffw::Promise<int></a> p([](<a href="ffw_Promise.html">ffw::Promise<int></a>&amp; </span><span class="hljs-keyword">self</span><span class="hljs-normal">)&#123;</span>
<span class="hljs-normal">    </span><span class="hljs-keyword">self</span><span class="hljs-normal">.resolve(123456);</span>
<span class="hljs-normal">&#125;</span>
<span class="hljs-normal">p.call();</span>
</div></pre>

 
### <span style="opacity:0.5;">function</span> <a id="867c4ace" href="#867c4ace">getResult</a>

```cpp
inline const PromiseResult< T > & getResult () const 
```



Returns the resul of this promise 
<pre><div class="lang-cpp" style="white-space: pre-wrap;"><span class="hljs-normal"><a href="ffw_Promise.html">ffw::Promise<int></a> p;</span>
<span class="hljs-normal">p.<a href="ffw_Promise.html#f9f6ea9a">resolve</a>(42);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">std::cout &lt;&lt; </span><span class="hljs-string">"Result: "</span><span class="hljs-normal"> &lt;&lt; p.<a href="ffw_Promise.html#867c4ace">getResult</a>() &lt;&lt; std::endl;</span>
<span class="hljs-normal"></span><span class="hljs-comment">// Prints "Result: 42"</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span>
<span class="hljs-normal">p.<a href="ffw_PromiseI.html#7d11756a">rejectWith</a>&lt;std::runtime_error&gt;(</span><span class="hljs-string">"Something went wrong"</span><span class="hljs-normal">);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">std::cout &lt;&lt; </span><span class="hljs-string">"Result: "</span><span class="hljs-normal"> &lt;&lt; p.<a href="ffw_Promise.html#867c4ace">getResult</a>() &lt;&lt; std::endl;</span>
<span class="hljs-normal"></span><span class="hljs-comment">// Will not print!</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span><span class="hljs-comment">// Throws std::runtime_error</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span>
<span class="hljs-normal"><a href="ffw_Promise.html">ffw::Promise<int></a> unresolved;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">std::cout &lt;&lt; </span><span class="hljs-string">"Result: "</span><span class="hljs-normal"> &lt;&lt; p.<a href="ffw_Promise.html#867c4ace">getResult</a>() &lt;&lt; std::endl;</span>
<span class="hljs-normal"></span><span class="hljs-comment">// Will not print!</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span><span class="hljs-comment">// Throws PromiseException: Promise is not resolved</span>
</div></pre>

 
### <span style="opacity:0.5;">function</span> <a id="43e473b8" href="#43e473b8">then</a>

```cpp
inline Promise< R > & then (
    Then const & then
) 
```



Creates a new then chain link with lambda
The lambda will be executed once the parent (the instance of the method you are calling) has been be resolved. The return value of lambda determines the template type of the [Promise](ffw_Promise.html) returned. For example, you create a promise that performs an SQL query which returns a raw string. Your next "then" chain link can have a lambda that accepts a string and produces an instance of class. You can then extend the chain even further by another "then" which accepts the instance of class and produces bool or anything else. 
<pre><div class="lang-cpp" style="white-space: pre-wrap;"><span class="hljs-normal"><a href="ffw_Promise.html">ffw::Promise<std::string></a> p;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal"><a href="ffw_Promise.html">ffw::Promise<int></a> next = p.<a href="ffw_Promise.html#43e473b8">then</a>([](std::string str) -&gt; </span><span class="hljs-title">int</span><span class="hljs-normal"> &#123;</span>
<span class="hljs-normal">    std::cout &lt;&lt; </span><span class="hljs-string">"Parent promise was resolved with: "</span><span class="hljs-normal"> &lt;&lt; str &lt;&lt; std::endl;</span>
<span class="hljs-normal">    </span><span class="hljs-keyword">return</span><span class="hljs-normal"> str.size();</span>
<span class="hljs-normal">&#125;);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal"><a href="ffw_Promise.html">ffw::Promise<void></a> last = next.<a href="ffw_Promise.html#43e473b8">then</a>([](</span><span class="hljs-title">int</span><span class="hljs-normal"> val) -&gt; </span><span class="hljs-title">void</span><span class="hljs-normal"> &#123;</span>
<span class="hljs-normal">    std::cout &lt;&lt; </span><span class="hljs-string">"Received integer of: "</span><span class="hljs-normal"> &lt;&lt; val &lt;&lt; std::endl;</span>
<span class="hljs-normal">&#125;);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">p.<a href="ffw_Promise.html#f9f6ea9a">resolve</a>(</span><span class="hljs-string">"Hello!"</span><span class="hljs-normal">);</span>
<span class="hljs-normal"></span><span class="hljs-comment">// Prints: "Parent promise was resolved with: Hello!"</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span><span class="hljs-comment">//         "Received integer of: 6"</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span>
<span class="hljs-normal"></span><span class="hljs-comment">// You don't need to explicitly declare the instances of promises as above</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span><span class="hljs-comment">// You can make them more simple as below:</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span>
<span class="hljs-normal">p.<a href="ffw_Promise.html#43e473b8">then</a>([](std::string str) -&gt; </span><span class="hljs-title">int</span><span class="hljs-normal"> &#123;</span>
<span class="hljs-normal">    std::cout &lt;&lt; </span><span class="hljs-string">"Parent promise was resolved with: "</span><span class="hljs-normal"> &lt;&lt; str &lt;&lt; std::endl;</span>
<span class="hljs-normal">    </span><span class="hljs-keyword">return</span><span class="hljs-normal"> str.size();</span>
<span class="hljs-normal">&#125;).<a href="ffw_Promise.html#43e473b8">then</a>([](</span><span class="hljs-title">int</span><span class="hljs-normal"> val) -&gt; </span><span class="hljs-title">void</span><span class="hljs-normal"> &#123;</span>
<span class="hljs-normal">    std::cout &lt;&lt; </span><span class="hljs-string">"Received integer of: "</span><span class="hljs-normal"> &lt;&lt; val &lt;&lt; std::endl;</span>
<span class="hljs-normal">&#125;);</span>
</div></pre>

 
### <span style="opacity:0.5;">function</span> <a id="83e8d83b" href="#83e8d83b">fail</a>

```cpp
inline Promise< T > & fail (
    Fail const & fail
) 
```



Creates a new fail chain link with lambda
The lambda will be executed once the parent (the instance of the method you are calling) has been be rejected. 
<pre><div class="lang-cpp" style="white-space: pre-wrap;"><span class="hljs-normal"><a href="ffw_Promise.html">ffw::Promise<std::string></a> p;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal"><a href="ffw_Promise.html">ffw::Promise<std::string></a> next = p.<a href="ffw_Promise.html#83e8d83b">fail</a>([](std::runtime_exception&amp; e)&#123;</span>
<span class="hljs-normal">    std::cout &lt;&lt; </span><span class="hljs-string">"runtime_exception has been thrown!"</span><span class="hljs-normal"> &lt;&lt; std::endl;</span>
<span class="hljs-normal">&#125;);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal"><a href="ffw_Promise.html">ffw::Promise<std::string></a> last = next.<a href="ffw_Promise.html#83e8d83b">fail</a>([](std::exception&amp; e)&#123;</span>
<span class="hljs-normal">    std::cout &lt;&lt; </span><span class="hljs-string">"raw exception has been thrown!"</span><span class="hljs-normal"> &lt;&lt; std::endl;</span>
<span class="hljs-normal">&#125;);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal"><a href="ffw_Promise.html">ffw::Promise<std::string></a> test = last.<a href="ffw_Promise.html#83e8d83b">fail</a>([](</span><span class="hljs-keyword">const</span><span class="hljs-normal"> std::exception_ptr&amp; eptr)&#123;</span>
<span class="hljs-normal">    </span><span class="hljs-keyword">try</span><span class="hljs-normal"> &#123;</span>
<span class="hljs-normal">        std::rethrow_exception(eptr);</span>
<span class="hljs-normal">    &#125; </span><span class="hljs-keyword">catch</span><span class="hljs-normal"> (std::runtime_exception&amp; e)&#123;</span>
<span class="hljs-normal">        std::cout &lt;&lt; </span><span class="hljs-string">"Caught runtime_exception!"</span><span class="hljs-normal"> &lt;&lt; std::endl;</span>
<span class="hljs-normal">    &#125; </span><span class="hljs-keyword">catch</span><span class="hljs-normal"> (std::exception&amp; e)&#123;</span>
<span class="hljs-normal">        std::cout &lt;&lt; </span><span class="hljs-string">"Caught raw exception!"</span><span class="hljs-normal"> &lt;&lt; std::endl;</span>
<span class="hljs-normal">    &#125;</span>
<span class="hljs-normal">&#125;);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">p.<a href="ffw_PromiseI.html#7d11756a">rejectWith</a>&lt;std::runtime_exception&gt;(</span><span class="hljs-string">"Hello!"</span><span class="hljs-normal">);</span>
<span class="hljs-normal"></span><span class="hljs-comment">// Prints: "runtime_exception has been thrown!"</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span><span class="hljs-comment">//         "raw exception has been thrown!"</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span><span class="hljs-comment">//         "Caught runtime_exception!"</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span><span class="hljs-comment">// Both first two "fail" lambdas will be called because both raw std::exception</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span><span class="hljs-comment">// and std::runtime_error match the exception thrown.</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span><span class="hljs-comment">// The last fail lambda will also be called because it accepts any exception in form of </span><span class="hljs-normal"></span>
<span class="hljs-normal"></span><span class="hljs-comment">// std::exception_ptr</span>
</div></pre>

 
### <span style="opacity:0.5;">function</span> <a id="d3dc6601" href="#d3dc6601">thenOrFail</a>

```cpp
inline Promise< R > & thenOrFail (
    Then const & then,
    Fail const & fail
) 
```



Creates a new then + fail chain link with lambda
Similarly with "then" and "fail" methods, you can combine those two and create one chain link that will contain both "then" and "fail" lambdas. 
### <span style="opacity:0.5;">function</span> <a id="ad5042c0" href="#ad5042c0">isResolved</a>

```cpp
inline bool isResolved () const 
```

Returns true if the promise has been resolved. 

### <span style="opacity:0.5;">function</span> <a id="5eddfa0a" href="#5eddfa0a">isRejected</a>

```cpp
inline bool isRejected () const 
```

Returns true if the promise has been rejected. 

### <span style="opacity:0.5;">function</span> <a id="a11bd247" href="#a11bd247">isFinished</a>

```cpp
inline bool isFinished () const 
```

Returns true if the promise has been either resolved or rejected. 

### <span style="opacity:0.5;">function</span> <a id="c4e1a4c1" href="#c4e1a4c1">getStatus</a>

```cpp
inline Status getStatus () const 
```

Returns the status of the promise (REJECTED, RESOLVED, or WAITING) 



