#include <iostream>
#include "Matrix.cpp"

using namespace std;

bool symmetry(MATRIX<double>& temp,int row) {
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < row; ++j) {
				if (temp[i][j] == temp[j][i]) 
					continue;
				else 
					return false;				
		} //end for
	} //end for
	return true;
} //end function symmetry

/*
int main(int argc, char const *argv[])
{
	int row = 3;
	MATRIX<double> test(row, row);
	test[0][0] = 1;
	test[1][2] = 1;
	//test[2][1] = 1;
	symmetry(test, row)?cout << "Is symmetry" << endl : cout << "Not symmetry" << endl;
	return 0;
} 
*/