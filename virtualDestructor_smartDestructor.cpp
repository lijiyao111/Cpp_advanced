/*
If a class is used in polymophic way, better define its destructor as virtual
OR, use smart pointer, shared_ptr
*/
#include <iostream>
#include <memory>
using namespace std;

class Dog{
public:
    // With virtual destructor:
    // YellowDog destroyed
    // Dog destroyed
    // Without virtual:
    // Dog destroyed
    virtual ~Dog(){cout<<"Dog destroyed"<<endl;}

    // If there is any virtual function, better use virtual destructor
    // virtual void bark(){};
};

class YellowDog:public Dog{
public:
    ~YellowDog(){cout<<"YellowDog destroyed"<<endl;}
};

class DogFactory{
public:
    static Dog* createYellowDog(){
        return (new YellowDog());
    }
};

int main(){
    Dog* pd=DogFactory::createYellowDog();

    delete pd;
}

/*
Or use shared pointer
*/

// class Dog{
// public:
//     ~Dog(){cout<<"Dog destroyed"<<endl;}

// };

// class YellowDog:public Dog{
// public:
//     ~YellowDog(){cout<<"YellowDog destroyed"<<endl;}
// };

// class DogFactory{
// public:
//     static shared_ptr<Dog> createYellowDog(){
//         return shared_ptr<YellowDog> (new YellowDog());
//     }
// };

// int main(){
//     shared_ptr<Dog> pd=DogFactory::createYellowDog();

//     // delete pd; No need for this
// }