#include <iostream>

/**
 *    Class Definition: TNode
 */
template <typename T> class TNode{
public:
	// Class Members
	T data;
	TNode<T>* next;
	TNode<T>* prev;
	// Constructor
	TNode(T data);
	// Destructor
	~TNode();
};

/** 
 *    Constructor
 */
template <typename T> TNode<T>::TNode(T data) : data{data}, next{nullptr}, prev{nullptr} {
}

/**
 *     Destructor
 */
template <typename T> TNode<T>::~TNode() {
}

/**
 *    Class Definition: TDLList (Template Singly Linked List)
 */
template <typename T> class TDLList{
private:
	TNode<T>* head;
	TNode<T>* tail;
	int size;
	constexpr TNode<T>* createNode(T data);
	constexpr void destroyNode(TNode<T>* node);
	TNode<T>* getNodeAt(int index);
public:
	// Constructor
	TDLList();
	// Destructor
	~TDLList();
	// Class Methods
	void insert(T data); //tail
	void insertBefore(T data, int index);
	void insertAfter(T data, int index);
	void remove(T data);
	void removeAt(int index);
	void removeAll();
	constexpr bool isEmpty();
	constexpr int getSize();
	T getData(int index);
	void traverse();
	void rtraverse();
};

// Constructor
template <typename T> TDLList<T>::TDLList() : head{nullptr}, tail{nullptr}, size{0} {
}

// Destructor
template <typename T> TDLList<T>::~TDLList() {
	removeAll();
}

// Class TDLList Private Methods
template <typename T> constexpr TNode<T>* TDLList<T>::createNode(T data) {
	size++;
	return new TNode<T>(data);
}

template <typename T> constexpr void TDLList<T>::destroyNode(TNode<T>* node) {
	if(node != nullptr) {
		delete node;
		node = nullptr;
		size--;
	}
}

// Class TDLList Public Methods
template <typename T> void TDLList<T>::insert(T data) {
    TNode<T>* node = createNode(data);

	if(head == nullptr) {
		head = tail = node;
	} else {
		tail->next = node;
		node->prev = tail;
		tail = node;
	}
}

template <typename T> TNode<T>* TDLList<T>::getNodeAt(int index) {
	TNode<T>* cur = head;

	if(index < 0 || index >= size)
		return nullptr;
	if(index == 0)
	    return cur;
			
	while(index--) {
		cur = cur->next;
	}
	return cur;
}

template <typename T> void TDLList<T>::insertBefore(T data, int index) {
	TNode<T>* node = createNode(data);
	TNode<T>* cur = getNodeAt(index);

	if(cur == nullptr) return;
	if(cur == head) {
		head->prev = node;
		node->next = head;
		head = node;
	} else {
		cur->prev->next = node;
		node->prev = cur->prev;
		cur->prev = node;
		node->next = cur;
	}
}

template <typename T> void TDLList<T>::insertAfter(T data, int index) {
	TNode<T>* node = createNode(data);
	TNode<T>* cur = getNodeAt(index);

	if(cur == nullptr) return;
	if(cur == tail) {
		tail->next = node;
		node->prev = tail;
		tail = node;
	} else {
		cur->next->prev = node;
		node->next = cur->next;
		cur->next = node;
		node->prev = cur;
	}
}

template <typename T> void TDLList<T>::remove(T data) {
	TNode<T>* cur = head;
	TNode<T>* del = cur;

	while(del != nullptr) {
		if (cur->data == data) {
			if (cur == head) {
				head = head->next;
				head->prev = nullptr;
			} else if (cur == tail) {
				tail = tail->prev;
				tail->next = nullptr;
			} else {
				cur->next->prev = cur->prev;
				cur->prev->next = cur->next;
			}
			destroyNode(del);
		}
		del = cur = cur->next;
	}
}

template <typename T> void TDLList<T>::removeAt(int index) {
	TNode<T>* del = getNodeAt(index);

	if (del == nullptr) return;
	if (del == head) {
		head = head->next;
		head->prev = nullptr;
	} else if (del == tail) {
		tail = tail->prev;
		tail->next = nullptr;
	} else {
		del->next->prev = del->prev;
		del->prev->next = del->next;
	}
	destroyNode(del);
}

template <typename T> void TDLList<T>::removeAll() {
	TNode<T>* cur = head;
	while(cur) {
		head = cur->next;
		destroyNode(cur);
		cur = head;
	}
	head = tail = nullptr;
}

template <typename T> constexpr bool TDLList<T>::isEmpty() {
	return !head;
}

template <typename T> constexpr int TDLList<T>::getSize() {
	return size;
}

template <typename T> T TDLList<T>::getData(int index) {
	if(index < 0 || index >= size)
		return T{};
	
	TNode<T>* cur = head;
	while(index--) {
		cur = cur->next;
	}
	return cur->data;
}

template <typename T> void TDLList<T>::traverse() {
	TNode<T>* cur = head;

	while(cur != nullptr) {
		std::cout << cur->data << ' ';
		cur = cur->next;
	}
	std::cout << std::endl;
}
template <typename T> void TDLList<T>::rtraverse() {
	TNode<T>* cur = tail;

	while(cur != nullptr) {
		std::cout << cur->data << ' ';
		cur = cur->prev;
	}
	std::cout << "(reverse)" << std::endl;
}

int main(int argc, char** argv) {
	TDLList<int> tdll{};
	tdll.insert(1);
	tdll.insert(2);
	tdll.insert(3);
	tdll.insert(4);
	tdll.insert(5);
	tdll.insert(6);
	tdll.insertAfter(7, 0);
	tdll.insertBefore(8, 0);
	tdll.traverse();
	tdll.rtraverse();
	tdll.removeAt(0);
	tdll.traverse();
	tdll.rtraverse();
	tdll.removeAt(tdll.getSize()-1);
	tdll.traverse();
	tdll.rtraverse();
	tdll.removeAt(1);
	tdll.traverse();
	tdll.rtraverse();
	tdll.remove(3);
	tdll.traverse();
	tdll.rtraverse();
	if(tdll.isEmpty()) std::cout << "list is empty - size:" << tdll.getSize() << std::endl;
	else std::cout << "list is NOT empty - size:" << tdll.getSize() << std::endl;
	tdll.removeAll();
	tdll.traverse();
	tdll.rtraverse();
	if(tdll.isEmpty()) std::cout << "list is empty - size:" << tdll.getSize() << std::endl;
	else std::cout << "list is NOT empty - size:" << tdll.getSize() << std::endl;
	
	TDLList<std::string> tsll2{};
	std::string str4{"four"};
	tsll2.insert("one");
	tsll2.insert("two");
	tsll2.insert("three");
	tsll2.insert(str4);
	tsll2.traverse();
	tsll2.rtraverse();
}
