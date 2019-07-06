/*
 * written by Jaehyun Park (Jul 6, 2019)
 */
#include <iostream>
#include <sstream>
#include <cassert>

/* struct
	A struct is simply a class where the members are public by default.
	It can have member functions and constructors.
 */

/* declaration and definition */
// The name of a struct becomes available for use immediately after it has been encountered.
struct Link {
	Link* prev;
	Link* next;
};

#if 0 // However, it is not possible to declare new objects of a struct until its complete declaration has been seen.
struct No_good {
	No_good member;
};
#endif

struct List; // Without this declaration of List, use of the pointer type List* in the declaration of Link would have been a syntax error.

struct Link2 {
	Link* prev;
	Link* next;
	List* node;
	int data;
};

struct List {
	Link2* head;
};

// The name of a struct can be used before the type is defined as long as it doesn't require the name of a member or the size of the structure to be known.
struct S;

S f();     // okay
void g(S); // okay
S* h(S*);  // okay

// It is possible to declare a struct and a non-struct with the same name in the same scope.
// However, it is best not to overload names.
struct stat {};
int stat(char* name, stat* buf);         // possible, but ambiguous.	
int stat2(char* name, struct stat* buf); // better, but still not good.

/* sturct and class */
// struct with default constructor
struct Point {
	int x, y;
};

// struct with explicit constructor
struct Address {
	std::string name;
	int number;
	std::string street;
	std::string city;
	char province[2];
	char postal[10];

	Address(const std::string& n, int nu, const std::string& s, const std::string& c, const std::string& pr, int po);
	void print();
};

Address::Address(const std::string& n, int nu, const std::string& s, const std::string& c, const std::string& pr, int po)
	:name{n}, number{nu}, street{s}, city{c} // initialization_list
{
	// we initialize only two members here (province, postal), others use initialization_list
	if (pr.size() != 2)
		assert("Province code should be two characters");
	province[0] = pr[0];
	province[1] = pr[1];

	std::ostringstream ost;
	ost << po;
	std::string poi {ost.str()};
	switch (poi.size()) {
		case 6:
			postal[0] = poi[0];
			postal[1] = poi[1];
			postal[2] = poi[2];
			postal[3] = poi[3];
			postal[4] = poi[4];
			postal[5] = poi[5];
			postal[6] = '\0';
			break;
		default:
			assert("unexpected Postal code format");
	}
}

void Address::print()
{
	std::cout 
		<< "name:     " << name << "\n"
		<< "number:   " << number << "\n"
		<< "street:   " << street << "\n"
		<< "city:     " << city << "\n"
		<< "province: " << province[0] << province[1] << "\n"
		<< "postal:   " << postal << std::endl;
}

/* Plain Old Data (POD) */
struct S1 {int a;}; // a POD
struct S2 : S1 {int b;}; // NOT a POD

int main()
{
	Address a {
		"Jaehyun Park",
		52,
		"College st",
		"Kitchener",
		"ON",
		123456
	};

	a.print();

	S2 s2 {};
	std::cout << s2.a << " " << s2.b << std::endl;
}
