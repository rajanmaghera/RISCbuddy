//
// Created by rajan on 10/14/22.
//

#include "ASTBuilder.h"

any ASTBuilder::visitFile(RISCParser::FileContext *ctx) {
    auto ast = make_shared<AST>(P::FILE);
    for (auto & line : ctx->line()) {
        ast->addChild(any_cast<shared_ptr<AST>>(visit(line)));
    }
    return ast;
}

any ASTBuilder::visitLine(RISCParser::LineContext *ctx) {
    auto ast = make_shared<AST>(P::LINE);
    if (ctx->label()) {
        ast->addChild(any_cast<shared_ptr<AST>>(visit(ctx->label())));
    } else if (ctx->ins()) {
        ast->addChild(any_cast<shared_ptr<AST>>(visit(ctx->ins())));
    }
    return ast;
}

any ASTBuilder::visitLabel(RISCParser::LabelContext *ctx) {
    auto ast = make_shared<AST>(P::LABEL);
    ast->addChild(make_shared<AST>(ctx->ID()->getSymbol()));
    return ast;
}

any ASTBuilder::visitIns(RISCParser::InsContext *ctx) {
    auto ast = make_shared<AST>(P::INS);
    if (ctx->arith()) {
        ast->addChild(any_cast<shared_ptr<AST>>(visit(ctx->arith())));
    } else if (ctx->jal()) {
        ast->addChild(any_cast<shared_ptr<AST>>(visit(ctx->jal())));
    } else if (ctx->mem()) {
        ast->addChild(any_cast<shared_ptr<AST>>(visit(ctx->mem())));
    } else if (ctx->ret()) {
        ast->addChild(any_cast<shared_ptr<AST>>(visit(ctx->ret())));
    }
    return ast;
}

any ASTBuilder::visitArith(RISCParser::ArithContext *ctx) {
    auto ast = make_shared<AST>(P::ARITH);
    ast->addChild(make_shared<AST>(ctx->ID(0)->getSymbol()));
    return ast;
}

any ASTBuilder::visitJal(RISCParser::JalContext *ctx) {
    auto ast = make_shared<AST>(P::JAL);
    ast->addChild(make_shared<AST>(ctx->ID()->getSymbol()));
    return ast;
}

any ASTBuilder::visitMem(RISCParser::MemContext *ctx) {
    auto ast = make_shared<AST>(P::MEM);
    ast->addChild(make_shared<AST>(ctx->ID()->getSymbol()));
    ast->addChild(make_shared<AST>(ctx->REG(0)->getSymbol()));
    ast->addChild(make_shared<AST>(ctx->REG(1)->getSymbol()));
    return ast;
}

any ASTBuilder::visitRet(RISCParser::RetContext *ctx) {
    auto ast = make_shared<AST>(P::RET);
    // TODO check if a jr goes to the ra?
    ast->addChild(make_shared<AST>(ctx->getStart()));
    return ast;
}