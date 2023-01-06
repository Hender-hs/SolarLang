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


void AST::identifyAndProcessKeywords(std::string word)
{
    if (word == funcDecl().keyword)
    { 
        AST::_funcDeclRule();
    }

    else if (word == varDecl().keyword)
    {
        AST::_varDeclRule();
    }

    else if (word == constDecl().keyword)
    {
        AST::_constDeclRule();
    }

    else if (word == refExpr().keyword)
    {
        AST::_refExpreRule();
    }

    else if (word == labelExpr().keyword)
    {
        AST::_labelExpreRule();
    }

    else if (word == whileStatemnt().keyword)
    {
        AST::_whileStatmntRule();
    }

    else if (word == ifStatemnt().keyword)
    {
        AST::_ifStatmntRule();
    }

    else if (word == returnStatemnt().keyword)
    {
        AST::_returnStatmntRule();
    }
};


void AST::GenerateAST() 
{

    SolarLang::Parser::Core c;
    std::vector<std::string> allProgramCode = c.Executor();

    for (std::string word : allProgramCode)
    {
        identifyAndProcessKeywords(word);
    }

    return;
};

