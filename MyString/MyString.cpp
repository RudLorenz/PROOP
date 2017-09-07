//
// Created by RudLorenz on 05/09/2017.
//

#include <iostream>
#include <cstring>
#include "MyString.h"

MyString::MyString(): length(0), body(nullptr)
{
    std::cout << "MyString() constructor called" << std::endl;
}

MyString::MyString(char *string): length(strlen(string)), body(new char[length+1])
{
    std::cout << "MyString(string) constructor called" << std::endl;

    strcpy(body, string);
}

MyString::MyString(const MyString &obj): length(obj.length), body(new char[length+1])
{
    std::cout << "MyString() copy constructor called" << std::endl;

    strcpy(body, obj.body);
}

MyString::~MyString()
{
    std::cout << "MyString() destructor called" << std::endl;
    delete [] body;
}

int MyString::GetLength() const {
    return length;
}

char *MyString::GetBody() const
{
    if (nullptr == body) {
        return "null";
    }
    return body;
}

MyString &MyString::operator=(const MyString &rhs)
{
    if (this != &rhs)
    {
        delete[] body;
		body = nullptr;

        length = rhs.length;

		if (nullptr != rhs.body)
		{
			body = new char[rhs.length + 1];
			strcpy(body, rhs.body);
		}
    }

    return *this;
}

MyString &MyString::operator+=(const MyString &rhs)
{
    if (nullptr != rhs.body)
    {
        char *tmp = new char[length + rhs.length + 1];

        if (body != nullptr) {
            strcpy(tmp, body);
        }

        strcat(tmp, rhs.body);

        delete[] body;
        body = nullptr;

        body = new char[length + rhs.length + 1];
        strcpy(body, tmp);

        length += rhs.length;

        delete[] tmp;
    }

    return *this;
}
