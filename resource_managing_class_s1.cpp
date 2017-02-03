/*
Person owns the string through its pointer
*/
#include <iostream>
#include <vector>
using namespace std;

class Person{
public:
    Person(string name){ pName_ = new string(name); }
    ~Person() {delete pName_;}

    void printName(){cout<<*pName_<<endl;}

    Person(const Person& rhs){ // deep copy in copy constructor
        pName_=new string(*(rhs.pName_));
    }
    Person& operator=(const Person& rhs){ // deep copy in copy assignment
        if (this==&rhs)
            return *this;
        delete pName_;
        pName_=new string(*rhs.pName_);
        return *this;
    };

private:
    string* pName_;
};

// Solution 1: Define copy constructor and copy assignment operator for deep copying
// Solution 2: Delete copy constructor and copy assignment operator

int main(){
    vector<Person> persons;
    persons.push_back(Person("George"));
    // 1. "George" is constructed
    // 2. A copy of "George" is saved in the vector persons (shallow copy, only the pointer)
    // 3. "George" is destroyed (now the pointer doesn't point to anything)

    persons.back().printName();

    Person p1("Jim"),p2("Jack");
    p1=p2;
    p1.printName(); // pring Jack

    cout<<"Goodbye."<<endl;
}
