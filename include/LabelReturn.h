//
// Created by rajan on 10/14/22.
//

#pragma once

// This pass determines all the labels that exist within a function and
// where the function ends (with a return statement).

#include "Pass.h"
#include <string>
#include <utility>
#include <iostream>
using namespace std;

class LabelReturn : public Pass<void> {
private:
    string funcName;
    // TODO use some sort of symbol table rather than a bool?
    bool start;
    bool end;
public:
    explicit LabelReturn(string funcName);
    void run(AST_t t) override;
    void visitFile(AST_t t) override;
    void visitLabel(AST_t t) override;
    void visitRet(AST_t t) override;
};
