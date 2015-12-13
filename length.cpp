#include <iostream>
#include "Matrix.cpp"

using namespace std;
MATRIX<double> multiplication(MATRIX<double>, int);


int length(MATRIX<double> temp, int row) {
	int input_length = 0;
	cout << "Please enter the length" << endl
		 << "length?";
	cin >> input_length;

	int pointA = 0;
	int pointB = 0;
	int pointC = 0;
	int pointD = 0;
	cout << "Please enter two point you want to use" << endl
		 <<"A?";
	cin >> pointA;
	cout << "B?";
	cin >> pointB;
	// cout << "C?";
	// cin >> pointC;
	// cout << "D?";
	// cin >> pointD;

	cout << "The two point is <" << pointA << "," << pointB << ">" << endl
		 << "<" << pointC << "," << pointD << ">" << endl;

	MATRIX<double> temp_return(row, row);
	for (int x = 0; x < input_length; ++x)
		temp_return = multiplication(temp, row);
	return temp_return[pointA][pointB];	
}

MATRIX<double> multiplication(MATRIX<double> temp, int row) {
	MATRIX<double> temp_return(row, row);
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < row; ++j)
		{
			double sum = 0.0;
			for (int k = 0; k < row; ++k)
			{
				sum += temp[i][k] * temp[k][j];
			}
			temp_return[i][j] = sum;
		}
	} //end for

	return temp_return;
}

int main(int argc, char const *argv[])
{
	int row = 4;
	MATRIX<double> test(row, row);
	test[0][1] = 1;
	test[1][2] = 1;
	// test[1][2] = 1;
	// test[1][3] = 1;
	// test[2][0] = 1;
	// test[2][1] = 1;
	// test[2][3] = 1;
	// test[3][0] = 1;

	MATRIX<double> test_return(row, row);
	int a = length(test, row);

	cout << a << endl;
	return 0;
}