#pragma once

#include <iostream>
#include <vector>
#include "./Expression.hpp"

namespace SolarLang::LanguageExpressions {

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

}
