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

    Person(const Person& rhs) = delete;
    Person& operator=(const Person& rhs) = delete;

    // if really need copy of object
    // in this case, no implicit copy
    Person* clone(){
        return (new Person(*pName_));
    }

private:
    string* pName_;
};

// Solution 1: Define copy constructor and copy assignment operator for deep copying
// Solution 2: Delete copy constructor and copy assignment operator

int main(){
    vector<Person *> persons;
    persons.push_back(new Person("George"));
    // 1. "George" is constructed
    // 2. A copy of "George" is saved in the vector persons (shallow copy, only the pointer)
    // 3. "George" is destroyed (now the pointer doesn't point to anything)

    persons.back()->printName();

    Person p2("Jack");
    Person * p1=p2.clone(); // make a copy
    p1->printName(); // pring Jack


    cout<<"Goodbye."<<endl;
}
