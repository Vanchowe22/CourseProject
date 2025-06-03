#include "CommandSearch.h"
#include "JsonObject.h"
#include "JsonArray.h"

void CommandSearch::execute(JsonValue *&root, MyString *text, size_t size)
{
    if (size < 1)
    {
        return;
    }
    this->search(root, text[0]);
}

void CommandSearch::search(const JsonValue *value, const MyString &key) const
{
    
    const JsonObject *obj = dynamic_cast<const JsonObject *>(value);
    if (obj)
    {
        MyString *keys = obj->getKeys();
        for (size_t i = 0; i < obj->getSize(); i++)
        {
            if (keys[i] == key)
            {
                obj->get(keys[i])->print();
            }
            search(obj->get(keys[i]), key);
        }
        return;
    }

    
    const JsonArray *arr = dynamic_cast<const JsonArray *>(value);
    if (arr)
    {
        for (size_t i = 0; i < arr->getSize(); i++)
            search(&(*arr)[i], key);
        return;
    }

    std::cout << "Search completed.";
}
