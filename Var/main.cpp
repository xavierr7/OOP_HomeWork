#include "Var.h"

int main()
{

	var a = 15;
	var b = 20;
	var c = 4.5;
	var d = 5.5;
	var e = "Hello World";
	var f = "Hello";
	cout << (a > b) << endl;
	cout << (a < b) << endl;
	cout << (a >= b) << endl;
	cout << (a <= b) << endl;
	cout << (a == b) << endl;
	cout << (a != b) << endl << endl;

	cout << (c > d) << endl;
	cout << (c < d) << endl;
	cout << (c >= d) << endl;
	cout << (c <= d) << endl;
	cout << (c == d) << endl;
	cout << (c != d) << endl << endl;

	cout << (e > f) << endl;
	cout << (e < f) << endl;
	cout << (e >= f) << endl;
	cout << (e <= f) << endl;
	cout << (e == f) << endl;
	cout << (e != f) << endl << endl;

	cout << (a + c) << endl;
	cout << (a - c) << endl;
	cout << (a * c) << endl;
	cout << (a / c) << endl << endl;

	cout << (e + b) << endl;
	cout << (e - b) << endl;
	cout << (e * b) << endl;
	cout << (e / b) << endl << endl;

	cout << (a + f) << endl;
	cout << (a - f) << endl;
	cout << (c * f) << endl;
	cout << (c / f) << endl << endl;


	return 0;
}