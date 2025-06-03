#include "JsonReader.h"
#include "JsonString.h"
#include "JsonNumber.h"
#include "JsonBool.h"
#include "JsonArray.h"
#include "JsonObject.h"
#include "JsonNull.h"

JsonValue *JsonReader::parse(std::istream &is)
{
    avoidSpace(is);

    char letter = this->peek(is);

    if (letter == '{')
    {
        return this->parseObject(is);
    }
    else if (letter == '[')
    {
        return this->parseArray(is);
    }
    else if ((letter >= '0' && letter <= 9) || letter == '-')
    {
        return this->parseNumber(is);
    }
    else if (letter == '"')
    {
        return this->parseString(is);
    }
    else if (letter == 't' || letter == 'f')
    {
        return this->parseBool(is);
    }
    else if (letter == 'n')
    {
        return this->parseNull(is);
    }

    throw "that is not a valid JSON";
}

void JsonReader::avoidSpace(std::istream &is)
{
    while (is.peek() == ' ')
    {
        is.get();
    }
}

char JsonReader::peek(std::istream &is)
{
    avoidSpace(is);

    return is.peek();
}

JsonValue *JsonReader::parseNull(std::istream &is)
{
    MyString text = "";
    for (size_t i = 0; i < 4; i++)
    {
        text += (const char *)is.get();
    }

    if (text != "null")
    {
        throw "Invalid Null";
    }

    return new JsonNull();
}

JsonValue *JsonReader::parseString(std::istream &is)
{
    MyString text = "";
    char temp;
    is.get();
    while ((temp = is.get()) != '"')
    {
        if (is.eof())
        {
            throw "Invalid string";
        }

        text += (const char *)temp;
    }

    return new JsonString(text);
}

JsonValue *JsonReader::parseBool(std::istream &is)
{
    char ch = is.peek();

    if (ch == 't')
    {
        MyString text = "";

        for (size_t i = 0; i < 4; i++)
        {
            text += (const char *)is.get();
        }
        if (text == "true")
        {
            return new JsonBool(true);
        }
    }
    else if (ch == 'f')
    {
        MyString text = "";

        for (size_t i = 0; i < 5; i++)
        {
            text += (const char *)is.get();
        }

        if (text == "false")
        {
            return new JsonBool(true);
        }
    }

    throw "Invalid bool";
}

JsonValue *JsonReader::parseNumber(std::istream &is)
{
    MyString text = "";

    if (is.peek() == '-')
    {
        text += (const char *)is.get();
    }

    while (is.peek() >= '0' && is.peek() <= '9')
    {
        text += (const char *)is.get();
    }
    return new JsonNumber(this->convertToNum(text));
}

int JsonReader::convertToNum(const MyString &text) const
{
    size_t size = text.getSize();
    int result = 0;
    if (text[0] == '-')
    {
        for (size_t i = 1; i < size; i++)
        {
            result = result * 10 + (text[i] - '0');
        }
        result *= -1;
    }
    else
    {
        for (size_t i = 0; i < size - 1; i++)
        {
            result = result * 10 + (text[i] - '0');
        }
    }

    return result;
}

JsonValue *JsonReader::parseArray(std::istream &is)
{
    if (is.peek() != '[')
    {
        throw "Invalid array";
    }

    is.get();

    JsonArray *arr = new JsonArray();

    avoidSpace(is);
    if (is.peek() == ']')
    {
        is.get();
        return arr;
    }

    while (is.peek() != ']')
    {
        arr->addElement(*this->parse(is));
        char temp = is.get();

        if (temp != ',')
        {
            throw "Invalid array";
        }
        avoidSpace(is);
    }
    is.get();
    return arr;
}

JsonValue *JsonReader::parseObject(std::istream &is)
{
    if (is.peek() != '{')
    {
        throw "Invalid object";
    }

    is.get();
    JsonObject *obj = new JsonObject();

    if (is.peek() == '}')
    {
        is.get();
        return obj;
    }

    while (is.peek() != '}')
    {
        avoidSpace(is);
        JsonString *key = (JsonString *)this->parseString(is);
        if (is.peek() != ':')
        {
            throw "Invalid object";
        }

        avoidSpace(is);
        obj->addElement(key->getText(), *this->parse(is));
        if (is.peek() != ',')
        {
            throw "Invalid object";
        }
        avoidSpace(is);
    }
    is.get();
    return obj;
}
