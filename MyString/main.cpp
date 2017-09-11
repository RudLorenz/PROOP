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
    MyString str4("Hello ");
    MyString str5("world");

    std::cout << str1.GetLength() << " : " << str1.GetBody() << std::endl;
    std::cout << str2.GetLength() << " : " << str2.GetBody() << std::endl;
    std::cout << str3.GetLength() << " : " << str3.GetBody() << std::endl;

    MyString str6;
    str6 = str4 + str5;

    std::cout << str6.GetLength() << " : " << str6.GetBody() << std::endl;

    for (int i = str6.GetLength()-1; i >= 0; --i) {
        std::cout << str6[i];
    }
    std::cout << std::endl;

    str6[5] = '5';
    str6[6] = '6';

    for (int i = str6.GetLength()-1; i >= 0; --i) {
        std::cout << str6[i];
    }
    std::cout << std::endl;

    return 0;
}