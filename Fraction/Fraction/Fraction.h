#pragma once
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

class Fraction
{
	int wholePart;
	int numerator;
	int denominator;

	void Simplify(Fraction& newFrac);
	void WholePart(Fraction& newFrac);
	void conversion(Fraction& newFrac);
	void conversionToImproperFraction(Fraction& This, Fraction& other);
	void correctFrac(Fraction& newFrac);
	bool Simpilify_lowestCommonDen(Fraction& tmp1, Fraction& tmp2);

public:
	Fraction() : numerator{ 1 }, denominator{ 1 }, wholePart{ 0 } {}
	Fraction(int numerator) : numerator{ numerator }, denominator{ 1 }, wholePart{ 0 }{}
	Fraction(int numerator, int denominator) : numerator{ numerator }, wholePart{ 0 }
	{
		SetDenominator(denominator);

	}
	Fraction(int wholePart, int numerator, int denominator) : numerator{ numerator }
	{
		SetWholePart(wholePart);
		SetDenominator(denominator);
	}

	Fraction operator + (Fraction other);
	Fraction operator - (Fraction other);
	Fraction operator * (Fraction other);
	Fraction operator / (Fraction other);
	Fraction operator += (Fraction other);
	Fraction operator -= (Fraction other);
	Fraction operator *= (Fraction other);
	Fraction operator /= (Fraction other);
	Fraction operator-();
	Fraction& operator++();
	Fraction operator++(int);
	Fraction& operator--();
	Fraction operator--(int);

	bool operator <(Fraction other);
	bool operator >(Fraction other);
	bool operator ==(Fraction other);
	bool operator !=(Fraction other);
	bool operator <=(Fraction other);
	bool operator >=(Fraction other);

	friend std::ostream& operator << (std::ostream& out, const Fraction& fraction);

	void SetWholePart(int wholePart)
	{
		this->wholePart = wholePart;
	}
	void SetNumerator(int numerator)
	{
		this->numerator = numerator;
	}
	void SetDenominator(int denominator)
	{
		if (denominator == 0)
		{
			return;
		}
		this->denominator = denominator;
	}

	int GetWholePart()
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

