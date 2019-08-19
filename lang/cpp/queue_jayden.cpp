#include <iostream>

template<typename T>
struct Node
{
	T Data;
	Node<T>* Previous;
	Node<T>* Next;
};

template<typename T>
class Queue
{
public:
	Queue();
	~Queue();

	int GetSize() const;

	T Peek();
	T Dequeue();
	void Enqueue(T data);
	void Clear();
	void Display();

private:
	Node<T>* mHead;
	Node<T>* mTail;
	int mSize;
};

template<typename T>
Queue<T>::Queue() : mHead{nullptr}, mTail{nullptr}, mSize{0}
{
}

template<typename T>
Queue<T>::~Queue()
{
	Clear();
}

template<typename T>
int Queue<T>::GetSize() const
{
	return mSize;
}

template<typename T>
T Queue<T>::Peek()
{
	return mHead->Data;
}

template<typename T>
T Queue<T>::Dequeue()
{
	Node<T>* node = mHead;
	T data = node->Data;
	mHead = mHead->Next;
	
	delete node;
	return data;
}

template<typename T>
void Queue<T>::Enqueue(T data)
{
	Node<T>* node = new Node<T>{ data, nullptr, nullptr };

	if(mHead)
	{
		node->Previous = mTail;
		mTail->Next = node;
	}
	else
	{
		mHead = node;
	}
	
	mTail = node;
}

template<typename T>
void Queue<T>::Clear()
{	
	Node<T>* node = nullptr;

	while(mHead)
	{
		node = mHead;
		mHead = mHead->Next;
		delete node;
	}
}

template<typename T>
void Queue<T>::Display()
{
	Node<T>* node = mHead;

	std::cout << "Queue: ";

	while(node)
	{
		std::cout << node->Data << ' ';
		node = node->Next;
	}

	std::cout << '\n';
}

int main()
{
	Queue<std::string> q1{};

	for(int i = 0; i < 5; i++)
	{
		q1.Enqueue("str" + std::to_string(i));
	}

	std::cout << "\n-----------Queue<string>-------------\n";
	q1.Display();

	std::cout << "\nCall Peek(): " << q1.Peek() << '\n';
	q1.Display();

	std::cout << "\nCall Dequeue(): " << q1.Dequeue() << '\n';
	q1.Display();

	std::cout << "\nCall Enqueue(\"orange\")\n";
	q1.Enqueue("orange");
	q1.Display();

	std::cout << "\nCall Enqueue(\"banana\")\n";
	q1.Enqueue("banana");
	q1.Display();

	std::cout << "\nCall Dequeue(): " << q1.Dequeue() << '\n';
	q1.Display();
}
