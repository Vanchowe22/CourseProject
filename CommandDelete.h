#include "Command.h"

/** @class CommandDelete
 *  @brief Команда за изтриване на елемент от JSON
 */
class CommandDelete : public Command
{
public:
    void execute(JsonValue *&root, MyString *text, size_t size) override;
};