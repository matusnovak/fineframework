InterfacePromise
===================================

[Promise](ffw_Promise.html) interface class. 

**Implemented by:** [ffw::Promise< T >](ffw_Promise.html), 

The documentation for this class was generated from: `include/ffw/math/promise.h`



## Public Types

| Type | Name |
| -------: | :------- |
| enum | [Status](#0b2c8e4c) |


## Public Functions

| Type | Name |
| -------: | :------- |
|   | [InterfacePromise](#2e53b7c3) ()  |
|  virtual  | [~InterfacePromise](#497c6539) ()  |
|  virtual void | [call](#91c53260) () = 0 <div style="opacity:0.8;">Calls the function associated within the promise. </div> |
|  virtual void | [reject](#14d46e92) (const std::exception_ptr & _e_) = 0 <div style="opacity:0.8;">Rejects this promise with an exception. </div> |
|  void | [rejectWith](#67e409ac) (Args &&... _args_) <div style="opacity:0.8;">Rejects this promise with an exception. </div> |


## Public Types Documentation

### <span style="opacity:0.5;">enum</span> <a id="0b2c8e4c" href="#0b2c8e4c">Status</a>

```cpp
enum Status {
    WAITING,
    RESOLVED,
    REJECTED,
}
```

The status of the promise. 



## Public Functions Documentation

### <span style="opacity:0.5;">function</span> <a id="2e53b7c3" href="#2e53b7c3">InterfacePromise</a>

```cpp
inline  InterfacePromise () 
```



### <span style="opacity:0.5;">function</span> <a id="497c6539" href="#497c6539">~InterfacePromise</a>

```cpp
inline virtual  ~InterfacePromise () 
```



### <span style="opacity:0.5;">function</span> <a id="91c53260" href="#91c53260">call</a>

```cpp
virtual void call () = 0 
```

Calls the function associated within the promise. 

### <span style="opacity:0.5;">function</span> <a id="14d46e92" href="#14d46e92">reject</a>

```cpp
virtual void reject (
    const std::exception_ptr & e
) = 0 
```

Rejects this promise with an exception. 


<pre><div class="lang-cpp" style="white-space: pre-wrap;"><span class="hljs-normal">Promise&lt;int&gt; p;</span>
<span class="hljs-normal"></span><span class="hljs-keyword">try</span><span class="hljs-normal"> &#123;</span>
<span class="hljs-normal">    </span><span class="hljs-keyword">throw</span><span class="hljs-normal"> std::runtime_error(</span><span class="hljs-string">"Something went wrong"</span><span class="hljs-normal">);</span>
<span class="hljs-normal">&#125; </span><span class="hljs-keyword">catch</span><span class="hljs-normal"> (...)&#123;</span>
<span class="hljs-normal">    p.reject(std::current_exception());</span>
<span class="hljs-normal">&#125;</span>
</div></pre>

 
### <span style="opacity:0.5;">function</span> <a id="67e409ac" href="#67e409ac">rejectWith</a>

```cpp
inline void rejectWith (
    Args &&... args
) 
```

Rejects this promise with an exception. 

This method will construct an exception based on the template and constructor arguments provided. 
<pre><div class="lang-cpp" style="white-space: pre-wrap;"><span class="hljs-normal">Promise&lt;int&gt; p;</span>
<span class="hljs-normal">p.rejectWith&lt;std::runtime_error&gt;(</span><span class="hljs-string">"Something went wrong"</span><span class="hljs-normal">);</span>
</div></pre>

 


