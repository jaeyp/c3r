/*
 * written by Jaehyun Park (Jul 13, 2019)
 *	The C++ programming language
 *	Chapter 11.2.4 Overloading new
 */

#include <iostream>
#include <cmath>

using namespace std;
class Complex 
{ 
private: 
	double re_, im_; 
public: 
	// Constructor 
	Complex(double re = 0, double im = 0): re_(re), im_(im) 
	{ 
		cout << "Constructor : (" << re_ 
			<< ", " << im_ << ")" << endl; 
	} 

	// Destructor 
	~Complex() 
	{ 
		cout << "Destructor : (" << re_ << ", "
			<< im_ << ")" << endl; 
	} 

	double normal() 
	{ 
		return sqrt(re_*re_ + im_*im_); 
	} 

	void print() 
	{ 
		cout << "|" << re_ <<" +j" << im_ 
			<< " | = " << normal() << endl; 
	} 
}; 

class Arena
{
public:
	unsigned char* buf;
	void set_buf(unsigned char* mem);
	void alloc(size_t sz);
	void dealloc();
};

void Arena::set_buf(unsigned char* mem)
{
	buf = mem;
}

void Arena::alloc(size_t sz)
{
	buf = (unsigned char*)malloc(sz);
}
void Arena::dealloc()
{
	if (buf != nullptr)
		free(buf);
}

void * operator new(size_t sz, Arena* a)
{
	cout << "overloading new" << endl;
	return a->buf;
}

int main()
{
	// buffer on stack 
	unsigned char buf[100]; 
	Arena* arena_stack = new Arena{};
	Arena* arena_malloc = new Arena{};
	arena_stack->set_buf(&buf[16]);
	arena_malloc->alloc(100);

	// placement new in stack memory allocated by overloading new
	Complex* pa = new(arena_stack) Complex(1.0, 1.0);
	cout << "pa address: " << pa << " buf: " << (int*)&buf[16] << endl;

	// placement new in dynamic memory allocated by overloading new
	Complex* pb = new(arena_malloc) Complex(9.0, 9.0);
	cout << "pb address: " << pb << endl;

	Complex* pc = new Complex(4.2, 5.3); 
	cout << "pc address: " << pc << endl;
	Complex* pd = new Complex[2] {{1.1, 1.2}, {2.1, 2.2}}; 
	cout << "pd address: " << pd << endl;

	// using placement new in memory preallocated
	Complex *pe = new (buf) Complex(2.6, 3.9); 
	cout << "pe address: " << pe << " buf: " << (int*)buf << endl;

	// use objects 
	pc -> print(); 
	pd[0].print(); 
	pd[1].print(); 
	pe->print(); 

	// Release objects 
	// calls destructor and then release memory 
	delete pc; 

	// Calls the destructor for object pd[0] 
	// and then release memory 
	// and it does same for pd[1] 
	delete [] pd; 

	// Release objects constructed using placement new
	// No delete 'cause only constucts an object in preallocated memory : Explicit call to Destructor.
	pe->~Complex(); 
	pa->~Complex();
	pb->~Complex();
	arena_malloc->dealloc();

	return 0; 
}
