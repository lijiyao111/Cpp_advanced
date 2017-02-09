/* New functions in C++ 11 */

/*
1. Initializer List
*/

//C++ 03 initializer list:
int arr[4]={3,2,3,5};

//C++ 11 extend it from array to other containers:
vector<int> v = {2,3,4,5,6}; // calling initializer_list constructor

// All the relevant STL containers have been updated to accept initializer_list

// Define your own initializer_list constructor:
#include <initializer_list>
class boVector{
    vector<int> m_vec;
public:
    boVector(const initializer_list<int>& v){
        for (initializer_list<int>::iterator itr = v.begin(); itr != v.end(); ++itr){
            m_vec.push_back(*itr);
        }
    }
};

boVector v={0,1,2,3,4};
boVector v{0,1,2,3,4}; // The same

/*
2. Uniform Initialization
*/
// C++03
class Dog{   // Aggregate class or struct
public:
    int age;
    string name;
};
Dog d1={5,"Henry"}; // Aggregate Initialization

// C++11 extend the curly brace initialization to ANY classes
// as long as its constructor takes the same parameters
class Dog
{
public:
    Dog(int age, string name){}
};
Dog d1={5,"Henry"};

/* Uniform Initialization Search Order:
    1. Initializer_list constructor
    2. Regular constructor that takes the appropriate parameters.
    3. Aggregate initializer
*/
// Example:
Dog d1{3};

class Dog{
public:
    int age;                                // 3rd choice

    Dog(int a){                             // 2nd choice
        age=a;
    }
    Dog(const initializer_list<int>& vec){  // 1st choice
        age=*(vec.begin());
    }
};


/*
3. auto type
*/
std::vector<int> vec ={2,3 4,5};

// C++03
for(std::vector<int>::iterator it = vec.begin(); it!= vec.end(); ++it){
    m_vec.push_back(*it);
}

// C++11: use auto type,  infer the type from the rvalue
for (auto it=vec.begin(); it!=vec.end(); ++it){
    m_vec.push_back(*it);
}

auto a=6;       // a is a integer
auto b=9.6;     // b is a double 
auto c=a;       // c is an integer

// IDE becomes more important to discover the real type of auto-defined variable

/*
4. foreach
*/
// C++03
for (vector<int>::iterator itr=v.begin(); itr!=v.end(); ++itr){
    cout<<(*itr);
}

// C++11
for (int i: v){     // works on any class that has begin() and end()
    cout<< i;       // read-only access
}

for (auto &i: v){
    i++;                   // changes the values in v
}

/*
5. nullptr

To replace NULL in C++03; NULL is defined as integer 0
*/
void foo(int i){ cout<< "foo int"<<endl;}
void foo(char* pc){ cout<<"foo char*"<<endl;}

int main(){
    foo(NULL);  // Ambiguity, int or null pointer?

    //C++11
    foo(nullptr);
}

/*
enum class
*/
// C++03,  enumerators are bassically integers
enum apple {green_a, red_a};
enum orange {big_o, small_o};
apple a = green_a;
orange o = big_o;

if(a==o)
    cout<<"green apple and big orange are the same\n";
else
    cout<<"green apple and big orange are not the same\n";
// Output: green apple and big orange are the same

// C++11, introduce enum class, more strong typed, safer to use
enum class apple {green, red};
enum class orange {big, small};
apple a=apple::green;
orange o = orange::big;

if(a==o)
    cout<<"green apple and big orange are the same\n";
else
    cout<<"green apple and big orange are not the same\n";
// Compile fails because no definition for ==(apple, orange)

/*
7. static_assert
*/
// run-time assert, C++03
assert(myPointer != Null);

// Compile time assert, (C++11)
static_assert(sizeof(int)==4);

/*
8. Delegating Constructor
*/
/* Idea, won't work in C++ (probably OK in java)
class Dog{ 
public:
    Dog(){...}
    Dog(int a){Dog(); doOtherThings(a);}  // Constructors share the same code
};
*/

// C++03
class Dog{
    init(){...}
public:
    Dog(){init();}
    DOg(int a){init(); doOtherThings();}
};
/* Cons:
1. Cumbersome code, multiple duplication
2. init() could be invoked by other functions.
*/

// C++11
class Dog{ 
    int age =9; // C++11 allows in-class data member initialization, age will be initialized at every constructor
public:
    Dog(){...}
    Dog(int a) :Dog() { doOtherThings();}  
};
// Limitation: Dog() has to be called first









