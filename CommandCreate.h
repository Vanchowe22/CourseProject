#include "Command.h"

/** @class CommandCreate
 *  @brief Команда за създаване на нов елемент в JSON структура
 */
class CommandCreate : public Command
{
public:
    void execute(JsonValue*&root, MyString *text, size_t size) override;
};