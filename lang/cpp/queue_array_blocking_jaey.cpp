#include <iostream>
#include <vector>
#include <mutex>
#include <condition_variable>
#include <chrono>
#include <thread>
#include <functional>

using namespace std::this_thread;
using namespace std::chrono;

template <typename T> class Queue {
public:
	Queue();
	Queue(int sz);
	~Queue();
	void enqueue(T* data);
	T* dequeue();
	void dequeue(std::function<T*(T*)> callback);
	T* peek();
	void flush();
private:
	// variables
	int size;
	int front;
	int rear;
	T** q;
	std::mutex mtx;
	std::condition_variable cv;
	// methods
	bool isFull() {
		return (front == (rear+1)%size);
	}
	bool isEmpty() {
		return (front == rear);
	}
	/*
	T* handler(T* data, std::function<T*(T*)> callback) {
		return callback(data);
	}
	*/
};

/**
 *	Public Functions
 */
// Default Constructor
template <typename T>
Queue<T>::Queue() : size{11}, front{0}, rear{0}, q{nullptr} {
	q = new T*[size];
}

// Custom Constructor
template <typename T>
Queue<T>::Queue(int sz) : size{sz+1}, front{0}, rear{0}, q{nullptr} {
	q = new T*[size];
}

// Destructor
template <typename T>
Queue<T>::~Queue() {
	delete q;
	q = nullptr;
}

template <typename T> 
void Queue<T>::enqueue(T* data) {
	if (!isFull()) {
		std::unique_lock<std::mutex> lock(mtx);

		q[rear] = data;
		rear = (rear+1)%size;

		cv.notify_all();
		//cv.notify_one();
	} else { // full
		std::cout << "full" << std::endl;
	}
}

template <typename T> 
T* Queue<T>::dequeue() {
	T* res{nullptr};

	std::unique_lock<std::mutex> lock(mtx);
	cv.wait(lock);

	if (!isEmpty()) {
		res = q[front];
		front = (front+1)%size;
	} else {
		std::cout << "queue is empty" << std::endl;
	}
	return res;
}

template <typename T> 
void Queue<T>::dequeue(std::function<T*(T*)> callback) {
	T* res{nullptr};

	std::unique_lock<std::mutex> lock(mtx);
	cv.wait(lock);

	while (!isEmpty()) {
		res = q[front];
		front = (front+1)%size;
		callback(res);
//		handler(res, callback);
	}
}

template <typename T> 
T* Queue<T>::peek() {
	T* res{nullptr};

	if (!isEmpty()) {
		res = q[(rear-1)%size];
		std::cout << "peek: " << *res << std::endl;
	} else {
	std::cout << "peek: empty" << std::endl;
	}
	return res;
}

template <typename T> 
void Queue<T>::flush() {
	std::cout << "flushing queue" << std::endl;
	while(!isEmpty()) {
		cv.notify_all();
		sleep_for(milliseconds(100));
	}
}

/**
 *	Global Functions
 */
// callback function
int* display(int* data) {
	std::cout << "callback: " << *data << std::endl;
	return data;
}

// worker thread
void workerThread(Queue<int>* q) {
	for(int i=0; i<10; i++) {
		sleep_for(milliseconds(1000));
		q->dequeue(display);
	}
}

/**
 *	main
 */
int main(int argc, char** argv) {
	Queue<int>* q = new Queue<int>(10);

	std::thread worker(workerThread, q);
	worker.detach();
	sleep_for(milliseconds(300));	// worker thread warming-up

	// enqueue data
	std::vector<int> vi{1,2,3,4,5,6,7,8,9,10};
	for (int i=0; i<10; i++) {
		std::cout<< "push: " << vi[i%10] << std::endl;
		q->enqueue(&vi[i%10]);
		sleep_for(milliseconds(300));
		q->peek();
	}

	q->flush();
	if (true == worker.joinable()) {
		worker.join();
		std::cout << "worker thread is joined" << std::endl;
	} else {
		std::cout << "worker thread is terminated" << std::endl;
	}

	return 0;
}
