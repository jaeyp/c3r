#include <iostream>
#include <vector>

template<typename T>
void InsertionSort(T data[], int size)
{
	for(int i = 1; i < size; i++)
	{
		T tmp{data[i]};            // two copies of data[i]

		int j;
		for(j = i; j > 0 && tmp < data[j - 1]; j--)
		{
			data[j] = data[j - 1]; // two copies of data[j - 1]
		}
		data[j] = tmp;             // two copies of tmp and a discarded copy of data[j]
	}
}

template<typename T>
void InsertionSort(std::vector<T>& data)
{
	// https://en.wikipedia.org/wiki/C%2B%2B11#Rvalue_references_and_move_constructors
	for(int i = 1; i < data.size(); i++)
	{
		T tmp{ std::move(data[i]) }; // C++11: use rvalue reference copying the pointer so it prevents deep copy

		int j;
		for(j = i; j > 0 && tmp < data[j - 1]; j--)
		{
			data[j] = std::move(data[j - 1]);
		}
		data[j] = std::move(tmp);
	}
}

int main()
{
	int a1[7]{ 8, 6, 4, 4, 1, 9, 2 };
	InsertionSort(a1, 7);
	std::vector<int> a2{ 5, 3, 1, 2, 9, 8, 7 };
	InsertionSort(a2);

	for(int i = 0; i < 7; i++)
	{
		std::cout << a1[i] << ' ';
	}
	std::cout << '\n';

	for(int i = 0; i < 7; i++)
	{
		std::cout << a2[i] << ' ';
	}
	std::cout << '\n';
}
