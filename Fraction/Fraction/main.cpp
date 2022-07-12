#include "Fraction.h"

int main()
{

	Fraction a(2, 3, 8);
	Fraction b(3, 19, 8);

	
	Fraction c = a + b;
	Fraction d = a - b;
	Fraction e = a * b;
	Fraction f = a / b;

	
	cout << c << endl;
	cout << d << endl;
	cout << e << endl;
	cout << f << endl;

	//cout << (a == b);

	return 0;
}