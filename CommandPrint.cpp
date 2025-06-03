#include "CommandPrint.h"
#include "JsonPrinter.h"
void CommandPrint::execute(JsonValue *&root, MyString *text, size_t size)
{
    if (root)
    {
        JsonPrinter printer(std::cout);
        root->accept(printer);
        std::cout << std::endl;
    }
    else
    {
        std::cout << "There is nothing to print";
    }
};
