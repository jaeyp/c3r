#include <iostream>
#include <string>

template<typename T>
struct Node
{
	T Data;
	Node<T>* Previous;
	Node<T>* Next;
};

template<typename T>
class List
{
public:
	List();
	~List();

	int GetSize() const;

	Node<T>* CreateNode(T data);
	Node<T>* FindNodeAt(int pos);
	void AddNode(Node<T>* node);
	void InsertNode(Node<T>* current, Node<T>* created);
	void RemoveNode(Node<T>* node);
	void Display();

private:
	void freeNode(Node<T>* node);
private:
	Node<T>* mHead;
	Node<T>* mTail;
	int mSize;
};

template<class T>
List<T>::List() : mHead{nullptr}, mTail{nullptr}, mSize{0}
{
}

template<class T>
List<T>::~List()
{
	Node<T>* node = nullptr;

	while(mHead)   // while(mHead != nullptr)
	{
		node = mHead;
		mHead = mHead->Next;

		freeNode(node);
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
	return new Node<T>{ data, nullptr, nullptr };
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
	if(mHead)   // if(mHead != nullptr)
	{
		mTail->Next = node;
		node->Previous = mTail;
	}
	else
	{
		mHead = node;
	}

	mTail = node;
	mSize++;
}

template<class T>
void List<T>::InsertNode(Node<T>* current, Node<T>* created)
{
	if(current == mHead)
	{
		created->Next = current;
		current->Previous = created;
		mHead = created;
	}
	else if(current == mTail)
	{
		AddNode(created);
	}
	else
	{
		current->Previous->Next = created;
		created->Previous = current->Previous;
		created->Next = current;
		current->Previous = created;
	}

	mSize++;
}

template<class T>
void List<T>::RemoveNode(Node<T>* node)
{
	if(node == mHead)
	{
		mHead = mHead->Next;
		mHead->Previous = nullptr;
	}
	else if(node == mTail)
	{
		mTail = mTail->Previous;
		mTail->Next = nullptr;
	}
	else
	{
		node->Previous->Next = node->Next;
		node->Next->Previous = node->Previous;
	}

	freeNode(node);
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

	std::cout << "\nHead: " << mHead->Data << " Head->Previous: " << mHead->Previous << " Head->Next: " << mHead->Next->Data;
	std::cout << "\nTail: " << mTail->Data << " Tail->Previous: " << mTail->Previous->Data << " Tail->Next: " << mTail->Next;
	std::cout << "\nSize: " << GetSize();
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

	std::cout << "\n-----------------List<int>---------------\n";
	list.Display();
    
	std::cout << "\nCall FindNodeAt(1) && RemoveNode(node)\n";
	node = list.FindNodeAt(1);
	list.RemoveNode(node);	
	list.Display();

	std::cout << "\nCall FindNodeAt(3) && CreateNode(9) && InsertNode(current, node)\n";
	node = list.CreateNode(9);
	Node<int>* current = list.FindNodeAt(3);
	list.InsertNode(current, node);
	list.Display();
 
	std::cout << "\nCall FindNodeAt(4) && RemoveNode(node)\n";
	node = list.FindNodeAt(4);
	list.RemoveNode(node);	
	list.Display();
 
	std::cout << "\nCall CreateNode(7) && AddNode(node)\n";
	node = list.CreateNode(7);
	list.AddNode(node);
	list.Display();

	std::cout << "\n-----------------List<string>-------------\n";
	list2.Display();

	std::cout << "\nCall FindNodeAt(1) && RemoveNode(node)\n";
	node2 = list2.FindNodeAt(1);
	list2.RemoveNode(node2);	
	list2.Display();

	std::cout << "\nCall FindNodeAt(3) && CreateNode(\"apple\") && InsertNode(current, node)\n";
	node2 = list2.CreateNode("apple");
	Node<std::string>* current2 = list2.FindNodeAt(3);
	list2.InsertNode(current2, node2);
	list2.Display();
 
	std::cout << "\nCall FindNodeAt(4) && RemoveNode(node)\n";
	node2 = list2.FindNodeAt(4);
	list2.RemoveNode(node2);	
	list2.Display();
 
	std::cout << "\nCall CreateNode(\"banana\") && AddNode(node)\n";
	node2 = list2.CreateNode("banana");
	list2.AddNode(node2);
	list2.Display();
	
}
