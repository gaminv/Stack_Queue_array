#ifndef WRONG_STACK_SIZE_H
#define WRONG_STACK_SIZE_H

#include <exception>

class WrongStackSize : public std::exception
{
public:
    const char* what() const noexcept
    {
        return "Wrong stack size";
    }
};

#endif // !WRONG_STACK_SIZE_H

