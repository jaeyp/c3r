#include <iostream>
#include <string>

template<class T>
struct Node
{
	T Data;
	Node<T>* Next;
};

template<class T>
class List
{
public:
	List();
	~List();

	int GetSize() const;  // not modify return value

	Node<T>* CreateNode(T data);
	Node<T>* FindNodeAt(int pos);
	void AddNode(Node<T>* node);
	void RemoveNode(Node<T>* previous, Node<T>* current);
	void Display();

private:
	void freeNode(Node<T>* node);

private:
	Node<T>* mHead;
	Node<T>* mTail;
	int mSize;           // size of List
};

template<class T>
List<T>::List() : mHead{nullptr}, mTail{nullptr}, mSize{0} 
{
}

template<class T>
List<T>::~List()
{
	Node<T>* current = nullptr;
	Node<T>* next = mHead;

	while(next)   // while(next != nullptr)
	{
		current = next;
		next = next->Next;

		freeNode(current);
	}
}

template<class T>
int List<T>::GetSize() const
{
	return mSize;
}

template<class T>
Node<T>* List<T>::CreateNode(T data)
{
	return new Node<T>{ data, nullptr };
}

template<class T>
Node<T>* List<T>::FindNodeAt(int pos)
{
	Node<T>* node = mHead;

	for(int i = 1; i < pos; i++)
	{
		node = node->Next;
	}

	return node;
}

template<class T>
void List<T>::AddNode(Node<T>* node)
{
	if(mHead)
	{
		mTail->Next = node;
	}
	else
	{
		mHead = node;
	}

	mTail = node;
	mSize++;
}

template<class T>
void List<T>::RemoveNode(Node<T>* previous, Node<T>* current)
{
/*
	switch(current)
	{
		case this->mHead:             // error: case only accepts constants known at compile time
			mHead = mHead->Next;
			break;

		case this->mTail:
			mTail = previous;
			mTail->Next = nullptr;
			break;

		default:
			previous->Next = current->Next;
			break;
	}
*/
	/*
	std::cout << "previous: " << previous;
	std::cout << "\ncurrent: " << current;
	std::cout << "\nmHead: " << mHead;
	std::cout << "\nmTail: " << mTail;
	std::cout << '\n';
	*/

	if(current == mHead)
	{
		mHead = mHead->Next;
	}
	else if(current == mTail)
	{
		mTail = previous;
		mTail->Next = nullptr;
	}
	else
	{
		previous->Next = current->Next;
	}

	freeNode(current);
	mSize--;
}

template<class T>
void List<T>::Display()
{
	Node<T>* node = mHead;
	
	while(node)
	{
		std::cout << node->Data << ' ';
		node = node->Next;
	}

	std::cout << "\nHead: " << mHead->Data << " Head->Next: " << mHead->Next->Data;
	std::cout << "\nTail: " << mTail->Data << " Tail->Next: " << mTail->Next;
	std::cout << "\nSize: " << mSize;
	std::cout << '\n';
}

template<class T>
void List<T>::freeNode(Node<T>* node)
{
	delete node;
}

int main()
{
	List<int> list{};
	List<std::string> list2{};
	
	Node<int>* node = nullptr;
	Node<std::string>* node2 = nullptr;

	for(int i = 0; i < 5; i++)
	{
		node = list.CreateNode(i);
		list.AddNode(node);

		node2 = list2.CreateNode("Str" + std::to_string(i));
		list2.AddNode(node2);
	}

	std::cout << "\n------------------List<int>------------------\n";
	list.Display();

	std::cout << "\nCall CreateNode(3) && AddNode(node)\n";
	node = list.CreateNode(3);
	list.AddNode(node);
	list.Display();

	std::cout << "\nCall FindNodeAt(1) && FindNodeAt(2) && RemoveNode(previous, current)\n";
	Node<int>* previous = list.FindNodeAt(1);
	Node<int>* current = list.FindNodeAt(2);
	list.RemoveNode(previous, current);
	list.Display();

	std::cout << "\nCall FindNodeAt(1) && FindNodeAt(1) && RemoveNode(previous, current)\n";
	previous = list.FindNodeAt(1);
	current = list.FindNodeAt(1);
	list.RemoveNode(previous, current);
	list.Display();

	std::cout << "\n------------------list<string>---------------\n";
	std::cout << "\nCall CreateNode(\"apple\") && AddNode(node)\n";
	node2 = list2.CreateNode("apple");
	list2.AddNode(node2);
	list2.Display();

	std::cout << "\nCall FindNodeAt(1) && FindNodeAt(2) && RemoveNode(previous, current)\n";
	Node<std::string>* previous2 = list2.FindNodeAt(1);
	Node<std::string>* current2 = list2.FindNodeAt(2);
	list2.RemoveNode(previous2, current2);
	list2.Display();

	std::cout << "\nCall FindNodeAt(1) && FindNodeAt(1) && RemoveNode(previous, current)\n";
	previous2 = list2.FindNodeAt(1);
	current2 = list2.FindNodeAt(1);
	list2.RemoveNode(previous2, current2);
	list2.Display();
}
