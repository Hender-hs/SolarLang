#include "./FS/FileStream.hpp"
#include "Parser.hpp"
#include "./AST/AST.hpp"

int main()
{   
#if 0
#ifdef MACRO
    char buff[] = "Write This Simple Phraser \n a1111111 \n \t 2222222222222";
    FileStream::Writter* wr = new FileStream::Writter("./filetest.txt");
    wr->write(buff, sizeof(buff));
#endif
#endif

#if 0
    //(new Parser::Core())->Executor();
    SolarLang::Parser::Core c;
    c.Executor();
    return 0;
#endif

    SolarLang::Parser::AST ast;
    ast.GenerateAST();
}
