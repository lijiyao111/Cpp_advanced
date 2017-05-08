/*
Handle self-assignment in operator=
if not handled carefully, self assignment could be dangerous
*/
#include <iostream>
using namespace std;

class Collar{
public:
    string color;
    Collar(string c){color=c;}
};
class Dog{
    Collar * pCollar;
public:
    Dog(string color){pCollar=new Collar(color);}
    ~Dog(){delete pCollar;}
    Dog& operator=(const Dog& rhs){
/* Wrong  // if self assigenment, bad
        delete pCollar;  // If self assignment, this is very unsafe
        pCollar=new Collar(*rhs.pCollar);
        return *this;
*/
/* Solution 1
*/
        if (this == &rhs) return *this;

        Collar * pOrigCollar = pCollar;
        pCollar=new Collar(*rhs.pCollar);
        delete pOrigCollar;  // delete after the new is successful
        return *this;
/* Solution 2

        *pCollar=*rhs.pCollar;  // If self assign, copy itself
        return *this;
*/
/* Solution 3
        Dog tmp(rhs); // Assume the copy constructor is deep copy
        swap(pCollar, tmp.pCollar);
        return *this;
*/
    }
};

int main(){
    Dog d1("Yellow"),d2("Blue");
    d1=d2;
    // d1=d1; in self assignment, pCollar will be deleted twice, code crash
}

