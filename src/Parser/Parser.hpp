#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include "./LANGEXPR/LanguageExpressions.hpp"
#include "./FS/FileStream.hpp"


namespace SolarLang::Parser {
    
    class Core
    {
    public:
        std::vector<std::string> Executor();
    };

    class ProcessChars
    {
    public:
            static std::string lookForKeywords(std::string word);
            static bool lookForKeyChars(int charCode);
            static bool isPiddingCharCode(int charCode);
    };
}
