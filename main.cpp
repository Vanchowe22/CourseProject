#include <iostream>
#include <fstream>
#include "JsonReader.h"
#include "JsonCommands.h"
#include "CommandFactory.h"

/**
 * @brief Главна функция на програмата. Зарежда JSON файл и приема команди от потребителя
 */
int main()
{
    std::cout << "Enter JSON file path to load: ";
    std::string filePath;
    std::getline(std::cin, filePath);

    std::ifstream in(filePath);
    if (!in)
    {
        std::cout << "Failed to open file: " << filePath << std::endl;
        return 1;
    }

    JsonReader reader;
    JsonValue *root = nullptr;

    try
    {
        root = reader.parse(in);
        std::cout << "JSON loaded successfully.\n";
    }
    catch (const char *msg)
    {
        std::cout << "Error parsing JSON: " << msg << std::endl;
        return 1;
    }

    JsonCommandProccesor processor(root);
    std::string line;

    while (true)
    {
        std::cout << "\n> ";
        std::getline(std::cin, line);
        if (line == "exit" || line == "quit")
            break;
        MyString command(line.c_str());
        processor.executeCommand(command);
    }

    delete root;
    return 0;
}