#include "CommandSet.h"
#include "JsonObject.h"
#include "JsonString.h"

void CommandSet::execute(JsonValue *&root, MyString *text, size_t size)
{
    if (!root || size < 2)
    {
        return;
    }

    JsonObject *obj = dynamic_cast<JsonObject *>(root);

    if (!obj)
        return;

    obj->addElement(text[0], JsonString(text[1]));
}