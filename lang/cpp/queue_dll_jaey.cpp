#include <iostream>
#include <vector>

template <typename T> struct Node {
	T* data;
	Node<T>* next;
	Node<T>* prev;
};

template <typename T> class Queue {
public:
	Queue(int size);
	~Queue();
	void enqueue(T* data);
	T* dequeue();
	T* peek();
private:
	Node<T>* front;
	Node<T>* rear;
	int size;
	constexpr bool isFull();
	constexpr bool isEmpty();
	constexpr int getSize();
};

template <typename T> 
Queue<T>::Queue(int sz) : front{nullptr}, rear{nullptr}, size{sz+1} {
	std::cout << "Queue Constructor: " << sz << std::endl;
	Node<T>* cur = nullptr;
	for(int i=0; i<size; i++) {
		Node<T>* node = new Node<T>();
		if (i==0) {
			cur = node;
			cur->next = node;
			cur->prev = node;
		} else {
			node->next = cur->next;
			cur->next->prev = node;
			node->prev = cur;
			cur->next = node;
			cur = node;
		}
	}
	front = rear = cur->next;
}

template <typename T> 
Queue<T>::~Queue() {
	std::cout << "Queue Destructor" << std::endl;
	Node<T>* cur = front;
	for(int i=0; i<size; i++) {
		Node<T>* node = cur;
		cur = cur->next;
		free(node);
	}
}

template <typename T> constexpr bool
Queue<T>::isFull() {
	return (rear->next == front);
}

template <typename T> constexpr bool
Queue<T>::isEmpty() {
	return (rear == front);
}

template <typename T> constexpr int
Queue<T>::getSize() {
	return (size-1);
}

template <typename T> void 
Queue<T>::enqueue(T* data) {
	// std::cout << "enqueue: " << front << ":" << rear << ":" << *data;
	if (!isFull()) {
		rear->data = data;
		rear = rear->next;
	} else { // full - overwrite
		//free(front->data);
		rear->data = data;
		rear = rear->next;
		front = front->next;
	}
}

template <typename T> T*
Queue<T>::dequeue() {
	// std::cout << "dequeue: " << front << ":" << rear << ":" << *front->data << std::endl;
	if (!isEmpty()) {
		front = front->next;
		return front->prev->data;
	} else { // empty
		return nullptr;
	}
}

template <typename T> T*
Queue<T>::peek() {
	if (!isEmpty())
		return front->data;
	else
		return nullptr;
}

int main(int argc, char** argv) {
	Queue<int>* qi = new Queue<int>(4);
	std::vector<int> vi{1,2,3,4,5,6,7,8};
	qi->enqueue(&vi[0]);
	qi->enqueue(&vi[1]);
	qi->enqueue(&vi[2]);
	qi->enqueue(&vi[3]);
	qi->enqueue(&vi[4]);

	std::cout << *qi->dequeue() << std::endl;
	std::cout << *qi->dequeue() << std::endl;
	std::cout << *qi->peek() << std::endl;
	std::cout << *qi->peek() << std::endl;
	std::cout << *qi->dequeue() << std::endl;
	std::cout << *qi->dequeue() << std::endl;
	
	qi->enqueue(&vi[5]);
	qi->enqueue(&vi[6]);

	std::cout << *qi->dequeue() << std::endl;
	std::cout << *qi->dequeue() << std::endl;

	qi->~Queue();
	free(qi);

	Queue<std::string> qs(5);
	std::vector<std::string> vs{"one", "two", "three", "four", "five"};
	qs.enqueue(&vs[0]);
	qs.enqueue(&vs[1]);
	qs.enqueue(&vs[2]);
	qs.enqueue(&vs[3]);
	qs.enqueue(&vs[4]);

	std::cout << *qs.dequeue() << std::endl;
	std::cout << *qs.dequeue() << std::endl;
	std::cout << *qs.dequeue() << std::endl;
	std::cout << *qs.dequeue() << std::endl;
	std::cout << *qs.dequeue() << std::endl;
	return 0;
}
