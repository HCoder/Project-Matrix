#include<iostream>
#include"matrix.h"
#include"matrix_util.h"

using namespace std;


int main() {

	Matrix<float> M1(3, 3, 1.0);

	Matrix<float> M2(3, 3, 0.0);

	M1[1][1] = 7;

	cout << "==============    M1   ================" << endl;


	cout << M1;

	cout << "==============    M2    =================" << endl;

	cout << M2;

	cout << "===============   M1 + M2   ================" << endl;

	
	cout << boolalpha << (M1 == M2) << endl;

	cout << (M1 + M2);

	cout << "================   M3   ===============" << endl;
	
	Matrix<float> M3(3, 2);
	 M3 = 12.2;

	 cout << M3;

	 cout << "================   M3 Transpose  ===============" << endl;
	 cout << M3.transpose();
	
	 cout << "================  Identity 3x3  ===============" << endl;
	 cout << Identity(3);

	return 0;
}


