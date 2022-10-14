grammar RISC;

tokens {
    FILE,
    LINE,
    LABEL,
    INS,
    ARITH,
    MEM
}


file: line* EOF;

line :
    directive
    | ins
    | label
    | term
    ;
directive : DIRECTIVE term ;
label : ID COLON term ;
ins :
    mem
    | arith
    | jal
    | ret
    ;

mem
    : ID REG NUM? OPR REG CPR term
    ;

arith :
    ID (REG | NUM | ID)* term;

jal : JAL ID term;


ret :
    RET | JRRA;

term : NL | COMMENT ;

COLON : ':';
DOT : '.' ;
OPR : '(' ;
CPR : ')' ;
COM : '#' ;
RET : 'ret' ;
JRRA : 'jr ra' ;
JAL : 'jal' ;

REG: [rRaAsSxXtT][0-9]+ ;

DIRECTIVE : DOT [a-zA-Z". ]+;
ID : [a-zA-Z_][a-zA-Z0-9_]*;
NUM : '-'?[0-9]+;
NL : '\r'? '\n';

// Skip whitespace
COMMA : ',' -> skip;
COMMENT: COM .*? NL;
WS : [ \t]+ -> skip ;
