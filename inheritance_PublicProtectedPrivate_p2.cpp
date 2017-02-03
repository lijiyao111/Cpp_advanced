/*
public inheritance:  is-a relation, e.g., D_pub is-a kind of a B.

private inheritance: similar to has-a relation. Similar to Composition.
*/

#include <iostream>
using namespace std;

class Ring {
public:
    void tinkle(){}
};

// Composition
class Dog {
    Ring m_ring;
    Ring m_ring2; // can definte another Ring object
public:
    void tinkle() {m_ring.tinkle();}  // call forwarding
};

// Private Inheritance
// Private inheritance can access Ring protected members, but Composition cannot
// and overriding virtual function is much easier in Private inheritance
class Dog2: private Ring{
public:
    using Ring::tinkle;
};

int main(){}

