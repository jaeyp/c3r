#include <iostream>
#include <string>
#include <vector>
#include <algorithm>   // std::sort

void a1(std::string s) { std::cout << s << std::endl; }
int a1(int i){ return i; }
void a2(int i) { std::cout << i << std::endl; }
void a3(int i) noexcept { std::cout << i << std::endl; }

void (*e1)(std::string);          // pointer to function taking a string argument and returning nothing
void (*e2)(std::string) = &a1;    // OK: same as = a1
void (*e3)(std::string) = a1;     // OK: same as = &a1
//void (*e4)(std::string) = a2;   // error: the complete function type must match exactly
int (*e5)(int) = a1;
//void (*e6)(int i) = a1;         // error: no void void a1(int)
void (*e7)(int) = a3;             // OK: but we throw away useful information
void (*e8)(int) noexcept = a3;    // OK: we preserve the noexcept information
//void (*e9)(int) noexcept = a2;  // error: we don't know that a2 doesn't throw

void f1()
{
	e1 = &a1;              // e1 points to a1
	e1("apple");           // call apple through e1
	e2("strawberry");      // OK: same as (*e2)("strawberry")
	(*e3)("kiwi");         // OK: as e3("kiwi")
	std::cout << e5(5) << std::endl;
	e7(100);
	e8(30);
	std::cout << '\n';
}

//--------------------------------------------------------//
using P1 = int(*)(int*);
using P2 = void(*)(void);
//using Pc = extern "C" void(int);     // error: linkage specification in alias
//using Pn = void(int) noexcept;       // error: noexcept in alias

void ff(P1 pf)
{
	P2 pf2 = reinterpret_cast<P2>(pf);
	//pf2();                             // serious problem
	P1 pf1 = reinterpret_cast<P1>(pf2);  // convert pf2 "back again"
	int x = 7;
	int y = pf1(&x);                     // OK
}

int (*pf)(int*);
int b1(int* i){}

void f2()
{
	pf = b1;
	ff(pf);
}

// -------------------------------------------------------//
struct User
{
	std::string name;
	std::string id;
	int dept;
};

std::vector<User> heads = {
	{"RitchieD.M.",      "dmr",     11271},
	{"SethiR.",          "ravi",    11273},
	{"SzymanskiT.G.",    "tgs",     11274},
	{"Schryerw.L.",      "nls",     11272},
	{"SchryerN.L.",      "nls",     11276},
	{"KernighanB.W.",    "bwk",     11275}
};

void print_id(std::vector<User>& v)
{
	for(auto& x : v)
	{
		std::cout << x.name << '\t' << x.id << '\t' << x.dept << '\n';
	}
}

void f3()
{
	std::cout << "Heads in alphabetical order:\n";
	std::sort(heads.begin(), heads.end(), [](const User& x, const User& y){ return x.name < y.name; });
	print_id(heads);
	std::cout << '\n';

	std::cout << "Heads in order of department number:\n";
	std::sort(heads.begin(), heads.end(), [](const User& x, const User& y){ return x.dept < y.dept; });
	print_id(heads);
	std::cout << '\n';
}

int main()
{
	f1();
	f2();
	f3();
}
