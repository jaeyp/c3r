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
	Node<T>* mFront;
	Node<T>* mRear;
	int mSize;
};

template<typename T>
Queue<T>::Queue() : mFront{nullptr}, mRear{nullptr}, mSize{0}
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
	return mFront->Data;
}

template<typename T>
T Queue<T>::Dequeue()
{
	Node<T>* node = mFront;
	T data = node->Data;
	mFront = mFront->Next;
	
	delete node;
	return data;
}

template<typename T>
void Queue<T>::Enqueue(T data)
{
	Node<T>* node = new Node<T>{ data, nullptr, nullptr };

	if(mFront)
	{
		node->Previous = mRear;
		mRear->Next = node;
	}
	else
	{
		mFront = node;
	}
	
	mRear = node;
}

template<typename T>
void Queue<T>::Clear()
{	
	Node<T>* node = nullptr;

	while(mFront)
	{
		node = mFront;
		mFront = mFront->Next;
		delete node;
	}

	mSize = 0;
}

template<typename T>
void Queue<T>::Display()
{
	Node<T>* node = mFront;

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
