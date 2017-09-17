Thread< Ret(Args...)>
===================================

Thread class that accepts non-void static and member functions. 

The documentation for this class was generated from: `include/ffw/math/thread.h`

## Detailed description

This thread class can accept any static or member function with variable arguments. The output of the target function is stored and can begin retrieved after the thread execution. Why another thread class? Why not std::thread? The ffw::Thread uses std::thread only if the compiler allows it. Some older GCC compilers do not have access to std::thread. If the std::thread is not available, the ffw::Thread will use POSIX pthreads instead. This also applies for [ffw::Mutex](ffw_Mutex.html). Secondly, there are minor differences between pthreads and std::thread + std::mutex. The two classes: ffw::Thread and [ffw::Mutex](ffw_Mutex.html) make sure that no matter which thread backend is being used, the written code and the behavior will be the same. 
<pre><div class="lang-cpp" style="white-space: nowrap;"><span class="hljs-normal">// Some class</span>
<span class="hljs-normal">class Foo &#123;</span>
<span class="hljs-normal">    public:</span>
<span class="hljs-normal">    float multiply(float a, float b) &#123;</span>
<span class="hljs-normal">        // Some time intensive work...</span>
<span class="hljs-normal">        return a * b;</span>
<span class="hljs-normal">    &#125;</span>
<span class="hljs-normal">&#125;</span>
<span class="hljs-normal">// Our main function</span>
<span class="hljs-normal">int main(int ac, char** av)&#123;</span>
<span class="hljs-normal">    Foo foo;</span>
<span class="hljs-normal">    // Declare our thread that acceps a function</span>
<span class="hljs-normal">    // with two float arguments and returns float</span>
<span class="hljs-normal">    ffw::Thread&lt;float(float, float)&gt; thread;</span>
<span class="hljs-normal">    // Run function on the thread</span>
<span class="hljs-normal">    // You need to provide a function pointer, </span>
<span class="hljs-normal">    // instance to the class, and function arguments</span>
<span class="hljs-normal">    thread.run(&amp;Foo::multiply, &amp;foo, 5.0f, 2.0f);</span>
<span class="hljs-normal">    // Wait for the thread to be done</span>
<span class="hljs-normal">    while(thread.isRunning()) &#123;</span>
<span class="hljs-normal">          // Do something else...</span>
<span class="hljs-normal">    &#125;</span>
<span class="hljs-normal">    thread.join();</span>
<span class="hljs-normal">    // Thread ended at this point, get the return value</span>
<span class="hljs-normal">    std::cout &lt;&lt; "Thread executed! Return value: " &lt;&lt; thread.getResult() &lt;&lt; std::endl;</span>
<span class="hljs-normal">&#125;</span>
</div></pre>

 


## Public Functions

| Type | Name |
| -------: | :------- |
|   | [Thread](#6b0b55c4) ()  |
|  virtual  | [~Thread](#926a46c8) ()  |
|  bool | [run](#cb3bc9e0) (Ret(T::*)(Args...) _func_, T * _instance_, Args &&... _args_) <div style="opacity:0.8;">Runs a thread on the member function. </div> |
|  bool | [run](#3f3acb95) (Ret(*)(Args...) _func_, Args &&... _args_) <div style="opacity:0.8;">Runs a thread on the static function. </div> |
|  Ret & | [getResult](#e71b0a60) () <div style="opacity:0.8;">Returns the result returned by the executed function. </div> |
|  const Ret & | [getResult](#a6da2ea7) () const <div style="opacity:0.8;">Returns the result returned by the executed function. </div> |
|  void | [join](#a412322a) () <div style="opacity:0.8;">Waits for the thread. </div> |
|  bool | [isRunning](#4f9cf94b) () const <div style="opacity:0.8;">Checks if the thread is still running. </div> |


## Public Functions Documentation

### <span style="opacity:0.5;">function</span> <a id="6b0b55c4" href="#6b0b55c4">Thread</a>

```cpp
inline  Thread () 
```



### <span style="opacity:0.5;">function</span> <a id="926a46c8" href="#926a46c8">~Thread</a>

```cpp
inline virtual  ~Thread () 
```



### <span style="opacity:0.5;">function</span> <a id="cb3bc9e0" href="#cb3bc9e0">run</a>

```cpp
inline bool run (
    Ret(T::*)(Args...) func,
    T * instance,
    Args &&... args
) 
```

Runs a thread on the member function. 

**Params:**
* _func:_ Pointer to the member function 
* _instance:_ Instance to the class of the member function 
* _args:_ List of arguments that matches the function declaration 


### <span style="opacity:0.5;">function</span> <a id="3f3acb95" href="#3f3acb95">run</a>

```cpp
inline bool run (
    Ret(*)(Args...) func,
    Args &&... args
) 
```

Runs a thread on the static function. 

**Params:**
* _func:_ Pointer to the static (non-member!) function 
* _args:_ List of arguments that matches the function declaration 


### <span style="opacity:0.5;">function</span> <a id="e71b0a60" href="#e71b0a60">getResult</a>

```cpp
inline Ret & getResult () 
```

Returns the result returned by the executed function. 

### <span style="opacity:0.5;">function</span> <a id="a6da2ea7" href="#a6da2ea7">getResult</a>

```cpp
inline const Ret & getResult () const 
```

Returns the result returned by the executed function. 

### <span style="opacity:0.5;">function</span> <a id="a412322a" href="#a412322a">join</a>

```cpp
inline void join () 
```

Waits for the thread. 

### <span style="opacity:0.5;">function</span> <a id="4f9cf94b" href="#4f9cf94b">isRunning</a>

```cpp
inline bool isRunning () const 
```

Checks if the thread is still running. 



