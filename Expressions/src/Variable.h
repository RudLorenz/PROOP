#ifndef EXPRESSIONS_VARIABLE_H
#define EXPRESSIONS_VARIABLE_H


#include <utility>

#include "Expression.h"
#include "Number.h"

class Variable : public Expression
{
public:
    Variable() : name_() {};
    explicit Variable(std::string name) : name_(std::move(name)) {};

    Expression *diff() const override;
    std::string tostring() const override;

    ~Variable() override;

private:
    std::string name_;
};

Expression *Variable::diff() const
{
    return new Number(0);
}

std::string Variable::tostring() const
{
    return name_;
}

Variable::~Variable()
{
}


#endif //EXPRESSIONS_VARIABLE_H