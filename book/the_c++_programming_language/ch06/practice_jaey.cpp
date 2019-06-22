#include <iostream>
#include <iomanip>
#include <iterator>

//using namespace std;	// This is not recommended because it can cause name clashes.

struct Foo {
	int   i;
	float f;
	double d;
	char  c;
};

struct Bar {
	char c;
	bool b;
	short s;
	int i;
	long l;
	long long ll;
	int* pi;
	double d;
	long double ld;
	char arr[14];
};

struct AlignedBar {
	/*  This is how to align every member with machine WORD size, 
	 *  Even though compiler mostly will add padding bit to make it aligned.
	 */
	alignas(sizeof(size_t)) char c;
	alignas(sizeof(size_t)) bool b;
	alignas(sizeof(size_t)) short s;
	alignas(sizeof(size_t)) int i;
	alignas(sizeof(size_t)) long l;
	alignas(sizeof(size_t)) long long ll;
	alignas(sizeof(size_t)) int* pi;
	alignas(sizeof(size_t)) double d;
	alignas(sizeof(size_t)) long double ld;
	alignas(sizeof(size_t)) char arr[14];
};

#pragma pack(1)
struct PackedBar {
	char c;
	bool b;
	short s;
	int i;
	long l;
	long long ll;
	int* pi;
	double d;
	long double ld;
	char arr[14];
};
#pragma pack(8)	// restore machine word align

class Chapter6 {
public:
	void TestSign(void);
	void TestAlignment(void);
	void TestAlignment2(void);
	void TestAlignment3(void);
	//void TestStringLiteral(void);
	void TestConst(void);
	void TestTypeDeduction(void);
	void TestLRvalue(void);

private:
	int x {111};
	struct Empty {};
	struct alignas(64) Empty64 {};
	struct Bar bar {};
	struct AlignedBar bar2 {};
	struct PackedBar bar3 {};

	const char *FuncWithConstReturn();
	void FuncAsConstMember() const;
};

/* 'const' return value in function */
const char* Chapter6::FuncWithConstReturn()
{ return "Some key"; }

/* 'const' member function */
void Chapter6::FuncAsConstMember() const
{
	// x = 1	// error
	std::cout << x << "\n";
}

/* signed and unsigned */
void Chapter6::TestSign()
{
	std::cout << "\n* Signed and Unsigned Characters *\n";
	// 100 == 0110 0100, 1's complement: 1001 1011, 2's comlement: 1001 1100
	// then, -100 == 1001 1100
	signed char sc = -100;	
	unsigned char uc = sc;	// 1001 1100 == 156 (unsigned), -100 (signed)
	std::cout << 
		"sc: " << (int)sc << "\n"
		"uc: " << (int)uc << "\n";

	char count[256] = {0,};
	char *cp = count;
	std::cout << "address of count[0]: " << &(count) << "\n";
	std::cout << "address of count[-100]: " << (void*)(cp-100) << "\n";
	//std::cout << (int)*(cp-120) << "\n";
	//std::cout << (int)*(cp+136) << "\n";
	std::cout << "count[-100]: " << (int)count[-100] << "\n";
	std::cout << "count[156]: " << (int)count[156] << "\n";
	std::cout << "increasement of count[-100]: " << ""; 
	++count[sc];	// undefined behavior
	std::cout << (int)*(cp-100) << " (undefined behavior)\n";
	std::cout << "increasement of count[156]: " << "";
	++count[uc];
	std::cout << (int)*(cp+156) << "\n";

	for(int i; i<sizeof(count)/sizeof(*count); i++)
		if((int)count[i] != 0)
			std::cout << "count[" << i << "]: "<< (int)count[i] << "\n";
}

/* struct size and alignment */
void Chapter6::TestAlignment()
{
	std::cout << "\n* Struct Empty *\n"
		<< "size of struct Empty: " << sizeof(struct Empty) << "\n"
		<< "size of struct alignas(64) Empty64: " << sizeof(struct Empty64) << std::endl;

	std::cout << "\n* Struct Bar *\n";
	std::cout << "machine word size: " << sizeof(size_t) << "\n"
		"MEMBER    " << "SIZE\t" << "ALIGN\t" << "ADDRESS" << "\n"
		// size:80 = 1 + 1 + 2 + 4 + 8*3 + 16*3
		"bar:      " << sizeof(bar) << " (1 + 1 + 2 + 4 + 8*3 + 16*3)" << "\n"
		"c:        " << sizeof(bar.c) << "\t" << alignof(bar.c) << "\t(" << &(bar) << ")" << "\n"
		"b:        " << sizeof(bar.b) << "\t" << alignof(bar.b) << "\t(" << &(bar.b) << ")" << "\n"
		"s:        " << sizeof(bar.s) << "\t" << alignof(bar.s) << "\t(" << &(bar.s) << ")" << "\n"
		"i:        " << sizeof(bar.i) << "\t" << alignof(bar.i) << "\t(" << &(bar.i) << ")" << "\n"
		"l:        " << sizeof(bar.l) << "\t" << alignof(bar.l) << "\t(" << &(bar.l) << ")" << "\n"
		"ll:       " << sizeof(bar.ll) << "\t" << alignof(bar.ll) << "\t(" << &(bar.ll) << ")" << "\n"
		"pi:       " << sizeof(bar.pi) << "\t" << alignof(bar.pi) << "\t(" << &(bar.pi) << ")" << "\n"
		"d:        " << sizeof(bar.d) << "\t" << alignof(bar.d) << "\t(" << &(bar.d) << ")" << " <= compiler added 8 padding here\n"
		"ld:       " << sizeof(bar.ld) << "\t" << alignof(bar.ld) << "\t(" << &(bar.ld) << ")" << "\n"
		"arr[14]:  " << sizeof(bar.arr) << "\t" << alignof(bar.arr) << "\t(" << &(bar.arr) << ")" << " <= compiler added 2 more padding here\n";
}

/* struct with aligned members (alignas) */
void Chapter6::TestAlignment2()
{	
	std::cout << "\n* Struct Bar with alignment *\n";
	std::cout << "machine word size: " << sizeof(size_t) << "\n"
		"MEMBER    " << "SIZE\t" << "ALIGN\t" << "ADDRESS" << "\n"
		// size:96 = 8*8 + 16*2
		"bar2:     " << sizeof(bar2) << " (8*8 + 16*2)" << "\n"
		"c:        " << sizeof(bar2.c) << "\t" << alignof(bar2.c) << "\t(" << &(bar2) << ")" << "\n"
		"b:        " << sizeof(bar2.b) << "\t" << alignof(bar2.b) << "\t(" << &(bar2.b) << ")" << "\n"
		"s:        " << sizeof(bar2.s) << "\t" << alignof(bar2.s) << "\t(" << &(bar2.s) << ")" << "\n"
		"i:        " << sizeof(bar2.i) << "\t" << alignof(bar2.i) << "\t(" << &(bar2.i) << ")" << "\n"
		"l:        " << sizeof(bar2.l) << "\t" << alignof(bar2.l) << "\t(" << &(bar2.l) << ")" << "\n"
		"ll:       " << sizeof(bar2.ll) << "\t" << alignof(bar2.ll) << "\t(" << &(bar2.ll) << ")" << "\n"
		"pi:       " << sizeof(bar2.pi) << "\t" << alignof(bar2.pi) << "\t(" << &(bar2.pi) << ")" << "\n"
		"d:        " << sizeof(bar2.d) << "\t" << alignof(bar2.d) << "\t(" << &(bar2.d) << ")" << "\n"
		"ld:       " << sizeof(bar2.ld) << "\t" << alignof(bar2.ld) << "\t(" << &(bar2.ld) << ")" << "\n"
		"arr[14]:  " << sizeof(bar2.arr) << "\t" << alignof(bar2.arr) << "\t(" << &(bar2.arr) << ")" << "\n";
}

/* struct with packing */
void Chapter6::TestAlignment3()
{	
	std::cout << "\n* Struct Bar with packing *\n";
	std::cout << "machine word size: " << sizeof(size_t) << "\n"
		"MEMBER    " << "SIZE\t" << "ALIGN\t" << "ADDRESS" << "\n"
		// size:70 = 1 + 1 + 2 + 4 + 8*4 + 16 + 14
		"bar3:     " << sizeof(bar3) << " (1 + 1 + 2 + 4 + 8*4 + 16 + 14)" << "\n"
		"c:        " << sizeof(bar3.c) << "\t" << alignof(bar3.c) << "\t(" << &(bar3) << ")" << "\n"
		"b:        " << sizeof(bar3.b) << "\t" << alignof(bar3.b) << "\t(" << &(bar3.b) << ")" << "\n"
		"s:        " << sizeof(bar3.s) << "\t" << alignof(bar3.s) << "\t(" << &(bar3.s) << ")" << "\n"
		"i:        " << sizeof(bar3.i) << "\t" << alignof(bar3.i) << "\t(" << &(bar3.i) << ")" << "\n"
		"l:        " << sizeof(bar3.l) << "\t" << alignof(bar3.l) << "\t(" << &(bar3.l) << ")" << "\n"
		"ll:       " << sizeof(bar3.ll) << "\t" << alignof(bar3.ll) << "\t(" << &(bar3.ll) << ")" << "\n"
		"pi:       " << sizeof(bar3.pi) << "\t" << alignof(bar3.pi) << "\t(" << &(bar3.pi) << ")" << "\n"
		"d:        " << sizeof(bar3.d) << "\t" << alignof(bar3.d) << "\t(" << &(bar3.d) << ")" << "\n"
		"ld:       " << sizeof(bar3.ld) << "\t" << alignof(bar3.ld) << "\t(" << &(bar3.ld) << ")" << "\n"
		"arr[14]:  " << sizeof(bar3.arr) << "\t" << alignof(bar3.arr) << "\t(" << &(bar3.arr) << ")" << "\n";
}

#if 0
/* UTF-8 encoding */
void Chapter6::TestStringLiteral()
{	
	std::cout << "\n* UTF-8 *\n";
	std::string s = "abcd 한글";	//u8"abcd 한글";

	std::ostringstream result;
	result << /*std::setw(8) << std::setfill('F') <<*/ std::hex << std::uppercase;
	std::copy(s.begin(), s.end(), std::ostream_iterator<unsigned short>(result, " "));
	std::cout << s << ":" << result.str() << std::endl;
}
#endif

/* 'const' declarations */
void Chapter6::TestConst()
{
	const int var1 = 10;
	int var2 = 20;
	int var3 = 30;

	// 1. k1 is a pointer to a constant integer, 
	//    you can't modify the pointed value.
	const int * k1 = &var1;	
	//var1 = 20;	// error
	//*k1 = 20; 	// error
	
	// 2. this is an alternative syntax which does the same with k1
	int const * k2 = &var1;	
	
	// 3. k3 is a constant pointer to a variable integer, 
	//    you can't modify the value of your pointer, 
	//    but you can modify the pointed value.
	int * const k3 = &var2;
	var2 *= 2;
	*k3 *= 2;
	//k3 = &var3;             // error. it's const pointer.
	//int * const k3 = &var1; // error. var1 is constant integer and can't convert constant integer to integer.
	
	// 4. k4 is a constant pointer of a constant integer.
	int const * const k4 = &var1;

	// const return value
	std::cout << "\n* const *\n"
		<< "var1: " << var1 << "\n"
		<< "var2: " << var2 << "\n"
		<< FuncWithConstReturn()[1]
		<< FuncWithConstReturn()[5] << std::endl;

	// const member function
	FuncAsConstMember();
	
	// TODO: mutable and const_cast

	// TODO: const variable vs constexpr variable
	// the initialization of a const variable can be deferred until run time.
	// while a constexpr variable must be initialized at compile time.
	int sz;
	const int ksz = 10;

	const int asz1 = sz;          // fine, asz1 is const copy of sz
	//std::array<int, asz1> data; // error, asz1's value unknown at compilation

	//constexpr int asz2 = sz;    // error. sz's value unknown at compilation
	//std::array<int, asz2> data; // error, asz2's value unknown at compilation

	constexpr int asz2 = ksz;      // fine, ksz is a compile-time constant
	std::array<int, asz2> data;    // fine, asz2 is constexpr

	// TODO: constexpr function vs inline function
}

/* auto and decltype() */
void Chapter6::TestTypeDeduction(void)
{
	// TODO:
}

/* Lvalue and Rvalue */
void Chapter6::TestLRvalue()
{
	/*  Lvalue is an expression that refers to an object. (somthing has identity, cannot be moved)
	 *  Rvalue no longer exists after an expression. (movable, temporary)
	 */

	int x = 3;          // 3 is rvalue
	const int y = x;
	int z = x + y;      // x + y is rvalue
	int arr[] = {1, 2}; // {1, 2} is rvalue


	int* p = &x;    // unary '&' means 'address of', and it's rvalue (important!)
	x = *p;         // unary '*' means 'contents of', and it's lvalue (important!)
	// We can use address-of operator '&' only for lvalue since rvalue is movable.
	//&x = 10;      // error, left operand of assignment must be lvalue.
	//&(&x);        // error, '&' requires lvalue

	p = &arr[0];    // &arr[0] is rvalue
	*(p+1) = 10;    // okay, *(p+1) is lvalue.
	&(*(p+1));      // okay, *(p+1) is lvalue.

	std::cout << "\n* lvalue and rvalue *\n"
		<< std::string("this is rvalue") << std::endl;	// return value of string() is rvalue

	int i, j;
	x = 1;
	i = ++x;    // i = 2, x = 2
	++x = i;    // okay, ++x is lvalue
	&(++x);     // okay, ++x is lvalue

	x = 1;
	j = x++;    // j = 1, and x comes to 2 after the expression.
	//x++ = j;  // error, x++ is rvalue
	//&(x++);   // error, x++ is rvalue
}

int main(int argc, char *argv[])
{
	std::unique_ptr<Chapter6> ch6 = std::make_unique<Chapter6>();

	ch6->TestSign();
	ch6->TestAlignment();
	ch6->TestAlignment2();
	ch6->TestAlignment3();
	//ch6->TestStringLiteral();
	ch6->TestConst();
	ch6->TestLRvalue();
}
