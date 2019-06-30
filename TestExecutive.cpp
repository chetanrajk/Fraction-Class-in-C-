///////////////////////////////////////////////////////////////////////////
// TestExecutive.cpp - Provides entry point for console application and  //
// ver 1.0             demonstrates Fraction class and its operations   //
// Language:    C++, Visual Studio 2017                                 //
/////////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include <iostream>
#include "FractionClass.h"

int main() {

	// construct fractions

	std::cout << "\n\n====> Fraction Class Demonstration <=====\n\n";
	Fraction f1;
	std::cout << "Fraction created with default constructor: " << f1 << std::endl;
	Fraction f2(8);
	std::cout << "Fraction created with one parameter constructor: " << f2 << std::endl;

	std::cout << "\n -- Operations on fractions --\n ";
	Fraction f3(7, 6);
	Fraction f4(4, 9);

	std::cout << "\nFractions created with two parameter constructor: f3 = " << f3 << " and f4 = " << f4;
	Fraction f5 = f3 + f4;
	std::cout << "\n\nAddition:- f3 + f4 = " << f5;
	Fraction f6 = f3 - f4;
	std::cout << "\n\nSubstraction:- f3 - f4 = " << f6;
	Fraction f7 = f3 * f4;
	std::cout << "\n\nMultiplication:- f3 * f4 = " << f7;
	Fraction f8 = f3 / f4;
	std::cout << "\n\nDivision:- f3 / f4 = " << f8;

	std::cout << "\n\nIs f3 is equal to f4 :- ";
	if (f3 == f4)
		std::cout << "True. Fractions are equal.";
	else
		std::cout << "False. Fractions are not equal.";

	std::cout << "\n\nIs f3 is not equal to f4 :- ";
	if (f3 != f4)
		std::cout << "True. Fractions are not equal.";
	else
		std::cout << "False. Fractions are equal.";

	std::cout << "\n\nIs f3 is greater than f4 :- ";
	if (f3 > f4)
		std::cout << "True. First fraction is greater than second";
	else
		std::cout << "False. First fraction is not greater than second.";

	std::cout << "\n\nIs f3 is less than f4 :- ";
	if (f3 < f4)
		std::cout << "True. First fraction is less than second";
	else
		std::cout << "False. First fraction is not less than second.";

	// test for exception

	try {
		std::cout << "\n\nTrying to create fraction with 0 at denominator. f5 = 5/0\n";
		Fraction f5(5, 0);
		std::cout << "\nFraction created";
	}
	catch (FractionExceptionClass &exp) {
		std::cout << exp.what();
	}

	std::cout << "\n\n";
	return 0;
}
