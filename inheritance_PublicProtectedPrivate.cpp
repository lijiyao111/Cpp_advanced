/*
Public, Protected, Private Inheritance
*/

#include <iostream>
using namespace std;

/*

class B{};
class D_priv: private B{};
class D_prot: protected B{};
class D_pub: public B{};

*/

/* 
Access Control:
1. None of the derived classes can access anything that is private in B.
2. D_pub inherits public members of B as public and the protected members of B as protected.
3. D_priv inherits the public and protected members of B as private.
4. D_prot inherits the public and protected members of B as protected.

Casting rule:
1. Anyone can cast a D_pub* to B*. D_pub is a special kind of B. (is-a relationship between base and child)
2. D_priv's members and friends can cast a D_priv* to B*.
3. D_prot's members, friends, and children can cast a D_prot* to B*.
*/

// Example
class B{
    public:
        void f_pub(){cout<<"f_pub is called.\n";}
    protected:
        void f_prot(){cout<<"f_prot is called.\n";}
    private:
        void f_priv(){cout<<"f_priv is called.\n";}
};

class D_pub: public B{
public:
    void f(){
        f_pub(); // OK, D_pub public function
        f_prot(); // OK, D_pub public function
        // f_priv(); // Error! B's private function
    }
};

class D_prot: protected B{
public:
    void f(){
        f_pub(); // OK, D_prot protected function
        f_prot(); // OK, D_prot protected function
        // f_priv(); // Error! B's private function
    }
};

class D_priv: private B{
public:
    void f(){
        f_pub(); // OK, D_priv private function
        f_prot(); // OK, D_priv private function
        // f_priv(); // Error! B's private function
    }
};

int main(){
    D_pub D1;
    D1.f_pub(); // OK
    D_prot D2;
    // D2.f_pub(); // Error, D_prot's f_pub() is protected

    B* pB=&D1; // OK
    // pB=&D2; // Error, D2 is protected inheritance of B
}