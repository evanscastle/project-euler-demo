/*//Evan Castle
//2020.03.25

#include <iostream>
#include <vector>

using namespace std;

//***************************************************************************************************
//GLOBAL METHODS SUPPORTING MAIN
//***************************************************************************************************

//compute the gcd of two integers using the euclidean algorithm
int gcd(int n, int m, bool display)
{
	//declare a to be the largest of the two integers in commencing the algorithm
	//there exists a unique q > 0, r > 0 such that a = q*b + r
	//while r > 0, repeat this process reassigning a = b, b = r
	//the gcd of a and b is the last non-zero remainder before the algorithm terminates
	int a, b, q, r;

	if (n > m) {
		a = n;
		b = m;
	}
	else {
		a = m;
		b = n;
	}

	q = a / b;
	r = a % b;

	if (display) {
		cout << a << " = " << q << "*" << b << " + " << r << endl;
	}

	while (r > 0) {

		a = b;
		b = r;

		q = a / b;
		r = a % b;

		if (display) {
			cout << a << " = " << q << "*" << b << " + " << r << endl;
		}

	}

	return b;
}

//returns the least common multiple of two positive integers m and n
int lcm(int n, int m) {
	//the least common multiple of two integers is given by lcm(m,n) = m*n/gcd(m,n)
	return m * n / gcd(m, n, false);

}

//***************************************************************************************************
//FRACTION CLASS DECLARATION
//***************************************************************************************************

//define a fraction class with supporting functions such as add, multiply, etc.
class Fraction {
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

//definition of constructor
Fraction::Fraction(int a, int b) {
	//initialize fraction in lowest terms
	int _gcd = gcd(a, b, false);

	numer = a / _gcd;
	denom = b / _gcd;
}

//print to terminal the value of the fraction
void Fraction::Print() {

	//verify that the fraction is not actually a whole number
	if (denom == 1) {
		cout << numer <<  endl; 
	}
	else {
		cout << numer << "/" << denom << endl;
	}

}

//adds two fractions and stores the result in the original object as fraction in simplest form
void Fraction::Add(Fraction frac) {
	int common_denom, numerator, _gcd;

	//find common denominator
	common_denom = lcm(this->denom, frac.getDenom());
	numerator = (common_denom/this->denom * this->numer) + (common_denom/frac.getDenom() * frac.getNumer());

	//store fraction in lowest terms
	_gcd = gcd(numerator, common_denom, false);

	this->numer = numerator / _gcd;
	this->denom = common_denom / _gcd;
}

void Fraction::Reciprocate() {
	int temp = this->numer;
	this->numer = this->denom;
	this->denom = temp;
}

//***************************************************************************************************
//SEQUENCE MANIPULATION METHODS
//***************************************************************************************************

//generate the continued fraction expansion of e of specified length
vector<int> generate_e_sequence(int length) {
	vector<int> continued_fraction_expansion = {};

	continued_fraction_expansion.push_back(2); continued_fraction_expansion.push_back(1);

	int k = 1;
	for (int i = 2; i < length; i++) {
		if (i % 3 == 2) {
			continued_fraction_expansion.push_back(2 * k);
			k++;
		}
		else {
			continued_fraction_expansion.push_back(1);
		}
	}

	return continued_fraction_expansion;

}


//***************************************************************************************************
//BEGINNING OF MAIN
//***************************************************************************************************

int main()
{

	int length = 15;
	vector<int> e_sequence = generate_e_sequence(length);

	Fraction frac(1, e_sequence[length - 1]);
	Fraction addend(1, 1);

	for (int i = length - 2; i >= 0; i--) {	
		addend.setNumer(e_sequence[i]);
		
		frac.Add(addend);

		if (i > 0) {
			frac.Reciprocate();
		}
		
	}

	frac.Print();
	system("pause");

	return 0;
}*/
