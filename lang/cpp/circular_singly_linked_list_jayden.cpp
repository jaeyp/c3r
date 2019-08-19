#include <iostream>

template<typename T>
struct Node
{
	T Data;
	Node* Next;
};

template<typename T>
class List
{
public:
	List();
	~List();

	int GetSize() const;

	void Add(T data);
	void RemoveAt(int index);
	void Display();

private:
	Node<T>* mHead;
	int mSize;
};

template<typename T>
List<T>::List() : mHead{nullptr}
{
}

template<typename T>
List<T>::~List()
{
	Node<T>* node = mHead->Next;
	Node<T>* currentNode = nullptr;

	while(node == mHead)
	{
		currentNode = node;
		node = node->Next;

		delete currentNode;
	}

	delete node;
}

template<typename T>
int List<T>::GetSize() const
{
	return mSize;
}

template<typename T>
void List<T>::Add(T data)
{
	Node<T>* newNode = new Node<T>{ data, nullptr };

	if(mHead)    // if(mHead != nullptr)
	{
		Node<T>* endNode = mHead;
		
		while(endNode->Next != mHead)
		{
			endNode = endNode->Next;
		}

		endNode->Next = newNode;
		newNode->Next = mHead;
	}
	else
	{
		mHead = newNode;
		mHead->Next = mHead;
	}
}

template<typename T>
void List<T>::RemoveAt(int index)
{
	if(mHead)
	{
		Node<T>* previous = mHead;
		Node<T>* removed = nullptr;

		if(index > 0)
		{
			for(int i = 0; i < index - 1; i++)
			{
				previous = previous->Next;
			}
			
			removed = previous->Next;
			previous->Next = removed->Next;
		}
		else if(index == 0)
		{
			while(previous->Next == mHead)
			{
				previous = previous->Next;
			}

			removed = previous->Next;
			mHead = mHead->Next;
			previous->Next = mHead;
		}

		delete removed;
	}
	else
	{
		return;
	}
}

template<typename T>
void List<T>::Display()
{
	std::cout << "List: ";

	Node<T>* node = mHead;

	do
	{
		std::cout << node->Data << ' ';
		node = node->Next;
	} while(node != mHead);

	std::cout << "\n\n";
}

int main()
{
	List<std::string> l1{};

	for(int i = 0; i < 5; i++)
	{
		l1.Add("str" + std::to_string(i));
	}

	l1.Display();

	std::cout << "Remove(2)" << std::endl;
	l1.RemoveAt(2);
	l1.Display();

	std::cout << "Add(\"banana\")" << std::endl;
	l1.Add("banana");
	l1.Display();
}
