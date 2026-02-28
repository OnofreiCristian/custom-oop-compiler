
/* prima parte a fisierului, aici punem headerele*/
%{


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "limbaj.tab.h"


%}

/* aici punem optiunile Flex*/

%option noyywrap
 
/* aici punem asta sa nu fim obligati sa definim o functie care gestioneaza finalul de fisier*/

%option yylineno

/* aici numara liniile din fisier*/

%%

    /* Incepe sectiunea de definire a tipurilor */

    /* avem nevoie de int, floar, bool, string, si tipuri de clase */

"int" { return INT; }
"float" { return FLOAT; }
"bool" { return BOOL; }
"string" { return STRING;}



    /* aici am pus definitia claselor */
"class" {return CLASS;}
"void" {return VOID;}
"return" {return RETURN;}


    /* functiile predefinite pentru print si main */
"Print" { return PRINT; }
"Main" {return MAIN;}


    /* statement if, else si while */
"if" { return IF;}
"else" { return ELSE;}
"while" {return WHILE;}

    /* variabile de tip bool pentru if, else, si while */
"true" {return BOOL_TRUE; }
"false" { return BOOL_FALSE; }


    /* aici construim id-ul pentru nume de variable si functii - o sa fie formate din orice combinatie de litere a-z si posibil numere */
[a-zA-Z][a-zA-Z0-9]* {yylval.str_val = strdup(yytext); return ID;}


    /* aici vom construi numere de tip int sau float */

[0-9]+ {yylval.int_val = atoi(yytext); return INT_VAL;}

[0-9]+\.[0-9]+ {yylval.float_val = atof(yytext); return FLOAT_VAL;}

    /* aici am declarat cum sa se citeasca stringuri: o ghilimea, urmat de orica caracter care NU este ghilimea, urmat de ghilimea din nou */

\"[^\"]*\" {yylval.str_val = strdup(yytext); return STRING_VAL;}




    /* aici vom declara operatorii si semnele de punctuatie */

":=" {return ASSIGN;}
"==" {return EQ;}
"!=" {return NEQ;}
"<=" {return LEQ;}
">=" {return GEQ;}
"&&" {return AND;}
"||" {return OR;}





[ \t] ; /* aceasta regula spune compilatorului sa ignore spatiile goale */

\n ; /* aceasta regula ne spune sa ignoram liniile noi (lineno creste automat din causa %option) */

. {return yytext[0];} /* aceasta regila retuneaza orice alt caracter pe care nu l-am definit noi (+,-,; etc) */

%%
