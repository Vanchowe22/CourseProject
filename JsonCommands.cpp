#include "JsonCommands.h"
#include "JsonPrinter.h"
#include "JsonReader.h"

JsonCommandProccesor::JsonCommandProccesor(JsonValue *root)
{
    this->root = root;
}

JsonCommandProccesor::~JsonCommandProccesor()
{
    this->root = nullptr;
}

void JsonCommandProccesor::executeCommand(MyString &text)
{
}