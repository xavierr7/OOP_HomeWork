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

void Fraction::correctFrac(Fraction& newFrac)
{
	Simplify(newFrac);
	WholePart(newFrac);
}

void Fraction::conversion(Fraction& newFrac)
{
	newFrac.numerator = newFrac.wholePart * newFrac.denominator + newFrac.numerator;
	newFrac.wholePart = 0;
}

void Fraction::conversionToImproperFraction(Fraction& This, Fraction& other)
{
	if (This.wholePart != 0 && other.wholePart != 0)
	{
		conversion(This);
		conversion(other);

	}
	else if (This.wholePart != 0 || other.wholePart != 0)
	{
		if (This.wholePart != 0)
		{
			conversion(This);
		}
		else
		{
			conversion(other);
		}
	}
}

bool Fraction::Simpilify_lowestCommonDen(Fraction& tmp1, Fraction& tmp2)
{
	Simplify(tmp1);
	Simplify(tmp2);

	int tmpDenominator = tmp1.denominator;
	tmp1.numerator *= tmp2.denominator;
	tmp1.denominator *= tmp2.denominator;
	tmp2.numerator *= tmpDenominator;
	tmp2.denominator *= tmpDenominator;

	if (tmp1.numerator == tmp2.numerator && tmp1.denominator == tmp2.denominator)
		return true;
	else
		return false;
}

Fraction Fraction::operator+( Fraction other)
{
	Fraction newFraction;
	Fraction tmp(*this);

	conversionToImproperFraction(tmp,other);

	if (tmp.denominator == other.denominator)
	{
		newFraction.numerator = tmp.numerator + other.numerator;
		newFraction.denominator = tmp.denominator;
		correctFrac(newFraction);
	}
	else
	{
		newFraction.numerator = tmp.numerator * other.denominator + other.numerator * tmp.denominator;
		newFraction.denominator = tmp.denominator * other.denominator;
		correctFrac(newFraction);
	}

	return newFraction;
}

Fraction Fraction::operator-(Fraction other)
{
	Fraction newFraction;
	Fraction tmp(*this);

	conversionToImproperFraction(tmp, other);

	if (tmp.denominator == other.denominator)
	{
		newFraction.numerator = tmp.numerator - other.numerator;
		newFraction.denominator = tmp.denominator;
		correctFrac(newFraction);
	}
	else
	{
		newFraction.numerator = tmp.numerator * other.denominator - other.numerator * tmp.denominator;
		newFraction.denominator = tmp.denominator * other.denominator;
		correctFrac(newFraction);
	}

	return newFraction;
}

Fraction Fraction::operator*(Fraction other)
{
	Fraction newFraction;
	Fraction tmp(*this);

	conversionToImproperFraction(tmp, other);

	newFraction.numerator = tmp.numerator * other.numerator;
	newFraction.denominator = tmp.denominator * other.denominator;
	correctFrac(newFraction);
	return newFraction;
}

Fraction Fraction::operator/(Fraction other)
{
	Fraction newFraction;
	Fraction tmp(*this);

	conversionToImproperFraction(tmp, other);

	newFraction.numerator = tmp.numerator * other.denominator;
	newFraction.denominator = tmp.denominator * other.numerator;
	correctFrac(newFraction);
	return newFraction;
}

Fraction Fraction::operator+=( Fraction other)
{
	
	return *this = *this + other;
}

Fraction Fraction::operator-=(Fraction other)
{
	return *this = *this - other;
}

Fraction Fraction::operator*=(Fraction other)
{
	return *this = *this * other;
}

Fraction Fraction::operator/=(Fraction other)
{
	return *this = *this / other;
}

Fraction Fraction::operator-()
{
	if (wholePart > 0)
	{
		return Fraction(-wholePart, numerator, denominator);
	}
	else if (wholePart < 0)
	{
		return Fraction(wholePart, numerator, denominator);
	}
	else if(numerator > 0)
	{
		return Fraction(-numerator, denominator);
	}
	else if (numerator < 0)
	{
		return Fraction(numerator, denominator);
	}
}

Fraction& Fraction::operator++()
{
	if (wholePart != 0)
	{
		wholePart += 1;
		return *this;
	}
	numerator += denominator;
	correctFrac(*this);
	return *this;
}

Fraction Fraction::operator++(int)
{
	if (wholePart != 0)
	{
		wholePart += 1;
		return *this;
	}
	Fraction temp(*this);
	numerator += denominator;
	correctFrac(*this);
	return temp;
}

Fraction& Fraction::operator--()
{
	if (wholePart != 0)
	{
		wholePart -= 1;
		return *this;
	}
	numerator -= denominator;
	return *this;
}

Fraction Fraction::operator--(int)
{
	if (wholePart != 0)
	{
		wholePart -= 1;
		return *this;
	}
	Fraction temp(*this);
	numerator -= denominator;
	return temp;
}

bool Fraction::operator<(Fraction other)
{
	if (wholePart != 0 && other.wholePart != 0)
	{
		if (wholePart > other.wholePart)
			return false;
		else
			return true;
	}
	else if(wholePart != 0 || other.wholePart != 0)
	{
		if (wholePart != 0)
		{
			if (wholePart > 0)
				return false;
			else
				return true;
		}
		else
		{
			if (other.wholePart > 0)
				return true;
			else
				return false;
		}
	}
	Fraction tmp(*this);

	tmp.numerator *= other.denominator;
	tmp.denominator *= other.denominator;
	other.numerator *= denominator;
	other.denominator *= denominator;
	
	if (tmp.numerator < other.numerator)
		return true;
	else
		return false;
}

bool Fraction::operator>(Fraction other)
{
	return !(*this < other);
}

bool Fraction::operator==(Fraction other)
{
	Fraction tmp1(*this);
	Fraction tmp2(other);

	if (wholePart != 0 && other.wholePart != 0)
	{
		conversion(tmp1);
		conversion(tmp2);

		return Simpilify_lowestCommonDen(tmp1, tmp2);
	}
	else if (wholePart != 0 || other.wholePart != 0)
	{
		if (wholePart != 0)
			conversion(tmp1);
		else
			conversion(tmp2);

		return Simpilify_lowestCommonDen(tmp1, tmp2);
	}
	Fraction tmp(*this);
	Simplify(tmp);
	Simplify(other);
	if (tmp.numerator == other.numerator && tmp.denominator == other.denominator)
		return true;
	return false;
}

bool Fraction::operator!=(Fraction other)
{
	return !(*this == other);
}

bool Fraction::operator<=(Fraction other)
{
	if (*this == other)
		return true;
	else if (*this < other)
		return true;
	else
		return false;
}

bool Fraction::operator>=(Fraction other)
{
	if (*this == other)
		return true;
	return !(*this <= other);
}

std::ostream& operator<<(std::ostream& out, const Fraction& fraction)
{
	if (fraction.wholePart != 0)
	{
		if (fraction.denominator == 1)
		{
			out << fraction.wholePart;
		}
		else
		{
			out << "whole part|numerator/denominator\n";
			out << fraction.wholePart << "|" << fraction.numerator << "/" << fraction.denominator;
		}
	}
	else
	{
		if (fraction.denominator == 1)
		{
			out << fraction.numerator;
		}
		else
		{
			out << "numerator/denominator\n";
			out << fraction.numerator << "/" << fraction.denominator;
		}
	}
	return out;
}
