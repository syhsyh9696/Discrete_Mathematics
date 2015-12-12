#include <iostream>
#include "Matrix.cpp"

using namespace std;

MATRIX<double> reflexivityClosure(MATRIX<double> temp, int row) {
	for (int i = 0; i < row; ++i) {
		if(temp[i][i] != 1)
			temp[i][i] = 1;
	}
	return temp;
}

MATRIX<double> symmetryClosure(MATRIX<double> temp, int row) {
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < row; ++j) {
			if(temp[i][j] == temp[j][i])
				continue;
			else 
				temp[i][j] = temp[j][i];
		}
		
	}
	return temp;
}

