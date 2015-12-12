#include <iostream>
#include "Matrix.cpp"

using namespace std;

bool transitivity(MATRIX<double>& temp, int row) {
	for (int i = 0; i < row; ++i) {
			for (int j = 0; j < row; ++j) {
				if (i == j) 
					continue;
				if (temp[i][j] == 1) {
					for (int k = 0; k < row; ++k) {
						if(temp[j][k] == 1)
							if(temp[i][k] == 1)
								return true;
					}
				}
			}
		}
	return false;	
}

int main(int argc, char const *argv[])
{
	int row = 3;
	MATRIX<double> test(row, row);
	test[0][1] = 1;
	test[1][2] = 1;
	// test[0][2] = 1;
	transitivity(test,row) ? cout << "ture" : cout << "false"; 
	return 0;
}