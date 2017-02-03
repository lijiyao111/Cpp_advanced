//############################
/* Main topic is User Defined Implicit Type Conversion

Categories of Type Conversion:

                                     Implicit   Explicit
Standard Type Conversion                A          B
User Defined Type Conversion            C          D
                                            (also called casting)
*/

#include <iostream>
using namespace std;

// // Category A: Implicit Standard Type Conversion
// char c='A';
// int i=c; // called integral promotion
// char * pc=0; // Null pointer initialization

// void f(int i); // parameter passing
// f(c);

// dog *pd=new yellowdog();  // pointer type conversion


/* Category C: Implicit User Defined Type Conversion
Defined inside class (user defined type)

There are 2 methods to define implicit user defined type conversion:
Method 1: Use constructor that can accept a single parameter.
    - convert other type of object into your class
Method 2: Use the type conversion function
    - convert an object of your class into other types
*/

/*
HOWEVER! too many implicit conversion make the interface too easy to use incorrectly, Not Good!

Principle: make interface easy to use correctly and hard to use incorrectly.
How hard is enough?  Ideally, uncompilable.

General guideline:
    1. Avoid defining seemingly unexpected conversion. // e.g. don't allow implicit conversion from Dog to String 
    2. Avoid defining two-way implicit conversion.
*/

class Dog{
public:
    Dog(string name){m_name=name;}
    // use explicit will prevent implicit conversion  
    // explicit Dog(string name){m_name=name;}
    string getName(){return m_name;}

    operator string () const {return m_name;}
private:
    string m_name;
};

void foo(Dog b){
    cout<<b.getName()<<endl;
};

int main(){
    string m="Bob",m2="Jim";
    Dog d1=m,d3("Bob");  // Also use implicit conversion from string to class
    // The same as Dog d1(Dog(m))

    foo(m); // Implicit conversion from string to user defined class

    string d2=d1; // Implicit convert Dog to String

    m=d1; // Implicit convert Dog to String

    d3=m2; // Implicit conversion from string to Dog

    cout<<m<<endl;

    cout<<d3.getName()<<endl;

}