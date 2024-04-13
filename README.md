# Project-Matrix
The Matrix class is a C++ template designed to handle mathematical matrices. It features a constructor for initializing matrices with specified dimensions and values, overloads for arithmetic operators to perform matrix operations like addition, subtraction, and multiplication, and methods for matrix transposition and symmetry checks. Additionally, it provides access to individual matrix elements using the [] operator and supports easy input and output using the << and >> operators, making it a versatile tool for matrix manipulations.'
![Screenshot 2024-04-13 090008](https://github.com/HCoder/Project-Matrix/assets/71689935/ed6f605a-dbe9-40a9-81f6-3c1d1a18d7d3)



# Detailed Overview of Matrix Class in C++

# Class Structure
The class is structured with private member variables rows, columns, and a dynamic 2D array main_ptr to store the matrix elements.

# Constructor and Destructor
The constructor initializes a matrix with a specified number of rows and columns, along with an optional initial value for all its elements. The destructor ensures proper memory deallocation when the matrix object is destroyed.

# Operator Overloading
The class overloads various arithmetic and assignment operators to perform matrix operations, such as addition, subtraction, multiplication, and division.

# Accessor Operator Overloading
The [] operator is overloaded to allow access to individual rows of the matrix, enabling the matrix to be treated like a 2D array.

# Matrix Operations
Transpose: The transpose() method computes and returns the transpose of the matrix.
Symmetry Check: The isSymmetric() method checks whether the matrix is symmetric.
Search: The search(T key) method searches for a specific value in the matrix and returns a boolean value indicating its presence.
Input and Output Operators
Overloaded << and >> operators are implemented to allow for easy input and output of matrices, enhancing the class's usability for debugging and displaying results.


