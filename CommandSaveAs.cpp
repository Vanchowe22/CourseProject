#include "CommandSaveAs.h"
#include <fstream>
#include "JsonPrinter.h"    


void CommandSaveAs::execute(JsonValue*&root, MyString *text, size_t size)
{
    if (!root || size < 1) {
            std::cout << "Usage: saveas <file>\n";

        }
        std::ofstream out(text[0].c_str());
        if (!out) {
            std::cout << "Failed to open " << text[0].c_str() << std::endl;
            return;
        }
        JsonPrinter printer(out);
        root->accept(printer);
        out.close();
        std::cout << "Saved to " << text[0].c_str() << std::endl;
}