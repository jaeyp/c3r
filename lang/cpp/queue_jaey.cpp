#include <iostream>

class Queue {
public:
	Queue(int size) : size{size+1}, front{0}, rear{0} {
		q = new int[size];
	}

	~Queue(){
		delete q;
	}

	void enqueue(int data) {
		if(isFull())
			front = (front + 1) % size;
		q[rear] = data;
		rear = (rear + 1) % size;
	}

	int dequeue() {
		if(isEmpty()) {
			std::cout << "Q is empty" << std::endl;
			return -1;
		}
		int pos = front;
		front = (front + 1) % size;
		return q[pos]; 
	}

	int peek() {
		if(isEmpty()) {
			std::cout << "Q is empty" << std::endl;
			return -1;
		}
		return q[front];
	}

private:
	int* q;
	int size;
	int front;
	int rear;

	bool isFull() {
		return (rear + 1) % size == front;
	}

	bool isEmpty() {
		return front == rear;
	}
};


int main(int argc, char** argv) {
	Queue q = Queue(5);
	for(int i=0; i<6; i++)
		q.enqueue(i);

	std::cout << "peek: " << q.peek() << std::endl;
	std::cout << "dequeue: " << q.dequeue() << std::endl;
	std::cout << "dequeue: " << q.dequeue() << std::endl;
	std::cout << "peek: " << q.peek() << std::endl;
	std::cout << "dequeue: " << q.dequeue() << std::endl;
	std::cout << "dequeue: " << q.dequeue() << std::endl;
	std::cout << "dequeue: " << q.dequeue() << std::endl;
	std::cout << "dequeue: " << q.dequeue() << std::endl;
}
