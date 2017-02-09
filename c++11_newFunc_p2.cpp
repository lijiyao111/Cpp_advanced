/* New functions in C++ 11 */ -- continued

/*
9. override (for virtual function)

to avoid inadvertently create new function in derived classes.
*/
// C++03
class Dog{
    virtual void A(int);
    virtual void B() const;
};

class YellowDog: public Dog{
    virtual void A(float);   // accidentally Create a new function, not overriding
    virtual void B();        // accidentally Create a new function, not overriding
};

// C++11
class Dog{
    virtual void A(int);
    virtual void B() const;
    void C();
};

class YellowDog: public Dog{
    virtual void A(float) override;   // Error! no function to override
    virtual void B() override;       // Error! no function to override
    void C() override;               // Error! no function to override, C() is not virtual function   
};


/*
10. final (for virtual function and for class)
*/
class Dog final{ // no class can be derived from Dog
    ...
};

class Dog{
    virtual void bark() final;  // No class (derived classes) can override bark()
};


/*
11. Compiler Generated Default Constructor
*/
class Dog{
    Dog(int age) {}
};
Dog d1;     // Error: compiler will not generate the default constructor

// C++11
class Dog{
    Dog(int age);
    Dog() = default; // Force compiler to generate the default constructor
};

/* 
12. delete
*/
class Dog{
    Dog(int age){}
};

Dog a(2);
Dog b(3.0);  // 3.0 is converted from double to int
a=b;         // Compiler generated assignment operator

// C++11
class Dog{
    Dog(int age) {}
    Dog(double ) = delete;  // Disallow some functions
    Dog & operator = (const Dog&) = delete;
};


/*
13. constexpr
(This seems like Macro to me. )
*/
int arr[6];         // OK
int A(){return 3;}
int arr[A() + 3];   // Compile Error

// C++11
constexpr int A(){return 3;} // Force the computation to happen at compile time

int arr[A()+3];              // Create an array of size 6

// Write faster program with constexpr
constexpr int cubed(int x) { return x*x*x; }

int y= cubed(1789); // compute at compile time


/*
14. New string literals
C++ 11 provide better support for unicode (not very helpful to me.)
*/
// C++03
char * a="string";

// C++11
char * a=u8"string";        // define an UTF-8 string
char16_t * b = u"string";   // define an UTF-16 string
char32_t * c = U"string";   // define an UTF-32 string
char * d=R"string \\";      // define a raw string

/*
15. Lambda function
anonymous function
*/
cout<<[](int x, int y){return x+y;}(3,4)<<endl;  // Output  7
auto f=[](int x, int y){return x+y;};
cout<< f(3,4)<< endl; // Output 7

// Functional programming
template<class func>
void filter(func f, vector<int> arr){
    for (auto i: arr){
        if (f(i))
            cout<< i <<" ";
    }
}

int main(){
    vector<int> v={1,2,3,4,5,6};

    filter([](int x){return (x>3);}, v);   // Output: 4 5 6
    filter([](int x){return (x>2 && x<5);}, v);   // Output: 3 4

    int y=4;
    filter([&](int x){return (x>y);}, v);  // Output: 5 6
    // Note:  [&] tells compiler that we want local variable capture
}


// END, visit boqian.weebly.com

