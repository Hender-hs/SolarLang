#include <stdio.h>
#include <iostream>
#include "./AST.hpp"
#include "../Parser.hpp"

using namespace SolarLang::Parser;


void AST::_funcDeclRule()
{
    return;
};

void AST::_varDeclRule()
{
    VaribleDeclaration varDeclarationInstance = varDecl();
    if (varDeclarationInstance.isVaribleType(_currWord)) 
    {
        // printf("entered 1");

        var.type = _currWord;
        nextTokenExpected = "<name>";
    }

    else if (nextTokenExpected == "<name>") 
    {
        // printf("entered 2");

        if (varDeclarationInstance.isDeclarationName(_currWord))
            throw std::runtime_error("Characters not allowed in this varible name assignment");

        var.name = _currWord;
        nextTokenExpected = "<assign_operator>";
    }

    else if (nextTokenExpected == "<assign_operator>")
    {
        // printf("entered 3");

        if (_currWord != "=")
        {
            std::string err = "Expected '=' (assign operator) in varible declaration";
            std::string mistake = "\n Got: ";
            throw std::runtime_error(err + mistake + _currWord);
        }

        nextTokenExpected = "<value>";
    }

    else if (nextTokenExpected == "<value>") 
    {
        // printf("entered 4");
        
        // TODO: change to verify the type value and its characters.
        if (varDeclarationInstance.isDeclarationName(_currWord))
            throw std::runtime_error("Characters not allowed in this value assignment");

        var.value = _currWord;
        nextTokenExpected = "<semicolon>";
    }

    else if (nextTokenExpected == "<semicolon>") 
    {
        // printf("entered 5");

        if (_currWord != ";")
            throw std::runtime_error("Expected ';' (semicolon) in varible declaration");

        astNode.push_back(var);

        // reseting states
        var = Varible();
        nextTokenExpected = "";

        return;
    }

    if (nextTokenExpected.empty())
        throw std::runtime_error("Varible declaration error");

};

void AST::_constDeclRule()
{

};

void AST::_refExpreRule()
{

};

void AST::_labelExpreRule()
{

};

void AST::_whileStatmntRule()
{

};

void AST::_ifStatmntRule()
{

};

void AST::_returnStatmntRule()
{

};


void AST::identifyKeyword()
{
    if (_currWord == funcDecl().keyword)
    { 
        _rulingState = _currWord;
    }

    else if (varDecl().isVarible(_currWord))
    {
        _rulingState = "var";
    }

    else if (_currWord == constDecl().keyword)
    {
        _rulingState = _currWord;
    }

    else if (_currWord == refExpr().keyword)
    {
        _rulingState = _currWord;
    }

    else if (_currWord == labelExpr().keyword)
    {
        _rulingState = _currWord;
    }

    else if (_currWord == whileStatemnt().keyword)
    {
        _rulingState = _currWord;
    }

    else if (_currWord == ifStatemnt().keyword)
    {
        _rulingState = _currWord;
    }

    else if (_currWord == returnStatemnt().keyword)
    {
        _rulingState = _currWord;
    }
};



void AST::processCode()
{
    if (_rulingState == funcDecl().keyword)
    { 
        AST::_funcDeclRule();
    }

    else if (_rulingState == varDecl().keyword)
    {
        AST::_varDeclRule();
    }

    else if (_rulingState == constDecl().keyword)
    {
        AST::_constDeclRule();
    }

    else if (_rulingState == refExpr().keyword)
    {
        AST::_refExpreRule();
    }

    else if (_rulingState == labelExpr().keyword)
    {
        AST::_labelExpreRule();
    }

    else if (_rulingState == whileStatemnt().keyword)
    {
        AST::_whileStatmntRule();
    }

    else if (_rulingState == ifStatemnt().keyword)
    {
        AST::_ifStatmntRule();
    }

    else if (_rulingState == returnStatemnt().keyword)
    {
        AST::_returnStatmntRule();
    }
};


void AST::errExpectedToken()
{
     if (!nextTokenExpected.empty())
    {
        std::string expectedTokenMsg = "Expecting ";
        expectedTokenMsg.append(nextTokenExpected);

        throw std::runtime_error(expectedTokenMsg);
    }
};

void AST::GenerateAST() 
{
    try {

        SolarLang::Parser::Core c;
        allProgramCode = c.Executor();

        for (std::string word : allProgramCode)
        {
            _currWord = word;

            if (_rulingState.empty())
            {
                errExpectedToken();
                identifyKeyword();
            }
            processCode();
        }
        errExpectedToken();

    }
    catch (const std::exception& err)
    {
        std::cout << err.what() << std::endl;
    }
};

