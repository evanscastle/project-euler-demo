#pragma once

using namespace std;

class Fraction
{
	int numer, denom;

public:
	Fraction(int, int); //constructor

	int getNumer() { return numer; }
	int getDenom() { return denom; }

	void setNumer(int a) { numer = a; }
	void setDenom(int b) { denom = b; }

	void Print();
	void Add(Fraction frac);
	void Reciprocate();
};

