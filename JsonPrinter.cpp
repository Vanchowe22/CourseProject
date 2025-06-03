#include "JsonPrinter.h"
#include "JsonNumber.h"
#include "JsonString.h"
#include "JsonBool.h"
#include "JsonNull.h"
#include "JsonArray.h"
#include "JsonObject.h"

JsonPrinter::JsonPrinter(std::ostream &os) : os(os)
{
}

void JsonPrinter::printSpace() const
{
    this->os << " ";
}

void JsonPrinter::visit(const JsonNull &null)
{
    this->os << "null";
}

void JsonPrinter::visit(const JsonNumber &number)
{
    this->os << number.getNumber();
}

void JsonPrinter::visit(const JsonString &string)
{
    this->os << string.getText().c_str();
}

void JsonPrinter::visit(const JsonBool &boolean)
{
    this->os << (boolean.getBool() ? "true" : "false");
}

void JsonPrinter::visit(const JsonArray &arr)
{
    this->os << "[" << std::endl;
    for (size_t i = 0; i < arr.getSize(); i++)
    {
        printSpace();
        arr[i].accept(*this);
        if (i < arr.getSize() - 1)
        {
            this->os << ", ";
        }
    }

    this->os << "]" << std::endl;
}

void JsonPrinter::visit(const JsonObject &obj)
{
    this->os << "{" << std::endl;
    MyString *keys = obj.getKeys();
    for (size_t i = 0; i < obj.getSize(); i++)
    {
        printSpace();
        this->os << "\"" << keys[i].c_str() << "\":";
        obj.get(keys[i])->accept(*this);

        if (i < obj.getSize() - 1)
        {
            this->os << ", ";
        }
        this->os << std::endl;
    }
    printSpace();

    this->os << "}";
}