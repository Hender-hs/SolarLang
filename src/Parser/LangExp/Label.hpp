#pragma once

#include <iostream>
#include <vector>
#include "./Expression.hpp"

namespace SolarLang::LanguageExpressions {

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

}
