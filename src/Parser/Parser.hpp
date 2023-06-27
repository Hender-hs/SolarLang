#pragma once

#include <iostream>
#include <fstream>
#include "./LangExp/LanguageExpressions.hpp"
#include "./FS/FileStream.hpp"
#include "../VectorSerial.hpp"


namespace SolarLang::Parser {
    
    class Core
    {
    public:
        Vector<std::string> Executor();
    };

    class ProcessChars
    {
    public:
            static std::string lookForKeywords(std::string word);
            static bool lookForKeyChars(int charCode);
            static bool isPiddingCharCode(int charCode);
    };
}
