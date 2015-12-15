#include <iostream>
#include "Matrix.h"
#include <cmath>
#include <string>

using namespace std;

bool reflexivity(MATRIX<double>& temp, int row);
bool anti_reflexivity(MATRIX<double>& temp, int row);
bool symmetry(MATRIX<double>& temp,int row);
bool transitivity(MATRIX<double>& temp, int row);
MATRIX<double> reflexivityClosure(MATRIX<double> temp, int row);
MATRIX<double> symmetryClosure(MATRIX<double> temp, int row);
MATRIX<double> transitivityClosure(MATRIX<double> temp, int row);
MATRIX<double> accMatrix(MATRIX<double> temp, int row);
MATRIX<double> disMatrix(MATRIX<double> temp, int row);
MATRIX<double> multiplication(MATRIX<double>& temp_store, MATRIX<double> temp, int row);
int length(MATRIX<double> temp, int row);
void getFigure(MATRIX<double>& newFigure, int nodeNumber);
void display(MATRIX<double> temp, int row);

int main(int argc, char const *argv[])
{
	int row;
	cout << "Please enter how many node in the figure" << endl
		 << "Row?";
	cin >> row;
	MATRIX<double> newFigure(row, row);
	getFigure(newFigure, row);
	display(newFigure,row);

	reflexivity(newFigure, row) ? cout << "The figure is reflexivity" << endl
								: cout << "The figure is't reflexivity" << endl;
	symmetry(newFigure, row) ? cout << "The figure is symmetry" << endl
							 : cout << "The figure is't symmetry" << endl;
	transitivity(newFigure, row) ? cout << "The figure is transitivity" << endl
								 : cout << "The figure is't transitivity" <<endl;							
	
	MATRIX<double> temp_for_display(row, row);
	
	temp_for_display = reflexivityClosure(newFigure, row);
	cout << "The reflexivityClosure is: " << endl;
	display(temp_for_display, row);
	cout << endl;

	temp_for_display = symmetryClosure(newFigure, row);
	cout << "The symmetryClosure is: " << endl;
	display(temp_for_display, row);
	cout << endl;

	temp_for_display = transitivityClosure(newFigure, row);
	cout << "The transitivityClosure is: " << endl;
	display(temp_for_display, row);
	cout << endl;

	temp_for_display = accMatrix(newFigure, row);
	cout << "The accMatrix is: " << endl;
	display(temp_for_display, row);
	cout << endl;

	temp_for_display = disMatrix(newFigure, row);
	cout << "The disMatrix is: " << endl;
	display(temp_for_display, row);
	cout << endl;

	int temp_int = 0;
	temp_int = length(newFigure, row);
	cout << temp_int << endl;

	return 0;
}

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

MATRIX<double> accMatrix(MATRIX<double> temp, int row) {
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

MATRIX<double> disMatrix(MATRIX<double> temp, int row) {
	MATRIX<double> tC(row, row);
	tC = transitivityClosure(temp, row);

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
						for (int x = 0; x < row; ++x) {
							temp_return = multiplication(tempin_store, temp, row);
							if (tempin_return[i][j] != 0) {
								temp_return[i][j] = tempin_return[i][j];
								break;
							}
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

void getFigure(MATRIX<double>& newFigure, int nodeNumber) {
	//int nodeNumber = 0;
	//cout << "How many node in the figure ?" << endl
	//	 <<"?";
	//cin >> nodeNumber;	

	//MATRIX<double> newFigure(nodeNumber,nodeNumber);

	int flag = 0;
	while(flag == 0) {
		char temp[5];
		cout << "Enter the two node, example(<1,2>)" << endl 
			 << "?";
		cin >> temp;
		//cout << temp << endl;

		int temp1 = (int)(temp[1] - '0');
		int temp2 = (int)(temp[3] - '0');

		++newFigure[temp1][temp2];
		//cout << newFigure[temp1][temp2];

		cout << "Do you want enter new? (enter 0 for next, enter 1 for exit)" << endl 
		     << "?";
		cin >> flag;
	}
	return;
}

void display(MATRIX<double> temp, int row) {
	for(int i = 0; i < row; ++i) {
		for(int j =0; j < row; ++j) {
			cout << temp[i][j] << "  ";
		}
		cout << endl;
	}
	return;
}