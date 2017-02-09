/*
Public inheritance => "is-a" relation

A Derived class should be able to do everything the Base class can do.

Lesson:
1. Prcise definition of classes;
2. Don't override non-virtual functions.
3. Don't override default parameter values for virtual functions. 
4. Force Inheritance of shadowed functions. (using base_class)
*/

#include <iostream>
using namespace std;

// Penguin inherit from Bird, but penguin cannot fly!!
// remove fly() from Bird.

// class Bird{
// public:
//     void fly();
// };

// class Penguin: Public Bird{};

// Penguin p;
// p.fly(); // This is wrong! penguin cannot fly. 



// Use virtual function!
// And don't overwrite default value for virtual function parameters in derived class!
// virtual function is binded at running time, but default parameter value is set in compile time.

class Dog {
public:
    // void bark(){cout<<"I am a dog.\n";}
    void bark(int age){cout<<"I am "<<age<<" years old\n";}

    virtual void bark(string msg=" just a "){cout<<"I am"<< msg << "dog.\n";}
};

class YellowDog: public Dog{
public:
    // void bark() { cout<<"I am a YellowDog.\n";}
    using Dog::bark;

    virtual void bark(string msg=" a Yellow "){cout<<"I am"<< msg << "dog.\n";}
};

int main(){
    YellowDog *py = new YellowDog();
    py->bark(5); // This will first look into the derived class, if it find any, it will use it, regardless of the parameter type
    // py->bark();
    // Dog *pd=py;
    // pd->bark();
}

/* Output:
I am a YellowDog.
I am a dog.
*/

