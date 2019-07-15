#include <iostream>

void f(int i)
{
	switch(i) {
		case 0:
			int x;
		case 1:
			x = 1;
			++x;
	}
}

int main()
{
	f(1);
}
