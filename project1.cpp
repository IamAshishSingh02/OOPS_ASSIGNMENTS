//Implement a class Complex which represents the Complex Number data type. Implement the following
//1.	Constructor (including a default constructor which creates the complex number 0+0i).
//2.	Overload operator+ to add two complex numbers.
//3.	Overload operator* to multiply two complex numbers.
//4.	Overload operators << and >> to print and read Complex Numbers

#include <bits/stdc++.h>
using namespace std;

class Complex 
{
    double real;
    double img;

public:

    //Default Constructor
    Complex():real(0),img(0){}

    //Parameterized Constructor
    Complex(double r,double i):real(r),img(i){}

    //Overload '+' Operator
    Complex operator+(const Complex &other)const 
    {
        return Complex(real+other.real,img+other.img);
    }

    //Overload '*' Operator
    Complex operator*(const Complex &other)const 
    {
        return Complex(real*other.real-img*other.img,real*other.img+img*other.real);
    }

    //Overload '>>' Operator
    friend istream &operator>>(istream &in,Complex &c) 
    {
        in>>c.real>>c.img;
        return in;
    }

    //Overload '<<' Operator
    friend ostream &operator<<(ostream &out,const Complex &c) 
    {
        out<<c.real;
        if (c.img>=0)
            out<<" + "<<c.img<<"i";
        else
            out<<" - "<<-c.img<<"i";
        return out;
    }
};

int main() 
{
    Complex C1,C2,C3,C4;

    //Input complex numbers
    cout<<"Enter Real and Imaginary part of the Complex Number 1: ";
    cin>>C1;
    cout<<"Enter Real and Imaginary part of the Complex Number 2: ";
    cin>>C2;

    //Perform addition and multiplication
    C3=C1+C2;
    C4=C1*C2;

    //Output results
    cout<<"Addition: "<<C3<<endl;
    cout<<"Multiplication: "<<C4<<endl;

    return 0;
}
