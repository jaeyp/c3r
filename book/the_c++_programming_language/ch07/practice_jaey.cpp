// ch7. practice
#include <iostream>
#include <vector>

void print_multi_array1(int m[3][5])
{
	for(int i=0; i<3; i++) {
		for(int j=0; j<5; j++)
			std::cout << m[i][j] << '\t';
		std::cout << '\n';
	}
}

// The second dimention is 5 so that we can locate m[i][5] for any i.
void print_multi_array2(int m[][5], int dim1)
{
	for(int i=0; i<dim1; i++) {
		for(int j=0; j<5; j++)
			std::cout << m[i][j] << '\t';
		std::cout << '\n';
	}
}

// This is illegal. The second dimention(j) must be known 
// in order to find the location of m[i][j] for any i.
#if 0
void print_multi_array3(int m[][], int dim1, int dim2) 
{
	for(int i=0; i<dim1; i++) {
		for(int j=0; j<dim2; j++)
			std::cout << m[i][j] << '\t';
		std::cout << '\n';
	}
}
#endif

void print_multi_array3(int* m, int dim1, int dim2)
{
	for(int i=0; i<dim1; i++) {
		for(int j=0; j<dim2; j++)
			std::cout << m[i*dim2+j] << '\t';
		std::cout << '\n';
	}
}

// swap two lvalues
template<class T>
void swap_lvalue(T& a, T& b)
{
#if 1	// move(x) produces an rvalue reference to x
	T tmp {std::move(a)};
	a = std::move(b);
	b = std::move(tmp);
#else
	T tmp {static_cast<T&&>(a)};
	a = static_cast<T&&>(b);
	b = static_cast<T&&>(tmp);
#endif
}

// replace lvalue with rvalue as default
template<class T>
void replace_lvalue_with_rvalue(T& a, T&& b)
{
	T tmp {std::move(a)};
	a = std::move(b);
	b = std::move(tmp);
}

void set_default(std::vector<int>& v)
{
	replace_lvalue_with_rvalue(v, std::vector<int>{0,1,2,3,4,5,6,7,8,9});
}

int main()
{
	int v[3][5] = {{0,1,2,3,4},{10,11,12,13,14},{20,21,22,23,24}};
	int* pv = v[0];	// = &v[0][0]

	print_multi_array1(v);
	print_multi_array2(v, 3);
	print_multi_array3(&v[0][0], 3, 5);
	print_multi_array3(pv, 3, 5);

	int i1 = 0;
	int i2 = 10;
	std::cout << "Swap lvalues\n" << i1 << ' ' << i2 << '\n';
	swap_lvalue(i1, i2);
	std::cout << i1 << ' ' << i2 << '\n';

	std::cout << "Replace lvalue with default rvalue\n";
	std::vector<int> vec(10);
	for(int i : vec) std::cout  << i << ' ';
	std::cout << '\n';
	set_default(vec);
	for(int i : vec) std::cout << i << ' ';
	std::cout << '\n';
}
