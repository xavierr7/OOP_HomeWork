#include "Matrix.h"

int main()
{
	srand((unsigned int)time(NULL));

	////////////////////////
	//definition and filling

	Matrix<int> arr1(2, 5);
	arr1.set();
	Matrix<double> arr2(2, 5);
	arr2.set();
	Matrix<char> arr3(2, 5);
	arr3.set();

	arr1.print();
	cout << endl;
	arr2.print();
	cout << endl;
	arr3.print();
	cout << endl;
	cout << "------------------------------------------------------------------\n";
	/////////////////////////
	//changes of arrays

	arr1.addRow(1);
	arr1.print();
	cout << endl;

	double arr[5]{ 3.2, 5.1, 7.9, 2.5, 0.4 };
	arr2.addRow(1, arr);
	arr2.print();
	cout << endl;

	arr1.delRow(1);
	arr1.print();
	cout << endl;

	arr3.addColumn(1);
	arr3.print();
	cout << endl;

	arr3.delColumn(1);
	arr3.print();
	cout << endl;
	cout << "------------------------------------------------------------------\n";

	/////////////////////////////
	//changes values of arrays


	Matrix<int> arr4(2, 5);
	arr4.set();
	arr4.print();
	cout << endl;

	Matrix<int> tmpArr = arr1 + arr4;

	tmpArr.print();

	cout << endl;

	tmpArr = arr1 * 2;
	tmpArr.print();
	cout << endl;
	cout << "------------------------------------------------------------------\n";

	////////////////////////
	//sort by row




	return 0;
}