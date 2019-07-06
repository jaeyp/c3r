/*
 * written by Jaehyun Park (Jul 6, 2019)
 */

#include <iostream>
#include <string>
#include <complex>

using namespace std;

/* union
	A union is a struct in which all members are allocated at the same address so that the union occupies only as much space as its largest member.
	- CANNOT have virtual functions
	- CANNOT have reference.
	- CANNOT have base classes.
	- CANNOT have user-defined constructor, copy/move operation, destructor.
	- CANNOT be used as a base class.
	- At most one member of a union can have an in-class initializer.
 */

/* union U */
union U {
	int a;
	// It is possible to specify an in-class initializer for at most one member. (only one member!)
	const char* p {""};
	// constructor, copy/move operation, or destructor CANNOT be used for an object of the union type.
#if 0 
	std::complex<double> m2; // error, complex has a constructor and it's deleted for this union
	std::string m3; // error, string has a constructor and it's deleted for this union
#endif
};

/* struct Entry */
enum Type {str, num};

union Value {
	char* s;
	int i;
};

struct Entry {
	std::string name {"entry"};
	Type t {num};
	Value v {.i=111};
};

void f(Entry* p)
{
	if (p->t == str)
		std::cout << p->v.s << std::endl;
	else
		std::cout << p->v.i << std::endl;
}

/* class Entry2 */
// example for preventing misuse of a union.
class Entry2 {
private:
	enum class Tag {number, text};
	Tag type;
	union {
		int i;
		std::string s;
	};
public:
	struct Bad_entry {};
	std::string name;

	Entry2();
	~Entry2();
	Entry2(const Entry2&); // copy contructor ($17.5)
	Entry2& operator=(const Entry2&); // copy assignment ($17.5)

	int number() const;
	std::string text() const;
	void print() const;

	void set_number(int n);
	void set_text(const std::string&);
};

Entry2::Entry2()
{
	std::cout << "constuctor" << std::endl;
	type = Tag::number;
	i = 222;
}

Entry2::~Entry2()
{
	std::cout << "destructor" << std::endl;
	if(type==Tag::text) s.~string(); // explicitly destory string ($11.2.4)
}

Entry2::Entry2(const Entry2& e)
{
	std::cout << "constuctor2" << std::endl;
	if(e.type==Tag::text)
		new(&s) std::string{e.s}; // explicit constuct ($11.2.4)
	else
		i = e.i;
}

Entry2& Entry2::operator=(const Entry2& e) // necessary because of the string variant
{
	if(type==Tag::text && e.type==Tag::text) {
		s = e.s;
		return *this;
	}

	if(type==Tag::text)s.~string(); // explicit destroy ($11.2.4)

	switch(e.type) {
		case Tag::number:
			i = e.i;
			break;
		case Tag::text:
			new(&s) std::string{e.s}; // explicit construct ($11.2.4)
			type = e.type;
			break;
		default:
			break;
	}

	return *this;
}

int Entry2::number() const
{
	if(type!=Tag::number) throw Bad_entry();
	return i;
};

std::string Entry2::text() const
{
	if(type!=Tag::text) throw Bad_entry();
	return s;
}

void Entry2::print() const
{
	if(type == Tag::number)
		std::cout << i << std::endl;
	else
		std::cout << s << std::endl;
}

void Entry2::set_number(int n)
{
	if (type==Tag::text) {
		s.~string(); // explicitly destory string ($11.2.4)
		type=Tag::number;
	}
	i = n;
}

void Entry2::set_text(const std::string& ss)
{
	if(type==Tag::text)
		s = ss;
	else {
		new(&s) std::string{ss}; // explicitly construct string ($11.2.4)
		type = Tag::text;
	}
}

/* struct Video (bit fields) */
struct H264Header {
	unsigned int sps_pos	: 8;
	unsigned int sps_size	: 8;
	unsigned int pps_pos	: 8;
	unsigned int pps_size	: 8;
	unsigned int sei_pos	: 8;
	unsigned int sei_size	: 8;
	unsigned int data_pos	: 8;
	unsigned int reserved	: 8;
	unsigned int data_size;
};
struct MPEG4Header {
	unsigned int mhvo_pos	: 8;
	unsigned int mhvo_size	: 8;
	unsigned int vol_pos	: 8;
	unsigned int vol_size	: 8;
	unsigned int data_pos	: 8;
	unsigned int reserved	: 24;
	unsigned int data_size;
};
struct Video {
	unsigned int codec_id	: 8;
	unsigned int width		: 12;
	unsigned int height		: 12;
	unsigned int seq_no;
	unsigned int timestamp;
	unsigned int profile_id	: 8;
	unsigned int pic_type	: 8;
	unsigned int frame_no	: 8;
	unsigned int reserved	: 8;

	union
	{
		H264Header h264;
		MPEG4Header mepg4;
	};
};

int main()
{
	U u;		// default initialized to u.p == ""
	U u2 {7};	// u.a == 7

	Entry e;
	f(&e);

	Entry2 e2 {};
	e2.print();
	string s {"test"};
	e2.set_text(s);
	e2.print();
}
