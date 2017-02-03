/*
All casting considered

Type Conversion:
    1. Implicit Type Conversion
    2. Explicit Type Conversion - Casting
*/

/*  C++ style casting
                                Generate_Code           Generate_Data        risky          data_type
                                runable code      consider pointee not pointer
Object casting:
    static_cast                     yes                     yes                2            any types

Pointer/Reference casting
    static_cast                      no                     no                 4           related types
    dynamic_cast                    Yes                     No                 3          related types(mostly down cast)
    const_cast                       no                     no                  1           same type
    reinterpret_cast                 no                     no                  5           any type
*/

/*
1. static_cast
It works for any type, as long as the type conversion is defined for that type

 No checks are performed during runtime to guarantee that the object being converted is in fact a full object of the destination type. 
 Therefore, it is up to the programmer to ensure that the conversion is safe.
 it does not incur the overhead of the type-safety checks of dynamic_cast.
*/
int i = 9;
float f = static_cast<float>(i); // convert object from one type to another
Dog d1 = static_cast<Dog>(string("Bob"));  // Type conversion from string to Dog need to be defined
Dog * pd = static_cast<Dog *>(new YellowDog()); // convert pointer/reference from one type to a related type (only down/up cast)

/*
2. dynamic_cast
dynamic_cast can only be used with pointers and references to classes (or with void*). 
Its purpose is to ensure that the result of the type conversion points to a valid complete object of the destination pointer type.
*/
Dog * pd=new YellowDog(); // implicit type conversion
YellowDog py= dynamic_cast<YellowDog*>(pd);
// a. only work with pointer/reference. Convert one type to a related type (down/up cast)
// b. run-time type check. If succeed, py==pd; if fail, py==0. (For reference cast, if fail, throw bad_cast exception)
// c. It requires the 2 types to be polymorphic (have virtual function)

/*
3. const_cast
cast away the constness
// a. only work with pointer/reference
// b. only work on the same type
*/
const char* str = "Hello World";
char * modifiable = const_cast<char*>(str);

/*
4. reinterpret_cast
convert any pointer type to any other pointer type, even of unrelated classes
Very unsafe !!!
*/
long p=51110980;
Dog * dd=reinterpret_cast<Dog*>(p); // cast long int to pointer
// int p2=reinterpret_cast<int>(p) // This won't run
// The ultimate cast that can cast one pointer to any other type of pointer

/* 
C-Style casting;
// A mixture of static_cast, const_cast and reinterpret_cast (No dynamic_cast)
*/
short a=2000;
int i = (int) a; // c-like cast notation
int j = int(a); // functional notation --  the same as above

// Generally C++ styple of cast are preferred over the C-style, because:
// 1. Easier to identify in the code
// 2. Less usage error. C++ style provides:
//      a. Narrowly specified purpose of each cast,
//      b. Run-tim type check capability.