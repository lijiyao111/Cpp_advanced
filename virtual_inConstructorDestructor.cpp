/*
Call virtual funciton in Constructor or Destructor

No meaning to call virtual function in Constructor or Destructor
Because either derived class is not created, or has been destroyed
*/

#include <iostream>
using namespace std;

class Dog{
public:
    Dog() {cout <<"Dog born. "; bark();}
    virtual void bark(){cout<<"I am just a dog."<<endl;}
    void seeCat(){bark();}
    ~Dog() {cout <<"Dog destroyed. "; bark();}
};

class YellowDog: public Dog{
public:
    YellowDog(){cout<<"Yellow Dog is born. ";  bark();}
    virtual void bark(){ cout<<"I am a yellow dog."<<endl;}
    ~YellowDog(){cout<<"Yellow Dog is destroyed. ";  bark();}
};

int main(){
    YellowDog d;
    // If bark() is not virtual, this will print base class bark()
    // because seeCat() is base class function
    d.seeCat(); 
}

/* Output:
Dog born. I am just a dog.
Yellow Dog is born. I am a yellow dog.
I am a yellow dog.
Yellow Dog is destroyed. I am a yellow dog.
Dog destroyed. I am just a dog.
*/
