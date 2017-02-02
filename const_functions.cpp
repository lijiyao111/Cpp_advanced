/*
const used with function
*/

#include <iostream>
using namespace std;

class Dog{
    int age;
    string name;

public:
    Dog(){
        age=3;
        name="dummy";
    }

    // parameter constness, can be overloaded
    void setAge(const int & a){ age =a;}
    void setAge(int & a){ age =a;}

    //
    // void setName(const string b){name=b;} cannot be overloaded, only reference const non-const can
    void setName(string b){name=b;}

    // Non meaning to set the return value by const but without reference, e.g. const string getName()
    const string& getName() {return name;}

    //const function
    // Cannot change member variables, && can only call other const member function
    void printDog() const {cout<< name<<' ' <<age <<" const" <<endl;}
    void printDog() {cout<< name<<' ' <<age <<" non-const"<<endl;}


};

int main(){
    Dog d;
    const Dog d2;

    int b=3;
    const int c=4;
    d.setAge(b);
    d.setAge(c); // overloading is OK!

    d.printDog(); // call non-const function when Dog is nonconst
    d2.printDog(); // call the const function when Dog is const
}
