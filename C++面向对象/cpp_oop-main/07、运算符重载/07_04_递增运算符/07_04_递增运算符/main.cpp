#include <iostream>
using namespace std;

/*
++

«∞÷√++
∫Û÷√++
*/

class Complex {
    friend ostream& operator<<(ostream& c, const Complex& a);
public:
    Complex() : real(0), image(0) {}
    Complex(int real, int image) {
        this->real = real;
        this->image = image;
    }

    Complex& operator++() {
        this->real += 1;
        return *this;
    }

    Complex operator++(int) {
        Complex c = *this;
        this->real += 1;
        return c;
    }

private:
    int  real;
    int image;
};

ostream& operator<<(ostream& c, const Complex& a) {
    c << a.real << '+' << a.image << 'i';
    return c;
}

class A {

};
A func1() {
    return A();
}
void func2(const A& a) {

}

int main() {
    int x = 1;
    cout << ++(++x) << endl;
    cout << x << endl;

    Complex a(10, 10);
    cout << a << endl;
    // ++a;
    cout << ++(++a) << endl;
    cout << a << endl;

    cout << a++ << endl;
    cout << a << endl;

    // func2(func1());

    // cout << ((a++)++)++ << endl;
    cout << a << endl;

    int b = 5;
    // cout << ((b++)++)++ << endl;
    cout << b << endl;

    return 0;
}