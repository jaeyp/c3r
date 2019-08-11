#include <iostream>

/**
 *    Class Definition: TNode
 */
template <typename T> class TNode{
public:
	// Class Members
	T data;
	TNode<T>* next;
	// Constructor
	TNode(T data);
	// Destructor
	~TNode();
};

/** 
 *    Constructor
 */
template <typename T> TNode<T>::TNode(T data) {
	this->data = data;
	this->next = nullptr;
}

/**
 *     Destructor
 */
template <typename T> TNode<T>::~TNode() {
}

/**
 *    Class Definition: TSLList (Template Singly Linked List)
 */
template <typename T> class TSLList{
private:
    TNode<T>* head;
	int size;
	constexpr TNode<T>* createNode(T data);
	constexpr void destroyNode(TNode<T>* node);
public:
	// Constructor
	TSLList();
	// Destructor
	~TSLList();
	// Class Methods
    void insert(T data); //tail
	void insertBefore(T data, int index);
	void insertAfter(T data, int index);
	void remove(); //tail
	void remove(T data);
	void removeAt(int index);
	void removeAll();
	constexpr bool isEmpty();
	constexpr int getSize();
	T getData(int index);
	void traverse();
};

// Constructor
template <typename T> TSLList<T>::TSLList() : head{nullptr}, size{0} {
}

// Destructor
template <typename T> TSLList<T>::~TSLList() {
}

// Class TSLList Private Methods
template <typename T> constexpr TNode<T>* TSLList<T>::createNode(T data) {
	size++;
	return new TNode<T>(data);
}

template <typename T> constexpr void TSLList<T>::destroyNode(TNode<T>* node) {
	if(node != nullptr) {
		free(node);
		node = nullptr;
		size--;
	}
}

// Class TSLList Public Methods
template <typename T> void TSLList<T>::insert(T data) {
    TNode<T>* node = createNode(data);
	
	if(head == nullptr) {
	    head = node;	
 	} else {
		TNode<T> *tail = head;
		while(tail->next != nullptr) {
			tail = tail->next;
		}
		tail->next = node;
 	}
}

template <typename T> void TSLList<T>::insertBefore(T data, int index) {
	if(index < 0 || index > size)
		return;

	TNode<T>* node = createNode(data);
	
	if(index == 0) {
		node->next = head->next;
		head = node;
	} else {
        TNode<T>* cur = head;
	    while(--index) {
			cur = cur->next;
		}
		node->next = cur->next;
		cur->next = node;
	}
}

template <typename T> void TSLList<T>::insertAfter(T data, int index) {
	if(index < 0 || index > size)
		return;
	
	TNode<T>* node = createNode(data);
	
	if(index == 0) {
		node->next = head->next;
		head = node;
	} else {
        TNode<T>* cur = head;
	    while(index--) {
			cur = cur->next;
		}
		node->next = cur->next;
		cur->next = node;
	}
}

template <typename T> void TSLList<T>::remove() {
	if(head == nullptr)
		return;

	if(head->next == nullptr) {
		destroyNode(head);
		head = nullptr;
	} else {
    	TNode<T>* cur = head;
		while(cur->next) {
			if(cur->next->next == nullptr) {
				destroyNode(cur->next);
				cur->next = nullptr;
				break;
			}
			cur = cur->next;
		}
	}
}

template <typename T> void TSLList<T>::remove(T data) {
	TNode<T>* cur = head;
	
	if(cur->data == data) {
		head = head->next;
		destroyNode(cur);
	}
	while(cur->next) {
		if(cur->next->data == data) {
			TNode<T>* del = cur->next;
			cur->next = cur->next->next;
			destroyNode(del);
		} else {
    		cur = cur->next;
		}
	}
}

template <typename T> void TSLList<T>::removeAll() {
	while(head) {
		TNode<T>* cur = head;
		head = head->next;
		destroyNode(cur);
	}
}

template <typename T> constexpr bool TSLList<T>::isEmpty() {
	return !head;
}

template <typename T> constexpr int TSLList<T>::getSize() {
	return size;
}

template <typename T> T TSLList<T>::getData(int index) {
	if(index < 0 || index >= size)
		return T{};
	
	TNode<T>* cur = head;
	while(index--) {
		cur = cur->next;
	}
	return cur->data;
}

template <typename T> void TSLList<T>::traverse() {
	TNode<T>* cur = head;

	while(cur != nullptr) {
		std::cout << cur->data << ' ';
		cur = cur->next;
	}
	std::cout << std::endl;
}

int main(int argc, char** argv) {
	TSLList<int> tsll{};
	tsll.insert(3);
	tsll.insert(1);
	tsll.insert(3);
	tsll.insert(2);
	tsll.insert(3);
	tsll.insert(3);
	tsll.insertAfter(4, 1);
	tsll.insertBefore(5, 1);
	tsll.traverse();
	if(tsll.isEmpty()) std::cout << "list is empty - size:" << tsll.getSize() << std::endl;
	else std::cout << "list is NOT empty - size:" << tsll.getSize() << std::endl;

	tsll.remove(3);
	tsll.remove();
	tsll.remove();
	tsll.traverse();
	if(tsll.isEmpty()) std::cout << "list is empty - size:" << tsll.getSize() << std::endl;
	else std::cout << "list is NOT empty - size:" << tsll.getSize() << std::endl;
	
	tsll.removeAll();
	tsll.traverse();
	if(tsll.isEmpty()) std::cout << "list is empty - size:" << tsll.getSize() << std::endl;
	else std::cout << "list is NOT empty - size:" << tsll.getSize() << std::endl;
	
	TSLList<std::string> tsll2{};
	std::cout << "[0]:" << tsll2.getData(0) << " [1]:" << tsll2.getData(1) << " [2]:" << tsll2.getData(2) << std::endl;
	std::string str4{"four"};
	tsll2.insert("one");
	tsll2.insert("two");
	tsll2.insert("three");
	tsll2.insert(str4);
	tsll2.traverse();
	std::cout << "[0]:" << tsll2.getData(0) << " [1]:" << tsll2.getData(1) << " [2]:" << tsll2.getData(2) << std::endl;
}
