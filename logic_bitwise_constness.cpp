/*
logic constness is what you think should be const
bitwise constness is what the compiler regard as const
*/
#include <iostream>
#include <vector>
using namespace std;

class BigArray{
    vector<char> v;
    mutable int accessCounter; // allow const function, or const class object to change some member variable

    int*v2;

public:
    int getItem(int index) const{
        accessCounter++;
        // const_cast<BigArray *>(this)->accessCounter++; // if no mutable when define, use this one
        return v[index];
    }

    // void setV2Item(int index, int x) const{ // this is bitwise const
    // but better not use const since it is not logic const
    void setV2Item(int index, int x){
        *(v2+index)=x;
    }

    // check this one:
    // parameter is the reference to a const pointer pointing to a const int
    const int*const func(const int* const & p) const;
};

int main(){

    BigArray b;

}