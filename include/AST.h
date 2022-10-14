//
// Created by rajan on 10/14/22.
//

#pragma once
#include <memory>
#include <vector>
#include "antlr4-runtime.h"
using namespace std;


class AST {
private:
    vector<shared_ptr<AST>> children;
    shared_ptr<antlr4::Token> token;

public:
    explicit AST(antlr4::Token *token);
    explicit AST(size_t token);
    void addChild(shared_ptr<AST> child);
    size_t getType();
    vector<shared_ptr<AST>> getChildren();
    shared_ptr<AST> getChild(uint32_t index);
    shared_ptr<antlr4::Token> getToken();

};
