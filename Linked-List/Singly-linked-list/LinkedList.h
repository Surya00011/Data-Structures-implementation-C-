#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

template <typename T>
struct Node
{
    T element;
    Node *next;
    Node(T val) : element(val), next(nullptr) {}
};

template <typename T>
class LinkedList
{
    Node<T> *head;
    int size;

public:
    LinkedList() : head(nullptr), size(0) {}

    ~LinkedList()
    {
        while (head != nullptr)
        {
            Node<T> *temp = head;
            head = head->next;
            delete temp;
        }
    }

    bool isEmpty() const
    {
        return head == nullptr;
    }

    void addFirst(T element)
    {
        Node<T> *newNode = new Node<T>(element);
        newNode->next = head;
        head = newNode;
        size++;
    }

    void add(T element)
    {
        if (isEmpty()) addFirst(element);
        else
        {
            Node<T> *temp = head;
            while (temp->next != nullptr) temp = temp->next;
            temp->next = new Node<T>(element);
            size++;
        }
    }

    T removeFirst()
    {
        if (isEmpty()) throw "List is empty";
        Node<T> *temp = head;
        T removedElement = head->element;
        head = head->next;
        delete temp;
        size--;
        return removedElement;
    }

    void printList() const
    {
        Node<T> *temp = head;
        while (temp != nullptr)
        {
            std::cout << temp->element;
            if (temp->next != nullptr)
            {
                std::cout << "->";
            }
            temp = temp->next;
        }
        std::cout << "->nullptr\n";
    }
    
    void reverse(){
        if(isEmpty()) throw "List is empty";
        Node<T>* prevNode = nullptr;
        Node<T>* currentNode = head;
        while(currentNode != nullptr){
            Node<T>* oldCurrent = currentNode->next;
            currentNode->next = prevNode;
            prevNode = currentNode;
            currentNode = oldCurrent;
        }
        head = prevNode;
    }

    friend std::ostream& operator<<(std::ostream& os, const LinkedList<T>& list) {
        Node<T>* temp = list.head;
        while (temp != nullptr) {
            os << temp->element;
            if (temp->next != nullptr) {
                os << "->";
            }
            temp = temp->next;
        }
        os << "->nullptr";
        return os;
    }

    void addAtIndex(int index,T element)
	{
	    if(index<0 || index>size-1) throw std::invalid_argument("Index out of Range");
	    if(index==0) {addFirst(element);}
	    else{
	        Node<T>* prevNode = head;
	        for(int i=0;i<index-1;i++){
	            prevNode=prevNode->next;
	        }
	        Node<T>* newNode = new Node(element);
	        newNode->next = prevNode->next;
	        prevNode->next=newNode;
	        size++;
	    }
	}

    const T& getFirst() const
    {
        if (isEmpty()) throw "List is empty";
        return head->element;
    }

    int getSize() const
    {
        return size;
    }   

    void clear()
    {
        while (!isEmpty()) removeFirst();
    }

    const T& getLast() const
    {
        if (isEmpty()) throw "List is empty";
        Node<T> *temp = head;
        while (temp->next != nullptr) temp = temp->next;
        return temp->element;
    }

    const T& get(int index) const
    {
        if (index < 0 || index >= size) throw std::invalid_argument("Index out of Range");
        Node<T> *temp = head;
        for (int i = 0; i < index; i++) temp = temp->next;
        return temp->element;
    }

    T removeAtIndex(int index) {
		T removedElement;
        if(index<0 || index>=size) throw std::invalid_argument("Index out of Range");
		if(isEmpty()) throw "List is empty";
		if(size==1) {
			return removeFirst();
		} else {
			Node<T>* temp = head;
			for(int i=0; i<index-1; i++) {
				temp=temp->next;
			}
			Node<T>* deletedNode = temp->next;
			removedElement= deletedNode->element;
			temp->next=deletedNode->next;
			delete deletedNode;
			size--;
			return removedElement;
		}
	}
    T removeByValue(const T& element)
	{
		if (isEmpty())
			throw std::runtime_error("List is empty");

		if (head->element == element) {
			return removeFirst();
		}

		Node<T> *prevNode = head;
		while (prevNode->next != nullptr && prevNode->next->element != element) {
			prevNode = prevNode->next;
		}
		if (prevNode->next == nullptr) {
			throw std::invalid_argument("Element not found in list");
		}

		Node<T> *deletedNode = prevNode->next;
		T removedElement = deletedNode->element;
		prevNode->next = deletedNode->next;
		delete deletedNode;
		size--;
		return removedElement;
	}
    
    int indexOf(const T& element) const
	{
		Node<T>* current = head;
		int index = 0;

		while (current != nullptr) {
			if (current->element == element) {
				return index;  
			}
			current = current->next;
			index++;
		}

		return -1; 
	}

    bool contains(const T& element) const
    {
        return indexOf(element) != -1;
    }
};

#endif
