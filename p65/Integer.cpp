#include "Integer.h"
#include <iostream>

using namespace std;

//definition of constructor
Integer::Integer(string a) {
	value = a;
}

void Integer::Add(Integer intg) {
	string new_value = "";


	int carry = 0;
	int curr; int digit;
	for (int i = value.size() - 1; i >= 0; i--) {
		curr = value[i] + intg.value[i] + carry - 2*'0';
		
		digit = curr % 10;

		if (curr >= 10)
			carry = 1;
		else
			carry = 0;

		new_value.push_back((int)digit);
	}

	value = "";

	for (int i = new_value.size(); i >= 0; i--) {
		value.push_back(new_value[i]);
	}
}

void Integer::Print() {
	cout << value;
}

//Integer operator + (Integer const& obj) {
//    Integer result("0");
//    
//    result.value = real + obj.real;
//    result.imag = imag + obj.imag;
//    return result;
//}