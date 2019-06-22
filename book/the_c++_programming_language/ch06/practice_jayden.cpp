#include <iostream>		// std::cout, std::endl
#include <string>		// std::string
#include <complex>		// std::complex
#include <vector>		// std::vector
#include <climits>		// CHAR_BIT

//using namespace std;

void DeclareBasicTypes()
{
	int i1 = 1;
	int i2{ 1 };
	int i3 = { 1 };

	//char c1 = 1234;			// warning: 1234 is an int and too big
	//char c2{ 1234 };			// error: narrowing

	int ii1 = 'a';				// 'a' is a char
	int ii2{ 'a' };				// fine: implicit char -> int conversion
									
	// array
	int array1[5];				// declaration
	int array2[]{ 1, 2 };
	int array3[] = { 1, 2 };

	// pointer
	int* p1{ new int(10) };			// *p1 becomes 10
	int* p2{ new int{10} };			// *p2 becomes 10
	char* p3{ new char[10]{} };		// p3[i] becomes 0 for all i
	char* p4{ new char[10]() };		// p4[i] becomes 0 for all i

	// string
	std::string str1 = "Food";
	std::string str2{ "Me" };
	
	// struct
	struct S { float f; std::string s; };
	S s1 = { 3.f, "Hey" };
	S s2{ 5.F, "Hi" };
	
	// class
	class C { double d; };
	C ccc;
	
	// the complex number:			(5 + 3i)
	std::complex<double> complex1 = { 5.0, 3.0 };		// use constructor	
	std::complex<double> complex2{ 5.0, 3.0 };		// use constructor
	std::complex<double> complex3(3, 2);			// use constructor
	std::complex<double> complex4();			// use constructor to the default value {0,0}

	// vector
	std::vector<std::string> v1 = { "Hamburger", "Ramen" };	// use list constructor
	std::vector<double> v2(10, 3.3);			// use constructor: v gets 10 elements initialized to 3.3
}

void DeclareFor()
{
	std::vector<int> numbers{ 1, 2, 3, 4 };
	std::vector<int>::iterator pt;				// iterator
		
	for (int i = 0; i < numbers.size(); i++)
	{
		std::cout << numbers[i] << ", ";		// output: 1, 2, 3, 4,
	}
	std::cout << '\n';
		
	for (pt = numbers.begin(); pt < numbers.end(); pt++)
	{
		std::cout << *pt << ", ";			// output: 1, 2, 3, 4,
	}
	std::cout << '\n';
		
	for (auto p = numbers.begin(); p != numbers.end(); ++p)
	{
		std::cout << *p << ", ";			// output: 1, 2, 3, 4,
	}		
	std::cout << '\n';
		
	for (const auto& x : numbers)				// auto is determined by element type of numbers, int.
	{
		std::cout << x << ", ";				// output: 1, 2, 3, 4,
	}
	std::cout << "\n\n";
}

void DeclareWithAuto(int& i)
{
	auto a1 = i;			// c is an int (not an int&)
	auto& a2 = i;			// d is an int&
		
	//auto aa1{};			// error: cannot deduce a type
	auto aa2{ 1 };			// list of int with one element
	auto aa3 = { 1, 2, 3 };		// std::initializer_list<int>
	auto aa4 = { 1.0, 2.5 };	// std::initializer_list<double>
	//auto aa5 = { 1.0, 2 };	// error: cannot deduce the type
}

void DeclareTypeAliases()
{
	// type aliases - when a original name is too long, complicated or ugly
	//		 when different types required with same name
	//		 when a specific type is mentioned in one place only to simplify maintenance
	using Pchar = char*;		// pointer to character
	using PF = int(*)(double);	// pointer to function taking a double and returning an int
}

void CheckTypeSize()
{
	// bits per byte varies depending on computer architecture
	std::cout << "Byte:		" << CHAR_BIT << " bits" << std::endl
		<< "char:		" << sizeof(char) << " bytes" << std::endl
		<< "int:		" << sizeof(int) << " bytes" << std::endl
		<< "short int:	" << sizeof(short int) << " bytes" << std::endl
		<< "long int:	" << sizeof(long int) << " bytes" << std::endl
		<< "float:		" << sizeof(float) << " bytes" << std::endl
		<< "double:		" << sizeof(double) << " bytes" << std::endl
		<< "wchar_t:	" << sizeof(wchar_t) << " bytes" << std::endl;

	// The result of sizeof is always nonzero, even if applied to an empty class type.
	struct Empty {};
	struct Base { int a; };
	struct Derived : Base { int b; };
	struct Bit { unsigned bit : 1; };

	Empty e;
	Derived d;
	Base& b = d;
	Bit bit;
	int a[10];

	std::cout << "empty class:				" << sizeof e << " bytes" << std::endl
		<< "pointer:				" << sizeof &e << " bytes" << std::endl
		//<< "size of function:                " << sizeof(void()) << " bytes" << "\n" // error
		<< "array of 10 int:			" << sizeof(int[10]) << " bytes" << std::endl
		<< "array of 10 int (2):			" << sizeof a << " bytes" << std::endl
		<< "length of array of 10 int:		" << ((sizeof a) / (sizeof *a)) << std::endl
		<< "length of array of 10 int (2):		" << ((sizeof a) / (sizeof a[0])) << std::endl
		<< "size of the Derived:			" << sizeof d << " bytes" << std::endl
		<< "size of the Derived through Base:	" << sizeof b << " bytes" << std::endl;
}


int main()
{
	DeclareBasicTypes();
	DeclareFor();
	DeclareTypeAliases();
	CheckTypeSize();
}
