#pragma once

#include<iostream>
#include"matrix.h"


using namespace std;

Matrix<int> Identity(int size) {
	Matrix<int> result(size, size, 0);
	for (int i(0); i < size; i++) {
		result[i][i] = 1;
	}
	return result;
}