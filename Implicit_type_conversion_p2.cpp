/* Implicit type conversion is useful when creating numerical types of class,
such as rational class
*/

class Rational {
public:
    // no explicit keyword, can take one parameter input, make the constructor also a type convertor
    // Constructor, & implicit type convertor & explicit type convertor
    Rational(int numerator=0, int denominator=1): num(numerator),den(denominator) {}
    int num;
    int den;

// This will also use implicit conversion from int to Rational in the parameter
    // const Rational operator*(const Rational& rhs){
    //     return Rational(num*rhs.num, den*rhs.den);
    // }

    operator int () const { return num/den; }


};

int main(){
    Rational r1=23;
    Rational r2=r1*2; // Since we define two-way implicit type conversion, ambiguity prevent code compile
                    // r1 to int is OK, 2 to Rational is OK, ambiguous!
    Rational r3=3*r1; // can not convert int to Rational
}

// Another way of keep r2 and r3 work
// const Rational operator*(const Rational& lhs, const Rational& rhs) {
//     return Rational(lhs.num*rhs.num, lhs.den*rhs.den);
// }