/*
C++ Keyword: using

1. using directive: to bring all namespace members into current scope
    Example:
    using namespace std;

2. using declaration
    a. Bring one specific namespace member to current scope.
    b. Bring a member from base class to current class's scope.
    Example:
    using std::cout;
    cout<<"Hello World.\n";
*/

using namespace std; // case 1, global scope
using std::cout;  // case 2.a, global scope

class B{
public:
    void f(int a);
};

class D: private B{
public:
    void g(){
        using namespace std;  // case 1, local scope
        cout<<"From D: \n";
    }
    void h(){
        using std::cout;   // case 2.a, local scope
        cout<<"From D: \n";
    }

    // TO overcome name hiding
    void f();
    using B::f;   // case 2.b class scope

    // Illegal in class scope
    using std::cout;
    using namespace std;
}

using B::f; // illegal, class cannot be used in global or local scope

D d;
d.f(8);


/*
Anonymous Namespace, namespace without a name
*/

// anonymous namespace is similar to static global function
static void h() {std::cout<<"h() \n"; }

void g();
namespace{
    void g();
    void h() {std::cout<<"h() \n";}
}

int main(){
    h();
}
