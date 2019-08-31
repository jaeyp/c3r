#include <iostream>

// O(n log n)
// worst case: O(n * n) due to phase 2
// comparable to the performance of quicksort

template<typename T>
void CombSort(T data[], const int size)   // improved BubbleSort2()
{
	int i, j, k;
	int step = size;
	while((step = int(step / 1.3)) > 1)   // phase 1
	{
		for(j = size-1; j >= step; j--)
		{
			k = j-step;
			if(data[j] < data[k])
			{
				std::swap(data[j], data[k]);
			}
		}
	}

	bool again{ true };
	for(i = 0; i < size-1 && again; i++)  // phase 2
	{
		again = false;
		for(j = size-1; j > i; j--)
		{
			if(data[j] < data[j-1])
			{
				std::swap(data[j], data[j-1]);
				again = true;
			}
		}
	}
}

int main()
{
	int a1[7]{ 8, 6, 4, 4, 1, 9, 2 };
	CombSort(a1, 7);

	for(int i = 0; i < 7; i++)
	{
		std::cout << a1[i] << ' ';
	}
	std::cout << '\n';
}
