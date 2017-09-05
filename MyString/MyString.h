//
// Created by rudlo on 05/09/2017.
//

#ifndef MYSTRING_MYSTRING_H
#define MYSTRING_MYSTRING_H


class MyString
{
public:
    MyString();
    explicit MyString(char* string);
    MyString(const MyString &obj);

    ~MyString();

    MyString& operator=(const MyString &rhs);

    int GetLength() const;
    char* GetBody() const;

private:
    int length;
    char* body;
};


#endif //MYSTRING_MYSTRING_H
