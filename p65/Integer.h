#pragma once
#include <string>

using namespace std;

class Integer
{
	string value;

public:
	Integer(string); //constructor

	string getValue() { return value; }
	void setValue(string a) { value = a; }

	void Add(Integer);

	//friend Integer operator+(Integer const& obj);

	void Print();
};

