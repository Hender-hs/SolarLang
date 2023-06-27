#include <iostream>
#include "./Expression.hpp"

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

std::string* LangExp::getTypes() {
    // TODO: REMOVE THIS RETURN FROM THE HEAP MEMORY
    return new std::string[] { 
        "void",
        "int", 
        "string", 
        "bool", 
        "object" 
    };
};


bool LangExp::isType(std::string token)
{
    int typeArrLength = 5;

    for (int i = 0; i < typeArrLength; i++)
    {
        if (getTypes()[i] == token)
            return 1;
    }
    return 0;
};


