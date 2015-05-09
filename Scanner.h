#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define NO_KEYWORDS 7
#define ID_LENGTH 12

enum tsymbol {
    tnull = -1, 
    /* 0    1           2           3           4           5       */
    tnot,   tnotequ,    tmod,       tmodAssign, tident,     tnumber,
    /* 6    7           8           9           10          11      */
    tand,   tlparen,    trparen,    tmul,       tmulAssign, tplus,
    /* 12   13          14          15          16          17      */
    tinc,   taddAssign, tcomma,     tminus,     tdec,       tsubAssign,
    /* 18   19          20          21          22          23      */
    tdiv,   tdivAssign, tsemicolon, tless,      tlesse,     tassign,
    /* 24   25          26          27          28          29      */
    tequal, tgreat,     tgreate,    tlbracket,  trbracket,  teof,
    // ......... word symbols ...........
    /* 30   31          32          33          34          35      */
    tconst, telse,      tif,        tint,       treturn,    tvoid,
    /* 36   37          38          39                              */
    twhile, tlbrace,    tor,        trbrace,
};

struct tokenType {
    int number; // token number
    union {
        char id[ID_LENGTH];         // identifier
        int num;                    // number
    } value;    // token value
};

extern char *keyword[NO_KEYWORDS];
extern enum tsymbol tnum[NO_KEYWORDS];

int hexValue(char ch);
void lexicalError(int n);
int getIntNum(char firstCharacter);
int superLetter(char ch);
int superLetterOrDigit(char ch);

struct tokenType scanner();
