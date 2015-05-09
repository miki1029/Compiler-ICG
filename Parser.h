#include "Scanner.h"
//#define NO_RULES 97             // number of rules
//#define GOAL_RULE (NO_RULES+1)  // accept rule
//#define NO_SYMBOLS 85           // number of grammar symbols
//#define NO_STATES 153           // number of states
#define PS_SIZE 200             // size of parsing stack
 
typedef struct nodeType {
    struct tokenType token;
    enum {terminal, nonterm} noderep;
    struct nodeType* son;
    struct nodeType* brother;
} Node;

enum nodeNumber {
    ACTUAL_PARAM,   ADD,            ADD_ASSIGN,     ARRAY_VAR,      ASSIGN_OP,
    CALL,           COMPOUND_ST,    CONST_NODE,     DCL,            DCL_ITEM,
    DCL_LIST,       DCL_SPEC,       DIV,            DIV_ASSIGN,     EQ,
    ERROR_NODE,     EXP_ST,         FORMAL_PARA,    FUNC_DEF,       FUNC_HEAD,
    GE,             GT,             IDENT,          IF_ELSE_ST,     IF_ST,
    INDEX,          INT_NODE,       LE,             LOGICAL_AND,    LOGICAL_NOT,
    LOGICAL_OR,     LT,             MOD,            MOD_ASSIGN,     MUL,
    MUL_ASSIGN,     NE,             NUMBER,         PARAM_DCL,      POST_DEC,
    POST_INC,       PRE_DEC,        PRE_INC,        PROGRAM,        RETURN_ST,
    SIMPLE_VAR,     STAT_LIST,      SUB,            SUB_ASSIGN,     UNARY_MINUS,
    VOID_NODE,      WHILE_ST
};

extern char *nodeName[];
extern int ruleName[];
extern char *tokenName[];
 
void semantic(int);
void printToken(struct tokenType token);
void dumpStack();
void errorRecovery();
int meaningfulToken(struct tokenType token);
Node* buildNode(struct tokenType token);
Node* buildTree(int nodeNumber, int rhsLength);
void printNode(Node *pt, int indent);
void printTree(Node *pt, int indent);
 
extern int errcnt;
extern int sp;                      // stack pointer
extern int stateStack[PS_SIZE];     // state stack
extern int symbolStack[PS_SIZE];    // symbol stack
extern Node* valueStack[PS_SIZE];     // value stack
 
Node *parser();
