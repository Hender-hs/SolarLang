#include "Function.hpp"

using namespace SolarLang::LanguageExpressions;

void FunctionDeclaration::stageFuncName(VectorString* tokens)
{
    // printf("entered 2");

    if (isDeclarationName(tokens->next()))
        throw std::runtime_error("Characters not allowed in this varible name assignment");

    func.name = tokens->getValue();
 
};

void FunctionDeclaration::stageParams(VectorString* tokens)
{       
        // printf("entered 3");

        // params begining
        if (tokens->next() != "(")
        {
            std::string err = "Expected <open_parenphases>";
            std::string mistake = "\n Got: ";
            throw std::runtime_error(err + mistake + tokens->getValue());
        }

        do 
        {
            if (tokens->next() == ")")
            {
                continue;
            }

            Tree::Params param;

            // param type
            if (isType(tokens->getValue())) 
            {
                std::string err = "Expected <param_type>";
                std::string mistake = "\n Got: ";
                throw std::runtime_error(err + mistake + tokens->getValue());
            }
            param.type = tokens->getValue();

            // param name
            if (isDeclarationName(tokens->next()))
            {
                std::string err = "Expected <param_type>";
                std::string mistake = "\n Got: ";
                throw std::runtime_error(err + mistake + tokens->getValue());
            }
            param.name = tokens->getValue();

            func.params.add(param);
        } 
        while (tokens->getValue() == ",");


        if (tokens->getValue() != ")")
        {
            std::string err = "Expected <close_param_parenphases>";
            std::string mistake = "\n Got: ";
            throw std::runtime_error(err + mistake + tokens->getValue());
        }
};

void FunctionDeclaration::stageFuncType(VectorString* tokens)
{        

        if (tokens->next() != ":")
        {
            std::string err = "Expected <colon>";
            std::string mistake = "\n Got: ";
            throw std::runtime_error(err + mistake + tokens->getValue());
        }

        if (!isType(tokens->next()))
        {
            std::string err = "Expected <valid_type>";
            std::string mistake = "\n Got: ";
            throw std::runtime_error(err + mistake + tokens->getValue());
        }

        func.type = tokens->getValue();
};

void FunctionDeclaration::stageFuncBody(VectorString* tokens, Vector<Tree::Parent>* astNode) 
{

        if (tokens->next() != "{")
        {
            std::string err = "Expected <open_brkts>";
            std::string mistake = "\n Got: ";
            throw std::runtime_error(err + mistake + tokens->getValue());
        }               

        // body

        tokens->next();
        do {
           //processTokens();
            std::cout << tokens->getValue() <<std::endl;
            tokens->next();
        } while (tokens->getValue() != "}");

        if (tokens->getValue() != "}")
        {
            std::string err = "Expected <close_brkts>";
            std::string mistake = "\n Got: ";
            throw std::runtime_error(err + mistake + tokens->getValue());
        }               


        astNode->add(func);

        // reseting states
        func = Tree::Function();

};

void FunctionDeclaration::stageFuncReturn(VectorString* tokens) 
{
        std::cout << "func ast finished" << std::endl;
};
