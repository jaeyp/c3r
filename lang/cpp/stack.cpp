#include <iostream>

template<typename T>
struct Node
{
	T Data;
	Node<T>* Next;
};

template<typename T>
class Stack
{
public:
	Stack();
	~Stack();

	int GetSize() const;
	
	void Push(T data);
	T Pop();
	void Display();

private:	
	Node<T>* createNode(T data);
	void freeNode(Node<T>* node);

private:
	Node<T>* mHead;
	int mSize;

};

template<typename T>
Stack<T>::Stack() : mHead{nullptr}, mSize{0}
{
}

template<typename T>
Stack<T>::~Stack()
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
int Stack<T>::GetSize() const
{
	return mSize;
}

template<typename T>
void Stack<T>::Push(T data)
{
	Node<T>* node = createNode(data);

	node->Next = mHead;
	mHead = node;
}

template<typename T>
T Stack<T>::Pop()
{
	Node<T>* node = mHead;
	T data = node->Data;
	mHead = mHead->Next;
	return data;
}

template<typename T>
void Stack<T>::Display()
{
	Node<T>* node = mHead;

	std::cout << "Stack: ";

	while(node)
	{
		std::cout << node->Data << ' ';
		node = node->Next;
	}

	std::cout << '\n';
}

template<typename T>
Node<T>* Stack<T>::createNode(T data)
{
	return new Node<T>{ data, nullptr };
}

template<typename T>
void Stack<T>::freeNode(Node<T>* node)
{
	delete node;
}

int main()
{
	Stack<std::string> s1{};

	for(int i = 0; i < 5; i++)
	{
		s1.Push("str" + std::to_string(i));
	}

	std::cout << "\n-------------Stack<string>------------\n";
	s1.Display();

	std::cout << "\nCall Pop(): " << s1.Pop() << '\n';
	s1.Display();

	std::cout << "\nCall Push(\"orange\")\n";
	s1.Push("orange");
	s1.Display();

	std::cout << "\nCall push(\"banana\")\n";
	s1.Push("banana");
	s1.Display();

	std::cout << "\nCall Pop(): " << s1.Pop() << '\n';
	s1.Display();
}

