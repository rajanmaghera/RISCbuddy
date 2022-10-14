//
// Created by rajan on 10/14/22.
//

#include "Pass.h"

template <typename T>
Pass<T>::Pass() = default;

template <typename T>
Pass<T>::~Pass() = default;

template<typename T>
T Pass<T>::visitChildren(const AST_t& t) {
    for (const auto& child : t->getChildren()) {
        visit(child);
    }
}

template<typename T>
T Pass<T>::visit(AST_t t) {
    switch (t->getType()) {
        case P::FILE:
            return visitFile(t);
        case P::LINE:
            return visitLine(t);
        case P::LABEL:
            return visitLabel(t);
        case P::INS:
            return visitIns(t);
        case P::ARITH:
            return visitArith(t);
        case P::JAL:
            return visitJal(t);
        case P::MEM:
            return visitMem(t);
        case P::RET:
            return visitRet(t);
    }
}

template<typename T>
T Pass<T>::visitFile(AST_t t) {
    visitChildren(t);
}

template<typename T>
T Pass<T>::visitLine(AST_t t) {
    visitChildren(t);
}

template<typename T>
T Pass<T>::visitLabel(AST_t t) {
    visitChildren(t);
}

template<typename T>
T Pass<T>::visitIns(AST_t t) {
    visitChildren(t);
}

template<typename T>
T Pass<T>::visitArith(AST_t t) {
    visitChildren(t);
}

template<typename T>
T Pass<T>::visitJal(AST_t t) {
    visitChildren(t);
}

template<typename T>
T Pass<T>::visitMem(AST_t t) {
    visitChildren(t);
}

template<typename T>
T Pass<T>::visitRet(AST_t t) {
    visitChildren(t);
}

template class Pass<void>;
