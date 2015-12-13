#include <iostream>
#include "Matrix.cpp"

using namespace std;
MATRIX<double> transitivityClosure(MATRIX<double>, int);
MATRIX<double> multiplication(MATRIX<double>& temp_store, MATRIX<double> temp, int row);
int length(MATRIX<double> temp, int row);

MATRIX<double> disMatrix(MATRIX<double> temp, int row) {
	MATRIX<double> tC(row, row);
	tC = transitivityClosure(temp, row);
	
	// for (int h1 = 0; h1 < row; ++h1)
	// {
	// 	for (int h2 = 0; h2 < row; ++h2)
	// 	{
	// 		cout << tC[h1][h2] << " ";
	// 	}
	// 	cout << endl;
	// }
	// cout << endl;

	MATRIX<double> temp_return(row, row);

	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < row; ++j) {
			if (tC[i][j] == 1) {
				if (temp[i][j] == 1)
					temp_return[i][j] = 1;
				else {
					for (int k = 0; k < row; ++k) {
						MATRIX<double> tempin_return(row, row);
						MATRIX<double> tempin_store(row, row);
						tempin_store = temp;
						for (int x = 1; x < row; ++x) {
							temp_return = multiplication(tempin_store, temp, row);
							if (tempin_return[i][j] != 0)
								temp_return[i][j] = tempin_return[i][j];
							else 
								continue; 
						}
					}
				}
			}
		}
	}
	return temp_return;
}




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


int length(MATRIX<double> temp, int row) {
	int input_length = 0;
	cout << "Please enter the length" << endl
		 << "length?";
	cin >> input_length;

	int pointA = 0;
	int pointB = 0;

	cout << "Please enter two point you want to use" << endl
		 <<"A?";
	cin >> pointA;
	cout << "B?";
	cin >> pointB;


	cout << "The two point is <" << pointA << "," << pointB << ">" << endl;

	MATRIX<double> temp_return(row, row);
	MATRIX<double> temp_store(row, row);
	temp_store = temp;

	for (int x = 1; x < input_length; ++x) {
		temp_return = multiplication(temp_store, temp, row);
	}
	
	return temp_return[pointA][pointB];	
}

MATRIX<double> multiplication(MATRIX<double>& temp_store, MATRIX<double> temp, int row) {
	MATRIX<double> temp_return(row, row);
	MATRIX<double> temp_re(row,row);
	temp_re  = temp_store;
	temp_store = temp_return;

	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < row; ++j)
		{
			double sum = 0.0;
			for (int k = 0; k < row; ++k)
			{
				sum =sum + temp_re[i][k] * temp[k][j];
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

	MATRIX<double> test_return(row, row);
	test_return = disMatrix(test, row);
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < row; ++j)
		{
			cout << test_return[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}