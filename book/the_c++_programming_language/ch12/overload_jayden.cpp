#include <iostream>    // std::cout, std::endl
#include <string>      // std::string
#include <cstdarg>     // needed to use ellipsis
#include <complex>     // std::complex

class Function1
{
public:
	void print(float){ std::cout << "float" << std::endl; }
	void print(double){ std::cout << "double" << std::endl; }

	void f()
	{
		print(1.f);  // print(float)
		print(1.0);  // print(double)
		//print(1);  // error, ambiguous
		std::cout << '\n';
	}
};

class Function2
{
public:
	void print(bool){ std::cout << "bool" << std::endl; }
	void print(int){ std::cout << "int" << std::endl; }
	void print(const char*){ std::cout << "char*" << std::endl; }
	void print(double){ std::cout << "double" << std::endl; }
	void print(long){ std::cout << "long" << std::endl; }
	void print(char){ std::cout << "char" << std::endl; }

	void h(char c, int i, short s, float f)
	{
		std::cout << "input type char -> "; print(c);        // exact match: invoke print(char)
		std::cout << "input type int -> "; print(i);         // exact match: invoke print(int)
		std::cout << "input type short -> "; print(s);       // integral promotion: invoke print(int)
		std::cout << "input type float -> "; print(f);       // float to double promotion: print(double)

		std::cout << '\n';

		std::cout << "input 'a' -> "; print('a');            // exact match: invoke print(char)
		std::cout << "input 30 -> "; print(30);              // exact match: invoke print(int)
		std::cout << "input 0 -> "; print(0);                // exact match: invoke print(int)
		std::cout << "input apple -> "; print("apple");      // exact match: invoke print(const char*)
		std::cout << "input nullptr -> "; print(nullptr);    // nullprt_t to const char* promotion: invoke print(const char*)
		std::cout << '\n';
	}
};

class Function3
{
public:
	float sqrt(float fl)
	{
		std::cout << "return float \n";
		return fl;
	}
	
	double sqrt(double d)
	{
		std::cout << "return double \n";
		return d;
	}

	void f(double da, float fla)
	{
		float fl = sqrt(da);    // call sqrt(double)
		double d = sqrt(da);    // call sqrt(double)
		fl = sqrt(fla);         // call sqrt(float)
		d = sqrt(fla);          // call sqrt(float)

		std::cout << '\n';
	}
};

class Function4
{
	struct Base
	{
		void f(int)
		{
			std::cout << "call f(int) \n";
		}
	};

	struct Derived : Base
	{
		void f(double)
		{
			std::cout << "call f(double) \n";
		}
	};

public:
	Derived derived;

	void g(Derived& d)
	{
		d.f(1);     // call Derived::f(double);
	}

	void f()
	{
		g(derived);
		std::cout << '\n';
	}
};

class Function5
{
public:
	int pow(int, int)
	{
		std::cout << "int, int" << std::endl;
	}
	
	double pow(double, double)
	{
		std::cout << "double double \n";
		return 0;
	}

	std::complex<double> pow(double, std::complex<double>)
	{
		std::cout << "double, complex \n";
		return 0;
	}

	std::complex<double> pow(std::complex<double>, int)
	{
		std::cout << "complex, int \n";
		return 0;
	}

	std::complex<double> pow(std::complex<double>, std::complex<double>)
	{
		std::cout << "complex, complex \n";
		return 0;
	}

	// Overload resolution rules can be used to select the most appropriate function 
	// when the efficiency or precision of computations differs significantly among types
	void k(std::complex<double> z)
	{
		//double d = pow(2.0, 2);   // error: pow(int(2.0, 2) or pow(2.0, double(2))? 
		
		std::cout << "input 2, 2 -> "; int i = pow(2, 2);                                 // invoke pow(int, int)
		std::cout << "input 2.0, 2.0 -> "; double d = pow(2.0, 2.0);                      // invoke pow(double, double)
		std::cout << "input 2, complex -> "; std::complex<double> z2 = pow(2, z);         // invoke pow(double, complex)
		std::cout << "input complex, 2 -> "; std::complex<double> z3 = pow(z, 2);         // invoke pow(complex, int)
		std::cout << "input complex, complex -> "; std::complex<double> z4 = pow(z, z);   // invoke pow(complex, complex)
	}

	void f()
	{
		k({2, 3});
		std::cout << '\n';
	}
};

class Function6
{
public:
	void f1(char) 
	{
		std::cout << "char";
	}
	void f1(long)
	{
		std::cout << "long";
	}

	void f2(char*)
	{
		std::cout << "char*";
	}
	void f2(int*)
	{
		std::cout << "int*";
	}

	void k(int i)
	{
		//f1(i);    // ambiguous: f1(char) or f1(long)?
		//f2(0);    // ambiguous: f2(char*) or f2(int*)?
	}

	inline void k1(int n)     // solve ambiguity by adding a version
	{
		f1(long(n));
	}

	void f()
	{
		k(1);
		k1(1);
		std::cout << '\n';
	}
};

class function7
{
public:
	int area(int len, int wid)   // may seem excessive, but useful to implementer, users of area() and testers.
	/*
	   calculate the area of a rectangle
	   precondition: len and wid are positive
	   postcondition: the return value is positive
	   postcondition: the return value is the area of a rectangle with sides len and wid
	 */
	// if a function writes to nonlocal objects its effect must be considered and documented
	{
		return len * wid;
	}
};

int main()
{
	Function1 f1;
	f1.f();

	Function2 f2;
	f2.h('f', 7, 3, 10.5);

	Function3 f3;
	f3.f(2.0, 3.f);

	Function4 f4;
	f4.f();

	Function5 f5;
	f5.f();

	Function6 f6;
	f6.f();
}
