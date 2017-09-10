//
// Created by RudLorenz on 05/09/2017.
//

#include <iostream>
#include <cstring>
#include "MyString.h"

MyString::MyString(): length_(0), body_(nullptr)
{
    std::cout << "MyString() constructor called" << std::endl;
}

MyString::MyString(char *string): length_(strlen(string)), body_(new char[length_+1])
{
    std::cout << "MyString(string) constructor called" << std::endl;

    strcpy(body_, string);
}

MyString::MyString(const MyString &obj): length_(obj.length_), body_(new char[length_+1])
{
    std::cout << "MyString() copy constructor called" << std::endl;

    strcpy(body_, obj.body_);
}

MyString::~MyString()
{
    std::cout << "MyString() destructor called" << std::endl;
    delete [] body_;
}

int MyString::GetLength() const {
    return length_;
}

char *MyString::GetBody() const
{
    if (nullptr == body_) {
        return "null";
    }
    return body_;
}

MyString &MyString::operator=(const MyString &rhs)
{
    if (this != &rhs)
    {
        delete[] body_;
		body_ = nullptr;

        length_ = rhs.length_;

		if (nullptr != rhs.body_)
		{
			body_ = new char[rhs.length_ + 1];
			strcpy(body_, rhs.body_);
		}
    }

    return *this;
}

MyString &MyString::operator+=(const MyString &rhs)
{
    if (nullptr != rhs.body_)
    {
        char *tmp = new char[length_ + rhs.length_ + 1];

        if (body_ != nullptr) {
            strcpy(tmp, body_);
        }

        strcat(tmp, rhs.body_);

        delete[] body_;
        body_ = nullptr;

        body_ = new char[length_ + rhs.length_ + 1];
        strcpy(body_, tmp);

        length_ += rhs.length_;

        delete[] tmp;
    }

    return *this;
}

char &MyString::operator[](int index)
{
    //out-of-bound behavior - "standard"
    //¯\_(ツ)_/¯
    return body_[index];
}

const char &MyString::operator[](int index) const
{
    return body_[index];
}
