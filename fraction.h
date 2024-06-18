#ifndef FRACTION_H
#define FRACTION_H
#include <iostream>
#include "combined.h"

using namespace std;

template <typename P>                  //CLASS DECLARATION
class Combined;

template <typename T>
class Fraction:public Combined<T>{             //SINGLE INHERITANCE
    private : 
        T numerator;
        T denominator;
    protected:    
        void normalise(T n, T d);             //Helper function
        T gcd(T n1, T n2);          //Helper function
    public:
        Fraction();                    //default constructor
        // Fraction(T num);               //paramaterised constructor
        Fraction(T num, T deno=1);       //paramaterised constructor
        Fraction(const Fraction& ob);  //copy constructor    
        ~Fraction(){};                             //destructor
        void setData(T n, T d);
        //overloading unary operators     COMPILE TIME POLYMORPHISM
        Fraction& operator+();            //+ve fraction
        Fraction& operator-();            //-ve fraction
        Fraction& operator++();           //prefix increment
        Fraction& operator--();           //prefix decrement
        Fraction& operator++(int);           //postfix increment
        Fraction& operator--(int);           //postfix decrement
        Fraction& operator+=(const Fraction& right);    //Addition to itself
        Fraction& operator-=(const Fraction& right);    //Substraction to itself
        Fraction& operator*=(const Fraction& right);    //Multiplication to itself
        Fraction& operator/=(const Fraction& right);    //Division

        //Global function as friend function
        template <typename U>
        friend const Fraction<U> operator+(const Fraction<U>& fr1, const Fraction<U>& fr2);

        template <typename U>
        friend const Fraction<U> operator-(const Fraction<U>& fr1, const Fraction<U>& fr2);

        template <typename U>
        friend const Fraction<U> operator*(const Fraction<U>& fr1, const Fraction<U>& fr2);

        template <typename U>
        friend const Fraction<U> operator/(const Fraction<U>& fr1, const Fraction<U>& fr2);

        // friend relational operator
        template <typename U>
        friend bool operator==(const Fraction<U>& left, const Fraction<U>& right);

        template <typename U>
        friend bool operator!=(const Fraction<U>& left, const Fraction<U>& right);

        template <typename U>
        friend bool operator<(const Fraction<U>& left, const Fraction<U>& right);  

        template <typename U>
        friend bool operator<=(const Fraction<U>& left, const Fraction<U>& right);        
        
        template <typename U>
        friend bool operator>(const Fraction<U>& left, const Fraction<U>& right);       
        
        template <typename U>
        friend bool operator>=(const Fraction<U>& left, const Fraction<U>& right);              

        void print(){
            normalise(numerator,denominator);

            cout<<"\nThe resultant fraction is "<<numerator<<"/"<<denominator<<endl<<endl;
        }

};

template <class T>
void Fraction<T>::normalise(T n, T d) {
    T x = gcd(n, d);
    numerator = n / x;
    denominator = d / x;
}

template <class T>
T Fraction<T>::gcd(T num, T deno) {
    T gcd = 1;
    for (T i = min(num, deno); i > 0; --i) {
        if (num % i == 0 && deno % i == 0) {
            return i;
        }
    }
    return gcd;
}


template <class T>
Fraction<T>::Fraction(){
    numerator = 0;
    denominator = 1;
}

template <class T>
Fraction<T>::Fraction(T num, T deno){
    numerator = num;
    denominator = deno;

    normalise(this->numerator,this->denominator);
}

template <class T>
Fraction<T>::Fraction(const Fraction & ob){
    numerator = ob.numerator;
    denominator = ob.denominator;

    normalise(this->numerator,this->denominator);
}

template <class T>
void Fraction<T>::setData(T n, T d){
    numerator = n;
    denominator = d;

    normalise(numerator,denominator);
}

template <class T>
Fraction<T>& Fraction<T>::operator+(){
    if(numerator<0)
        this->numerator=-numerator;
    return *this;
}

template <class T>
Fraction<T>& Fraction<T>::operator-(){
    this->numerator = -numerator;
    return *this;
}

template <class T>
Fraction<T>& Fraction<T>::operator++(){
    if(numerator>0) this->numerator=numerator+denominator;
    else this->numerator = denominator-numerator;
    return *this;    
}

template <class T>
Fraction<T>& Fraction<T>::operator++(int){
    Fraction temp(*this);
    if(numerator>0) numerator=numerator+denominator;
    else numerator = denominator-numerator;
    return temp;
}

template <class T>
Fraction<T>& Fraction<T>::operator--(){
    numerator=numerator-denominator;
    return *this;
}

template <class T>
Fraction<T>& Fraction<T>::operator--(int){
    Fraction temp(*this);
    numerator = numerator-denominator;
    return temp;
}

template <class T>
Fraction<T>& Fraction<T>::operator+=(const Fraction& right){
    this->numerator=numerator*right.denominator+right.numerator*denominator;
    this->denominator=denominator*right.denominator;
    normalise(this->numerator,this->denominator);
    return *this;
}

template <class T>
Fraction<T>& Fraction<T>::operator-=(const Fraction& right){
    this->numerator=numerator*right.denominator-right.numerator*denominator;
    this->denominator=denominator*right.denominator;
    normalise(this->numerator,this->denominator);
    return *this;
}

template <class T>
Fraction<T>& Fraction<T>::operator*=(const Fraction& right){
    this->numerator=numerator*right.numerator;
    this->denominator=denominator*right.denominator;
    normalise(this->numerator,this->denominator);
    return *this;
}

template <class T>
Fraction<T>& Fraction<T>::operator/=(const Fraction& right){
    this->numerator*=right.denominator;
    this->denominator*=right.numerator;
    normalise(this->numerator,this->denominator);
    return *this;
}

template <class T>
const Fraction<T> operator+(const Fraction<T>& left, const Fraction<T>& right){
    T newNun=left.numerator*right.denominator+right.numerator*left.denominator;
    T newDeno=left.denominator*right.denominator;
    Fraction<T> result(newNun,newDeno);
    return result;    
}

template <class T>
const Fraction<T> operator-(const Fraction<T>& left, const Fraction<T>& right){
    T newNun=left.numerator*right.denominator-right.numerator*left.denominator;
    T newDeno=left.denominator*right.denominator;
    Fraction<T> result(newNun,newDeno);
    return result;    
}

template <class T>
const Fraction<T> operator*(const Fraction<T>& left, const Fraction<T>& right){
    T numer=left.numerator*right.numerator;
    T denom=left.denominator*right.denominator;
    Fraction<T> result(numer,denom);
    return result;    
}

template <class T>
const Fraction<T> operator/(const Fraction<T>& left, const Fraction<T>& right){
    T numer=left.numerator*right.denominator;
    T denom=left.denominator*right.numerator;
    Fraction<T> result(numer,denom);
    return result;    
}

template <class T>
bool operator==(const Fraction<T>& left, const Fraction<T>& right){
    
    if(left.numerator == right.numerator && left.denominator == right.denominator) return true;
    else return false;   
}

template <class T>
bool operator!=(const Fraction<T>& left, const Fraction<T>& right){
     return(left.numerator*right.denominator!=right.numerator*left.denominator);   
}

template <class T>
bool operator<(const Fraction<T>& left, const Fraction<T>& right){
    return(left.numerator*right.denominator<right.numerator*left.denominator);   
}

template <class T>
bool operator<=(const Fraction<T>& left, const Fraction<T>& right){
    return(left.numerator*right.denominator<=right.numerator*left.denominator);  
}

template <class T>
bool operator>(const Fraction<T>& left, const Fraction<T>& right){
    return(left.numerator*right.denominator>right.numerator*left.denominator); 
}

template <class T>
bool operator>=(const Fraction<T>& left, const Fraction<T>& right){
    
    return(left.numerator*right.denominator>= right.numerator*left.denominator);
}

// When we overload a binary operator as a member function, one of the operands needs to be 
// the host object. This is fine when each operand has a different role in the operation. However, in some operators, such as (a + b) or (a < b), the two operands play the same role and 
// neither of them is related to the result. In these cases, it is better to use a nonmember function. We have two choices: global functions or friend functions.

#endif




