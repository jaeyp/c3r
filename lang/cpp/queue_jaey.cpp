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
		if(isEmpty())
			return -1;
		int pos = front;
		front = (front + 1) % size;
		return q[pos]; 
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
	bool getSize() {
		return size;
	}
};


int main(int argc, char** argv) {
	Queue q = Queue(5);
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	q.enqueue(4);
	q.enqueue(5);
	q.enqueue(6);

	std::cout << q.dequeue() << std::endl;
	std::cout << q.dequeue() << std::endl;
	std::cout << q.dequeue() << std::endl;
	std::cout << q.dequeue() << std::endl;
	std::cout << q.dequeue() << std::endl;
	std::cout << q.dequeue() << std::endl;
}
