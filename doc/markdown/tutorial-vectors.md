Tutorial: Vectors
-----------------

This tutorial will explain the basics hidden behind vectors. However, you are expected to know basics of linear algebra, such as vector addition.

There are four vector classes you can use: ffw::Vec2 ffw::Vec3 ffw::Vec4 and ffw::Vec. All of these classes are templates and can hold any data type you choose to use. For example, if you want 3 component vector, for example to represent a position in 3D space, you might use **ffw::Vec3\<double\>** or **ffw::Vec3\<float\>**. For less typing, multiple typedefs are provided to you such as ffw::Vec3d (double) ffw::Vec3f (float) ffw::Vec3i (int), this also applies for 2D and 4D vectors: **ffw::Vec2d, ffw::Vec2f, ffw::Vec2i, ffw::Vec4d, ffw::Vec4f, ffw::Vec4i.** 

The ffw::Vec (notice no number) is a special vector, as it can hold any number of components. Do you need 1000 component vector? No problem. The maximum number of components it can hold is the limit of std::size_t (or SIZE_MAX) which is more than plenty. Note that when declaring your massive vector, you have to provide data type (same as ffw::Vec2\<double\> etc...) but also number of components. For example: **ffw::Vec\<double, 1000\>**

The **ffw::Vec\<double, 1000\>** does not have a constructor that acceps 1000 parameters. However, it acceps an initializer list, which is a curly bracket list such as: `ffw::Vec<double, 6> vec({1, 2, 3, 4, 5, 6})`. You can also use the [ ] operator to access individual elements: `vec[0] = 2.0; // 1st component is now 2.0`

*Please note, do not mistake `a * b` operation as a dot product! The asterisk will multiply all components in component wise order and return a new vector. To use dot use `ffw::dot(a, b)` instead.*

### The basic operations

Initializing vector can be done via the constructor, or via set() function. Note that the ffw::Vec\<T, S\> does not have a typical constructor!

```cpp
// Initializing vector
ffw::Vec2f a;               // Will be initialized to [0, 0]
ffw::Vec2f b(10.0f, 20.0f); // Will be initialized to [10, 20]
ffw::Vec2f c(20.0f);        // Will be initialized to [20, 20]
ffw::Vec<float, 6> d({1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f});
                            // Will be initialized to [1, 2, 3, 4, 5, 6]
```

```cpp
// Casting to a different data type is done explicitly!
ffw::Vec2i e = a; // ERROR, will not work, cannot convert ffw::Vec2f to ffw::Vec2i
ffw::Vec2i e = (int)a; // ERROR, will not work, cannot cast ffw::Vec2f to int
ffw::Vec2i e = (ffw::Vec2i)a; // OK!
```

```cpp
// Setting it to a different value
a.set(0.5f, 0.7f);          // A is now [0.5, 0.7]
b.set(1.0f);                // B is now [1.0, 1.0]
c = a;                      // Copy A to C
c.set(a);                   // Copy A to C
d.set(1.0f);                // D is now [1, 1, 1, 1, 1, 1]
d.set({0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f}); // D is now [0, 1, 0, 0, 0, 0]
```

```cpp
// Accessing individual elements
c.x = 55.0f;
c.y = 66.0f;
// C is now [55, 66]

d[5] = 10.0f;
// D's 6th component is set to 10

std::cout << a.x << ", " << a.y << std::endl; // Prints "0.5, 0.7"
// Same as std::cout << a << std::endl;
```

```cpp
// Scalling
c.scale(2.0);               // C is now [110, 132]
```

```cpp
// Unary operator
b = -b;                     // B is now [-1.0, -1.0]

// Addition (component wise)
std::cout << (a + b) << std::endl; // Prints "-0.5, -0.3"
// 'a' and 'b' remains unmodified!

c = a + b;                  // C is now [-0.5, -0.3]

// All other operators (+, -, *, /) follow same principle 
// They can be also used as += -= *= /= 

a += b;
// Is same as
a = a + b;
```

All operations (addition, subtraction, multiplication, division) are component wise. Meaning that computing addition of 3 componet vector follows:

```cpp
// Given a, b, and c are 3D vectors
c.x = a.x + b.x;
c.y = a.y + b.y;
c.z = a.z + b.z;
```

 ### Magnitude (length) 

From linear algebra, we know that magnitude of a vector is sqrt(x^2 + y^2 + ...). Magnitude is also the length of a vector. To scale the vector so the magnitude/lengths equals 1.0 you can use **vec.normalize()**. Additionally, you can use **ffw::normalize()** (won't modify the original vector) which returns a copy of a normalized vector. 

```cpp
ffw::Vec3f a(1.0f, 0.0f, 0.0f);
std::cout << a.length() << std::endl; // Prints "1.0"

ffw::Vec3f b(2.0f, 0.0f, 0.0f);
std::cout << b.length() << std::endl; // Prints "2.0"

b.normalize(); // B is now normalized
std::cout << b << " length: " << b.length() << std::endl; // Prints: "1, 0, 0 length: 1"

ffw::Vec3f c(1.0f, 1.0f, 1.0f);
std::cout << c.length() << std::endl; // Prints "1.73205080757" (also known as sqrt(3))

ffw::Vec<float, 7> d({1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f});
std::cout << d.length() << std::endl; // Prints "11.8321595662"

// Optionally, you can use lengthSqrd() to get squared length.
// It is faster to compare two lengths of vectors via lengthSqrd() rather than
// length() because length() uses expensive sqrd() operation.
```

### Rotation

All rotation is done in clockwise, as all vectors should do. Rotation can be done either on ffw::Vec2 in one axis or on ffw::Vec3 in X, Y, and Z axis. 

```cpp
ffw::Vec3f a(1.0f, 0.0f, 0.0f);
a.rotateZ(90.0); // Rotate by 90 degrees clockwise

std::cout << a << std::endl; // Prints "0, 1, 0"
// Might also print: "8.94897e-10, 1, 0" which is essentially 0, 1, 0
// due to the floating point precision
```

### Angle between vectors

You can use ffw::angle or ffw::angleRad (for radians) on ffw::Vec2 and ffw::Vec3 which will give you an angle between those two vectors

```cpp
ffw::Vec3f a(1.0f, 0.0f, 0.0f);
ffw::Vec3f b(0.0f, 1.0f, 0.0f);

std::cout << ffw::angle(a, b) << std::endl; // Prints "90"
std::cout << ffw::angleRad(a, b) << std::endl; // Prints "1.5708"
// Both 'a' and 'b' remain unmodified!
```

### Dot and cross product

Cross and dot product is provided, using ffw::dot and ffw::cross. Note that dot product can be used with all vectors, but cross product can be used only with ffw::Vec3. However, you can not 

```cpp
ffw::Vec3f a(1.0f, -0.5f, 0.0f); // Float
ffw::Vec3f b(-0.2f, 1.0f, 0.5f); // Float
ffw::Vec3d c(-0.2, 1.0, 0.5); // Double equivalent of 'b'

// std::cout << "dot: " << ffw::dot(a, c) << std::endl;
// Will give you compile error due to the reason that 'a' and 'c'
// are different data types!

std::cout << "dot: " << ffw::dot(a, b) << std::endl;
std::cout << "cross: " << ffw::cross(a, b) << std::endl;
// 'a' and 'b' remain unmodified!

// Prints:
// dot: -0.7
// cross: -0.25, -0.5, 0.9
```

As a proof a links to symbolab.com for [cross product](https://www.symbolab.com/solver/vector-cross-product-calculator/%5Cbegin%7Bpmatrix%7D1%26-0.5%260%5Cend%7Bpmatrix%7D%5Ctimes%5Cbegin%7Bpmatrix%7D-0.2%261%260.5%5Cend%7Bpmatrix%7D) and [dot product](https://www.symbolab.com/solver/vector-dot-product-calculator/%5Cleft(1%2C%20-0.5%2C%200%5Cright)%5Ccdot%5Cleft(-0.2%2C%201%2C%200.5%5Cright))