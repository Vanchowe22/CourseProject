#include "CommandCreate.h"
#include "JsonObject.h"
#include "JsonReader.h"
#include <sstream>
void CommandCreate::execute(JsonValue *&root, MyString *text, size_t size)
{
    if (!root || size < 2)
        return;
    JsonObject *obj = dynamic_cast<JsonObject *>(root);
    if (!obj)
        return;
    if (obj->contains(text[0]))
    {
        std::cout << "Element already exists.\n";
        return;
    }
    try {
            std::istringstream ss(text[1].c_str());
            JsonReader reader;
            JsonValue* newVal = reader.parse(ss);
            obj->addElement(text[0], *newVal);
            std::cout << "Element created.\n";
            delete newVal;
        } catch (const char* msg) {
            std::cout << "Invalid JSON value: " << msg << std::endl;
        }
}