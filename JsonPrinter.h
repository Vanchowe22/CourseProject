#include "JsonVisitor.h"
#include <iostream>

class JsonPrinter : public JsonVisitor
{
    std::ostream &os;
    void printSpace() const;

public:
    JsonPrinter(std::ostream &os);

    void visit(const JsonNumber &number) override;
    void visit(const JsonString &string) override;
    void visit(const JsonBool &boolean) override;
    void visit(const JsonNull &null) override;
    void visit(const JsonArray &array) override;
    void visit(const JsonObject &object) override;
};