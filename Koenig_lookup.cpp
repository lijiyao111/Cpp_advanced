/*
Koenig Lookup
*/

#include <iostream>
using namespace std;

// Example 1.
// namespace A{
//     struct X{};
//     void g(X){cout<< " Calling A::g() \n";}
// }

// int main(){
//     A::X x1;
//     g(x1);  // Koenig Lookup, also look into the scope where its parameter is defined
// }

// Example 2.
class C{
public:
    struct Y{};
    static void h(Y){ cout<<"calling C::h() \n";}
};

int main(){
    C::Y y;
    C::h(y);
    // h(y); // Won't compile, Koenig lookup does not apply to Class, only to namespace
}

/*
With namespace:
current scope => next enclosed scope => ... => global scope

To override the sequence:
    1. Qualifier or using declaration
    2. Koenig lookup

With classes:
current scope => parent scope => ... => global scope

To override the sequence:
    - Qualifier or using declaration

Name hiding
*/
