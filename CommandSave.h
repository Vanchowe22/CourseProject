#include "Command.h"

/** @class CommandSave
 *  @brief Команда за запазване на JSON в оригиналния файл
 */
class CommandSave : public Command
{
public:
    void execute(JsonValue *&root, MyString *text, size_t size) override;
};