class JsonArray;
class JsonObject;
class JsonNull;
class JsonBool;
class JsonNumber;
class JsonObject;
class JsonString;


/**
 * @class JsonVisitor
 * @brief Интерфейс за посещение на JSON елементи (Visitor Pattern)
 */
class JsonVisitor
{
public:
    virtual void visit(const JsonArray &arr) = 0;
    virtual void visit(const JsonBool &arr) = 0;
    virtual void visit(const JsonNull &arr) = 0;
    virtual void visit(const JsonNumber &arr) = 0;
    virtual void visit(const JsonObject &arr) = 0;
    virtual void visit(const JsonString &arr) = 0;

    virtual ~JsonVisitor() = default;
};