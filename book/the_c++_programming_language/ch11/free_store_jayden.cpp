#include <iostream>
#include <string>
#include <vector>
#include <complex>       // complext
#include <algorithm>     // for_each
#include <memory>        // unique_ptr
#include <stdexcept>     // strcpy, strcpy_s
#include <stdio.h>
#include <string.h>

class FreeStore1
{
public:
	//int* p = new int = 7;

	void F()
	{
		auto pc1 = new std::complex<double>;       // the complex is initialized to {0, 0}
		auto pi1 = new int;                        // the int is uninitialized
		std::cout << "address: " << pc1 << "\t\t" << "value: " << *pc1 << std::endl;
		std::cout << "address: " << pi1 << "\t\t" << "value: " << *pi1 << std::endl;
		std::cout << '\n';

		// to be sure
		auto pc2 = new std::complex<double>{};     // the complex is initialized to {0, 0}
		auto pi2 = new int{};                      // the int is initialized to 0
	
		std::cout << "address: " << pc2 << "\t\t" << "value: " << *pc2 << std::endl;
		std::cout << "address: " << pi2 << "\t\t" << "value: " << *pi2 << std::endl;
	}
};

class FreeStore2
{
public:
	void A()
	{
		int* p1 = new int{77};
		int* p2 = p1;                     // potential trouble
		delete p1;                        // now p2 doesn't point to a valid object
		p1 = nullptr;                     // gives a false sense of safety
		char* p3 = new char{ 'x' };       // p3 may now point to the memory pointed to by p2
		*p2 = 777;                        // this may cause trouble
		std::cout << *p3 << '\n';         // may not print x
	}

	void Sloppy()                 // very bad code
	{
		int *p = new int[1000];   // acquire memory
		
		// ..

		delete[] p;               // release memory

		// ..

		delete[] p;               // but sloppy() does not own *p
	}

	void F1(const std::string& s)  // the standard-library vector is an example of these techniques
	{
		std::vector<char> v;
		
		for (auto c : s)
		{
			v.push_back(c);
			std::cout << c;
		}
		std::cout << '\n';
	}

	std::string Reverse(const std::string& s)   // simply move the ss out of reverse() rather than copying any elements
	{
		std::string ss;
		
		for(int i = s.size() - 1; 0 <= i; --i)
		{
			ss.push_back(s[i]);
		}
			
		return ss;
	}

	void F2(int n)                                  // further example
	{
		int* p1 = new int[n];                       // potential trouble
		std::unique_ptr<int[]> p2{ new int[n] };

		if(n % 2)
		{
			throw std::runtime_error("odd");
		}

		delete[] p1;                                // may never get here
	}

	class AA
	{
	public:
		std::string s;
		AA(std::string ss) : s(ss) { std::cout << s << ": call constructor" << std::endl;  }

		~AA(){ std::cout << s << ": call destructor" << std::endl;	}
	};

	void F()
	{
		A();
		//Sloppy();     // bad code
		std::string s{"Hello"};
		F1(s);
		std::cout << "input: Hello\t\toutput: " << Reverse(s) << '\n' << std::endl;
		F2(100);
		AA* a = new AA{"new"};                          // doesn't free the memory
		std::unique_ptr<AA> aa{new AA{"unique_ptr"}};   // does free the memory calling destructor
	}
};

class FreeStore3
{
public:
	char* SaveString1(const char* p)
	{
		char* s = new char[strlen(p) + 1];
		
		//std::strcpy(s, p);             // error: until C99
		strcpy(s,p);                     // copy from p to s. since c99
		//strcpy_s(s, sizeof(s), p);     // prohibits truncation due to potential security risks. since C11
		
		return s;
	}

	std::string SaveString2(const char* p)
	{
		return std::string{ p };
	}

	void F1()
	{
		const char* c{"hungry"};
		const char* p = SaveString1(c);

		std::cout << "\nchar* copy: " << (const void*)c << " -> " << static_cast<const void*>(p) << std::endl;  // Don't try to cast away the constness like (void*), static_cast<void*>
		std::cout << "char* copy: " << c << " -> " << p << std::endl;   // std::cout treats a char* as a pointer to a C-style string
		delete[] p;
		std::cout << "p value after delete: " << p << std::endl;
		std::cout << '\n';

		std::string s = SaveString2(c);
		std::cout << "char* copy: " << c << " -> " << s << std::endl;
		
		
		//std::vector<int>* p = new std::vector<int>(n);   // individual object
		//int* q = new int[n];    // array
		// ..
		//delete p;
		//delete[] q;
	}

	void F2()
	{
		int n = 10;
		std::vector<int>* p = new std::vector<int>(n);  // individual object
		int* q = new int[n];      // array

		delete p;
		delete[] q;   // delete[] operator may be applied only to a pointer to an array returned by new of an array
		delete[] q;   // applying delete[] to the null pointer has no effect
	}
	class X {};
	
	void F3()     // bad: do not use new to create local objects
	{
		X* p = new X;

		delete p;
	}

	void F4()     // instead of F3(): the local variable x is implicitly destroyed upon exit from F4
	{
		X x;
		//...
	}

	void F()
	{
		F1();
		F2();
		F3();
		F4();
	}
};

int main()
{
	FreeStore1 f1{};
	f1.F();

	FreeStore2 f2{};
	f2.F();

	FreeStore3 f3{};
	f3.F();
}

