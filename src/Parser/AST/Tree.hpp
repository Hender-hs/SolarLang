#include <iostream>
#include <vector>


namespace SolarLang::Parser::Tree {

    class Parent 
    { };

    class LangTypes : public Parent
    {
    public:
        std::string _void = "void";
        std::string _int = "int";
        std::string _string = "string";
        std::string _bool = "bool";
        std::string _object = "object";
    };

    class BoolCondition : public Parent
    {
    public:
        std::vector<std::string> boolExpressions;         
    };

    class FuncReturn : public Parent
    {
    public:
        std::string value;
    };

    class Varible : public Parent
    {
    public:
        std::string type;
        std::string value;
        std::string name;
    };

    class Constant : public Parent
    {
    public:
        std::string type;
        std::string value;
        std::string name;
    };

    class If : public Parent
    {
    public:
        std::vector<BoolCondition> condition;
        //Body body;
    };

    class While : public Parent
    {
    public:
        std::vector<BoolCondition> condition;
        //Body body;
    };

    class Params : public Parent
    {
    public:
        std::string type;
        std::string value;
        std::string name;
    };

    class Body : public Parent
    {
    public:
        std::vector<Varible> varibles;
        std::vector<Constant> constants;
        std::vector<If> ifs;
        std::vector<While> whiles;
    };

    class Function : public Parent
    {
    public:
        std::string type;
        std::vector<Params> params;
        std::vector<Body> body;
        std::vector<FuncReturn> _return;
    };
};
