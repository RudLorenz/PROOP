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
    MyList<T>() {};
    MyList<T>(const MyList& rhs) = delete;
    ~MyList();

    MyList<T>& operator=(const MyList<T>&) = delete;

    void Push(const T& value);
    void PushFront(const T& value);

    void PrintList() const;

    void PopFront();
    void PopBack();

private:
	struct Node;
    Node * head = nullptr;
};

template <typename T>
struct MyList<T>::Node
{
    T value;
    Node* next;

    Node(const T& value) :value(value), next() {};
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
    std::cout << "NULL" << std::endl;
}

template <typename T>
void MyList<T>::PopFront()
{
    if (head)
    {
        auto tmp = head->next;
        delete head;
        head = tmp;
    }
}

template <typename T>
void MyList<T>::Push(const T &value)
{
    if (nullptr == head)
    {
        head = new Node(value);
        return;
    }

    auto tmp = head;

    while (tmp->next) {
        tmp = tmp->next;
    }

    tmp->next = new Node(value);
}

template <typename T>
void MyList<T>::PopBack()
{
	if (head)
	{
        if (head->next)
        {
            auto tmp1 = head, tmp2 = head->next;

            while (tmp2->next) {
                tmp1 = tmp1->next;
                tmp2 = tmp2->next;
            }

            delete tmp2;
            tmp2 = nullptr; //just to make sure

            tmp1->next = nullptr;
        }
        else
        {
            delete head;
            head = nullptr;
        }
    }
}

#endif //MYLIST_MYLIST_H