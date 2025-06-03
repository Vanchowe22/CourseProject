#include "CommandValidate.h"

void CommandValidate::execute(JsonValue *&root, MyString *text, size_t size)
{
    std::cout << (root != nullptr) ? "Yes its valid" : "No its not valid";
}