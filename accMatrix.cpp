#include <iostream>
#include "Matrix.cpp"

using namespace std;

MATRIX<double> accMatrix(MATRIX<double> temp, int row) {
	//MATRIX<double> temp_return(row, row);
	for (int i = 0; i < row; ++i) 
		temp = temp*temp;
	for (int j = 0; j < row; ++j) {	
		for (int k = 0; k < row; ++k) {
			if (temp[j][k] != 0)
				temp[j][k] = 1;
		}
	}
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