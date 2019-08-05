#include <iostream>
#include <string>      // std::string
#include <vector>      // std::vector<T>

class Statement1
{
public:
	void F1()
	{
		std::vector<int> v{ 1, 2, 3, 4, 5 };
		int s = 0;
		
		for(int x : v)     // range-for-statement
		{
			s += x;
		}

		std::cout << "F1(): " << s << std::endl;  // output: 15
	}

	void F2()
	{
		std::vector<int> v{ 1, 2, 3, 4, 5 };
		int s = 0;

		for(auto p = begin(v); p != end(v); ++p)
		{
			s += *p;
		}

		std::cout << "F2(): " << s << std::endl;  // output: 15
	}

	void F3()
	{
		std::vector<int> v{ 1, 2, 3, 4, 5 };
		
		for(int& x : v)     // modify elements in the range-for loop
		{
			++x;
		}

		int s = 0;

		for(int x : v)
		{
			s += x;
		}

		std::cout << "F3(): " << s << std::endl;  // output: 20
	}

	void F()
	{
		F1();
		F2();
		F3();

		std::cout << '\n';
	}
};

class Statement2
{
public:
	void F1()
	{
		int s = 0;
		int max = 5;

		for(auto i = 0; i != max; ++i)   // use auto 
		{
			s += i;
		}

		std::cout << "for loop: " << s << std::endl;     // output: 10

		int i = 0;        // introduce loop variable
		s = 0;
		
		while(i != max)   // test termination condition
		{
			s += i;
			++i;          // increment loop variable
		}

		std::cout << "while loop: " << s << std::endl;  // output: 10
	}

	void F2()
	{
		std::vector<std::string> v;
		std::cout << "\nenter any words and e to terminate!\n";

		for(std::string s; std::cin >> s;)  // no need for an explicit loop variable
		{
			v.push_back(s);

			if(s == "e")
			{
				break;    // loop exit
			}
		}

		std::cout << "\ntyped words" << std::endl;

		for(auto s : v)
		{
			std::cout << s << std::endl;
		}

		//for(;;)      // forever
		//{
		//}

		//while(true)  // forever
		//{
		//}
	}

	void F3()
	{
		int i = 10;
		std::cout << "\ndo while: ";
		
		do                             // body is always executed once before the condition is evaluated 
		{
			std::cout << --i << ' ';   // output: 9 8 7 6 5 4 3 2 1 0
		} while(i);

		std::cout << '\n';
	}

	void F4()
	{
		std::vector<int> n;

		for(auto i = 0; i < 5; ++i)
		{
			if(i == 2)
			{
				continue;    // skip the rest of the iteration-statement body
			}

			if(i == 4)
			{
				goto done;   // jump both into and out of blocks
			}

			n.push_back(i);
		}

done:
		std::cout << "continue: ";
	
		for(auto i : n)
		{
			std::cout << i << ' ';   // 0 1 3
		}

		std::cout << '\n';
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
}
