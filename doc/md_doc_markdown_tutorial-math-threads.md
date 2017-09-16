Threads
=================

This tutorial will explain how to create and launch threads using ffw::Thread and how [ffw::Mutex](ffw_Mutex.html) can be used alongside it. The threads are inside of [math module](group__math.html) which is a header only library. All you need to do is to add `#include <[ffw/math.h]()>` into your project. **This tutorial will not explain concurrency or basics of threads! You are required to know the basics.**

Why another thread class? Why not std::thread? The ffw::Thread uses std::thread only if the compiler allows it. Some older GCC compilers do not have access to std::thread. If the std::thread is not available, the ffw::Thread will use POSIX pthreads instead. This also applies for [ffw::Mutex](ffw_Mutex.html). Secondly, there are minor differences between pthreads and std::thread + std::mutex. The two classes: ffw::Thread and [ffw::Mutex](ffw_Mutex.html) make sure that no matter which thread backend is being used, the written code and the behavior will be the same. **If you can (your compiler allows it), use std::thread always!**

#### Creating thread


Note that ffw::Thread uses std::function and due to many reasons you should avoid using references as function parameters for threads (pointers are welcome!). A ffw::Thread can accept both static or member functions. How to tell if a function is non-static? If the function belongs to the class and has no "static" keyword then it is not a static funtion.


<pre><div class="lang-cpp"><span class="hljs-keyword">class </span><span class="hljs-normal">Foo &#123;</span>
<span class="hljs-normal"></span><span class="hljs-keyword">public</span><span class="hljs-normal">:</span>
<span class="hljs-normal">  Foo(</span><span class="hljs-title">int</span><span class="hljs-normal"> v)&#123;</span>
<span class="hljs-normal">    val = v;</span>
<span class="hljs-normal">  &#125;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">  </span><span class="hljs-comment">// We create a thread to use this function</span><span class="hljs-normal"></span>
<span class="hljs-normal">  </span><span class="hljs-title">float</span><span class="hljs-normal"> bar(</span><span class="hljs-title">int</span><span class="hljs-normal"> p, </span><span class="hljs-title">int</span><span class="hljs-normal"> t)&#123;</span>
<span class="hljs-normal">    </span><span class="hljs-comment">// Some random algorithm</span><span class="hljs-normal"></span>
<span class="hljs-normal">    </span><span class="hljs-keyword">return</span><span class="hljs-normal"> (val * p) / (float)t;</span>
<span class="hljs-normal">  &#125;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">  </span><span class="hljs-comment">// References are not allowed.</span><span class="hljs-normal"></span>
<span class="hljs-normal">  </span><span class="hljs-comment">// Trying to call this function via ffw::Thread will</span><span class="hljs-normal"></span>
<span class="hljs-normal">  </span><span class="hljs-comment">// result in compilation error.</span><span class="hljs-normal"></span>
<span class="hljs-normal">  </span><span class="hljs-comment">// Use pointers instead!</span><span class="hljs-normal"></span>
<span class="hljs-normal">  </span><span class="hljs-title">float</span><span class="hljs-normal"> bar_alt(</span><span class="hljs-title">int</span><span class="hljs-normal">&amp; p, </span><span class="hljs-title">int</span><span class="hljs-normal">&amp; t)&#123;</span>
<span class="hljs-normal">    </span><span class="hljs-comment">// Some random algorithm</span><span class="hljs-normal"></span>
<span class="hljs-normal">    </span><span class="hljs-keyword">return</span><span class="hljs-normal"> (val * p) / (float)t;</span>
<span class="hljs-normal">  &#125;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal"></span><span class="hljs-keyword">private</span><span class="hljs-normal">:</span>
<span class="hljs-normal">  </span><span class="hljs-title">int</span><span class="hljs-normal"> val;</span>
<span class="hljs-normal">&#125;;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal"></span><span class="hljs-title">int</span><span class="hljs-normal"> main()&#123;</span>
<span class="hljs-normal">  </span><span class="hljs-comment">// Create instance of Foo class</span><span class="hljs-normal"></span>
<span class="hljs-normal">  Foo foo(10);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">  </span><span class="hljs-comment">// Create thread instance that matches the function we are</span><span class="hljs-normal"></span>
<span class="hljs-normal">  </span><span class="hljs-comment">// going to use.</span><span class="hljs-normal"></span>
<span class="hljs-normal">  ffw::Thread&lt;float(int, int)&gt; thread;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">  </span><span class="hljs-comment">// Launch the thread and use Foo::bar function.</span><span class="hljs-normal"></span>
<span class="hljs-normal">  </span><span class="hljs-comment">// When calling non-static member function, you need to pass</span><span class="hljs-normal"></span>
<span class="hljs-normal">  </span><span class="hljs-comment">// the pointer to the class instance as well.</span><span class="hljs-normal"></span>
<span class="hljs-normal">  </span><span class="hljs-comment">// The function () acceps unlimited number of parameters, it will scale</span><span class="hljs-normal"></span>
<span class="hljs-normal">  </span><span class="hljs-comment">// based on the &lt;float(int, int)&gt; template parameter.</span><span class="hljs-normal"></span>
<span class="hljs-normal">  thread.run(&amp;Foo::bar, &amp;foo, 5, 2);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">  </span><span class="hljs-comment">// If the function was a global function, or static member function,</span><span class="hljs-normal"></span>
<span class="hljs-normal">  </span><span class="hljs-comment">// then the instance is irrelevant and you can use:</span><span class="hljs-normal"></span>
<span class="hljs-normal">  </span><span class="hljs-comment">// thread.run(&amp;Foo::bar, 5, 2);</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span>
<span class="hljs-normal">  </span><span class="hljs-comment">// Now you can do something else while the thread is running.</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span>
<span class="hljs-normal">  </span><span class="hljs-comment">// You can check if the thread is still running by calling:</span><span class="hljs-normal"></span>
<span class="hljs-normal">  std::cout &lt;&lt; </span><span class="hljs-string">"is running? "</span><span class="hljs-normal"> &lt;&lt; thread.isRunning() &lt;&lt; std::endl;</span>
<span class="hljs-normal">  </span><span class="hljs-comment">// Note that because we are not doing any heavy work inside of</span><span class="hljs-normal"></span>
<span class="hljs-normal">  </span><span class="hljs-comment">// Foo::bar function, thread will most likely finish before you</span><span class="hljs-normal"></span>
<span class="hljs-normal">  </span><span class="hljs-comment">// manage to call thread.isRunning()</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span>
<span class="hljs-normal">  </span><span class="hljs-comment">// Always join the thread! This will release memory needed for the</span><span class="hljs-normal"></span>
<span class="hljs-normal">  </span><span class="hljs-comment">// thread. If the thread is still running, the function thread.join()</span><span class="hljs-normal"></span>
<span class="hljs-normal">  </span><span class="hljs-comment">// will not finish until the thread has finished first.</span><span class="hljs-normal"></span>
<span class="hljs-normal">  thread.join();</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">  </span><span class="hljs-comment">// Check the result, prints: "Result: 25"</span><span class="hljs-normal"></span>
<span class="hljs-normal">  </span><span class="hljs-comment">// The getResult() returns float because we used &lt;float(int, int)&gt;</span><span class="hljs-normal"></span>
<span class="hljs-normal">  </span><span class="hljs-comment">// as a template parameter that mathces Foo::bar </span><span class="hljs-normal"></span>
<span class="hljs-normal">  std::cout &lt;&lt; </span><span class="hljs-string">"Result: "</span><span class="hljs-normal"> &lt;&lt; thread.getResult() &lt;&lt; std::endl;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">  </span><span class="hljs-comment">// The end</span><span class="hljs-normal"></span>
<span class="hljs-normal">  </span><span class="hljs-keyword">return</span><span class="hljs-normal"> 0;</span>
<span class="hljs-normal">&#125;</span>
</div></pre>



#### Mutex


Mutex can be used to lock specific areas of the program. You are required to understand basics of mutex and concurrency. There are many great tutorials out there and there is simply no reason to create another tutorial explaining it. The following code will only explain how to use [ffw::Mutex](ffw_Mutex.html).


<pre><div class="lang-cpp"><span class="hljs-comment">// We will store some data here,</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span><span class="hljs-comment">// There is no great use for it, this is just for the purpose</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span><span class="hljs-comment">// of the tutorial.</span><span class="hljs-normal"></span>
<span class="hljs-normal">std::vector&lt;int*&gt; data;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal"></span><span class="hljs-comment">// Our mutex</span><span class="hljs-normal"></span>
<span class="hljs-normal"><a href="ffw_Mutex.html">ffw::Mutex</a> mutex;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal"></span><span class="hljs-comment">// Some global function</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span><span class="hljs-title">void</span><span class="hljs-normal"> foo(</span><span class="hljs-title">size_t</span><span class="hljs-normal"> len, </span><span class="hljs-title">int</span><span class="hljs-normal"> start)&#123;</span>
<span class="hljs-normal">  </span><span class="hljs-title">int</span><span class="hljs-normal">* arr = </span><span class="hljs-keyword">new</span><span class="hljs-normal"> </span><span class="hljs-title">int</span><span class="hljs-normal">[len];</span>
<span class="hljs-normal">  </span><span class="hljs-keyword">for</span><span class="hljs-normal">(</span><span class="hljs-title">size_t</span><span class="hljs-normal"> i = 0; i &lt; len; i++)&#123;</span>
<span class="hljs-normal">    </span><span class="hljs-comment">// Make square</span><span class="hljs-normal"></span>
<span class="hljs-normal">    arr[i] = (start + i) * (start + i);</span>
<span class="hljs-normal">  &#125;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">  </span><span class="hljs-comment">// Lock the mutex. If there is already a lock by a different thread,</span><span class="hljs-normal"></span>
<span class="hljs-normal">  </span><span class="hljs-comment">// the current thread will wait until the lock has been released.</span><span class="hljs-normal"></span>
<span class="hljs-normal">  mutex.<a href="ffw_Mutex.html#e7eb5d3d">lock</a>();</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">  </span><span class="hljs-comment">// We have a lock! Push data to our array!</span><span class="hljs-normal"></span>
<span class="hljs-normal">  dara.push_back(arr);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">  </span><span class="hljs-comment">// Release the lock.</span><span class="hljs-normal"></span>
<span class="hljs-normal">  mutex.<a href="ffw_Mutex.html#6106acf1">unlock</a>();</span>
<span class="hljs-normal">&#125;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal"></span><span class="hljs-title">int</span><span class="hljs-normal"> main()&#123;</span>
<span class="hljs-normal">  ffw::Thread&lt;void(size_t, int)&gt; thread;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">  </span><span class="hljs-comment">// Launch 16 threads</span><span class="hljs-normal"></span>
<span class="hljs-normal">  </span><span class="hljs-keyword">for</span><span class="hljs-normal">(</span><span class="hljs-title">int</span><span class="hljs-normal"> i = 0; i &lt; 16; i++)&#123;</span>
<span class="hljs-normal">    thread.run(&amp;foo, 1024, i * 1024);</span>
<span class="hljs-normal">  &#125;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">  </span><span class="hljs-comment">// Wait for all threads</span><span class="hljs-normal"></span>
<span class="hljs-normal">  </span><span class="hljs-keyword">for</span><span class="hljs-normal">(</span><span class="hljs-title">int</span><span class="hljs-normal"> i = 0; i &lt; 16; i++)&#123;</span>
<span class="hljs-normal">    thread.join();</span>
<span class="hljs-normal">  &#125;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">  </span><span class="hljs-comment">// thread.getResult() does not make sense here!</span><span class="hljs-normal"></span>
<span class="hljs-normal">  </span><span class="hljs-comment">// The function is "void", you can't retun anything in void function!</span><span class="hljs-normal"></span>
<span class="hljs-normal"></span>
<span class="hljs-normal">  </span><span class="hljs-comment">// Do something with data</span><span class="hljs-normal"></span>
<span class="hljs-normal">  some_kind_of_function_to_process_data(&amp;data);</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">  </span><span class="hljs-comment">// Release the dynamically allocated arrays</span><span class="hljs-normal"></span>
<span class="hljs-normal">  </span><span class="hljs-keyword">while</span><span class="hljs-normal">(data.size())&#123; </span><span class="hljs-comment">// While there is anything in the vector</span><span class="hljs-normal"></span>
<span class="hljs-normal">    </span><span class="hljs-keyword">delete</span><span class="hljs-normal">[] data.back(); </span><span class="hljs-comment">// Get the element at the back (last element)</span><span class="hljs-normal"></span>
<span class="hljs-normal">    data.push_back(); </span><span class="hljs-comment">// Remove the element from back (last element)</span><span class="hljs-normal"></span>
<span class="hljs-normal">  &#125;</span>
<span class="hljs-normal"></span>
<span class="hljs-normal">  </span><span class="hljs-comment">// The end</span><span class="hljs-normal"></span>
<span class="hljs-normal">  </span><span class="hljs-keyword">return</span><span class="hljs-normal"> 0;</span>
<span class="hljs-normal">&#125;</span>
</div></pre>

 

