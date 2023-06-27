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
        static std::string* getTypes();
        bool isType(std::string);
    };

}

