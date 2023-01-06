#include <iostream>
#include <vector>


namespace SolarLang::Parser::Tree {

    class Parent 
    { };

    class LangTypes : public Parent
    {
        std::string _void = "void";
        std::string _int = "int";
        std::string _string = "string";
        std::string _bool = "bool";
        std::string _object = "object";
    };

    class BoolCondition : public Parent
    {
        std::vector<std::string> boolExpressions;         
    };

    class FuncReturn : public Parent
    {
        std::string value;
    };

    class Varible : public Parent
    {
        LangTypes type;
        std::string value;
        std::string name;
    };

    class Constant : public Parent
    {
        LangTypes type;
        std::string value;
        std::string name;
    };

    class If : public Parent
    {
        std::vector<BoolCondition> condition;
        //Body body;
    };

    class While : public Parent
    {
        std::vector<BoolCondition> condition;
        //Body body;
    };

    class Params : public Parent
    {
        LangTypes type;
        std::string value;
        std::string name;
    };

    class Body : public Parent
    {
        std::vector<Varible> varibles;
        std::vector<Constant> constants;
        std::vector<If> ifs;
        std::vector<While> whiles;
    };

    class Function : public Parent
    {
        LangTypes type;
        std::vector<Params> params;
        std::vector<Body> body;
        std::vector<FuncReturn> _return;
    };
};
