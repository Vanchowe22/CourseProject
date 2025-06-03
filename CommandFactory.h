#include "MyString.h"
#include "Command.h"


/**
 * @class CommandFactory
 * @brief Фабрика за създаване на конкретни команди от низове
 */
class CommandFactory
{
public:
    static Command *createCommand(const MyString &name);
};