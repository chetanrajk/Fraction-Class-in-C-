﻿/////////////////////////////////////////////////////////////////////////////////////////////////
// FractionClass.cpp - Implements Fraction class with support for operations like              //
// ver 1.0           addition, substraction, multiplication, division, equality/non-equality,//
//				     greater than/less than and display                      //
///////////////////////////////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include<iostream>

#include "FractionClass.h"

//----< Default constructor >-----------------------------
Fraction::Fraction(){
	numer = 0;
	denom = 1;
}

//----< one parameter constructor >-----------------------------
Fraction::Fraction(int n){
	numer = n;
	denom = 1;
}

//----< get greatest common divisor >-----------------------------
int Fraction::getGCD(int m, int n) {

	if (m <= n && (n % m == 0)) {
		return m;
	}
	else if (n < m) {
		return getGCD(n, m);
	}
	else {
		return getGCD(m, n % m);
	}
}

//----< two parameter constructor and also reduce if possible >-----------------------------
Fraction::Fraction(int n, int m) {
	
	if (m == 0) {
		throw FractionExceptionClass("Error: Denominator cannot be equal to 0..!");
	}
	else {

		int gcd = getGCD(abs(n), abs(m));

		if (m < 0) {
			numer = -(n / gcd);
			denom = -(m / gcd);
		}
		else {
			numer = n / gcd;
			denom = m / gcd;
		}
	}
}

//----< addition operation >-----------------------------
Fraction operator+(const Fraction& f1, const Fraction& f2) {
	if (f1.denom == f2.denom) {
		return Fraction(f1.numer + f2.numer, f1.denom);
	}
	else {
		return Fraction((f1.numer*f2.denom) + (f1.denom*f2.numer), (f1.denom*f2.denom));
	}
}

//----< substraction operation >-----------------------------
Fraction operator-(const Fraction& f1, const Fraction& f2) {
	if (f1.denom == f2.denom) {
		return Fraction(f1.numer - f2.numer, f1.denom);
	}
	else {
		return Fraction((f1.numer*f2.denom) - (f1.denom*f2.numer), (f1.denom*f2.denom));
	}
}

//----< multiplication operation >-----------------------------
Fraction operator*(const Fraction& f1, const Fraction& f2) {
	return Fraction(f1.numer*f2.numer, f1.denom*f2.denom); 
}

//----< division operation >-----------------------------
Fraction operator/(const Fraction& f1, const Fraction& f2) {
	return Fraction(f1.numer*f2.denom, f1.denom*f2.numer);
}

//----< check for equality >-----------------------------
bool operator==(const Fraction& f1, const Fraction& f2) {
	return ((f1.numer == f2.numer) && (f1.denom == f2.denom));
}

//----< check for non-equality >-----------------------------
bool operator!=(const Fraction& f1, const Fraction& f2) {
	return ((f1.numer != f2.numer) || (f1.denom != f2.denom));
}

//----< check if first is greater than second >-----------------------------
bool operator>(const Fraction& f1, const Fraction& f2) {
	return ((f1.numer * f2.denom) > (f2.numer * f1.denom));
}

//----< check if first is less than second >-----------------------------
bool operator<(const Fraction& f1, const Fraction& f2) {
	return ((f1.numer * f2.denom) < (f2.numer * f1.denom));
}

//----< constructor >-----------------------------
FractionExceptionClass::FractionExceptionClass(const std::string& msg1) {
	msg = msg1;
}

//----< getter for message >-----------------------------
std::string& FractionExceptionClass::what() {
	return msg;
}

//----< display fraction >-----------------------------
std::ostream& operator<<(std::ostream& os, const Fraction& f) {

	os << f.getNumerator() << "/" << f.getDenomenator();
	return os;
}
