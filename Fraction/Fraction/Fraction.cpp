#include "Fraction.h"

void Fraction::Simplify()
{
	int act = 1;
	while (act !=0)
	{
		act = 0;
		for (size_t i = 2; i <= 10; i++)
		{
			if (this->numerator % i == 0 && this->denominator % i == 0)
			{
				this->numerator /= i;
				this->denominator /= i;
				++act;
			}
		}
		if (this->numerator == this->denominator)
		{
			this->numerator = 1;
			this->denominator = 1;
		}
	}
}

void Fraction::WholePart()
{
	if ((this->numerator / this->denominator) >= 1)
	{
		int count = 0;
		int tmp = this->numerator;
		while (true)
		{
			if (tmp % this->denominator != 0)
			{
				++count;
				--tmp;
			}
			else
			{
				this->wholePart = (this->numerator - count) / this->denominator;
				this->numerator = this->numerator - (this->numerator - count);
				break;
			}
		}
	}
}

void Fraction::correctFrac()
{
	this->Simplify();
	this->WholePart();
}

void Fraction::conversion()
{
	this->numerator = this->wholePart * this->denominator + this->numerator;
	this->wholePart = 0;
}

void Fraction::conversionToImproperFraction(Fraction& other)
{
	if (this->wholePart != 0 && other.wholePart != 0)
	{
		this->conversion();
		other.conversion();

	}
	else if (this->wholePart != 0 || other.wholePart != 0)
	{
		if (this->wholePart != 0)
		{
			this->conversion();
		}
		else
		{
			other.conversion();
		}
	}
}

bool Fraction::Simpilify_lowestCommonDen( Fraction& tmp2)
{
	this->Simplify();
	tmp2.Simplify();

	int tmpDenominator = this->denominator;
	this->numerator *= tmp2.denominator;
	this->denominator *= tmp2.denominator;
	tmp2.numerator *= tmpDenominator;
	tmp2.denominator *= tmpDenominator;

	if (this->numerator == tmp2.numerator && this->denominator == tmp2.denominator)
		return true;
	else
		return false;
}

Fraction Fraction::operator+( Fraction other)
{
	Fraction newFraction;
	Fraction tmp(*this);

	tmp.conversionToImproperFraction(other);

	if (tmp.denominator == other.denominator)
	{
		newFraction.numerator = tmp.numerator + other.numerator;
		newFraction.denominator = tmp.denominator;
		newFraction.correctFrac();
	}
	else
	{
		newFraction.numerator = tmp.numerator * other.denominator + other.numerator * tmp.denominator;
		newFraction.denominator = tmp.denominator * other.denominator;
		newFraction.correctFrac();
	}

	return newFraction;
}

Fraction Fraction::operator-(Fraction other)
{
	Fraction newFraction;
	Fraction tmp(*this);

	tmp.conversionToImproperFraction( other);

	if (tmp.denominator == other.denominator)
	{
		newFraction.numerator = tmp.numerator - other.numerator;
		newFraction.denominator = tmp.denominator;
		newFraction.correctFrac();
	}
	else
	{
		newFraction.numerator = tmp.numerator * other.denominator - other.numerator * tmp.denominator;
		newFraction.denominator = tmp.denominator * other.denominator;
		newFraction.correctFrac();
	}

	return newFraction;
}

Fraction Fraction::operator*(Fraction other)
{
	Fraction newFraction;
	Fraction tmp(*this);

	tmp.conversionToImproperFraction( other);

	newFraction.numerator = tmp.numerator * other.numerator;
	newFraction.denominator = tmp.denominator * other.denominator;
	newFraction.correctFrac();
	return newFraction;
}

Fraction Fraction::operator/(Fraction other)
{
	Fraction newFraction;
	Fraction tmp(*this);

	tmp.conversionToImproperFraction( other);

	newFraction.numerator = tmp.numerator * other.denominator;
	newFraction.denominator = tmp.denominator * other.numerator;
	newFraction.correctFrac();
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
	this->correctFrac();
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
	this->correctFrac();
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
		tmp1.conversion();
		tmp2.conversion();

		return tmp1.Simpilify_lowestCommonDen(tmp2);
	}
	else if (wholePart != 0 || other.wholePart != 0)
	{
		if (wholePart != 0)
			tmp1.conversion();
		else
			tmp2.conversion();

		return tmp1.Simpilify_lowestCommonDen(tmp2);
	}
	Fraction tmp(*this);
	tmp.Simplify();
	other.Simplify();
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
