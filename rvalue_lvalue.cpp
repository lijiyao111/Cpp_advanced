/*
Understanding Rvalue and Lvalue

Why do I care?
1. Understand C++ construct, and decypher compiler erros or warnings.
2. C++ 11 introduced rvalue reference.
*/

/* Simple Definition:

lvalue: An object that occupyies some identifiable location in memory (can get address)
rvalue: Any object that is not a lvalue

Summary:
1. Every C++ expression yield either an rvalue or lvalue
2. If the expression has an identifiable memory address, it is lvalue; otherwise, rvalue.
*/

// Lvalue examples:
int i;      // i is a lvalue
int *p=&i;  // i's address is identifiable
i = 2;      // Memory content is modified

class Dog;
Dog d1;     // lvalue of user defined type (class)
            // Most variables in C++ code are lvalues

// Rvalue examples:
int x = 2;       // 2 is an Rvalue
int x= i+2;      // (i+2) is an Rvalue
int *p= &(i+2);  // Error! Cannot get address of Rvalue
i+2 =4;          // Error! Rvalue cannot be assigned
2=i;             // Error!

Dog d1;
d1 = Dog();  // Dog() is rvalue of user defined type (class)

int sum(int x, int y){return x+y;}
int i = sum(3, 4); // sum(3, 4) is Rvalue

// Rvalues: 2, i+2, Dog(), sum(3, 4), x+y
// Lvalues: x, i p, d1


// Reference (or lvalue reference)
int i;
int &r=i;
int &r = 5; // Error
//Exception
const int &r=5; // OK

int square(int & x){return x*x;}
square(i);  // OK
square(40); // Error! 40 is an Rvalue

// Solution:
int square(const int& x){ return x*x;}


// Transforming between lvalue and rvalue
// lvalue can be used to create an rvalue
int i=1;
int x=i+2; // i+2 is rvalue
int x=i;  // in this case, i is implicitly transformed into Rvalue

// rvalue can be used to create an lvalue
int v[3];
*(v+2)=4;


// Misconception 1: functions or operator always yields rvalues
int x=i+3;
int y=sume(3,4);

int myglobal;
int &foo(){
    return myglobal;
}

foo() = 50; // OK, return reference of myglobal

// A more common example:
array[3]=50; // Operator [] almost always generates lvalues


// Misconception2 : lvalues are always modifiable
// const is also a lvalue, but not modifiable
const int c=1;
c=2; // Error!


// Misconception 3: rvalues are not modifiable
i+3=6;      // Error
sum(3,4)=7; // Error

// it is not true for user-defined types (class)
class Dog;
Dog().bark(); // bark() may change the status of the Dog object

