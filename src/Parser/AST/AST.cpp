#include <stdio.h>
#include <iostream>
#include "./AST.hpp"
#include "../Parser.hpp"
#include "../../VectorSerial.hpp"

using namespace SolarLang::Parser;

// TODO: REFACT THE WHOLE CODE. ALL OF THOSE IFs COULD BE A FUNCTION, NOT AN "ELSE IF"
// INSTEAD OF USING A LOOP, USE A STEP OR NEXT FUNCTION TO INTERATE THROUGH ALL THE TOKENS

void AST::_funcDeclRule()
{   
    // init "func" key
    // 1. name
    // 2. open parenphases params
    // 3. params
    // 4. close parenphases params
    // 5. colon
    // 6. type
    // 7. open curly brackets
    // 8. body
    // 9. return
    // 10. close curly brackets
    // 11. 

    FunctionDeclaration funcDeclInstance = FunctionDeclaration();

    funcDeclInstance.stageFuncName(&tokens);
    funcDeclInstance.stageParams(&tokens);
    funcDeclInstance.stageFuncType(&tokens);
    funcDeclInstance.stageFuncBody(&tokens, &astNode);
    funcDeclInstance.stageFuncReturn(&tokens);
};

void AST::_varDeclRule()
{

    VaribleDeclaration varDeclInstance = VaribleDeclaration();
    
    varDeclInstance.stageVarName(&tokens);
    varDeclInstance.stageVarAssignment(&tokens);
    varDeclInstance.stageVarValue(&tokens);
    varDeclInstance.stageVarEndDeclaration(&tokens, &astNode);

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


void AST::processTokens()
{
    std::string token = tokens.getValue();

    if (token == funcDecl().keyword)
    { 
        _funcDeclRule();
    }

    else if (varDecl().isVarible(token))
    {
        _varDeclRule();
    }

    else if (token == constDecl().keyword)
    {
        _constDeclRule();
    }

    else if (token == refExpr().keyword)
    {
        _refExpreRule();
    }

    else if (token == labelExpr().keyword)
    {
        _labelExpreRule();
    }

    else if (token == whileStatemnt().keyword)
    {
        _whileStatmntRule();
    }

    else if (token == ifStatemnt().keyword)
    {
        _ifStatmntRule();
    }

    else if (token == returnStatemnt().keyword)
    {
        _returnStatmntRule();
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
        tokens = c.Executor();

        processTokens();

#if 0
        for (std::string token : tokens)
        {
            _currToken = token;

            if (_rulingState.empty())
            {
                errExpectedToken();
                identifyKeyword();
            }
            processCode();
        }
        errExpectedToken();
#endif

    }
    catch (const std::exception& err)
    {
        std::cout << err.what() << std::endl;
    }
};

