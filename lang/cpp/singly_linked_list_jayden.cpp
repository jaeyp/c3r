#include <iostream>

struct Node
{
	Node* Next;
	int Data;
};

class List
{
public:
	List();
	~List();

	int GetHead() const;
	int GetTail() const;
	int GetSize() const;  // not modify return value

	void Add(int value);
	void Insert(int index, int value);
	void Remove(int index);
	void Display();

private:
	Node* mHead;
	Node* mTail;
	int mSize;           // size of List
};

List::List() : mHead{nullptr}, mTail{nullptr}, mSize{0} 
{
}

List::~List()
{
	Node* current = nullptr;
	Node* next = mHead;

	while(next)   // while(next != nullptr)
	{
		current = next;
		next = next->Next;

		delete current;
	}
}

int List::GetHead() const
{
	return mHead->Data;
}

int List::GetTail() const
{
	return mTail->Data;
}

int List::GetSize() const
{
	return mSize;
}

void List::Add(int value)
{
	Node* temp = new Node{ nullptr, value };

	if(mHead)    // if(mHead != nullptr)
	{
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
	if(index >= 0 && index <= mSize)
	{
		Node* temp = new Node{ nullptr, value };

		if(index == 0)            // if inserting to the front
		{
			temp->Next = mHead;
			mHead = temp;
		}
		else if(index == mSize)   // if inserting to the end
		{
			mTail->Next = temp;
			mTail = temp;
		}
		else
		{
			Node* previous = nullptr;
			Node* current = mHead;
		
			for(int i = 0; i < index; i++)
			{
				previous = current;
				current = current->Next;
			}

			previous->Next = temp;
			temp->Next = current;
		}

		mSize++;
	}
}

void List::Remove(int index)
{
	if(index >= 0 && index < mSize)
	{
		Node* current = mHead;

		if(index == 0)               // if removing head
		{
			mHead = current->Next;
		}
		else
		{	
			Node* previous = nullptr;
			
			for(int i = 0; i < index; i++)
			{
				previous = current;
				current = current->Next;
			}
	
			previous->Next = current->Next;
		
			if(index == mSize - 1)  // if removing tail
			{
				mTail = previous;
			}
		}

		delete current;
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

	std::cout << "\nHead: " << mHead->Data << " Head->Next: " << mHead->Next->Data;
	std::cout << "\nTail: " << mTail->Data << " Tail->Next: " << mTail->Next;
	std::cout << "\nSize: " << mSize;
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
