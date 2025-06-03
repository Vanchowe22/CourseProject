#include <iostream>
#include "MyString.h"
#include "JsonValue.h"

/**
 * @class ICommand
 * @brief Интерфейс за команди върху JSON обект
 */
class Command
{
public:
    virtual void execute(JsonValue *&root, MyString *text, size_t size) = 0;
    virtual ~Command() = default;
};