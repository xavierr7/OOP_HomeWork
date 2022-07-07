#include "Fraction.h"

int main()
{

	Fraction a(3, 4);
	Fraction b(1, 2);

	Fraction c = a + b;
	Fraction d = a - b;
	Fraction e = a * b;
	Fraction f = a / b;

	cout << c;
	cout << d;
	cout << e;
	cout << f;

	return 0;
}