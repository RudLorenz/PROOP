//
// Created by rudlo on 05/09/2017.
//

#ifndef MYSTRING_MYSTRING_H
#define MYSTRING_MYSTRING_H


class MyString
{
public:
    MyString();
    explicit MyString(char *string);
    MyString(const MyString &obj);

    ~MyString();

    MyString &operator=(const MyString &rhs);
    MyString &operator+=(const MyString &rhs);

    explicit operator const char *() const { return body_; };
    char &operator[](int index);
    const char &operator[](int index) const;

    int GetLength() const;
    char *GetBody() const;

private:
    int length_;
    char *body_;
};

inline MyString operator+(MyString lhs, const MyString &rhs)
{
    lhs += rhs;
    return lhs;
}

#endif //MYSTRING_MYSTRING_H
