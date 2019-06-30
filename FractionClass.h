#pragma once
///////////////////////////////////////////////////////////////////////////////////////////////
// FractionClass.h - Implements Fraction class with support for operations like              //
// ver 1.0           addition, substraction, multiplication, division, equality/non-equality,//
//				     greater than/less than and display                      //
///////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>

// Fraction class

class Fraction{

public:

	Fraction();
	Fraction(int n);
	Fraction(int n, int m);

	// Getters
	int getNumerator() const { return numer; }
	int getDenomenator() const { return denom; }

	// common diviser
	int getGCD(int a, int b);

	// Overloaded operators for operations on fractions
	friend Fraction operator+(const Fraction& f1, const Fraction& f2); // addition operation
	friend Fraction operator-(const Fraction& f1, const Fraction& f2); // substraction operation
	friend Fraction operator*(const Fraction& f1, const Fraction& f2); // multiplication operation
	friend Fraction operator/(const Fraction& f1, const Fraction& f2); // divide operation

	friend bool operator==(const Fraction& f1, const Fraction& f2); // equality operation
	friend bool operator!=(const Fraction& f1, const Fraction& f2); // non-equality operation
	
	friend bool operator>(const Fraction& f1, const Fraction& f2);   // greater than operation
	friend bool operator<(const Fraction& f1, const Fraction& f2);   // less than operation

	friend std::ostream& operator<<(std::ostream& os, const Fraction& f); // display fractions

private:

	int numer;
	int denom;
};

// FractionExceptionClass for generating exception and display message
class FractionExceptionClass{

public:
	FractionExceptionClass(const std::string& msg);
	std::string& what(void);

private:
	std::string msg;
};
