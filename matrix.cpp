#include<iostream>
#include<iomanip>
#include "matrix.h"

using namespace std;


// Definition for operator<<
template<class T>
ostream& operator<<(ostream& os, Matrix<T>& M) {
    for (int i = 0; i < M.rows; ++i) {
        os << "|";
        for (int j = 0; j < M.columns; ++j) {
            os << " " << setw(5) << fixed << setprecision(2) << static_cast<T>(M[i][j]);
        }
        os << " |" << endl;
    }
    return os;
}

template<class T>
ostream& operator<<(ostream& os, Matrix<T>&& M) {
    for (int i = 0; i < M.rows; ++i) {
        os << "|";
        for (int j = 0; j < M.columns; ++j) {
            os << " " << setw(5) << fixed << setprecision(2) << static_cast<T>(M[i][j]);
        }
        os << " |" << endl;
    }
    return os;
}

// Definition for operator>>
template<class T>
istream& operator>>(istream& is, Matrix<T>& M) {
    for (int i = 0; i < M.rows; ++i) {
        cout << "Enter " << M.columns << " Values for row " << i + 1 << ": ";
        for (int j = 0; j < M.columns; ++j) {
            is >> M[i][j];
        }
    }
    return is;
}


template<class T>
Matrix<T> Matrix<T>::operator+(Matrix<T>& other) {

    Matrix<T> result(rows, columns); // Create a new Matrix to hold the result

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            result.main_ptr[i][j] = this->main_ptr[i][j] + other.main_ptr[i][j];
        }
    }

    return result; // Return the result by value
}

template<class T>
Matrix<T> Matrix<T>::operator+(Matrix<T>&& other) {

    Matrix<T> result(rows, columns); // Create a new Matrix to hold the result

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            result.main_ptr[i][j] = this->main_ptr[i][j] + other.main_ptr[i][j];
        }
    }

    return result; // Return the result by value
}

template<class T>
Matrix<T> Matrix<T>::operator-(Matrix<T>& other) {

    Matrix<T> result(rows, columns); // Create a new Matrix to hold the result
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            result.main_ptr[i][j] = this->main_ptr[i][j] - other.main_ptr[i][j];
        }
    }

    return result; // Return the result by value
}

template<class T>
Matrix<T> Matrix<T>::operator-(Matrix<T>&& other) {

    Matrix<T> result(rows, columns); // Create a new Matrix to hold the result
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            result.main_ptr[i][j] = this->main_ptr[i][j] - other.main_ptr[i][j];
        }
    }

    return result; // Return the result by value
}

template<class T>
Matrix<T> Matrix<T>::operator*(int k) const{
    Matrix<T> result(rows, columns); // Create a new Matrix to hold the result

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            result.main_ptr[i][j] = this->main_ptr[i][j] * k;
        }
    }

    return result; // Return the result by value
}

template<class T>
Matrix<T> Matrix<T>::operator+(int k) const {
    Matrix<T> result(rows, columns); // Create a new Matrix to hold the result

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            result.main_ptr[i][j] = this->main_ptr[i][j] + k;
        }
    }

    return result; // Return the result by value
}


template<class T>
Matrix<T> Matrix<T>::operator-(int k) const {
    Matrix<T> result(rows, columns); // Create a new Matrix to hold the result

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            result.main_ptr[i][j] = this->main_ptr[i][j] - k;
        }
    }

    return result; // Return the result by value
}

template<class T>
Matrix<T> Matrix<T>::operator/(int k) const {
    Matrix<T> result(rows, columns); // Create a new Matrix to hold the result

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            result.main_ptr[i][j] = this->main_ptr[i][j] / k;
        }
    }

    return result; // Return the result by value
}

template<class T>
Matrix<T>& Matrix<T>::operator*=(int k) {

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            this->main_ptr[i][j] *= k;
        }
    }

    return *this; // Return the result by value
}

template<class T>
Matrix<T>& Matrix<T>::operator+=(int k) {

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            this->main_ptr[i][j] += k;
        }
    }

    return *this; // Return the result by value
}

template<class T>
Matrix<T>& Matrix<T>::operator/=(int k) {

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            this->main_ptr[i][j] /= k;
        }
    }

    return *this; // Return the result by value
}

template<class T>
Matrix<T>& Matrix<T>::operator-=(int k) {

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            this->main_ptr[i][j] -= k;
        }
    }

    return *this; // Return the result by value
}

template<class T>
Matrix<T>& Matrix<T>::operator=(Matrix<T>& other) {

    for (int i(0); i < rows; i++) {
        for (int j(0); j < columns; j++) {
            this->main_ptr[i][j] = other.main_ptr[i][j];
        }
   }

    return *this;
}




template<class T>
Matrix<T>& Matrix<T>::operator=(T k) {

    for (int i(0); i < rows; i++) {
        for (int j(0); j < columns; j++) {
            this->main_ptr[i][j] = k;
        }
    }

    return *this;
}


template<class T>
Matrix<T> Matrix<T>::transpose() const{
    Matrix<T> result(columns, rows,0);
    for (int i(0); i < columns; i++) {
        for (int j(0); j < rows; j++) {
            result.main_ptr[i][j] = this->main_ptr[j][i];
        }
    }
        
    return result;
}

template<class T>
bool Matrix<T>::operator==(Matrix<T>& other) {
    for (int i(0); i < rows; i++) {
        for (int j(0); j < columns; j++) {
            if (this->main_ptr[i][j] != other.main_ptr[i][j]) return false;
        }
    }
    return true;
}

template<class T>
bool Matrix<T>::operator==(Matrix<T>&& other) {
    for (int i(0); i < rows; i++) {
        for (int j(0); j < columns; j++) {
            if (this->main_ptr[i][j] != other.main_ptr[i][j]) return false;
        }
    }
    return true;
}

template<class T>
bool Matrix<T> :: isSymmetric()  {

    
    if ((*this) == this->transpose()) return true;

    return false;

}


template<class T>
bool Matrix<T> ::search(T key) const {
    for (int i(0); i < rows; i++) {
        for (int j(0); j < columns; j++) {
            if (this->main_ptr[i][j] == key) { 
                cout << "Element Found At pos (" << i << "," << j << ")" << endl;
                return true; 
            }
        }
    }

    cout << "Element Not Found" << endl;
    return false;

}





// Explicit instantiation
 template ostream& operator<<(ostream& os, Matrix<int>& M);
template ostream& operator<<(ostream& os, Matrix<float>& M);

template ostream& operator<<(ostream& os, Matrix<int>&& M);
template ostream& operator<<(ostream& os, Matrix<float>&& M);

template istream& operator>>(istream& is, Matrix<int>& M);
template istream& operator>>(istream& is, Matrix<float>& M);

template Matrix<int> Matrix<int>::operator+(Matrix<int>& other);
template Matrix<int> Matrix<int>::operator-(Matrix<int>& other);

template Matrix<float> Matrix<float>::operator+(Matrix<float>& other);
template Matrix<float> Matrix<float>::operator-(Matrix<float>& other);

template Matrix<int> Matrix<int>::operator+(Matrix<int>&& other);
template Matrix<float> Matrix<float>::operator+(Matrix<float>&& other);

template Matrix<int> Matrix<int>::operator-(Matrix<int>&& other);
template Matrix<float> Matrix<float>::operator-(Matrix<float>&& other);

template Matrix<int> Matrix<int>::operator*(int k) const;
template Matrix<float> Matrix<float>::operator*(int k) const;

template Matrix<int> Matrix<int>::operator/(int k) const;
template Matrix<float> Matrix<float>::operator/(int k) const;

template Matrix<int> Matrix<int>::operator-(int k) const;
template Matrix<float> Matrix<float>::operator-(int k) const;

template Matrix<int> Matrix<int>::operator+(int k) const;
template Matrix<float> Matrix<float>::operator+(int k) const;

template Matrix<int>& Matrix<int>::operator*=(int k) ;
template Matrix<float>& Matrix<float>::operator*=(int k) ;

template Matrix<int>& Matrix<int>::operator/=(int k);
template Matrix<float>& Matrix<float>::operator/=(int k);

template Matrix<int>& Matrix<int>::operator-=(int k);
template Matrix<float>& Matrix<float>::operator-=(int k);

template Matrix<int>& Matrix<int>::operator+=(int k);
template Matrix<float>& Matrix<float>::operator+=(int k);

template Matrix<int>& Matrix<int>::operator=(Matrix<int>& other);
template Matrix<float>& Matrix<float>::operator=(Matrix<float>& other);


template Matrix<int>& Matrix<int>::operator=(int k);
template Matrix<float>& Matrix<float>::operator=(float k);

template Matrix<int> Matrix<int>::transpose() const;
template Matrix<float> Matrix<float>::transpose() const;

template bool Matrix<int> ::isSymmetric() ;
template bool Matrix<float> ::isSymmetric() ;

template bool Matrix<int> :: operator==(Matrix<int>& other);
template bool Matrix<float> :: operator==(Matrix<float>& other);

template bool Matrix<int> :: operator==(Matrix<int>&& other);
template bool Matrix<float> :: operator==(Matrix<float>&& other);

template bool Matrix<int> ::search(int key) const;
template bool Matrix<float> ::search(float key) const;

