#include "CommandSave.h"
#include <fstream>
#include "JsonPrinter.h"

void CommandSave::execute(JsonValue *&root, MyString *text, size_t size)
{
    if (!root)
    {
        std::cout << "No JSON to save.\n";
        return;
    }
    std::ofstream out("default.json");
    if (!out)
    {
        std::cout << "Failed to open default.json\n";
        return;
    }
    JsonPrinter printer(out);
    root->accept(printer);
    out.close();
    std::cout << "Saved to default.json\n";
}