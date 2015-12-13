#include <iostream>
#include "Matrix.cpp"

using namespace std;
MATRIX<double> multiplication(MATRIX<double>& temp_store, MATRIX<double> temp, int row);


int length(MATRIX<double> temp, int row) {
	int input_length = 0;
	cout << "Please enter the length" << endl
		 << "length?";
	cin >> input_length;

	int pointA = 0;
	int pointB = 0;
	//int pointC = 0;
	//int pointD = 0;
	cout << "Please enter two point you want to use" << endl
		 <<"A?";
	cin >> pointA;
	cout << "B?";
	cin >> pointB;
	// cout << "C?";
	// cin >> pointC;
	// cout << "D?";
	// cin >> pointD;

	cout << "The two point is <" << pointA << "," << pointB << ">" << endl;
		 //<< "<" << pointC << "," << pointD << ">" << endl;

	MATRIX<double> temp_return(row, row);
	MATRIX<double> temp_store(row, row);
	temp_store = temp;
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < row; ++j)
		{
			cout << temp_store[i][j] << " ";
		}
		cout << endl;
	}

	cout << endl;
	
	for (int x = 1; x < input_length; ++x){
		temp_return = multiplication(temp_store, temp, row);
	}

	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < row; ++j)
		{
			cout << temp_store[i][j] << " ";
		}
		cout << endl;
	}

	cout << endl;
	
	return temp_return[pointA][pointB];	
}

MATRIX<double> multiplication(MATRIX<double>& temp_store, MATRIX<double> temp, int row) {
	MATRIX<double> temp_return(row, row);
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < row; ++j)
		{
			double sum = 0.0;
			for (int k = 0; k < row; ++k)
			{
				sum =sum + temp_store[i][k] * temp[k][j];
			}
			
			temp_store[i][j] = sum;
			temp_return[i][j] = sum;
		}
	} //end for

	return temp_store;
}

int main(int argc, char const *argv[])
{
	int row = 5;
	MATRIX<double> test(row, row);
	test[0][1] = 1;
	test[1][0] = 1;
	test[1][2] = 1;
	test[2][1] = 1;
	test[3][4] = 1;
	test[4][3] = 1;
	// test[][3] = 1;
	// test[3][0] = 1;

	MATRIX<double> test_return(row, row);
	int a = length(test, row);

	cout << a << endl;

	return 0;
}