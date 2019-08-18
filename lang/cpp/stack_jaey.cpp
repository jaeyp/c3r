#include <iostream>

class Stack {
public:
	Stack(int size) : size{size}, top{0} {
		stack = new int[size];
	}

	~Stack(){
		delete stack;
	}

	void push(int data) {
		if(isFull()) {
			std::cout << "stack is full" << std::endl;
			return;
		}
		stack[top++] = data;
	}

	int pop() {
		if(isEmpty()) {
			std::cout << "stack is empty" << std::endl;
			return -1;
		}
		return stack[--top]; 
	}

	int peek() {
		if(isEmpty()) {
			std::cout << "stack is empty" << std::endl;
			return -1;
		}
		return stack[top-1];
	}

private:
	int* stack;
	int size;
	int top;

	bool isFull() {
		return top == size;
	}

	bool isEmpty() {
		return top == 0;
	}
};


int main(int argc, char** argv) {
	Stack s(8);
	for(int i=0; i<10; i++) {
		s.push(i);
	}

	std::cout << "peek: " << s.peek() << std::endl;

	for(int i=0; i<10; i++) {
		std::cout << "pop: " << s.pop() << std::endl;
	}
}
