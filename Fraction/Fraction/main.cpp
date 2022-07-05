#include "Fraction.h"

int main()
{

	Fraction a(5, 7);
	Fraction b(3, 5);

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