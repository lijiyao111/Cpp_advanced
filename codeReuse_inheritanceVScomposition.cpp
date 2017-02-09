/*
Code Reuse: Inheritance Vs. Composition
*/



// Reuse through Inheritance
class Dog{
    // common activities
};

class BullDog: public Dog{
    // Call the common activities to perform more tasks
};

class ShepherdDog: public Dog{
    // Call the common activities to perform more tasks
};


// Reuse through Composition
class ActivityManger{
    // common activities
};

class Dog{
};

class BullDog: public Dog{
    ActivityManger * pActMngr;
    // Call the common activities through pActMngr
};

class ShepherdDog: public Dog{
    ActivityManger * pActMngr;
    // Call the common activities through pActMngr
};

/* Code reuse: composition is better than inheritance

1. Less code coupling between reused code and reuser of the code
    a. Child class automatically inherits ALL parent class's public members
    b. Child class can access parent's protected members.
        - Inheritance break the encapsulation
        - Friends and Children are the enemy of class privacy

2. Dynamic Binding, The relationship
    a. Inheritance is bound at compile time  (base and derived)
    b. Composition can be bound either at compile time or at run time  (use the activity pointer)
*/

class OutdoorActivityManager : public ActivityManger{};
class IndoorActivityManager : public ActivityManger{};

/*
3. Flexible code construct
    Dog          ActivityManager
    BullDog      OutdoorActivityManager
    ShepherdDog  IndoorActivityManager
*/