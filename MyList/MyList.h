//
// Created by rudlo on 07/09/2017.
//

#ifndef MYLIST_MYLIST_H
#define MYLIST_MYLIST_H

#include <iostream>

template <typename T>
class MyList
{
public:
    ~MyList();

    void PushFront(const T& value);
    void PrintList() const;
    void EraseFront();

private:
	struct Node
	{
		T value;
		Node* next;
		
		Node(const T& value) :value(value), next() {};
	};
    Node * head = nullptr;
};

template <typename T>
MyList<T>::~MyList()
{
    auto tmp = head;

    while (head)
    {
        head = head->next;
        delete tmp;
        tmp = head;
    }

	std::cout << "MyList destructor" << std::endl;
}

template <typename T>
void MyList<T>::PushFront(const T &value)
{
    auto tmp = new Node(value);
    tmp->next = head;
    head = tmp;
}

template <typename T>
void MyList<T>::PrintList() const
{
    auto tmp = head;

    while(tmp)
    {
        std::cout << tmp->value << " -> ";
        tmp = tmp->next;
    }
    std::cout << std::endl;
}

template <typename T>
void MyList<T>::EraseFront()
{
    if (head)
    {
        auto tmp = head->next;
        delete head;
        head = tmp;
    }
}

#endif //MYLIST_MYLIST_H