#pragma once

#include <vector>
#include <iostream>
#if 0
#include "../LangExp/Function.hpp"
#include "../LangExp/Varible.hpp"
#include "../LangExp/Constant.hpp"
#include "../LangExp/If.hpp"
#include "../LangExp/While.hpp"
#include "../LangExp/Label.hpp"
#include "../LangExp/Reference.hpp"
#include "../LangExp/Return.hpp"
#endif
#include "../LangExp/LanguageExpressions.hpp"
#include "./Tree.hpp"
#include "../../VectorSerial.hpp"


// Creating the AST
//
// 1. Read the array of words
// 2. Identify those words and tokenize
// 3. 

namespace SolarLang::Parser {

    using namespace LanguageExpressions;
    using namespace Tree;

    class AST {
    public:

        static FunctionDeclaration funcDecl()  { return FunctionDeclaration(); };
        static VaribleDeclaration varDecl()    { return VaribleDeclaration(); };
        static ConstantDeclaration constDecl() { return ConstantDeclaration(); };
        static ReferenceExpression refExpr()   { return ReferenceExpression(); };
        static LabelExpression labelExpr()     { return LabelExpression(); };
        static WhileStatement whileStatemnt()  { return WhileStatement(); };
        static IfStatement ifStatemnt()        { return IfStatement(); };
        static ReturnStatement returnStatemnt(){ return ReturnStatement(); };

        void processTokens();

        void GenerateAST();
        Vector<std::string> readWords();

        // TODO: implement this function
        void throwErr(std::string err, std::string err2, std::string err3);

        void errExpectedToken();

        Vector<std::string> tokens;
        // AST data
        Vector<Tree::Parent> astNode;

    private:
        std::string nextTokenExpected;

        void _funcDeclRule();

        void _varDeclRule();

        void _constDeclRule();
        void _refExpreRule();
        void _labelExpreRule();
        void _whileStatmntRule();
        void _ifStatmntRule();
        void _returnStatmntRule();

    };

};

