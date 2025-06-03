#include "CommandDelete.h"
#include "JsonObject.h"

void CommandDelete::execute(JsonValue *&root, MyString *text, size_t size)
{
    if (!root || size < 1)
    {
        return;
    }

    JsonObject *obj = dynamic_cast<JsonObject *>(root);

    if (!obj)
    {
        return;
    }

    obj->remove(text[0]);
}