#ifndef STACK_UNDERFLOW_H
#define STACK_UNDERFLOW_H

#include <exception>

class StackUnderflow : public std::exception
{
public:
    const char* what() const noexcept
    {
        return "Stack underflow";
    }
};

#endif // !STACK_UNDERFLOW_H

