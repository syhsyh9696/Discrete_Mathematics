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

MATRIX<double> transitivityClosure(MATRIX<double> temp, int row) {
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < row; ++j) {
			if(temp[j][i] == 1) {
				for (int k = 0; k < row; ++k) {
					temp[j][k] += temp[i][k];
				}
			}
			else
				continue;  
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
	int row = 7;
	MATRIX<double> test(row, row);

	MATRIX<double> test1(row, row);

	test[0][0] = 1;
	test[0][1] = 1;
	test[1][3] = 1;
	test[2][4] = 1;
	test[3][1] = 1;
	// test[2][3] = 1;
	// test[3][0] = 1;
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < row; ++j)
		{
			cout << test[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

	test1 = transitivityClosure(test, row);

	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < row; ++j)
		{
			cout << test1[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}