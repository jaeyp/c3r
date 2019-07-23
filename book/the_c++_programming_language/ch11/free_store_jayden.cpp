#include <iostream>
#include <string>
#include <vector>
#include <complex>       // complext
#include <algorithm>     // for_each
#include <memory>        // unique_ptr
#include <stdexcept>     // strcpy, strcpy_s

class FreeStore1
{
public:
	//int* p = new int = 7;

	void f()
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
	void a()
	{
		int* p1 = new int{77};
		int* p2 = p1;                     // potential trouble
		delete p1;                        // now p2 doesn't point to a valid object
		p1 = nullptr;                     // gives a false sense of safety
		char* p3 = new char{ 'x' };       // p3 may now point to the memory pointed to by p2
		*p2 = 777;                        // this may cause trouble
		std::cout << *p3 << '\n';         // may not print x
	}

	void sloppy()                 // very bad code
	{
		int *p = new int[1000];   // acquire memory
		
		// ..

		delete[] p;               // release memory

		// ..

		delete[] p;               // but sloppy() does not own *p
	}

	void f1(const std::string& s)  // the standard-library vector is an example of these techniques
	{
		std::vector<char> v;
		
		for (auto c : s)
		{
			v.push_back(c);
			std::cout << c;
		}
		std::cout << '\n';
	}

	std::string reverse(const std::string& s)   // simply move the ss out of reverse() rather than copying any elements
	{
		std::string ss;
		
		for(int i = s.size() - 1; 0 <= i; --i)
		{
			ss.push_back(s[i]);
		}
			
		return ss;
	}

	void f2(int n)                                  // further example
	{
		int* p1 = new int[n];                       // potential trouble
		std::unique_ptr<int[]> p2{ new int[n] };

		if(n % 2)
		{
			throw std::runtime_error("odd");
		}

		delete[] p1;                                // may never get here
	}

	class A
	{
	public:
		std::string s;
		A(std::string ss) : s(ss) { std::cout << s << ": call constructor" << std::endl;  }

		~A(){ std::cout << s << ": call destructor" << std::endl;	}
	};

	void f()
	{
		a();
		//sloppy();     // bad code
		std::string s{"Hello"};
		f1(s);
		std::cout << "input: Hello\t\toutput: " << reverse(s) << '\n' << std::endl;
		f2(100);
		A* a = new A{"new"};
		std::unique_ptr<A> aa{new A{"unique_ptr"}};
	}
};

int main()
{
	FreeStore1 f1{};
	f1.f();

	FreeStore2 f2{};
	f2.f();
}

