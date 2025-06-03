#include "Command.h"

/** @class CommandPrint
 *  @brief Команда за отпечатване на текущата JSON структура
 */
class CommandPrint : public Command
{
public:
    void execute(JsonValue *&root, MyString *text, size_t size) override;
};