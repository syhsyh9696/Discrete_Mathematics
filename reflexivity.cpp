#include <iostream>
#include <cmath>
#include "Matrix.cpp"

using namespace std;

bool reflexivity(MATRIX<double>& temp, int row) {
	int flag = 0;
	for (int i = 0; i < row; ++i)
	{
		if (temp[i][i] == 1) {
			++flag;
			continue;
		}
		else 
			break;
	}
	return (flag == row);
}

bool anti_reflexivity(MATRIX<double>& temp, int row) {
	int flag = 0;
	for (int i = 0; i < row; ++i)
	{
		if (temp[i][i] == 0) {
			++flag;
			continue;
		}
		else 
			break;
	}
	return (flag == row);
}

int main(int argc, char const *argv[])
{
	int r = 3;
	MATRIX<double> test(r,r);
	for (int i = 0; i < r; ++i)
	{
		test[i][i] = 1;
		//cout << test[i][i];
	}

	if( reflexivity(test, r) )
		cout << "reflexivity" << endl;

	return 0;
}