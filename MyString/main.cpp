#include <iostream>
#include <cstring>
#include "MyString.h"

int main()
{
    auto* somestr = new char[11];
    strcpy(somestr, "I'msomestr");

    MyString str1;
    MyString str2(somestr);
    MyString str3(str2);

    std::cout << str1.GetLength() << " : " << str1.GetBody() << std::endl;
    std::cout << str2.GetLength() << " : " << str2.GetBody() << std::endl;
    std::cout << str3.GetLength() << " : " << str3.GetBody() << std::endl;

    str3 = str2;

    std::cout << str3.GetLength() << " : " << str3.GetBody() << std::endl;

    return 0;
}