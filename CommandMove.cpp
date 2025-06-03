#include "CommandMove.h"
#include "JsonObject.h"
#include "JsonValue.h"

void CommandMove::execute(JsonValue *&root, MyString *text, size_t size)
{
    if (!root || size < 2)
    {
        return;
    }

    JsonObject *obj = dynamic_cast<JsonObject *>(root);

    if (!obj)
    {
        return;
    }
    JsonValue* val = obj->get(text[0]);
    obj->remove(text[0]);
    obj->addElement(text[1], *val);
}