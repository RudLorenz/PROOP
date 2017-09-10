#include <iostream>
#include "MyList.h"

int main()
{
    MyList<int> listy;

    listy.PushFront(1);
    listy.PushFront(2);
    listy.PushFront(3);
    listy.PushFront(4);
    listy.PushFront(5);

    listy.PrintList();

    listy.PopFront();
    listy.PrintList();

    listy.PopFront();
    listy.PrintList();

    listy.Push(6);
    listy.Push(7);

    listy.PrintList();

    listy.PopBack();

    listy.PrintList();

    MyList<int> wocka;

    wocka.Push(1);
    wocka.Push(2);

    wocka.PrintList();
    wocka.PopBack();
    wocka.PrintList();
    wocka.PopBack();
    wocka.PrintList();

    std::cout << "---------------" << std::endl;
    listy.PrintList();
    std::cout << "size = " << listy.GetSize() << std::endl;

    auto it = listy.begin();

    std::cout << *++it << " " << *it++ << " " << *it << std::endl;


    return 0;
}