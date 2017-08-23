Tutorial: Threads
-------------------------------------

This tutorial will explain how to create and launch threads using ffw::Thread and how ffw::Mutex can be used alongside it. The threads are inside of [math module](group__math.html) which is a header only library. All you need to do is to add `#include <ffw/math.h>` into your project. **This tutorial will not explain concurrency or basics of threads! You are required to know the basics.**

Why another thread class? Why not std::thread? The ffw::Thread uses std::thread only if the compiler allows it. Some older GCC compilers do not have access to std::thread. If the std::thread is not available, the ffw::Thread will use POSIX pthreads instead. This also applies for ffw::Mutex. Secondly, there are minor differences between pthreads and std::thread + std::mutex. The two classes: ffw::Thread and ffw::Mutex make sure that no matter which thread backend is being used, the written code and the behavior will be the same. **If you can (your compiler allows it), use std::thread always!**

### Creating thread

Note that ffw::Thread uses std::function and due to many reasons you should avoid using references as function parameters for threads (pointers are welcome!). A ffw::Thread can accept both static or member functions. How to tell if a function is non-static? If the function belongs to the class and has no "static" keyword then it is not a static funtion.

```cpp
class Foo {
public:
  Foo(int v){
    val = v;
  }
  
  // We create a thread to use this function
  float bar(int p, int t){
    // Some random algorithm
    return (val * p) / (float)t;
  }
  
  // References are not allowed.
  // Trying to call this function via ffw::Thread will
  // result in compilation error.
  // Use pointers instead!
  float bar_alt(int& p, int& t){
    // Some random algorithm
    return (val * p) / (float)t;
  }
  
private:
  int val;
};

int main(){
  // Create instance of Foo class
  Foo foo(10);
  
  // Create thread instance that matches the function we are
  // going to use.
  ffw::Thread<float(int, int)> thread;
  
  // Launch the thread and use Foo::bar function.
  // When calling non-static member function, you need to pass
  // the pointer to the class instance as well.
  // The function () acceps unlimited number of parameters, it will scale
  // based on the <float(int, int)> template parameter.
  thread.run(&Foo::bar, &foo, 5, 2);
  
  // If the function was a global function, or static member function,
  // then the instance is irrelevant and you can use:
  // thread.run(&Foo::bar, 5, 2);
  
  // Now you can do something else while the thread is running.
  
  // You can check if the thread is still running by calling:
  std::cout << "is running? " << thread.isRunning() << std::endl;
  // Note that because we are not doing any heavy work inside of
  // Foo::bar function, thread will most likely finish before you
  // manage to call thread.isRunning()
  
  // Always join the thread! This will release memory needed for the
  // thread. If the thread is still running, the function thread.join()
  // will not finish until the thread has finished first.
  thread.join();
  
  // Check the result, prints: "Result: 25"
  // The getResult() returns float because we used <float(int, int)>
  // as a template parameter that mathces Foo::bar 
  std::cout << "Result: " << thread.getResult() << std::endl;
  
  // The end
  return 0;
}
```

### Mutex

Mutex can be used to lock specific areas of the program. You are required to understand basics of mutex and concurrency. There are many great tutorials out there and there is simply no reason to create another tutorial explaining it. The following code will only explain how to use ffw::Mutex.

```cpp
// We will store some data here,
// There is no great use for it, this is just for the purpose
// of the tutorial.
std::vector<int*> data;

// Our mutex
ffw::Mutex mutex;

// Some global function
void foo(size_t len, int start){
  int* arr = new int[len];
  for(size_t i = 0; i < len; i++){
    // Make square
    arr[i] = (start + i) * (start + i);
  }
  
  // Lock the mutex. If there is already a lock by a different thread,
  // the current thread will wait until the lock has been released.
  mutex.lock();
  
  // We have a lock! Push data to our array!
  dara.push_back(arr);
  
  // Release the lock.
  mutex.unlock();
}

int main(){
  ffw::Thread<void(size_t, int)> thread;
  
  // Launch 16 threads
  for(int i = 0; i < 16; i++){
    thread.run(&foo, 1024, i * 1024);
  }
  
  // Wait for all threads
  for(int i = 0; i < 16; i++){
    thread.join();
  }
  
  // thread.getResult() does not make sense here!
  // The function is "void", you can't retun anything in void function!
  
  // Do something with data
  some_kind_of_function_to_process_data(&data);
  
  // Release the dynamically allocated arrays
  while(data.size()){ // While there is anything in the vector
    delete[] data.back(); // Get the element at the back (last element)
    data.push_back(); // Remove the element from back (last element)
  }
  
  // The end
  return 0;
}
```

