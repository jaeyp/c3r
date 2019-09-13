#include <iostream>
#include <utility>
#include <vector>
#include <array>

// average: O(n * n)

template<typename Comparable>
void BubbleSort(const int size, Comparable* const outData)
{
	for(int i = 0; i < size - 1; i++)
	{
		for(int j = size - 1; j > i; j--)
		{
			if(*(outData + j) < *(outData + j - 1))
			{
				std::swap(*(outData + j), *(outData + j - 1));
			}
		}
	}
}

template<typename Comparable>
void BubbleSort2(const int size, Comparable* const outData)  // better
{
	bool again{true};
	for(int i = 0; i < size - 1 && again; i++)
	{
		again = false;
		for(int j = size - 1; j > i; j--)
		{
			if(*(outData + j) < *(outData + j - 1))
			{
				std::swap(*(outData + j), *(outData + j - 1));
				again = true;    // to check if swaped 
			}
		}
	}
}

template<typename Comparable, size_t N>
void BubbleSort(std::array<Comparable, N>* const outData) // for std::array
{
	bool again{ true };
	for(size_t i = 0; i < N - 1 && again; i++)
	{
		again = false;
		for(size_t j = N - 1; j > i; j--)
		{
			if(outData->at(j) < outData->at(j - 1))
			{
				std::swap(outData->at(j), outData->at(j - 1));
				again = true;
			}
		}
	}
}

template<typename Comparable>
void BubbleSort(std::vector<Comparable>* const outData) // for std::vector
{
	size_t size = outData->size();
	bool again{ true };
	
	for(size_t i = 0; i < size - 1 && again; i++)
	{
		again = false;
		for(int j = size - 1; j > i; j--)
		{
			if(outData->at(j) < outData->at(j - 1))
			{
				std::swap(outData->at(j), outData->at(j - 1));
				again = true;
			}
		}
	}
}

template<typename T>
void Swap(T* const outFirst, T* const outSecond) // same as std::swap()
{
	T tmp{ std::move(*outFirst) };
	*outFirst = std::move(*outSecond);
	*outSecond = std::move(tmp);
}

int main()
{
	int a1[7]{ 8, 6, 4, 4, 1, 9, 2 };
	int a2[7]{};
	std::copy(a1, a1 + 7, a2);
	std::array<int, 7> a3{};
	std::copy(a1, a1 + 7, a3.begin());
	std::vector<int> a4{a1, a1 + 7};

	BubbleSort(7, a1);
	BubbleSort2(7, a2);
	BubbleSort(&a3);
	BubbleSort(&a4);

	for(const auto& x : a1)
	{
		std::cout << x << ' ';
	}
	std::cout << '\n';

	for(const auto& x : a2)
	{
		std::cout << x << ' ';
	}
	std::cout << '\n';

	for(const auto& x : a3)
	{
		std::cout << x << ' ';
	}
	std::cout << '\n';

	for(const auto& x : a4)
	{
		std::cout << x << ' ';
	}
	std::cout << '\n';
}
