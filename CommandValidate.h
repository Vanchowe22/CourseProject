#include "Command.h"

/** @class CommandValidate
 *  @brief Команда за проверка на валидността на JSON структурата
 */
class CommandValidate : public Command
{
public:
    void execute(JsonValue *&root, MyString *text, size_t size) override;
};