#include <iostream>
#include "stack_jayden.cpp"

class Calculator
{
public:
	Calculator();
	~Calculator();
	
	double Calculate(std::string const&);

private:
	double operate(const double, const double, const char);
	void clearAllMembers();
	void clearBuffer();
	void showError();

private:
	Stack<char> mOperators;
	Stack<double> mNumbers;
	char mBuffer[10];
};

Calculator::Calculator() : mOperators{}, mNumbers{}
{
}

Calculator::~Calculator()
{
	mOperators.Clear();
	mNumbers.Clear();
}

double Calculator::Calculate(std::string const& input)
{
	int i{0};
	bool isPriority{false};

	for(char c : input)
	{
		if(isdigit(c))
		{
			mBuffer[i] = c;
			i++;
		}
		else
		{
			switch(c)
			{
				case '+':
				case '-':
				case '*':
				case '/':
					{
						double number = atof(mBuffer);
						clearBuffer();

						mNumbers.Push(number);
						i = 0;

						if(isPriority)
						{
							double n2 = mNumbers.Pop();
							double n1 = mNumbers.Pop();
							char oper = mOperators.Pop();

							double result = operate(n1, n2, oper);
							mNumbers.Push(result);
							isPriority = false;
						}

						mOperators.Push(c);

						if(c == '*' || c == '/')
						{
							isPriority = true;
						}
					}
					break;

				case '(':
					mOperators.Push(c);
					isPriority = false;
					break;

				case ')':
					{
						double number = atof(mBuffer);
						mNumbers.Push(number);
						clearBuffer();

						char oper = mOperators.Pop();
						while(oper != '(')
						{
							double n2 = mNumbers.Pop();
							double n1 = mNumbers.Pop();
	
							double result = operate(n1, n2, oper);
							mNumbers.Push(result);
	
							oper = mOperators.Pop();
						}

						if(mOperators.Peek() == '*' || mOperators.Peek() == '/')
						{
							isPriority = true;
						}
					}
					break;

				case ' ':
					break;

				default:
					showError();
					clearAllMembers();
					break;
					
			}
		}
	}

	if(mBuffer[0] != '\0')
	{
		mNumbers.Push(atof(mBuffer));
		clearBuffer();
	}
	
	double result{0};

	while(mOperators.GetSize() != 0)
	{
		if(mNumbers.GetSize() < 2)
		{
			showError();
			clearAllMembers();
			return 0;
		}

		result = operate(mNumbers.Pop(), mNumbers.Pop(), mOperators.Pop());
		mNumbers.Push(result);
	}

	result = mNumbers.Pop();
	clearAllMembers();

	return result;
}

double Calculator::operate(const double n1, const double n2, const char oper)
{
	double result{0};

	switch(oper)
	{
		case '+':
			result = n1 + n2;
			break;
		case '-':
			result = n1 - n2;
			break;
		case '*':
			result = n1 * n2;
			break;
		case '/':
			result = n1 / n2;
			break;
	}

	return result;
}

void Calculator::clearAllMembers()
{
	mNumbers.Clear();
	mOperators.Clear();
	clearBuffer();
}

void Calculator::clearBuffer()
{
	for(char& c : mBuffer)
	{
		c = '\0';
	}
}

void Calculator::showError()
{
	std::cout << "Wrong!\n";
	clearAllMembers();
}

int main()
{
	Calculator c{};
	std::string input{};

	while(true)
	{
		std::cout << "\nEnter to calculate\n";
		getline(std::cin, input);

		std::cout << "Result: " << c.Calculate(input) << std::endl;
	}
}
