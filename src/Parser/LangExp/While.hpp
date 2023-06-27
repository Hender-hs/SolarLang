#pragma once

#include <iostream>
#include <vector>
#include "./Expression.hpp"


namespace SolarLang::LanguageExpressions {

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

}
