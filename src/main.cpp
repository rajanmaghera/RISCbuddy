#include "RISCLexer.h"
#include "RISCParser.h"

#include "ANTLRFileStream.h"
#include "CommonTokenStream.h"
#include "tree/ParseTree.h"
#include "tree/ParseTreeWalker.h"
#include "ASTBuilder.h"
#include "AST.h"
#include "LabelReturn.h"

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(int argc, char **argv) {
  if (argc < 3) {
    std::cout << "Missing required argument.\n"
              << "Required arguments: <input file path> <function name>\n";
    return 1;
  }

   string titleText =
   "\n"
   "  _______ ___ _______ _______ __             __    __       \n"
   " |   _   |   |   _   |   _   |  |--.--.--.--|  .--|  .--.--.\n"
   " |.  l   |.  |   1___|.  1___|  _  |  |  |  _  |  _  |  |  |\n"
   " |.  _   |.  |____   |.  |___|_____|_____|_____|_____|___  |\n"
   " |:  |   |:  |:  1   |:  1   |                       |_____|\n"
   " |::.|:. |::.|::.. . |::.. . |                              \n"
   " `--- ---`---`-------`-------'                              \n"
   "                                                            ";

    cout << titleText << endl;
    cout << "Welcome to RISCbuddy! I'm your little friend that will help catch bugs in your RISC-V assembly code." << endl;
    cout << "I'm going to run a few checks on your code to make sure it's correct. Hang tight and read the messages carefully." << endl;
    cout << endl;

  antlr4::ANTLRFileStream afs;
  afs.loadFromFile(argv[1]);
  risc::RISCLexer lexer(&afs);
  antlr4::CommonTokenStream tokens(&lexer);
  risc::RISCParser parser(&tokens);

  antlr4::tree::ParseTree *tree = parser.file();

  ASTBuilder astBuilder;
  auto ast = any_cast<shared_ptr<AST>>(astBuilder.visit(tree));

  auto* pass = new LabelReturn(argv[2]);
  pass->run(ast);

  return 0;
}

