#include <iostream>
#include "LanguageExpressions.hpp"

using namespace SolarLang::LanguageExpressions;

bool LangExp::isDeclarationName(std::string token)
{
    for (char letter : token) 
    {
        // check if there is only numbers and letters on the token name
        if (
        !((int)letter >= 48 && (int)letter <= 57) ||
        !((int)letter >= 65 && (int)letter <= 90) ||
        !((int)letter >= 97 && (int)letter <= 122))
        {
            return 0;
        }
    }
    return 1;
};
