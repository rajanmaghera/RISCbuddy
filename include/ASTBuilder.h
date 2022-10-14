//
// Created by rajan on 10/14/22.
//

#pragma once

#include "RISCBaseVisitor.h"
#include "AST.h"

using namespace risc;
using namespace std;

typedef RISCParser P;

class ASTBuilder : public RISCBaseVisitor {
public:

    any visitFile(RISCParser::FileContext *ctx) override;
    any visitLine(RISCParser::LineContext *ctx) override;
    any visitLabel(RISCParser::LabelContext *ctx) override;
    any visitIns(RISCParser::InsContext *ctx) override;
    any visitArith(RISCParser::ArithContext *ctx) override;
    any visitJal(RISCParser::JalContext *ctx) override;
    any visitMem(RISCParser::MemContext *ctx) override;
    any visitRet(RISCParser::RetContext *ctx) override;

};
