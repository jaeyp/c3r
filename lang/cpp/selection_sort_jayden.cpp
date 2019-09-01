#include <iostream>
#include <utility>  // std::swap
#include <vector>

// O(n * n)

template<typename T>
void SelectionSort(T data[], int size)
{
	for(int i = 0; i < size-1; i++)
	{
		int least = i;
		for(int j = i+1; j < size; j++)
		{
			if(data[j] < data[least])
			{
				least = j;
			}
		}

		if(i != least)  // if the elements in data are large compound entities such as arrays or structures
		{               // then one swap may take much time so using a conditional swap() is recommended.
			std::swap(data[least], data[i]);
		}
	}
}

template<typename T>
void SelectionSort(std::vector<T>& data)
{
	int size{ (int)data.size() };
	for(int i = 0; i < size; i++)
	{
		int least = i;
		for(int j = i+1; j < size; j++)
		{
			if(data[j] < data[least])
			{
				least = j;
			}
		}

		if(i != least)  // if the elements in data are large compound entities such as arrays or structures
		{               // then one swap may take much time so using a conditional swap() is recommended.
			std::swap(data[least], data[i]);
		}
	}
}

template<typename T>
void Swap(T& a, T&b)   // same as std::swap()
{
	T c{ std::move(a) };
	a = std::move(b);
	b = std::move(c);
}

int main()
{	
	int a1[7]{ 8, 6, 4, 4, 1, 9, 2 };
	SelectionSort(a1, 7);
	std::vector<int> a2{ 5, 3, 1, 2, 9, 8, 7 };
	SelectionSort(a2);

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
