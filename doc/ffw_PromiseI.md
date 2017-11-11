PromiseI
===================================

[Promise](ffw_Promise.html) interface class. 

**Implemented by:** [ffw::Promise< T >](ffw_Promise.html), 

The documentation for this class was generated from: `include/ffw/math/promise.h`



## Public Types

| Type | Name |
| -------: | :------- |
| enum | [Status](#af35a7f5) |


## Public Functions

| Type | Name |
| -------: | :------- |
|   | [PromiseI](#f4a6edb8) ()  |
|  virtual  | [~PromiseI](#5ac1a5a0) ()  |
|  virtual void | [call](#98ff0a8e) () = 0 <div style="opacity:0.8;">Calls the function associated within the promise. </div> |
|  virtual void | [reject](#38460c5d) (const std::exception_ptr & _e_) = 0 <div style="opacity:0.8;">Rejects this promise with an exception. </div> |
|  void | [rejectWith](#7d11756a) (Args &&... _args_) <div style="opacity:0.8;">Rejects this promise with an exception. </div> |


## Public Types Documentation

### <span style="opacity:0.5;">enum</span> <a id="af35a7f5" href="#af35a7f5">Status</a>

```cpp
enum Status {
    WAITING,
    RESOLVED,
    REJECTED,
}
```

The status of the promise. 



## Public Functions Documentation

### <span style="opacity:0.5;">function</span> <a id="f4a6edb8" href="#f4a6edb8">PromiseI</a>

```cpp
inline  PromiseI () 
```



### <span style="opacity:0.5;">function</span> <a id="5ac1a5a0" href="#5ac1a5a0">~PromiseI</a>

```cpp
inline virtual  ~PromiseI () 
```



### <span style="opacity:0.5;">function</span> <a id="98ff0a8e" href="#98ff0a8e">call</a>

```cpp
virtual void call () = 0 
```

Calls the function associated within the promise. 

### <span style="opacity:0.5;">function</span> <a id="38460c5d" href="#38460c5d">reject</a>

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

 
### <span style="opacity:0.5;">function</span> <a id="7d11756a" href="#7d11756a">rejectWith</a>

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

 


