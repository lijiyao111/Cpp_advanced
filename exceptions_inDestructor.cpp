/*
prevent Exceptions from leaving destructors
Two pending exceptions from Destructor will cause code to crash!
Extra comment, if one is not OK. still pending destruction

In the new C++11 standard all throwing destructors terminate the program, even when not UnwindingTheStack
*/

/*
1. Throw exception in Destructor: -- Don't do this
Bad idea, two unhandled exceptions cause the program to TERMINATE
2. Throw exception in Constructor: -- Kind of OK
Destructor for the class will not be called:
- Data members that are fully constructred will be destroyed automatically
- No clean-up process. Any memory allocated in the constructor will not be released.
*/

#include <iostream>
using namespace std;

class Dog{
public:
    string m_name;
    Dog(string name){
        m_name=name;
        cout<<name<<" is born."<<endl;
        // throw 10;
    }
    // If putting a throw in desctructor, code crash:
    // If using C++11, definitely crash
    // If not using C++11, crash there two Dog in try{}
    // ~Dog(){cout<<m_name<<" is destroyed."<<endl; throw 20; }
    ~Dog(){cout<<m_name<<" is destroyed."<<endl;}
    void bark(){}
    // Solution 1
    // ~Dog(){
    //     cout<<m_name<<" is destroyed."<<endl; 
    //     try{
    //         throw 30;
    //     } catch(int e){
    //         cout<<e<<" is caught inside Destroctor."<<endl;
    //     }
    // }
    // Solution 2
    // void prepareToDestr(){throw 20;}
};

int main(){
    try{
        Dog dog1("Henry");
        Dog dog2("Bob");
        dog1.bark();
        dog2.bark();
        // Solution 2
        // dog1.prepareToDestr();
        // dog2.prepareToDestr();
    } catch(int e){
        cout<<e<<" is caught."<<endl;
    }
}

/* Output:
Henry is born.
Bob is born.
Bob is destroyed.
Henry is destroyed.
*/