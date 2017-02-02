/*
compiler generate 4 default functions for class
1. copy constructor  // Member by member initialization
2. copy assignment operate  // Member by member copying
3. Destructor  // call base class and member default destructor
4. Constructor  // call base class and member default constructor
*/
#include <iostream>
using namespace std;

// Example
/*
copy constructor  -- No, not used
copy assignment  -- Yes
Destructor  -- No
Constructor  -- No
*/
class dog{
public:
    string m_name;

    dog(string name="Bob"){
        m_name=name;
        cout<<name<<" is born."<<endl;
    }
    ~dog(){cout<<m_name<<" is destroyed.\n";}
};

class toy{
public:
    toy()=default; // This is required, otherwise toy(string color){} will not construct by default
    // toy(){} // this define default destructor too
    toy(string color){cout<<" toy is born.\n";}
};

class cat{
    toy m_toy;

};

int main(){
    dog dog1("Henry");
    dog dog2;
    dog2=dog1;
/* output:
Henry is born.
Bob is born.
Henry is destroyed.
Henry is destroyed.
*/

    cat cat1;
}