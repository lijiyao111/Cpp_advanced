/* 
The Duality of Public Inheritance.
    - Inheritance of Interface.
    - Inheritance of Implementation.
*/

class Dog{
public:
    virtual void bark()=0;  // Interface only
    void run() { cout<< "I am running.";} // Dual 
    virtual void eat(){ cout<<"I am eating.\n";} // if YellowDog override, eat is interface. If not, eat is Dual

protected:
    void sleep(){cout<<"I am sleeping.\n";}  // YellowDog only inherit the implementation, not interface
};

class YellowDog: public Dog{
public:
    virtual void bark() {cout<< "I am a yellow dog.\n";}

    void iSleep(){sleep();}
};

/* Types of Inheritance in C++:
    1. Pure virtual public function -- inherit interface only
    2. Non-virtual public function -- inherit both interface and implementation
    3. Impure virtual public function -- inherit interface and default implementation
    4. Protected function  -- inherit implementation only

It is important to separate the concepts of interface and implementation.
*/

/* Interface inheritance
    1. Subtyping   --- on Type can be used in place where another Type is expected
    2. Polymorphism
*/
virtual void bark()=0;

/* Pitfalls:
-- Be careful of interface bloat.
-- Interfaces do not reveal implementing.
*/

/* Implementation Inheritance
    -- Increase code complexity
    -- Not encouraged
*/

public:
    void run() { cout<< "I am running.";} // Dual 
    virtual void eat(){ cout<<"I am eating.\n";} // if YellowDog override, eat is interface. If not, eat is Dual
protected:
    void sleep(){cout<<"I am sleeping.\n";}  // YellowDog only inherit the implementation, not interface

/* Guidelines for Implementation Inheritance:
    1. Do not use inheritance for code reuse, use composition
    2. Minimize the implementation in base classes. Base classes should be thin.
    3. Minimize the level of hierarchies in implementation inheritance.
*/