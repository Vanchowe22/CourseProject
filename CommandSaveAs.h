#include "Command.h"

/** @class CommandSaveAs
 *  @brief Команда за запазване на JSON в нов файл
 */
class CommandSaveAs : public Command
{
public:
    void execute(JsonValue*&root, MyString *text, size_t size) override;
};