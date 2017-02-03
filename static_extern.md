The keyword static has different meanings in C++, depending on the context.

When declaring a free function or a global variable it means that the function is not to be available outside of this single translation unit:
```
// test.cpp
static int a = 1;
static void foo() {}
```
If the result of compiling that translation unit is linked with a different translation unit containing symbols a and foo it will not break the One Definition Rule, as in this particular translation unit a and foo are private symbols. This use has been obsoleted by unnamed namespaces.
```
// test2.cpp
namespace {
   static int a = 1;
   static void foo() {}
}
```

If global variable is not local to one file, definte it there and then declare it in other files:
```
//file1.cpp
int a=1;
//file2.cpp
extern int a; // then a can be used
```

When declaring a local variable within a function it means that the lifetime of the variable will extend from the first call to the function to the end of the program, and not only for the duration of the call:
```
int foo() {
   static int counter = 0;
   return ++counter;
}
int main() {
  for ( int i = 0; i < 10; ++i ) { 
     std::cout << foo() << std::endl;
  }
}
```
In the previous code, counter is initialized once when foo is called for the first time, but the variable will outlive the function and keep the value across different function calls. The previous code will print "1 2 3 4... 10". If the variable was not declared static then the output would be "1 1 1... 1".

Within a class scope, static means that the member is a member of the class, and not of a particular instance. This use is equivalent to the use in your other question: usage of that particular member is not bound to any specific object.
```
struct test {
   int x;
   static int y;
};
int test::y;       // need to define it in one translation unit
int main() {
   // test::x = 5; // !error cannot access a non-static member variable
                   // without an instance
   test::y = 5;    // ok
   test t, other;
   t.x = 10;       // ok
   t.y = 15;       // ok, the standard allows calling a static member through
                   // an instance, but this is the same as test::y
}
```
In this case, the member x is a non-static member attribute, and as such there is a different x for each instance of the class. In the sample program t.x and other.x refer to different integers. On the other hand y is static and thus there is a single instance of test::y in the program. Even if the standard allows to call t.y and other.y both uses refer to the same variable. The same goes with member methods. If they are static they are class-level methods and can be called without an instance, while if they are non-static they are applied to a concrete instance and the a.b or a->b syntax must be used.

This use of static is similar to the use of the same keyword in Java, while the other two are not present in that language. There is one use of the keyword in Java that is not present in C++, and that is the use of static class initializers (a block of code at class level surrounded by static { ... }). In Java that block of code will be executed when the class is loaded and only once. Initialization of static member variables in C++ must be done in the initializer of the variable definition.