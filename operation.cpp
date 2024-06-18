#include <iostream>
#include "fraction.h"
#include "matrix.h"
#include "complex.h"
#include "combined.h"
using namespace std;

template <typename T>            //CLASS DECLARATION, TEMPLATE
class Matrix;

template <typename T>            //CLASS DECLARATION, CLASS TEMPLATE
class Fraction;

template <typename T>            //CLASS DECLARATION, CLASS TEMPLATE
class Complex;

template <typename T>    //MULTIPLE INHERITANCE
class Operation:public Matrix<T>,public Fraction<T>,public Complex<T>{

    public:

    void performComplexOperation();

    void performFractionOperation();

    void performMatrixOperation();

};


template <class T>                     //TEMPLATE FUNCTION
void Operation<T>::performMatrixOperation(){
    cout<<"\n\nxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n";
    cout<<"\t\tMATRIX OPERATION";
    cout<<"\nxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n";

    int r,c;
    T ele;
    cout<<"\n\nEnter row of first matrix : ";
    cin>>r;
    cout<<"\n\nEnter column of first matrix : ";
    cin>>c;
    Matrix<int> m_ob1(r,c);
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout<<"\nEnter element : ";
            cin>>ele;
            m_ob1.setValue(i,j,ele);
        }
    }
    m_ob1.print();
    cout<<"\n\nEnter row of second matrix : ";
    cin>>r;
    cout<<"\n\nEnter column of second matrix : ";
    cin>>c;
    Matrix<int> m_ob2(r,c);
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout<<"\nEnter element : ";
            cin>>ele;
            m_ob2.setValue(i,j,ele);
        }
    }
    m_ob2.print();   

    cout<<"\n\n\tOPERATOR OVERLOADING UNARY ADDITION\n";
    m_ob1 += m_ob2;
    m_ob1.print();

    cout<<"\n\nOPERATOR OVERLOADING UNARY SUBSTRACTION\n";
    m_ob1 -= m_ob2;
    m_ob1.print();

    cout<<"\n\nOPERATOR OVERLOADING UNARY MULTIPLICATION\n";
    m_ob1 *= m_ob2;
    m_ob1.print();

    cout<<"\n\nFRIEND FUNCTION OVERLOADING - ADDITION\n";
    Matrix<int> m_ob3 =  m_ob1+m_ob2;
    m_ob3.print();

    cout<<"\n\nFRIEND FUNCTION OVERLOADING - SUBSTRACTION\n";
    m_ob3 =  m_ob1-m_ob2;
    m_ob3.print();

    cout<<"\n\nFRIEND FUNCTION OVERLOADING - MULTIPLICATION\n";
    m_ob3 =  m_ob1*m_ob2;
    m_ob3.print();        


    cout<<"\n\n\t----DETERMINANT----\n";
    int deter = m_ob2.determinant();
    cout<<"\n\nDeterminant of the matrix is : "<<deter<<endl<<endl;

    cout<<"\n\n\t----TRANSPOSE----\n";
    m_ob2.transpose();
    m_ob2.print();
    
}


template <class T>
void Operation<T>::performFractionOperation(){
    cout<<"\n\nxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n";
    cout<<"\t\t FRACTION OPERATION";
    cout<<"\nxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n";    
    Fraction<int> f_ob1(5,9);
    Fraction<int> f_ob2(2,3);

    cout<<"\n\n\n\t---- INPUT 1 ---- \n\n";
    f_ob1.print();

    cout<<"\n\t---- INPUT 2 ---- \n\n";
    f_ob2.print();
    
    cout<<"\n\n--- PREFIX INCREMENT OPERATOR OVERLOADING ---\n\n";
    ++f_ob1;
    f_ob1.print();

    cout<<"\n--- PREFIX DECREMENT OPERATOR OVERLOADING ---\n\n";
    f_ob2.setData(2,3);
    f_ob1.setData(5,9);
    --f_ob2;
    f_ob2.print();
    
    cout<<"\n\t    --- ADDITION ---\n\n";
    f_ob2.setData(2,3);
    f_ob1.setData(5,9);  
    f_ob1 += f_ob2;
    f_ob1.print();
    cout<<"\n\t    --- SUBSTRACTION ---\n\n";
    f_ob2.setData(2,3);
    f_ob1.setData(5,9);    
    f_ob1 -= f_ob2;
    f_ob1.print();

    cout<<"\n\t    --- MULTIPLICATION ---\n\n";
    f_ob2.setData(2,3);
    f_ob1.setData(5,9);   
    f_ob1 *= f_ob2;
    f_ob1.print();

    cout<<"\n\t    --- DIVISION ---\n\n";
    f_ob2.setData(2,3);
    f_ob1.setData(5,9);  
    f_ob1 /= f_ob2;
    f_ob1.print();

    cout<<"\n\n\t USING FRIEND FUNCTION OPERATOR OVERLOADING \n\n";

    cout<<"\n\t    --- ADDITION ---\n\n";

    f_ob2.setData(2,3);
    f_ob1.setData(5,9);  
    Fraction<int> f_ob3 = f_ob1 + f_ob2;    
    f_ob3.print();

    cout<<"\n\t    --- SUBSTRACTION ---\n\n";

    f_ob2.setData(2,3);
    f_ob1.setData(5,9);  
    f_ob3 = f_ob1 - f_ob2;    
    f_ob3.print();

    cout<<"\n\t    --- MULTIPLICATION ---\n\n";

    f_ob2.setData(2,3);
    f_ob1.setData(5,9);  
    f_ob3 = f_ob1 * f_ob2;    
    f_ob3.print();    

    cout<<"\n\t    --- DIVISION ---\n\n";

    f_ob2.setData(2,3);
    f_ob1.setData(5,9);  
    f_ob3 = f_ob1 / f_ob2;    
    f_ob3.print();   

    cout<<"\n\n\t USING FRIEND FUNCTION RELATIONAL OPERATOR OVERLOADING \n\n";

    cout<<"\n\t    --- EQUALS TO ---\n\n";

    f_ob2.setData(2,3);
    f_ob1.setData(5,9);     
    bool result = f_ob1==f_ob2;
    if(result) cout<<"\nFraction 1 is EQUALS TO Fraction 2\n";
    else cout<<"\nFraction 1 is NOT EQUALS TO Fraction 2\n";

    cout<<"\n\t    --- GREATER THAN ---\n\n";

    f_ob2.setData(2,3);
    f_ob1.setData(5,9);     
    result = f_ob1>f_ob2;
    if(result) cout<<"\nFraction 1 is GREATER THAN Fraction 2\n";
    else cout<<"\nFraction 1 is LESS THAN to Fraction 2\n";   

    cout<<"\n\t    --- LESS THAN OR EQUALS TOO ---\n\n";

    f_ob2.setData(2,3);
    f_ob1.setData(5,9);     
    result = f_ob1<=f_ob2;
    if(result) cout<<"\nFraction 1 is LESS THAN OR EQUALS TOO Fraction 2\n";
    else cout<<"\nFraction 1 is GREATER THAN Fraction 2\n\n\n";         

}


template <class T>
void Operation<T>::performComplexOperation(){
    cout<<"\n\nxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n";
    cout<<"\t\t COMPLEX OPERATION";
    cout<<"\nxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n";    
    Complex<int> c_ob1 (3,8);
    Complex<int> c_ob2(5,9);

    cout<<"\n\n\n\t---- INPUT 1 ---- \n\n";
    c_ob1.print();

    cout<<"\n\t---- INPUT 2 ---- \n\n";
    c_ob2.print();
    
    cout<<"\n\n--- PREFIX INCREMENT OPERATOR OVERLOADING ---\n\n";
    ++c_ob1;
    c_ob1.print();

    cout<<"\n--- PREFIX DECREMENT OPERATOR OVERLOADING ---\n\n";
    c_ob2.setData(5,9);
    c_ob1.setData(3,8);
    --c_ob2;
    c_ob2.print();
    
    cout<<"\n\t    --- ADDITION ---\n\n";
    c_ob2.setData(5,9);
    c_ob1.setData(3,8);  
    c_ob1 += c_ob2;
    c_ob1.print();

    cout<<"\n\t    --- SUBSTRACTION ---\n\n";
    c_ob2.setData(5,9);
    c_ob1.setData(3,8);    
    c_ob1 -= c_ob2;
    c_ob1.print();

    cout<<"\n\t    --- MULTIPLICATION ---\n\n";
    c_ob2.setData(5,9);
    c_ob1.setData(3,8);   
    c_ob1 *= c_ob2;
    c_ob1.print();

    cout<<"\n\t    --- DIVISION ---\n\n";
    c_ob2.setData(5,9);
    c_ob1.setData(3,8);  
    c_ob1 /= c_ob2;
    // c_ob1.print();

    cout<<"\n\n\t USING FRIEND FUNCTION OPERATOR OVERLOADING \n\n";
    c_ob2.setData(5,9);
    c_ob1.setData(3,8);  
    Complex<int> c_ob3 = c_ob1 + c_ob2;    
    c_ob3.print();

}


int main(){
    Operation<int> ob;

    char ch='y';

    while(ch=='y'||ch=='Y'){
        int choice;
        cout<<"\n\n\n\t-----SELECT OPERATIONS-----\n";
        cout<<"\n1. MATRIX OPERATION";
        cout<<"\n2. FRACTION OPERATION";
        cout<<"\n3. COMPLEX OPERATION";
        cout<<"\nENTER YOUR CHOICE : ";
        cin>>choice;

        switch (choice)
        {
        case 1:
            ob.performMatrixOperation();
            break;

        case 2:
            ob.performFractionOperation();
            break;

        case 3: 
            ob.performComplexOperation();
            break;
                
        default:
            cout<<"\n\n----INVALID CHOICE-----\n";
            break;
        }

        cout<<"\nxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n";
        cout<<"\nDO YOU WANT TO CONTINUE : ";
        cin>>ch;
    }

}