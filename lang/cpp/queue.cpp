#include <iostream>

template <typename T>
struct Node
{
	T Data;
	Node<T>* Next;
}

template <typename T>
class Queue
{
public:
	Queue();
	~Queue();

	int GetSize() const;

	T Peek();
	
	void Enqueue(T data);
	void Dequeue();

private:


}
