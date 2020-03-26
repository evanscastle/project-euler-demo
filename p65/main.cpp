//Evan Castle
//2020.03.25

#include <iostream>
#include <vector>
#include <string>
#include "Fraction.h"
#include "Integer.h"

using namespace std;


//generate the continued fraction expansion of 'e' of specified length
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

int main()
{
	/*int length = 15;
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

	frac.Print();*/


	Integer int1("102"); Integer int2("502");

	int1.Add(int2);
	int1.Print();

	system("pause");

	return 0;
}