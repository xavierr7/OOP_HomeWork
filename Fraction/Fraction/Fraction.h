#pragma once
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

class Fraction
{
	size_t numerator;
	size_t denominator;
	size_t wholePart;
public:
	Fraction() : numerator{ 1 }, denominator{ 1 }, wholePart{0} {}
	Fraction(size_t numerator) : numerator{numerator}, denominator { 1 }, wholePart{ 0 }{}
	Fraction(size_t numerator, size_t denominator) : numerator{numerator}, wholePart{0}
	{
		SetDenominator(denominator);
	}
	Fraction(size_t wholePart, size_t numerator, size_t denominator) : numerator{numerator} 
	{
		if (wholePart == 0)
		{
			return;
		}
		SetDenominator(denominator);
		this->wholePart = wholePart;
	}

	void SetDenominator(size_t denominator);
	void Simplify(Fraction& newFrac);
	void WholePart(Fraction& newFrac);
	Fraction operator + (const Fraction& other);
	Fraction& operator = (const Fraction& other);
	friend std::ostream& operator << (std::ostream& out, const Fraction& fraction);
};

