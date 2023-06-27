#include "Varible.hpp"

using namespace std;
using namespace SolarLang::LanguageExpressions;


bool VaribleDeclaration::isVarible(std::string token)
{
    int typetokensLength = 5;

    for (int i = 0; i < typetokensLength; i++)
    {
     if (getKeyword()[i] == token)
         return 1;
    }
    return 0;
};


void VaribleDeclaration::stageVarName(Vector<string>* tokens)
{
    if (isDeclarationName(tokens->next()))
        throw std::runtime_error("Characters not allowed in this varible name assignment");

    var.name = tokens->getValue();
};


void VaribleDeclaration::stageVarAssignment(Vector<string>* tokens)
{    

    if (tokens->next() != "=")
    {
        std::string err = "Expected '=' (assign operator) in varible declaration";
        std::string mistake = "\n Got: ";
        throw std::runtime_error(err + mistake + tokens->getValue());
    }
};


void VaribleDeclaration::stageVarValue(Vector<string>* tokens)
{
    // TODO: change to verify the type.
    if (isDeclarationName(tokens->next()))
        throw std::runtime_error("Characters not allowed in this value assignment");

    var.value = tokens->getValue();
};


void VaribleDeclaration::stageVarEndDeclaration(Vector<string>* tokens, Vector<Tree::Parent>* astNode)
{   
    if (tokens->next() != ";")
        throw std::runtime_error("Expected ';' (semicolon) in varible declaration");

    astNode->add(var);

    // reseting states
    var = Tree::Varible();

    std::cout << "var parsing finished" << std::endl; 
};

