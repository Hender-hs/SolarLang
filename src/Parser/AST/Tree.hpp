#pragma once

#include <iostream>
#include "../../VectorSerial.hpp"


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
        Vector<std::string> boolExpressions;         
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
        Vector<BoolCondition> condition;
        //Body body;
    };

    class While : public Parent
    {
    public:
        Vector<BoolCondition> condition;
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
        Vector<Varible> varibles;
        Vector<Constant> constants;
        Vector<If> ifs;
        Vector<While> whiles;
    };

    class Function : public Parent
    {
    public:
        std::string name;
        Vector<Params> params;
        std::string type;
        Vector<Body> body;
        Vector<FuncReturn> _return;
    };
};
