// Introduction to Templates

// Template cause code bloat, different versions of code will be stored
#include <iostream>
using namespace std;

template <class T>
T square(T x){
    return x*x;
}

template <class T>
class BoVector{
    T arr[1000];
    int size;
public:
    BoVector():size(0){}
    void push(T x){ arr[size]=x; size++; }
    T get(int i) const {return arr[i];}
    int getSize() const { return size;}
    void print() const {
        for(int i=0; i<size; i++){
            cout<< arr[i]<<endl;
        }
    }
};

// Operator modifier
template <class T>
BoVector<T> operator* (const BoVector<T>& rhs1, BoVector<T>& rhs2){
    BoVector<T> ret;
    for (int i=0;i<rhs1.getSize(); ++i){
        ret.push(rhs1.get(i)*rhs2.get(i));
    }
    return ret;
}

int main(){
    // For function template, it's OK to not specify Typename
    cout<<square<int>(5)<<endl; // 
    cout<<square(5)<<endl; // 
    cout<<square<float>(5.5)<<endl;

// For class template, MUST specify Typename
    BoVector<int> bv;
    bv.push(2);
    bv.push(5);
    bv.push(8);
    bv.push(9);
    bv.print();

    cout<<"Print squared bv:"<<endl;
    bv=square(bv);
    bv.print();

}