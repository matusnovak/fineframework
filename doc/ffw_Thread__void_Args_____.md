Thread< void(Args...)>
===================================

Thread class that accepts static and member void only functions. 

The documentation for this class was generated from: `include/ffw/math/thread.h`

## Detailed description

This thread class can accept any static or member function with variable arguments. The output of the target function is NOT stored as this thread class accepts only void functions. To use non-void functions, see ffw::Thread< Ret(Args...)> Why another thread class? Why not std::thread? The ffw::Thread uses std::thread only if the compiler allows it. Some older GCC compilers do not have access to std::thread. If the std::thread is not available, the ffw::Thread will use POSIX pthreads instead. This also applies for [ffw::Mutex](ffw_Mutex.html). Secondly, there are minor differences between pthreads and std::thread + std::mutex. The two classes: ffw::Thread and [ffw::Mutex](ffw_Mutex.html) make sure that no matter which thread backend is being used, the written code and the behavior will be the same. 
<pre><div class="lang-cpp" style="white-space: nowrap;"><span class="hljs-normal">// Some class</span>
<span class="hljs-normal">class Foo &#123;</span>
<span class="hljs-normal">    public:</span>
<span class="hljs-normal">    void baz(int val) &#123;</span>
<span class="hljs-normal">        // Some time intensive work...</span>
<span class="hljs-normal">        bar = val * val;</span>
<span class="hljs-normal">    &#125;</span>
<span class="hljs-normal">    int bar;</span>
<span class="hljs-normal">&#125;</span>
<span class="hljs-normal">// Our main function</span>
<span class="hljs-normal">int main(int ac, char** av)&#123;</span>
<span class="hljs-normal">    Foo foo;</span>
<span class="hljs-normal">    foo.bar = 10;</span>
<span class="hljs-normal">    // Declare our thread that acceps a void function</span>
<span class="hljs-normal">    ffw::Thread&lt;void(void)&gt; thread;</span>
<span class="hljs-normal">    // Run function on the thread</span>
<span class="hljs-normal">    // You need to provide a function pointer, </span>
<span class="hljs-normal">    // instance to the class, and function arguments</span>
<span class="hljs-normal">    thread.run(&amp;Foo::baz, &amp;foo, 10);</span>
<span class="hljs-normal">    // Wait for the thread to be done</span>
<span class="hljs-normal">    while(thread.isRunning()) &#123;</span>
<span class="hljs-normal">          // Do something else...</span>
<span class="hljs-normal">    &#125;</span>
<span class="hljs-normal">    thread.join();</span>
<span class="hljs-normal">    // Thread ended at this point</span>
<span class="hljs-normal">    std::cout &lt;&lt; "Thread executed! Result: " &lt;&lt; foo.bar &lt;&lt; std::endl;</span>
<span class="hljs-normal">&#125;</span>
</div></pre>

 


## Public Functions

| Type | Name |
| -------: | :------- |
|   | [Thread](#8f1140be) ()  |
|  virtual  | [~Thread](#f9fc2bab) ()  |
|  bool | [run](#0844df56) (void(T::*)(Args...) _func_, T * _instance_, Args &&... _args_) <div style="opacity:0.8;">Runs a thread on the member function. </div> |
|  bool | [run](#807bd58b) (void(*)(Args...) _func_, Args &&... _args_) <div style="opacity:0.8;">Runs a thread on the static function. </div> |
|  void | [getResult](#a32bda28) () <div style="opacity:0.8;">Returns the result returned by the executed function. </div> |
|  void | [getResult](#f6cdbddb) () const <div style="opacity:0.8;">Returns the result returned by the executed function. </div> |
|  void | [join](#54b3db43) () <div style="opacity:0.8;">Waits for the thread. </div> |
|  bool | [isRunning](#10f054fa) () const <div style="opacity:0.8;">Checks if the thread is still running. </div> |


## Public Functions Documentation

### <span style="opacity:0.5;">function</span> <a id="8f1140be" href="#8f1140be">Thread</a>

```cpp
inline  Thread () 
```



### <span style="opacity:0.5;">function</span> <a id="f9fc2bab" href="#f9fc2bab">~Thread</a>

```cpp
inline virtual  ~Thread () 
```



### <span style="opacity:0.5;">function</span> <a id="0844df56" href="#0844df56">run</a>

```cpp
inline bool run (
    void(T::*)(Args...) func,
    T * instance,
    Args &&... args
) 
```

Runs a thread on the member function. 

**Params:**
* _func:_ Pointer to the member function 
* _instance:_ Instance to the class of the member function 
* _args:_ List of arguments that matches the function declaration 


### <span style="opacity:0.5;">function</span> <a id="807bd58b" href="#807bd58b">run</a>

```cpp
inline bool run (
    void(*)(Args...) func,
    Args &&... args
) 
```

Runs a thread on the static function. 

**Params:**
* _func:_ Pointer to the static (non-member!) function 
* _args:_ List of arguments that matches the function declaration 


### <span style="opacity:0.5;">function</span> <a id="a32bda28" href="#a32bda28">getResult</a>

```cpp
inline void getResult () 
```

Returns the result returned by the executed function. 

There is no returned value if you are using void function to run a thread. **see:** ffw::Thread< Ret(Args...)> 


### <span style="opacity:0.5;">function</span> <a id="f6cdbddb" href="#f6cdbddb">getResult</a>

```cpp
inline void getResult () const 
```

Returns the result returned by the executed function. 

There is no returned value if you are using void function to run a thread. **see:** ffw::Thread< Ret(Args...)> 


### <span style="opacity:0.5;">function</span> <a id="54b3db43" href="#54b3db43">join</a>

```cpp
inline void join () 
```

Waits for the thread. 

### <span style="opacity:0.5;">function</span> <a id="10f054fa" href="#10f054fa">isRunning</a>

```cpp
inline bool isRunning () const 
```

Checks if the thread is still running. 



