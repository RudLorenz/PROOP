#include <iostream>
#include "MyList.h"

int main()
{
    MyList<int> listy;

    listy.PushFront(1);
    listy.PushFront(2);
    listy.PushFront(3);
    listy.PushFront(4);

    listy.PrintList();

    listy.EraseFront();
    listy.PrintList();

    listy.EraseFront();
    listy.PrintList();

    return 0;
}