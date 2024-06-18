#ifndef COMPLEX_H
#define COMPLEX_H
#include <iostream>
#include "combined.h"
#include <math.h>

using namespace std;

template <typename P>                   //CLASS DECLARATION
class Combined;

template <typename T>
class Complex:public Combined<T> {        //SINGLE INHERITANCE
private:
    T real;
    T imaginary;
// protected:
    T gcd(T n1, T n2);
    // void normalise(T num, T denom);
public:
    Complex();
    Complex(T r ,T img);
    Complex(const Complex& ob);
    ~Complex(){};
    
    void setData(T r, T img);
    const Complex& operator++();
    const Complex& operator--();
    const Complex& operator++(int);
    const Complex& operator--(int);
//using member function
    Complex& operator+=(const Complex& ob);
    Complex& operator-=(const Complex& ob);
    Complex& operator*=(const Complex& ob);
    Complex& operator/=(const Complex& ob);
    Complex<T> subtract(const Complex<T> &c1, const Complex<T> &c2);
    // using friend function
    template <typename U>
    friend Complex<U> operator+(const Complex<U>& c1,const Complex<U>& c2);

    void print(){
    cout<<"The resultant complex number obtained is "<<real<<"+"<<"("<<imaginary<<")"<<"i"<<endl<<endl;;
    }

};


// template <class T>
// void Complex<T>::normalise(T n, T d){
//     int x=0;
//     while(x!=1){
//         x = gcd(n,d);
//         numerator=n/x;
//         denominator=d/x;
//     }
// }

template <class T>
T Complex<T>::gcd(T num, T deno)
{
    int gcd = 1;
    for(int i=min(num,deno);i>0;i--){
        if(num%i==0 && deno%i==0) return i;
    }
    return gcd;
}

template <class T>
Complex<T>::Complex(){
    real=0;
    imaginary=0;
}

template <class T>
Complex<T>::Complex(T r ,T img){
    real=r;
    imaginary=img;
}

template <class T>
Complex<T>::Complex(const Complex& ob){
    real=ob.real;
    imaginary=ob.imaginary;
}

template <class T>
void Complex<T>::setData(T r, T img){
    real = r;
    imaginary = img;
}


template <class T>
const Complex<T>& Complex<T>::operator++(){
    real = real+1;
    return(*this);
}

template <class T>
const Complex<T>& Complex<T>::operator--(){
    real = real-1;
    return(*this);
}

template <class T>
const Complex<T>& Complex<T>::operator++(int){
    Complex temp(*this);
    real= real+1;
    return(temp);
}

template <class T>
const Complex<T>& Complex<T>::operator--(int){
    Complex temp(*this);
    real= real-1;
    return(temp);
}

template <class T>
Complex<T>& Complex<T>::operator+=(const Complex& ob){
    real= real+ob.real;
    imaginary=imaginary+ob.imaginary;
    return(*this);
}

template <class T>
Complex<T>& Complex<T>::operator-=(const Complex& ob){
    real= real-ob.real;
    imaginary=imaginary-ob.imaginary;
    return(*this);
}

template <class T>
Complex<T>& Complex<T>::operator*=(const Complex& ob){
    T r, i;
    r= (real*ob.real)-(imaginary*ob.imaginary);
    i=real*ob.imaginary+imaginary*ob.real;
    real=r;
    imaginary=i;
    return(*this);
}

template <class T>
Complex<T>& Complex<T>::operator/=(const Complex& ob){
    T r, i;
    int rn,rd,in,id;
    r=((real*ob.real)+(imaginary*ob.imaginary))/(pow(ob.real,2)+pow(ob.imaginary,2));
    i=((imaginary*ob.real-real*ob.imaginary))/(pow(ob.real,2)+pow(ob.imaginary,2));
    if(r != static_cast<int>(r))
    {
        rn=r*10;
        rd=10;
    }

    if(i != static_cast<int>(i))
    {
        in=i*10;
        id=10;
    }
    //can use function from fraction class
    // normalise(rn,rd);
    // normalise(in,id);
    cout<<"The resultant complex number obtained is "<<rn<<"/"<<rd<<"+"<<"("<<in<<"/"<<id<<")"<<"i"<<endl<<endl;
}

template <class T>
Complex<T> operator+(const Complex<T>& c1,const Complex<T>& c2)
{
    T rl,img;
    rl=c1.real+c2.real;
    img=c1.imaginary+c2.imaginary;
    return Complex<T>(rl,img);
}

template <class T>
Complex<T> Complex<T>::subtract(const Complex<T>& c1,const Complex<T>& c2)
{
    T r1,img;
    r1=c1.real-c2.real;
    img=c1.imaginary-c2.imaginary;
    return Complex<T>(r1,img);
}

#endif