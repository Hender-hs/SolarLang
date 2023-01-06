#pragma once
#include <vector>
#include <iostream>
#include "../LANGEXPR/LanguageExpressions.hpp"
#include "./Tree.hpp"


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

        void GenerateAST();

        std::vector<std::string> readWords();
        void identifyAndProcessKeywords(std::string);

        static FunctionDeclaration funcDecl()  { return FunctionDeclaration(); };
        static VaribleDeclaration varDecl()    { return VaribleDeclaration(); };
        static ConstantDeclaration constDecl() { return ConstantDeclaration(); };
        static ReferenceExpression refExpr()   { return ReferenceExpression(); };
        static LabelExpression labelExpr()     { return LabelExpression(); };
        static WhileStatement whileStatemnt()  { return WhileStatement(); };
        static IfStatement ifStatemnt()        { return IfStatement(); };
        static ReturnStatement returnStatemnt(){ return ReturnStatement(); };

        // AST data
        std::vector<Tree::Parent> astData;

    private:
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

