#pragma once

#include <iostream>
#include "../../VectorSerial.hpp"
#include "./Expression.hpp"
#include "../AST/Tree.hpp"

namespace SolarLang::LanguageExpressions {

    using namespace Parser;

    typedef Vector<std::string> VectorString;

    class FunctionDeclaration : public LangExp
    {

    public:

        static std::string getClassName() { return "FunctionDeclaration"; };
        static std::string getKeyword() { return "func"; };

        std::string className = "FunctionDeclaration";
        std::string keyword = "func";

 
        const std::string rules[11] = { "<func_keyword>", 
                                        // "<left_arrow>",
                                        // "<type>", 
                                        // "<right_arrow>", 
                                        "<func_name>",
                                        "<left_parentheses>", 
                                        "<func_params_block>",
                                        "<right_parentheses>", 
                                        "<left_curly_brkts>",
                                        "<block_statement>", 
                                        "<colon>",
                                        "<type>", 
                                        "<right_curly_brkst>"
                                      };

        
        Tree::Function func;

        void stageFuncName(VectorString*);
        void stageParams(VectorString*);
        void stageFuncType(VectorString*);
        void stageFuncBody(VectorString*, Vector<Tree::Parent>*);
        void stageFuncReturn(VectorString*);

    };

    class ReturnStatement : public LangExp
    {
    public:
        std::string className = "ReturnStatement";
        std::string keyword = "return";

        std::string rules[2] = { "<return_keyword>",
                                 "..."
                               };

        static std::string getClassName() { return "ReturnStatement"; };
        static std::string getKeyword() { return "return"; };
    };

}
