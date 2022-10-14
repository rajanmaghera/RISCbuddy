//
// Created by rajan on 10/14/22.
//

#include "AST.h"

AST::AST(antlr4::Token *token) :
token(make_shared<antlr4::CommonToken>(token)) {}

AST::AST(size_t token) :
token(make_shared<antlr4::CommonToken>(token)) {}

void AST::addChild(shared_ptr<AST> child) {
    children.push_back(child);
}

vector<shared_ptr<AST>> AST::getChildren() {
    return children;
}

shared_ptr<AST> AST::getChild(uint32_t index) {
    return children[index];
}

size_t AST::getType() {
    return token->getType();
}

shared_ptr<antlr4::Token> AST::getToken() {
    return token;
}