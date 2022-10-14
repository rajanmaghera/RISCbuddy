//
// Created by rajan on 10/14/22.
//

#include "LabelReturn.h"

LabelReturn::LabelReturn(string funcName) :
Pass<void>(), funcName(std::move(funcName)), start(false), end(false) {}

void LabelReturn::run(AST_t t) {
    cout << "+-------------------+" << endl;
    cout << "| Labels and Return |" << endl;
    cout << "+-------------------+" << endl;
    cout << "This portion finds all the labels inside your function so you can check if they should be there. If you find values that should not be there, check where you return your value." << endl;
    cout << endl;
    visit(t);
    if (!start)
        cout << "I could not find a label named [\e[1m" << funcName <<"\e[0m] in your code." << endl;
}

void LabelReturn::visitFile(AST_t t) {
    for (const auto& child : t->getChildren()) {
        visit(child);
        if (end) break;
    }
}

void LabelReturn::visitLabel(AST_t t) {
    if (!start && t->getChild(0)->getToken()->getText() == funcName) {
        cout << "I found the start of function [\e[1m" << funcName << "\e[0m] on line " << t->getChild(0)->getToken()->getLine() << "." << endl;
        start = true;
    }

    if (start) {
        cout << "I found label [\e[1m" << t->getChild(0)->getToken()->getText() << "\e[0m] on line " << t->getChild(0)->getToken()->getLine() << "." << endl;

    }
}

void LabelReturn::visitRet(AST_t t) {
    if (start) {
        cout << "I found the end of function [\e[1m" << funcName << "\e[0m] on line " << t->getChild(0)->getToken()->getLine() << endl;
        end = true;
    }
}
