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

	cout << arr1 << endl;

	cout << arr2 << endl;

	cout << arr3 << endl;

	cout << "------------------------------------------------------------------\n";
	/////////////////////////
	//changes of arrays

	arr1.addRow(1);
	cout << arr1 << endl;

	double arr[5]{ 3.2, 5.1, 7.9, 2.5, 0.4 };
	arr2.addRow(1, arr);
	cout << arr2 << endl;

	arr1.delRow(1);
	cout << arr1 << endl;

	arr3.addColumn(3);
	cout << arr3 << endl;

	arr3.delColumn(3);
	cout << arr3 << endl;
	cout << "------------------------------------------------------------------\n";

	/////////////////////////////
	//changes values of arrays


	Matrix<int> arr4(2, 5);
	arr4.set();
	cout << arr4 << endl;

	Matrix<int> tmpArr = arr1 + arr4;

	cout << tmpArr << endl;

	tmpArr = arr1 * 2;
	cout << tmpArr << endl;
	cout << "------------------------------------------------------------------\n";

	////////////////////////
	//sort by row

	arr1.sortByRow();
	cout << arr1 << endl;
	

	arr2.sortByRow();
	cout << arr2 << endl;

	arr3.sortByRow();
	cout << arr3 << endl;
	cout << "------------------------------------------------------------------\n";

	////////////////////////////////
	//transform

	arr1.transform();
	cout << arr1 << endl;

	arr2.transform();
	cout << arr2 << endl;


	arr3.transform();
	cout << arr3 << endl;
	cout << "------------------------------------------------------------------\n";

	///////////////////
	// index

	cout << arr3[0][0];
	

	return 0;
}