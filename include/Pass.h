//
// Created by rajan on 10/14/22.
//

#pragma once
#include <memory>
#include "AST.h"
#include "RISCParser.h"

typedef shared_ptr<AST> AST_t;
typedef risc::RISCParser P;

template <typename T>
class Pass {
public:
    Pass();
    virtual ~Pass();
    virtual T run(AST_t t) = 0;
protected:
    T visit(AST_t t);
    T visitChildren(const AST_t& t);
    virtual T visitFile(AST_t t);
    virtual T visitLine(AST_t t);
    virtual T visitLabel(AST_t t);
    virtual T visitIns(AST_t t);
    virtual T visitArith(AST_t t);
    virtual T visitJal(AST_t t);
    virtual T visitMem(AST_t t);
    virtual T visitRet(AST_t t);

};

