#pragma once

#include <iostream>
#include <vector>
#include "./Expression.hpp"

namespace SolarLang::LanguageExpressions {

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
}
