#pragma once
#include <iostream>
using std::ostream;

class Fraction
{
public:
	// Constructors
	Fraction();
	Fraction(int n, int d);

	// POST: Fraction is simplified, e.g. 3/9, simplifies to 1/3
	void simplify(); 
	
	// PARAM: f is a Fraction
	// POST: Returns true if calling object and f are equivalent fractions,
	//       false otherwise
	bool equals(const Fraction & f)const;

	// Overloaded comparison operators
	// ==, !=, <, <=, >, >=

	// PARAM: f is a Fraction
	// POST: Returns true if calling object and f are equivalent fractions,
	//       false otherwise
	// bool operator==(const Fraction & f)const;

private:
	int numerator; //the "top" of the fraction
	int denominator; //the "bottom" of the fraction

	// PARAM: a and b are integers
	// POST: Returns the greatest common divisor of a and b
	int gcd(int a, int b)const;

	friend ostream & operator<<(ostream & os, const Fraction & f);
};

