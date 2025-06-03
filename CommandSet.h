#include "Command.h"

/** @class CommandSet
 *  @brief Команда за задаване на стойност на определен ключ
 */
class CommandSet : public Command
{
public:
    void execute(JsonValue *&root, MyString *text, size_t size) override;
};