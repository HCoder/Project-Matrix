#pragma once

#include<iostream>
#include<iomanip>

using namespace std;

template<class T>
class Matrix {

private:
    int rows, columns;
    T** main_ptr;

public:

    Matrix(int val1 = 0, int val2 = 0, T init_val = 0) : rows(val1), columns(val2) {
        main_ptr = new T * [rows];
        for (int i = 0; i < rows; ++i) {
            main_ptr[i] = new T[columns];
            for (int j = 0; j < columns; ++j) {
                main_ptr[i][j] = init_val;
            }
        }
    }

    ~Matrix() {
        for (int i = 0; i < rows; ++i) {
            delete[] main_ptr[i];
        }
        delete[] main_ptr;
    }

    T* operator[](int i) {
        return main_ptr[i];
    }

    bool operator==(Matrix<T>& other);
    bool operator==(Matrix<T>&& other);
    Matrix<T> operator+(Matrix<T>& other);
    Matrix<T> operator+(Matrix<T>&& other);
    Matrix<T> operator-(Matrix<T>& other);
    Matrix<T> operator-(Matrix<T>&& other);
    Matrix<T>& operator*=(int k) ;
    Matrix<T>& operator+=(int k);
    Matrix<T>& operator/=(int k);
    Matrix<T>& operator-=(int k);
    Matrix<T> operator*(int k) const;
    Matrix<T> operator/(int k) const;
    Matrix<T> operator-(int k) const;
    Matrix<T> operator+(int k) const;
    Matrix<T>& operator=(Matrix<T>& other); // Might Require to Declare a Move Assignment In future. 
    Matrix<T>& operator=(T k);
    Matrix<T> transpose() const;
    bool isSymmetric() ;
    bool search(T key) const;



    template<class T>
    friend ostream& operator<<(ostream& os, Matrix<T>& M);

    template<class T>
    friend ostream& operator<<(ostream& os, Matrix<T>&& M);

    template<class T>
    friend istream& operator>>(istream& os, Matrix<T>& M);
};



