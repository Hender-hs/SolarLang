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

    typedef std::vector<std::string> VectorString;
    typedef std::vector<Tree::Parent> VectorASTNode;

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


        void GenerateAST();
        VectorString readWords();
        void identifyKeyword();
        void processCode();

        void errExpectedToken();


        VectorString allProgramCode;
        // AST data
        VectorASTNode astNode;

    private:
        std::string nextTokenExpected;

        void _funcDeclRule();

        void _varDeclRule();
        Tree::Varible var;

        void _constDeclRule();
        void _refExpreRule();
        void _labelExpreRule();
        void _whileStatmntRule();
        void _ifStatmntRule();
        void _returnStatmntRule();

        std::string _currWord;
        std::string _rulingState;
    };

};

