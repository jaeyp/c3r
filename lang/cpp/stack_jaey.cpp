#include <iostream>

class Stack {
public:
	Stack(int size) : size{size}, top{0} {
		stack = new int[size];
	}
	~Stack(){}
	void push(int data) {
		top = top + 1;
		stack[top] = data;
	}
	int pop() {
		int pos = top;
		top = top - 1;
		return stack[pos]; 
	}
private:
	int* stack;
	int size;
	int top;
	bool isEmpty() {
		return top == 0;
	}
	bool getSize() {
		return size;
	}
};


int main(int argc, char** argv) {
	Stack s = Stack(10);
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);

	std::cout << s.pop() << std::endl;
	std::cout << s.pop() << std::endl;
	std::cout << s.pop() << std::endl;
	std::cout << s.pop() << std::endl;
}
