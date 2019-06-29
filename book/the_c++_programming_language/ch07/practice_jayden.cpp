#include "pch.h"
#include <iostream>
#include <string>				// std::string
#include <vector>			// std::vector

int main()
{
	// nullptr
	int* pi1 = nullptr;
	char* pd = nullptr;
	//int i = nullptr;			// i is not a pointer
	int* pi2 = 0;				// pi2 gets the value nullptr
	int* pi3 = NULL;		// uses the macro NULL

	// Whether two identical string literals are allocated as one array 
	// or as two is implementation-defined
	const char* a = "c3r";
	const char* b = "c3r";
	if (a == b)
	{
		std::cout << "Same address!\n";		// implementation-defined
	}

	aa();
}

void f(int* i)
{
	void* pv = i;		// ok: implicit conversion of int* to void*
	//*pv;				// error: can't dereference void*
	//++pv;				// error: can't increment void* (the size of the object pointed to is unknown)

	int* pi2 = static_cast<int*>(pv);					// explicit conversion back to int*

	//double* pd1 = pv;										// error
	//double* pd2 = pi;										// error
	double * pd3 = static_cast<double*>(pv);	// unsafe
}

void f1(int n)
{
	int aa[10];
	aa[6] = 9;			// assign to aa's 7th element
	int x = aa[99];	// undefined behavior

	//int v1[n];							// error: array size not a constant expression
	std::vector<int> v2(n);		// OK: vector with n int elements

	int a2[20];							// 20 ints on the stack
	int* p = new int[40];			// 40 ints on the free store

	//char* p3 = "Plato";			// error, but accepted in pre-C++11-standard code
	//p3[4] = 'e';						// error: assignment to const
	char p3[] = "Apple";			// p3 is an array of 5 char
	p3[0] = 'A';						// OK

}

void UsePointer1(const int* a)
{
	//*a = 3;		// error
}

void UsePointer2(int* const a)
{
	*a = 3;
}

void UseReference1(const int& a)
{
	//a = 3;		// error
}

void UseReference2(int& const a)
{
	a = 3;
}

const char* aa()
{
	// the memory holding the string literal below will not go away after the call of aa()
	return "string literal is statically allocated so it is safe to return on from a function";
}
