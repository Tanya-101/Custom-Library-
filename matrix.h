#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
#include "combined.h"
#include <vector>

using namespace std;

template <typename P>                //CLASS DECLARATION
class Combined;

template <typename T>
class Matrix:public Combined<T>{     //SINGLE INHERITANCE
    private :
        vector<vector<T>> data;      //DATA MEMBERS
        int row;
        int col;
    public:
        Matrix(int n=0);               //DEFAULT CONSTRUCTOR
        Matrix(int r, int c);          //PARAMATERIZED CONSTRUCTOR
        Matrix(const Matrix& ob);      //COPY CONSTRUCTOR
        ~Matrix(){}                    //DESTRUCTOR
        const Matrix& operator+=(const Matrix<T>& mat);
        const Matrix& operator-=(const Matrix<T>& mat);
        const Matrix& operator*=(const Matrix<T>& mat);

        template <typename U> //BINARY FRIEND FUNCTION OPERATOR OVERLOADING
        friend Matrix<U> operator+(const Matrix<U>& mat1, const Matrix<U>& mat2);

        template <typename U>
        friend Matrix<U> operator-(const Matrix<U>& mat1, const Matrix<U>& mat2);

        template <typename U>
        friend Matrix<U> operator*(const Matrix<U>& mat1, const Matrix<U>& mat2);

        Matrix transpose();
        T determinant();                          //RECURSION
        Matrix<T> FindSubMatrix(int r, int c);    //Helper function for the calculation of determinants

        void setValue(int r,int c,T val);

        //OVERRIDEN FUNCTION
        void print(){
            cout<<"\n\nResultant Matrix is : \n";
            for(int i=0;i<row;i++){
                for(int j=0;j<col;j++){
                    cout<<data[i][j]<<"\t";
                }
                cout<<endl;
            }
            cout<<endl<<endl;
        }
};

template <typename T>
Matrix<T>::Matrix(int n){           //DEFAULT PARAMETER CONSTRUCTOR
    row=n;
    col=n;
    data.resize(row,vector<T>(col,0));
}

template <typename T>               //PARAMATERISED CONSTRUCTOR
Matrix<T>::Matrix(int r, int c){
    row=r;
    col=c;
    data.resize(row,vector<T>(col));
}

template <typename T>                //COPY CONSTRUCTOR
Matrix<T>::Matrix(const Matrix& ob){
    row = ob.row;
    col = ob.col;
    data.resize(row,vector<T>(col));
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            data[i][j] = ob.data[i][j];
        }
    }
}

template <typename T>               //SET INPUTS TO MATRIX
void Matrix<T>::setValue(int r, int c, T val){
    if(r>=0 && r<row && c>=0 && c<col){
        data[r][c]=val;
    }else{
        cout<<"\nInvalid indices!\n";
    }
}

template <typename T>              //OPERATOR OVERLOADING
const Matrix<T>& Matrix<T>::operator+=(const Matrix<T>& mat){
    if(row == mat.row && col == mat.col){
        for(int i=0;i<mat.row;i++){
            for(int j=0;j<mat.col;j++){
                this->data[i][j] = data[i][j]+mat.data[i][j];
            }
        }
        return *this;
    }else{
        cout<<"\n\t----Given order of matrix cannot be added----\n";
        exit(0);
    }
}

template <typename T>
const Matrix<T>& Matrix<T>::operator-=(const Matrix<T>& mat){
    if(row == mat.row && col == mat.col){
        for(int i=0;i<mat.row;i++){
            for(int j=0;j<mat.col;j++){
                this->data[i][j] = data[i][j]-mat.data[i][j];
            }
        }
        return *this;
    }else{
        cout<<"\n\t----Given order of matrix cannot be substracted----\n";
        exit(0);
    }
}

template <typename T>
const Matrix<T>& Matrix<T>::operator*=(const Matrix<T>& mat){
    if(col != mat.row){
        cout<<"\n\t----Given order of matric cannot be multiplied----\n";
        exit(0);
    }else{
        int r = row;
        int c = mat.col;
        vector<vector<T>> temp(r,vector<T> (c,0));
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                temp[i][j]=0;
                for(int k=0;k<col;k++){
                    temp[i][j]+=data[i][k]*mat.data[k][j];
                }
            }
        }

        this->row=r;
        this->col=c;
        this->data = temp;
        return *this;
    }
}

template <typename T>                     //FRIEND FUNCTION 
Matrix<T> operator+(const Matrix<T>& mat1,const Matrix<T>& mat2){
    if(mat1.row == mat2.row && mat1.col == mat2.col){
        Matrix<T> result(mat1.row,mat1.col);
        for(int i=0;i<mat1.row;i++){
            for(int j=0;j<mat1.col;j++){
                result.data[i][j] = mat1.data[i][j]+mat2.data[i][j];
            }
        }
        return result;
    }else{
        cout<<"\n\t----Given order of matrix cannot be added----\n";
        exit(0);
    }    
}

template <typename T>
Matrix<T> operator-(const Matrix<T>& mat1,const Matrix<T>& mat2){
    if(mat1.row == mat2.row && mat1.col == mat2.col){
        Matrix<T> result(mat1.row,mat1.col);
        for(int i=0;i<mat1.row;i++){
            for(int j=0;j<mat1.col;j++){
                result.data[i][j] = mat1.data[i][j]-mat2.data[i][j];
            }
        }
        return result;
    }else{
        cout<<"\n\t----Given order of matrix cannot be added----\n";
        exit(0);
    }    
}

template <typename T>
Matrix<T> operator*(const Matrix<T>& mat1,const Matrix<T>& mat2){
    if(mat1.col != mat2.row){
        cout<<"\n\t----Given order of matric cannot be multiplied----\n";
        exit(0);
    }else{
        int r = mat1.row;
        int c = mat2.col;
        Matrix<T> matr(r,c);
        vector<vector<T>> temp(r,vector<T> (c,0));
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                temp[i][j]=0;
                for(int k=0;k<mat1.col;k++){
                    temp[i][j]+=mat1.data[i][k]*mat2.data[k][j];
                }
            }
        }
        matr.data = temp;
        return matr;
    }  
}

template <typename T>
Matrix<T> Matrix<T>::transpose(){
    Matrix<T> mat(row,col);
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            mat.data[i][j] = data[j][i];
        }
    }
    this->data = mat.data;
    return *this;
}

template <typename T>
Matrix<T> Matrix<T>::FindSubMatrix(int r, int c){
    Matrix<T> subMatrix(row-1,col-1);
    subMatrix.data.resize(0);

    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            vector<T> roww;
            if((i!=row)&&(j!=col)){
                roww.push_back(this->data[i][j]);
            }
            subMatrix.data.push_back(roww);
        }
    }
    return subMatrix;
}

template <typename T>
T Matrix<T>::determinant(){
    T value;
    if(row==2){
        value = data[0][0]*data[1][1]-data[0][1]*data[1][0];
    }else{
        T cumulativesum = 0;
        T sign = 1;
        for(int j=0;j<col;j++){
            Matrix<T> subMatrix = this->FindSubMatrix(0,j);
            cumulativesum += this->data[0][j]*subMatrix.determinant()*sign;
            sign = -sign;
        }
        value = cumulativesum;
    }
    return value;
}

#endif
