#pragma once

#include <iostream>
#include <vector>

namespace SolarLang::LanguageExpressions {

    class LangExp 
    {
    public:
        std::string className;
        std::string keyword;

        bool isDeclarationName(std::string);
    };

    class FunctionDeclaration : public LangExp
    {
    public:
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

        static std::string getClassName() { return "FunctionDeclaration"; };
        static std::string getKeyword() { return "func"; };
    };


    class VaribleDeclaration : public LangExp
    {
     public:
        std::string className = "VaribleDeclaration";
        std::string keyword = "var";
        std::string keywords = "";

        const std::string rules[6] = {  "<type>",
                                        "<name>",
                                        "<assign_operator>",
                                        "<value>",
                                        "<semicolon>"
                                     };

        static std::string getClassName() { return "VaribleDeclaration"; };
        static std::string* getKeyword() { 
            // TODO: REMOVE THIS RETURN FROM THE HEAṔ MEMORY
            return new std::string[5] { 
                "void",
                "int", 
                "string", 
                "bool", 
                "object" 
            }; 
        };

        
        bool isVarible(std::string token)
        {
            int typeArrLength = 5;

            for (int i = 0; i < typeArrLength; i++)
            {
                if (getKeyword()[i] == token)
                    return 1;
            }
            return 0;
        };

        bool isVaribleType(std::string token) { return isVarible(token); };
    };


    class ConstantDeclaration : public LangExp
    {  
    public:
        std::string className = "ConstantDeclaration";
        std::string keyword = "const";
 
        const std::string rules[7] = {      "<const_keyword>",
                                            "<type>",
                                            "<empty_space>", 
                                            "<varible_name>", 
                                            "<assign_operator>",
                                            "<value>",
                                            "<semicolon>"
                                      };

        static std::string getClassName() { return "ConstantDeclaration"; };
        static std::string getKeyword() { return "const"; };
    };


    class ReferenceExpression : public LangExp
    {
    public:
        std::string className = "ReferenceExpression";
        std::string keyword = "ref";

        const std::string rules[2] = {  "<ref_keyword>",
                                        "<varible_name>"
                                     };

        static std::string getClassName() { return "ReferenceExpression"; };
        static std::string getKeyword() { return "ref"; };
    };


    class LabelExpression : public LangExp
    {
    public:
        std::string className = "LabelExpression";
        std::string keyword = "<label_word>:";

        const std::string rules[2] = {  "<label_word>",
                                        "<colon_char>"
                                     };

        static std::string getClassName() { return "LabelExpression"; };
        static std::string getKeyword() { return ""; };
    };


    class WhileStatement : public LangExp
    {
    public:
        std::string className = "WhileStatement";
        std::string keyword = "while";

        std::string rules[3] = {    "<while_keyword>",
                                    "<left_parent_char>",
                                    "..."
                               };

        static std::string getClassName() { return "WhileStatement"; };
        static std::string getKeyword() { return "while"; };
    };


    class IfStatement : public LangExp
    {
    public:
        std::string className = "IfStatement";
        std::string keyword = "if";

        std::string rules[2] = {    "<if_keyword>",
                                    "..."
                               };

        static std::string getClassName() { return "IfStatement"; };
        static std::string getKeyword() { return "if"; };
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

