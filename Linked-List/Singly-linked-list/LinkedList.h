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
        if (isEmpty())
        {
            addFirst(element);
        }
        else
        {
            Node<T> *temp = head;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = new Node<T>(element);
            size++;
        }
    }

    T removeFirst()
    {
        if (isEmpty())
        {
            throw "List is empty";
        }
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

    T getFirst() const
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
        while (!isEmpty())
        {
            removeFirst();
        }
    }

    T getLast() const
    {
        if (isEmpty()) throw "List is empty";
        Node<T> *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        return temp->element;
    }

    T get(int index) const
    {
        if (index < 0 || index >= size) throw "Index out of bounds";
        Node<T> *temp = head;
        for (int i = 0; i < index; i++)
        {
            temp = temp->next;
        }
        return temp->element;
    }

    T removeAtIndex(int index) {
		T removedElement;
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
};

#endif
