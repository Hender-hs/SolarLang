#pragma once

#include <iostream>
#include "../../VectorSerial.hpp"
#include "./Expression.hpp"
#include "../AST/Tree.hpp"

namespace SolarLang::LanguageExpressions {

    using namespace Parser;

    typedef Vector<std::string> VectorString;

    class VaribleDeclaration : public LangExp
    {
     public:

         VaribleDeclaration() { };

         static std::string getClassName() { return "VaribleDeclaration"; };
         static std::string* getKeyword() { return LangExp::getTypes(); };


         std::string className = "VaribleDeclaration";
         std::string keyword = "var";
         std::string keywords = "";

         const std::string rules[6] = {
                                     "<type>",
                                     "<name>",
                                     "<assign_operator>",
                                     "<value>",
                                     "<semicolon>"
                                  };

         Tree::Varible var;

         bool isVarible(std::string token);
         bool isVaribleType(std::string token) { return isVarible(token); };

         void stageVarName(VectorString*);
         void stageVarAssignment(VectorString*);
         void stageVarValue(VectorString*);
         void stageVarEndDeclaration(VectorString*, Vector<Tree::Parent>*);
    };
}
