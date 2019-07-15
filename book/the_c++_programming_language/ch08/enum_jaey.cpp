/*
 * written by Jaehyun Park (Jul 6, 2019)
 */
#include <iostream>

/* enum class (prefered)
   - local scope
   - no implicit conversion
 */
enum class Light { red, green, blue };
// We can represent an enumeration's underlying type.
// Also, an enumerator can be initialized by a constant expression of integral type.
enum class Color : char { 
	red = 1, 
	green = 2, 
	blue = 4, 
	yellow = red | green,
	cyan = green | blue,
	magenta = blue | red,
	white = magenta | yellow | cyan
};

constexpr Color operator| (Color a, Color b)
{
	return static_cast<Color>(static_cast<char>(a)|static_cast<char>(b));
}

constexpr Color operator& (Color a, Color b)
{
	return static_cast<Color>(static_cast<char>(a)&static_cast<char>(b));
}

constexpr bool operator&& (Color a, Color b)
{
	return static_cast<bool>(static_cast<char>(a)&static_cast<char>(b));
}

void palette(Color c)
{
	switch(c) {
		case Color::red:
			std::cout << "Red" << std::endl;
			break;
		case Color::green:
			std::cout << "Green" << std::endl;
			break;
		case Color::blue:
			std::cout << "Blue" << std::endl;
			break;
		case Color::yellow:
			std::cout << "Yellow" << std::endl;
			break;
		case Color::cyan:
			std::cout << "Cyan" << std::endl;
			break;
		case Color::magenta:
			std::cout << "Magenta" << std::endl;
			break;
		case Color::white:
			std::cout << "White" << std::endl;
			break;
		default:
			std::cout << "Unknown color type (" << static_cast<int>(c) << ")"  << std::endl;
	}
}

void extract(Color c)
{
	std::cout << "The color consist of ";
	if(c && Color::red) {
		std::cout << "Red ";
	}
	if(c && Color::green) {
		std::cout << "Green ";
	}
	if(c && Color::blue) {
		std::cout << "Blue ";
	}
	std::cout << std::endl;
}

/* plain enum (C, C++98)
   - exported into the enum's scope
   - support implicit conversion
 */
enum PlainColor {red, green, blue};
// unnamed enum
enum {arrow_up=1, arrow_down, arrow_left, arrow_right};

int main()
{
	/* enum class */
	Color c = Color::green | Color::blue; // cyan
	palette(c);
	extract(c);
	c = Color::green | Color::blue | Color::red; // white
	palette(c);
	extract(c);

	Color c0 {}; // c0 gets the default value 0
	//Color c1 = 1; // error, 1 is not of type Color. it's integral value
	Color c2 = Color(1); // okay
	Color c3 = Color(999); // okay
	//Color c3 = Color{1}; // error, no narrowing conversion to an enum class
	Color c4 = static_cast<Color>(1); // brute force
	Color c5 = static_cast<Color>(999); // brute force (0011 1110 0111)
	//Color c6 {1}; // error
	//Color c7(1);  // error
	palette(c0); // 0
	palette(c2); // red
	palette(c3); // -25
	palette(c4); // red
	palette(c5); // -25: 1110 0111

	/* plain enum */
	PlainColor pc = red;
	int i = green;
	int arrow = arrow_right;
}
