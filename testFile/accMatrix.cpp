#include <iostream>
#include "Matrix.cpp"

using namespace std;

MATRIX<double> transitivityClosure(MATRIX<double> temp, int row) {
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < row; ++j) {
			if(temp[j][i] == 1) {
				for (int k = 0; k < row; ++k) {
					temp[j][k] = temp[j][k] + temp[i][k];
				}
			} 
		}
	} //end for

	for (int x = 0; x < row; ++x) {
		for (int y = 0; y < row; ++y) {
			if(temp[x][y] != 0)
				temp[x][y] = 1;
		}
	} //end for

	return temp;
}
int main(int argc, char const *argv[])
{
	int row = 4;
	MATRIX<double> test(row, row);
	test[0][1] = 1;
	test[1][2] = 1;
	test[1][3] = 1;
	test[2][0] = 1;
	test[2][1] = 1;
	test[2][3] = 1;
	test[3][0] = 1;

	MATRIX<double> test_return(row, row);
	test_return = accMatrix(test, row);
	return 0;
}