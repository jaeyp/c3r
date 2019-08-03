#include <iostream>
#include <string>
#include <vector>
#include <math.h>

class Statement1
{
public:
	void F1()
	{
		std::string s1;
		s1 = "Postponding the definition of a variable until a suitable initializer is available";
	
		// can be faster than the above
		std::string s2 {"simple initialization to the desired value"};
	}

	void F2()
	{
		std::vector<int>v;   // better than array
		int max = 5;
		int buf[max];
		int count = 0;

		std::cout << "array and vector\n";
		for (int i; std::cin >> i;)
		{
			if(i < 0)
			{
				std::cout << "unexpected negative value" << std::endl;
			}
			
			v.push_back(i);

			if(count == max)
			{
				std::cout << "array: buffer overflow" << std::endl;
				break;
			}
			else
			{
				buf[count++] = i;
			}
		}
	}

	void F()
	{
		F1();
		F2();
		std::cout << '\n';
	}
};

class Statement2
{
public:
	void F1()
	{
		int x;

		std::cout << "x = " << x << " and result of if(x): ";

		if(x)     // same as if(x != 0)
		{
			std::cout << "true\n";
		}
		else
		{
			std::cout << "false\n";     // executed
		}

		int* p = nullptr;
		
		std::cout << "p = " << p << " and result of if(p): ";

		if(p)     // same as if(p != nullptr)
		{
			std::cout << "true\n";
		}
		else
		{
			std::cout << "false\n";    // executed
		}

		std::cout << '\n';
	}

	enum E1 { a, b };        // can be implicitly converted to an integer and then to a bool
	enum class E2 { a, b};   // cannot

	void F2()
	{
		E1 e1 = E1::a;
		E2 e2 = E2::a;

		E2 x = e2;

		if(e1)     // OK
		{
			std::cout << "E1::a == 1 \n";
		}
		else
		{
			std::cout << "E1::a != 1\n";     // executed
		}

		//if(e2)     // error: no conversion to bool
		
		if(x == E2::a)  // Ok
		{
			std::cout << "x == E2::a\n";     // executed
		}
		else
		{
			std::cout << "x != E2::a\n";
		}

		std::cout << '\n';
	}

	void F3()
	{
		std::vector<int>* p;

		if(p && 1 < p->size())     // tests 1 < p->count only if p is not nullptr
		{
		}
	}

	int F4(int a, int b)
	{
		return (a > b)? a : b;    // return the larger of a and b
	}

	void F5(int i)
	{
		std::cout << "\nparameter i: " << i << std::endl;
		std::cout << "if(i): ";
		
		if(i)       // executed
		{
			std::cout << "true\n";
			int x = i + 2;
			++i;
		}
		else
		{
			std::cout << "false\n";
			//++x;    // error: x is not in scope
		}
		//++x;        // error: x is not in scope
		std::cout << '\n';
	}

	void F()
	{
		F1();
		F2();
		F3();
		std::cout << F4(5, 7) << std::endl;
		F5(5);
	}
};

class Statement3
{
public:
	void F1()
	{
		int i{5};

		switch(i)             // preferred: easier to read for nontrivial examples, not to repeatedly check individual values unlike if-else
		{
			//case 2.7:       // error: floating point uses for case
			case 3:
				std::cout << "case 3\n";
				break;
			case 4:
				std::cout << "case 4\n";
				break;
			case 6-1:         // OK
				std::cout << "case 6-1\n";
				// no break: fall through to print - better to comment
			default:
				std::cout << "default\n";
				break;
		}

		if(i == 3)   // same as switch-case above
		{
			std::cout << "case 3\n";
		}
		else if(i == 4)
		{
			std::cout << "case 4\n";
		}
		else if(i == 6-1)
		{
			std::cout << "case 6-1\n";
			std::cout << "default\n";
		}
		else
		{
			std::cout << "default\n";
		}
	}

	enum class Vessel{ cup, glass, goblet, chalice };

	void F2()
	{
		Vessel v = Vessel::cup;

		switch(v)      // no warning
		{
			case Vessel::cup:
				break;
			case Vessel::glass:
				break;
		}
	}

	void F3()
	{
		int i{0};

		switch(i)
		{
			case 0:
				int x;            // uninitialized
				//int y = 3;      // error: declaration can be bypassed (explicitly initialized)
				//string s;       // error: declaration can be bypassed (implicitly initialized)
			case 1:
				//++x;            // error: use of uninitialized object
				//++y;
				//s = "nasty!";
				break;
		}
	}

	void F4()
	{
		std::cout << "\ndelayed definition d: ";
		
		// usually best to delay the definition of a local variable until one can give it an initial value
		// a declaration in a condition must declare and initialize a single variable or const
		if(double d = round(0.3))    // d becomes 0 and is in scope on both branches - the most compact source code
		{
			std::cout << d << " from if statement\n" << std::endl;
		}
		else
		{
			std::cout << d << " from else statement\n" << std::endl;    // executed
		}
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
	Statement1 s1{};
	s1.F();

	Statement2 s2{};
	s2.F();

	Statement3 s3{};
	s3.F();
}
