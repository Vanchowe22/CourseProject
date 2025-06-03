#include <iostream>
#include "JsonValue.h"
#include "MyString.h"


/**
 * @class JsonCommandProccesor
 * @brief Интерпретира и изпълнява низови команди върху JSON дървото
 */
class JsonCommandProccesor
{
    JsonValue *root;

public:
    JsonCommandProccesor(JsonValue *root);
    ~JsonCommandProccesor();

    void executeCommand(MyString &command);
};