#include "JsonArray.h"

JsonArray::JsonArray()
{
    this->capacity = 0;
    this->current = 0;
    this->ptr = nullptr;
}

void JsonArray::resize()
{
    if (capacity == 0)
    {
        this->capacity = 2;
    }
    else
    {
        this->capacity *= 2;
    }

    JsonValue **newPtr = new JsonValue *[this->capacity];

    for (size_t i = 0; i < this->current; i++)
    {
        newPtr[i] = ptr[i];
    }

    delete[] this->ptr;
    this->ptr = newPtr;
}

void JsonArray::addElement(const JsonValue &el)
{
    if (this->capacity == this->current)
    {
        this->resize();
    }

    this->ptr[current++] = el.clone();
}

const JsonValue &JsonArray::operator[](int index) const
{
    return *this->ptr[index];
}

JsonValue &JsonArray::operator[](int index)
{
    return *this->ptr[index];
}

// void JsonArray::remove(int index)
// {
//     this->ptr[index].~JsonValue();
// }

void JsonArray::free()
{
    for (size_t i = 0; i < this->current; i++)
    {
        delete ptr[i];
    }

    delete[] this->ptr;
    this->capacity = 0;
    this->current = 0;
}

void JsonArray::copyFrom(const JsonArray &other)
{
    this->capacity = other.capacity;
    this->current = other.current;
    this->ptr = new JsonValue *[other.capacity];
    for (size_t i = 0; i < other.current; i++)
    {
        this->ptr[i] = other.ptr[i]->clone();
    }
}

JsonArray::~JsonArray()
{
    this->free();
}

JsonArray::JsonArray(const JsonArray &other)
{
    this->copyFrom(other);
}

JsonArray &JsonArray::operator=(const JsonArray &other)
{
    if (this != &other)
    {
        this->free();
        this->copyFrom(other);
    }

    return *this;
}

JsonValue *JsonArray::clone() const
{
    return new JsonArray(*this);
}

void JsonArray::print() const
{
    std::cout << "[";
    for (size_t i = 0; i < this->current; ++i)
    {
        if (i > 0)
            std::cout << ", " << ptr[current];
    }
    std::cout << "]" << std::endl;
}

unsigned JsonArray::getSize() const
{
    return this->current;
}

void JsonArray::accept(JsonVisitor &visitor) const
{
    visitor.visit(*this);
}