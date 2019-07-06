#include "pch.h"
#include <iostream>

struct Passport
{
	const char* firstName;
	const char* lastName;
	const char* country;
	const char* number;
	int yearOfBirth;
	int monthOfBirth;
	int dayOfBirth;
	char sex;
};

struct OrderBySize
{
	double num1;
	int num2;
	char char1;
	char char2;
};

struct OrderInRandom
{
	char char1;
	int num2;
	double num1;
	char char2;
};

struct Name2;					// struct name declaration: List to be defined later
struct Name1 
{
	Name1* firstName;		// available after it has been encountered
	//Name1 lastName;		// error: compiler is not able to determine the size
};
struct Name2 
{
	Name2* firstName;
	int num;
};



int main()
{
	Passport p1{};
	Passport p2{};

	//if (p1 == p2)				// error, not available
	OrderBySize o1{};
	OrderInRandom o2{};

	std::cout << sizeof(o1) << std::endl;			// output: 16
	std::cout << sizeof(o2) << std::endl;			// output: 24
}
