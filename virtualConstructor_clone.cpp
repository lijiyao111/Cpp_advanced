/*
Clone is like a virtual constructor
make sure the proper type of object will be constructed, 
no matter what type the original object has been cast into
*/

#include <iostream>
using namespace std;

// // Problem: c is not identical copy of d
// class Dog{
// public:
//     virtual void bark(){
//         cout<<"This is a dog."<<endl;
//     }

// };

// class YellowDog: public Dog{
// public:
//     virtual void bark(){
//         cout<<"This is a yellow dog."<<endl;
//     }

// };
// // Problems:
// void foo(Dog* d){  // This is a YellowDog
//     Dog *c = new Dog(*d); // this is a Dog, not a YellowDog;
//     // c is not identical copy of d
//     c->bark(); // Output: This is a dog.
// }



class Dog{
public:
    virtual Dog* clone(){ return (new Dog(*this)); }
    virtual void bark(){
        cout<<"This is a dog."<<endl;
    }

};

class YellowDog: public Dog{
public:
    virtual YellowDog* clone(){ return (new YellowDog(*this)); } // co-variant return type
    // the overwriting function is returning a different type (YellowDog*)
    //, which is based on the return type in the base class (Dog *)
    virtual void bark(){
        cout<<"This is a yellow dog."<<endl;
    }

};
// Problems:
void foo(Dog* d){ 
    Dog *c = d->clone(); // Now c is a YellowDog
    c->bark(); //Output: This is a yellow dog.
}

int main(){
    YellowDog d;
    foo(&d);
}