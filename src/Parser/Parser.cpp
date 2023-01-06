#include <iostream>
#include "Parser.hpp"
#include <vector>
//#include <array>

namespace SolarLang { 
    struct CharsCode {
        int _NULL = 0;
        int LINE_FEED = 10;
        int LEFT_ARROW = 60;
        int RIGHT_ARROW = 62;
        int LEFT_PARENTHESES = 40;
        int RIGHT_PARENTHESES = 41;
        int LEFT_CURLY_BRKTS = 123;
        int RIGHT_CURLY_BRKTS = 125;
        int VALUE_ASSIGMENT = 61;
        int SEMI_COLON = 59;
        int SPACE = 32;
        int COMMA = 44;
    } charsCode;
};

bool SolarLang::Parser::ProcessChars::isPiddingCharCode(int incomingCharCode)
{
    int keyChars[] {
        charsCode.SPACE,
        charsCode._NULL,
        charsCode.LINE_FEED,
    };

    for (int kchr : keyChars)
    {
        if (kchr == incomingCharCode)
            return 1;
    }

    return 0;
};

bool SolarLang::Parser::ProcessChars::lookForKeyChars(int incomingCharCode)
{
    int keyChars[] {
        charsCode.LEFT_ARROW,
        charsCode.RIGHT_ARROW,
        charsCode.SEMI_COLON,
        charsCode.VALUE_ASSIGMENT,
        charsCode.LEFT_PARENTHESES,
        charsCode.RIGHT_PARENTHESES,
        charsCode.LEFT_CURLY_BRKTS,
        charsCode.RIGHT_CURLY_BRKTS,
        charsCode.COMMA,
    };

    for (int kchr : keyChars)
    {
        if (kchr == incomingCharCode)
            return 1;
    }

    return 0;
};

std::string SolarLang::Parser::ProcessChars::lookForKeywords(std::string word)
{
    using namespace SolarLang::LanguageExpressions;

    std::cout << word << std::endl;

    bool isVarible = 0;
    std::string* varibleInitializers = VaribleDeclaration::getKeyword();

    for (int i = 0; i < int(5); i++) 
    {
        if (varibleInitializers[i] == word) {
            isVarible = 1;
            std::cout << "is Varible: " << varibleInitializers[i] << std::endl;  
        }
    }

    if (word == FunctionDeclaration::getKeyword()) {
        std::cout << FunctionDeclaration::getKeyword() << std::endl;
    }

    if (isVarible) {
        std::cout << VaribleDeclaration::getKeyword() << std::endl;
    }

    if (word == ConstantDeclaration::getKeyword()) {
        std::cout << ConstantDeclaration::getKeyword() << std::endl;
    }

    return "";
};





std::vector<std::string> SolarLang::Parser::Core::Executor()
{
    // This file has to be in the Heap, it can be so large to store in the stack
    FileStream::Reader* rd = new FileStream::Reader("../../script-example.sl");
    
    const char* fileBuffer = rd->read();

    //std::cout << "&fileBuffer: " << &fileBuffer << std::endl;
    //int bufferSize = *(&fileBuffer + 1) - fileBuffer;
    int bufferSize = rd->fileSize / sizeof(char);

    // std::cout << fileBuffer << std::endl;    
#if 0
    SolarLang::LanguageExpressions::LangExp a[3] = {
        SolarLang::LanguageExpressions::FunctionDeclaration::getObject(), 
        SolarLang::LanguageExpressions::VaribleDeclaration::getObject(), 
        SolarLang::LanguageExpressions::ConstantDeclaration::getObject(), 
    };
#endif


    //struct SolarLang::CharsCode charsCode;
    std::string word;

    std::vector<std::string> allInputWords;

    std::cout <<  bufferSize << std::endl;

    for (int i = 0; i < bufferSize; i++)
    {
        //std::cout << int(fileBuffer[i]) << " - " << fileBuffer[i] << std::endl;
        using namespace SolarLang::Parser;

        if (ProcessChars::lookForKeyChars(int(fileBuffer[i])))
        {
            if (word != "")
            {
                allInputWords.push_back(word); 
                word = "";
            }
            word += fileBuffer[i];
            allInputWords.push_back(word); 
            word = "";
        }
        else if (ProcessChars::isPiddingCharCode(int(fileBuffer[i])))
        {
            if (word != "")
            {
                allInputWords.push_back(word); 
                word = "";
            }
        }
        else 
        {
            word += fileBuffer[i];
        }
        // SolarLang::Parser::Token::lookForKeywords(word);
    }

    for (int i = 0; i < int(allInputWords.size()); i++)
    {
        std::cout << allInputWords[i] << std::endl;
    }

    return allInputWords;
};
