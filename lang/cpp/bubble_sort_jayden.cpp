#include <iostream>
#include <utility>
#include <vector>

// average: O(n * n)

template<typename T>
void BubbleSort(T data[], int size)
{
	for(int i = 0; i < size-1; i++)
	{
		for(int j = size-1; j > i; j--)
		{
			if(data[j] < data[j-1])
			{
				std::swap(data[j], data[j-1]);
			}
		}
	}
}

template<typename T>
void BubbleSort2(T data[], int size)
{
	bool again{true};
	for(int i = 0; i < size-1 && again; i++)
	{
		again = false;
		for(int j = size-1; j > i; j--)
		{
			if(data[j] < data[j-1])
			{
				std::swap(data[j], data[j-1]);
				again = true;    // to check if swaped 
			}
		}
	}
}

int main()
{
	int a1[7]{ 8, 6, 4, 4, 1, 9, 2 };
	int a2[7];
	std::copy(a1, a1+7, a2);

	BubbleSort(a1, 7);
	BubbleSort2(a2, 7);

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
