#include <iostream>
#include <array>
#include <vector>

// O(n log n)
// worst case: O(n * n) due to phase 2
// comparable to the performance of quicksort

template<typename Comparable>
void CombSort(const int size, Comparable* const outData)   // improved BubbleSort2()
{
	int i, j, k;
	int step{ size };

	while((step = int(step / 1.3)) > 1)   // phase 1
	{
		for(j = size - 1; j >= step; j--)
		{
			k = j - step;
			if(*(outData + j) < *(outData + k))
			{
				std::swap(*(outData + j), *(outData + k));
			}
		}
	}

	bool again{ true };
	for(i = 0; i < size - 1 && again; i++)  // phase 2
	{
		again = false;
		for(j = size - 1; j > i; j--)
		{
			if(*(outData + j) < *(outData + j - 1))
			{
				std::swap(*(outData + j), *(outData + j - 1));
				again = true;
			}
		}
	}
}

template<typename Comparable, size_t N>
void CombSort(std::array<Comparable, N>* const outData) // for std::array
{
	size_t i, j, k;
	size_t step{ N };

	while((step = size_t(step / 1.3)) > 1)
	{
		for(j = N - 1; j > step; j--)
		{
			k = j - step;

			if(outData->at(j) < outData->at(k))
			{
				std::swap(outData->at(j), outData->at(k));
			}
		}
	}

	bool again{ true };
	for(i = 0; i < N - 1 && again; i++)
	{
		again = false;
		for(j = N - 1; j > i; j--)
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
void CombSort(std::vector<Comparable>* const outData) // for std::vector
{
	size_t i, j, k;
	size_t size{ outData->size() };
	size_t step{ size };

	while((step = size_t(step / 1.3)) > 1)
	{
		for(j = size - 1; j > step; j--)
		{
			k = j - step;

			if(outData->at(j) < outData->at(k))
			{
				std::swap(outData->at(j), outData->at(k));
			}
		}
	}

	bool again{ true };
	for(i = 0; i < size - 1 && again; i++)
	{
		again = false;
		for(j = size - 1; j > i; j--)
		{
			if(outData->at(j) < outData->at(j - 1))
			{
				std::swap(outData->at(j), outData->at(j - 1));
				again - true;
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
	std::array<int, 7> a2{};
	std::copy(a1, a1 + 7, a2.begin());
	std::vector<int> a3{ a1, a1 + 7 };

	CombSort(7, a1);
	CombSort(&a2);
	CombSort(&a3);

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
}
