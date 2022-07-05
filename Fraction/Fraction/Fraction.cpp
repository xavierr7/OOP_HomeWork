#include "Fraction.h"

void Fraction::Simplify(Fraction& newFrac)
{
	int act = 1;
	while (act !=0)
	{
		act = 0;
		for (size_t i = 2; i <= 10; i++)
		{
			if (newFrac.numerator % i == 0 && newFrac.denominator % i == 0)
			{
				newFrac.numerator /= i;
				newFrac.denominator /= i;
				++act;
			}
		}
		if (newFrac.numerator == newFrac.denominator)
		{
			newFrac.numerator = 1;
			newFrac.denominator = 1;
			newFrac.wholePart = 0;
		}
	}
}

void Fraction::WholePart(Fraction& newFrac)
{
	if ((newFrac.numerator / newFrac.denominator) >= 1)
	{
		int count = 0;
		int tmp = newFrac.numerator;
		while (true)
		{
			if (tmp % newFrac.denominator != 0)
			{
				++count;
				--tmp;
			}
			else
			{
				newFrac.wholePart = (newFrac.numerator - count) / newFrac.denominator;
				newFrac.numerator = newFrac.numerator - (newFrac.numerator - count);
				break;
			}
		}
	}
}

void Fraction::conversionToImproperFraction(Fraction& newFrac)
{
	newFrac.numerator = newFrac.wholePart * newFrac.denominator + newFrac.numerator;
	wholePart = 0;
}

Fraction Fraction::operator+( Fraction& other)
{
	Fraction newFraction;
	if (this->wholePart > 0 || other.wholePart > 0)
	{
		if (this->wholePart > 0)
		{
			conversionToImproperFraction(*this);
		}
		else
		{
			conversionToImproperFraction(other);
		}
	}
	else
	{
		conversionToImproperFraction(*this);
		conversionToImproperFraction(other);
	}

	if (this->denominator == other.denominator)
	{
		newFraction.numerator = numerator + other.numerator;
		newFraction.denominator = denominator;
	}
	else
	{
		newFraction.numerator = this->numerator * other.denominator + other.numerator * this->denominator;
		newFraction.denominator = this->denominator * other.denominator;
		Simplify(newFraction);
		WholePart(newFraction);
	}

	return newFraction;
}

Fraction Fraction::operator-(Fraction& other)
{
	Fraction newFraction;
	if (this->wholePart > 0 || other.wholePart > 0)
	{
		if (this->wholePart > 0)
		{
			conversionToImproperFraction(*this);
		}
		else
		{
			conversionToImproperFraction(other);
		}
	}
	else
	{
		conversionToImproperFraction(*this);
		conversionToImproperFraction(other);
	}

	if (this->denominator == other.denominator)
	{
		newFraction.numerator = numerator - other.numerator;
		newFraction.denominator = denominator;
	}
	else
	{
		newFraction.numerator = this->numerator * other.denominator - other.numerator * this->denominator;
		newFraction.denominator = this->denominator * other.denominator;
		Simplify(newFraction);
		WholePart(newFraction);
	}

	return newFraction;
}

Fraction Fraction::operator*(Fraction& other)
{
	Fraction newFraction;
	if (this->wholePart > 0 || other.wholePart > 0)
	{
		if (this->wholePart > 0)
		{
			conversionToImproperFraction(*this);
		}
		else
		{
			conversionToImproperFraction(other);
		}
	}
	else
	{
		conversionToImproperFraction(*this);
		conversionToImproperFraction(other);
	}

	newFraction.numerator = numerator * other.numerator;
	newFraction.denominator = denominator * other.denominator;
	Simplify(newFraction);
	WholePart(newFraction);

	return newFraction;
}

Fraction Fraction::operator/(Fraction& other)
{
	Fraction newFraction;
	if (this->wholePart > 0 || other.wholePart > 0)
	{
		if (this->wholePart > 0)
		{
			conversionToImproperFraction(*this);
		}
		else
		{
			conversionToImproperFraction(other);
		}
	}
	else
	{
		conversionToImproperFraction(*this);
		conversionToImproperFraction(other);
	}

	newFraction.numerator = numerator * other.denominator;
	newFraction.denominator = denominator * other.numerator;
	Simplify(newFraction);
	WholePart(newFraction);

	return newFraction;
}

Fraction& Fraction::operator=(const Fraction& other)
{
	this->numerator = other.numerator;
	this->denominator = other.denominator;
	this->wholePart = other.wholePart;
	return *this;
}

std::ostream& operator<<(std::ostream& out, const Fraction& fraction)
{
	if (fraction.wholePart > 0)
	{
		out << "whole part|numerator/denominator\n";
		out << fraction.wholePart << "|" << fraction.numerator << "/" << fraction.denominator << endl;
	}
	else
	{
		out << "numerator/denominator\n";
		out << fraction.numerator << "/" << fraction.denominator << endl;
	}
	return out;
}
