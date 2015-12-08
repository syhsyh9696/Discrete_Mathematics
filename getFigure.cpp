#include <iostream>
#include "Matrix.cpp"

using namespace std;

void getFigure() {
	int nodeNumber = 0;
	cout << "How many node in the figure ?" << endl
		 <<"?";
	cin >> nodeNumber;	

	MATRIX<double> newFigure(nodeNumber,nodeNumber);

	int flag = 0;
	while(flag == 0) {
		char temp[5];
		cout << "Enter the two node, example(<1,2>)" << endl 
			 << "?";
		cin >> temp;
		cout << temp;

		int temp1 = (int)(temp[1] - '0');
		int temp2 = (int)(temp[3] - '0');
		
	}

}

int main(int argc, char const *argv[])
{
	getFigure();
	return 0;
}