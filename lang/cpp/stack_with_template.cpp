#include <iostream>
#include <stdexcept>


template <class T> class TStack{

public:

//####################################
//          Constructor.
//####################################

TStack();

//####################################
//          Destructor.
//####################################

~TStack();

//####################################
//          Class methods.
//####################################

/**
 *  Adds an item to the stack.
 *  <b>Notes:</b><br>
 *  &nbsp; N/A <br>
 *  ------<br>
 *  <b>Arguments:</b><br>
 *  &nbsp; template<class T>: the type of the class.<br>
 *  ------<br>
 *  <b>Return:</b><br>
 *  &nbsp; N/A<br>
 *  ------<br>
 *  <b>Throws</b><br>
 *  &nbsp; N/A<br>
 */
void push(T elem);


/**
 *  Removes the data item at the beginning of the stack.
 *  <b>Notes:</b><br>
 *  &nbsp; Caller is responsible for releasing objects that are popped from the stack.<br>
 *  ------<br>
 *  <b>Arguments:</b><br>
 *  &nbsp; N/A <br>
 *  ------<br>
 *  <b>Return:</b><br>
 *  &nbsp;dataType T: the type<br>
 *  ------<br>
 *  <b>Throws</b><br>
 *  &nbsp; out_of_range exception for an empty stack.<br>
 */
T pop();

/**
 *  The size of the stack.
 *  <b>Notes:</b><br>
 *  &nbsp;N/A<br>
 *  ------<br>
 *  <b>Arguments:</b><br>
 *  &nbsp; N/A <br>
 *  ------<br>
 *  <b>Return:</b><br>
 *  &nbsp;int : The size of the stack.<br>
 *  ------<br>
 *  <b>Throws</b><br>
 *  &nbsp; N/A<br>
 */
int getSize();

/**
 *  Reports if the stack is empty.
 *  <b>Notes:</b><br>
 *  &nbsp;N/A<br>
 *  ------<br>
 *  <b>Arguments:</b><br>
 *  &nbsp; N/A <br>
 *  ------<br>
 *  <b>Return:</b><br>
 *  &nbsp;int : Whether the stack is empty of not.<br>
 *  ------<br>
 *  <b>Throws</b><br>
 *  &nbsp; N/A<br>
 */
bool isEmpty();

//####################################
//      End - Class methods.
//####################################

private:


/**
 *  A linked list node struct.
 *  <b>Notes:</b><br>
 *  &nbsp;N/A<br>
 **/
struct Node{

    T data_;
    Node* next_;

};


/**
 *  The size of the stack.
 *  <b>Notes:</b><br>
 *  &nbsp;N/A<br>
 **/
int size_;

/**
 *  The head of the linked list(stack).
 *  <b>Notes:</b><br>
 *  &nbsp;N/A<br>
 **/
Node *head_;

};

//####################################
//          Constructor.
//####################################
template <class T> TStack <T>::TStack(){

    this->size_ = 0;
    this->head_ = NULL;
}

//####################################
//          Destructor.
//####################################
template <class T> TStack <T>::~TStack(){

    // Nothing to tear down.
}

//####################################
//       Class TStack Methods.
//####################################
template<class T> void TStack< T >::push(T elem){


    Node * newNode = new Node();
    newNode->data_ = elem;
    newNode->next_ = NULL;


    // If the head is NULL just assign it to newNode();
    if(this->head_ == NULL){

        this->head_= newNode;

    }else{

        newNode->next_ = this->head_;
        this->head_ = newNode;
    }

    this->size_ += 1;

}


template<class T> T TStack< T >::pop(){

// Suppress compile error for "Control reaches end
// of statement". We will throw an exception if the
// stack is empty.
#pragma GCC diagnostic ignored "-Wreturn-type"

    try{

        if(this->isEmpty() == false){

            Node *temp = this->head_;
            this->head_ = this->head_->next_;
            this->size_ --;
            return temp->data_;

            // If we just popped the last node, set head to NULL.
            if(this->isEmpty() == true)
                this->head_ = NULL;


        }else{

            throw std::out_of_range("The Stack Is Empty!");
        }

    }catch (const std::out_of_range& e) {

        std::cerr <<e.what() <<std::endl;
    }

}



template<class T> int TStack<T>::getSize(){

    return this->size_;
}


template<class T> bool TStack<T>::isEmpty(){

    if(this->size_ > 0)
        return false;

    return true;

}

//####################################
//      End Class TStack Methods.
//####################################

//####################################
//      End Class TStack.
//####################################


int main(int argc, const char * argv[]) {

    int* one = new int(34);
    int* two = new int(68);
    int* three = new int(72);
    TStack<int*> myStack;
    myStack.push(one);
    myStack.push(two);
    myStack.push(three);

    while(myStack.getSize() > 0){
        int* ans = myStack.pop();
        std::cout<<"Value: "<<*ans<<std::endl;
        delete ans;
    }
    // Throws and catches exception gracefully and logs the stack is empty.
    int* ans = myStack.pop();

	std::string str1("string one");
	std::string str2("string two");
	std::string str3("string three");
	TStack<std::string> myStack2;
	myStack2.push(str1);
	myStack2.push(str2);
	myStack2.push(str3);
	while(myStack2.getSize() > 0){
		std::string ans = myStack2.pop();
        std::cout<<"Value: "<< ans <<std::endl;
    }

    return 0;
}
