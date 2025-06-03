#include "Command.h"

/** @class CommandMove
 *  @brief Команда за преместване на стойност от един ключ в друг
 */
class CommandMove : public Command
{
public:
    void execute(JsonValue *&root, MyString *text, size_t size) override;
};