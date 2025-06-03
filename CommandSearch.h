#include "Command.h"

/** @class CommandSearch
 *  @brief Команда за търсене на стойности по ключ в JSON
 */
class CommandSearch : public Command
{
    void search(const JsonValue *root, const MyString &text) const;

public:
    void execute(JsonValue *&root, MyString *text, size_t size) override;
};