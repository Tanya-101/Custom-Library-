#ifndef COMBINED_H
#define COMBINED_H
#include <iostream>

using namespace std;

template <typename T>
class Combined{                          //ABSTRACT CLASS
    public:
       virtual void print() = 0;     //PURE VIRTUAL FUNCTION
       virtual T gcd(T num, T deno);
       virtual void normalise(T n, T d);
};


template <class T>
void Combined<T>::normalise(T n, T d) {
    T x = gcd(n, d);
    n = n / x;
    d = d / x;
}

template <class T>
T Combined<T>::gcd(T num, T deno) {
    T gcd = 1;
    for (T i = min(num, deno); i > 0; --i) {
        if (num % i == 0 && deno % i == 0) {
            return i;
        }
    }
    return gcd;
}


#endif
