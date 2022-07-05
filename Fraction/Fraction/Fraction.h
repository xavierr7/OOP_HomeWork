#pragma once
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

class Fraction
{
	size_t wholePart;
	int numerator;
	int denominator;

	void Simplify(Fraction& newFrac);
	void WholePart(Fraction& newFrac);
	void conversionToImproperFraction(Fraction& newFrac);

public:
	Fraction() : numerator{ 1 }, denominator{ 1 }, wholePart{ 0 } {}
	Fraction(int numerator) : numerator{ numerator }, denominator{ 1 }, wholePart{ 0 }{}
	Fraction(int numerator, int denominator) : numerator{ numerator }, wholePart{ 0 }
	{
		SetDenominator(denominator);
	}
	Fraction(size_t wholePart, int numerator, int denominator) : numerator{ numerator }
	{
		SetWholePart(wholePart);
		SetDenominator(denominator);
	}

	Fraction operator + (Fraction& other);
	Fraction operator - (Fraction& other);
	Fraction operator * (Fraction& other);
	Fraction operator / (Fraction& other);
	Fraction& operator = (const Fraction& other);
	friend std::ostream& operator << (std::ostream& out, const Fraction& fraction);

	void SetWholePart(size_t wholePart)
	{
		if (wholePart < 0)
		{
			return;
		}
		this->wholePart = wholePart;
	}
	void SetNumerator(int numerator)
	{
		this->numerator;
	}
	void SetDenominator(int denominator)
	{
		if (denominator == 0)
		{
			return;
		}
		this->denominator = denominator;
	}

	size_t GetWholePart()
	{
		return wholePart;
	}
	int GetNumerator()
	{
		return numerator;
	}
	int GetDenominator()
	{
		return denominator;
	}
};

