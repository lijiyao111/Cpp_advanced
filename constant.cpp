/*
const
- a compile time constraint that an object cannot be modified

Why use constant:
- Guard against inadvertent write to the variable
- Self documenting
- Enable compiler to do more optimization, making code tighter
- const means the variable can be put in ROM (Read only Memory)
*/

int main(){
    const int i=9;
    // i=6; would not compile

    const_cast<int&>(i)=6; // cast away the const

    int j;
    // static_cast<const int&>(j)=9; // add const to variable, won't compile

    int k=2;

    const int *p1=&k; // 'const' object must be initialized if not 'extern'
    // *p1=2; won't compile
    p1 ++; //OK

    int *const p2=&k; // pointer is const
    int const* const p3=&k; // both data and pointer are const

// const is on left of *, data const
// const is on right of *, pointer const

}

