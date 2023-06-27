#pragma once

#include <iostream>
#include <vector>
#include "./Expression.hpp"

namespace SolarLang::LanguageExpressions {

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

}
