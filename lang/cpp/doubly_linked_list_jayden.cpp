#include <iostream>

struct Node
{
	Node* Previous;
	Node* Next;
	int Data;
};

class List
{
public:
	List();
	~List();

	int GetSize() const;

	void Add(int value);
	void Insert(int index, int value);
	void Remove(int index);
	void Display();

private:
	Node* mHead;
	Node* mTail;
	int mSize;
};

List::List() : mHead{nullptr}, mTail{nullptr}, mSize{0}
{
}

List::~List()
{
	Node* temp = nullptr;

	while(mHead)   // while(mHead != nullptr)
	{
		temp = mHead;
		mHead = mHead->Next;
		delete temp;
	}
}

int List::GetSize() const
{
	return mSize;
}

void List::Add(int value)
{
	Node* temp = new Node{ nullptr, nullptr, value };   // initialize
	
	if(mHead)   // if(mHead != nullptr)
	{
		temp->Previous = mTail;
		mTail->Next = temp;
	}
	else
	{
		mHead = temp;
	}

	mTail = temp;
	mSize++;
}

void List::Insert(int index, int value)
{
	Node* temp = new Node{ nullptr, nullptr, value};

	if(index >= 0 && index <= mSize)   // 0 <= index <= mSize
	{
		if(index == 0)                 // if inserting to the front
		{
			temp->Next = mHead;
			mHead->Previous = temp;
			mHead = temp;
		}
		else if(index == mSize)        // if inserting to the end
		{
			temp->Previous = mTail;
			mTail->Next = temp;
			mTail = temp;
		}
		else
		{
			Node* previousNode = nullptr;
			Node* currentNode = mHead;

			for(int i = 0; i < index; i++)
			{
				previousNode = currentNode;
				currentNode = currentNode->Next;
			}

			previousNode->Next = temp;
			temp->Previous = previousNode;
			temp->Next = currentNode;
			currentNode->Previous = temp;
		}

		mSize++;
	}
}

void List::Remove(int index)
{
	if(index >= 0 && index < mSize)   // 0 <= index < mSize
	{
		Node* temp = nullptr;

		if(index == 0)                // if removing head
		{
			temp = mHead;
			mHead = mHead->Next;
			mHead->Previous = nullptr;
		}
		else if(index == mSize - 1)   // if removing tail
		{
			temp = mTail;
			mTail = mTail->Previous;
			mTail->Next = nullptr;
		}
		else
		{
			temp = mHead;

			for(int i = 0; i < index; i++)
			{
				temp = temp->Next;
			}

			temp->Previous->Next = temp->Next;
			temp->Next->Previous = temp->Previous;
		}

		delete temp;
		mSize--;
	}
}

void List::Display()
{
	Node* temp = mHead;

	while(temp)
	{
		std::cout << temp->Data << ' ';
		temp = temp->Next;
	}

	std::cout << "\nHead: " << mHead->Data << " Head->Previous: " << mHead->Previous << " Head->Next: " << mHead->Next->Data;
	std::cout << "\nTail: " << mTail->Data << " Tail->Previous: " << mTail->Previous->Data << " Tail->Next: " << mTail->Next;
	std::cout << "\nSize: " << GetSize();
	std::cout << '\n';
}

int main()
{
	List list{};

	for(int i = 0; i < 5; i++)
	{
		list.Add(i);
	}

	list.Display();
	list.Remove(0);
	list.Insert(0, 7);
    
	std::cout << "\nCall Remove(0) && Insert(0, 7)\n";
	list.Display();
 
	list.Remove(2);
	list.Insert(2, 9);
 
	std::cout << "\nCall Remove(2) && Insert(2, 9)\n";
	list.Display();
 
	list.Remove(4);
	list.Insert(4, 10);

	std::cout << "\nCall Remove(4) && Insert(4, 10)\n";
	list.Display();
 
	list.Remove(3);
	list.Remove(0);
	list.Add(7);
 
	std::cout << "\nCall Remove(3) && Remove(0) && Add(7)\n";
	list.Display();
}
