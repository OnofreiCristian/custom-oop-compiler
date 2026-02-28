%{

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <cstring>
#include "structures.h"

using namespace std;

void yyerror(const char *s);
extern int yylex();
extern int yylineno;

//manager global de tabele de simboluri
SymbolTableManager manager;

//variabile ajutatoare pentru verificare parametrii functii

vector<string> declParams; //tipul parametrilor la declarare
vector<string> callArgs; // tipul argumentelor la apel

char* lastFuncName = nullptr; // retinem numele functiei curente pt a-i adauga parametrii


%}



/*tipurile de variabile cu care lucram*/
%union {

    int int_val;
    float float_val;
    char* str_val;


}


/* aici sunt token-urile pentru int, float si str*/
%token <int_val> INT_VAL
%token <float_val> FLOAT_VAL
%token <str_val> STRING_VAL ID

/*aici vom avea token-urile pentru tipurile predefinite*/

%token INT FLOAT STRING BOOL

/*aici sunt token-urile pentru cuvinte cheie*/

%token CLASS VOID RETURN MAIN PRINT IF ELSE WHILE BOOL_TRUE BOOL_FALSE 

%token ASSIGN EQ NEQ LEQ GEQ AND OR

/* asta o punem aici ca sa putem folosi $1 */
%type <str_val> type expr func_call


/*ordinea in care operatorii vor avea prioritate*/

%left OR
%left AND 
%left EQ NEQ
%left '<' '>' LEQ GEQ 
%left '+' '-'
%left '*' '/'
%left '.' /*prioritate maxima pentru campuri a.camp*/

%start progr


%%

    /*aici va fi sectiunea globala si main*/


    /*programul e impartit in declaratii globale si dupaia blocul main*/
progr : declarations main_block
      { 
        printf("Sintaxa corecta!\n"); 
        // La final printam tabelele
        manager.printAllTables("tables.txt");  
      }
      ;



    /*putem avea cat de multe declaratii dorim pana ne oprim*/
declarations :
             | declarations decl
             ;


    /*declaratiile pot fi de trei tipuri: variabile, clase sau functii*/
decl : var_decl
     | class_decl
     | func_decl
     ;



    /*acestea sunt tipurile de variabile sau functii pe care le putem avea ; id-ul este doar numele unei variabile sau a unei functii*/
    /*acum atribuim valoarea textuala pentru tipuri */
type : INT { $$ = strdup("int"); }
     | FLOAT { $$ = strdup("float"); }
     | BOOL { $$ = strdup("bool"); }
     | STRING { $$ = strdup("string"); }
     | VOID { $$ = strdup("void"); }
     | ID { $$ = $1; } /* pentru tipuri obiect (nume de clase) */
     ;

    /*clasele sunt formate din: CLASS token, ID token, doua acolade si corpul clasei intre acolade*/
class_decl : CLASS ID 
            { 
                manager.addClass($2); // adaugam simbolul clasei in Global
                manager.enterScope($2); // intram in scope-ul clasei

                // Salvam scope-ul ca sa putem verifica obj.proprietate mai tarziu
                manager.saveClassScope($2);
            }

            '{' class_body '}'

            {
                manager.exitScope(); // iesim din scope-ul clasei

            }

           ;


    /*aici avem definirea corpului clasei, care poate avea variabile sau functii*/
class_body : 
           | class_body var_decl
           | class_body func_decl
           ;


    /*aici definim structura unei variabile: poate fi ori variabila goala, ori variabila asignata*/
    /*adaugam variabilele in scope-ul curent*/
var_decl : type ID ';'
           {
             manager.addVariable($2,$1);
           }

         | type ID ASSIGN expr ';'
           {
            manager.addVariable($2, $1);
           }
         ;

    /*aici definim structura functiei: tipul functiei, numele, lista de parametrii si codul din inauntrul funciei*/
    /* adaugam functia, apoi intram in scope-ul ei pentru parametrii si body */
func_decl : type ID
          {

            manager.addFunction($2,$1); // adaugam functia in parinte
            manager.enterScope($2); // intram in scope-ul functiei

            lastFuncName = strdup($2); // tinem minte numele functiei

            declParams.clear(); // resetam lista de parametrii

          }
          
           '(' param_list ')'
           
          {

            // dupa de am citit parametrii, actualizam semnatura functiei in SymbolTable
            manager.currentScope->parent->symbols.at(lastFuncName).paramTypes = declParams;

          }


           '{' func_body '}'
          {

            manager.exitScope(); //iesim din scope-ul functiei
          }
          ;

    /*lista de parametrii poate sa fie goala, sau formata din mai multi parametrii, cu nume si tip*/
param_list : 
           | params
           ;

/* parametrii sunt tratati ca variabile locale in scope-ul functiei */
params : type ID
        {

            manager.addVariable($2,$1);
            declParams.push_back($1); // adaugam tipul in lista

        }

       | params ',' type ID
       {
            manager.addVariable($4,$3);
            declParams.push_back($3);
       }
       ;


    /*corpul unei functii este format din: ori declaratii de variabile, ori cod concret*/
func_body : 
          | func_body var_decl
          | func_body statement
          ;


    /*aici vom defini functia main care este formata din mai multe statement-uri*/
    /* main va fi un bloc in global scope, fara definitii de var/functii */
main_block : MAIN 
            {
                manager.enterScope("Main");
            }
            '{' statement_list '}'
            {
                manager.exitScope();
            }
            ;



    /*lista de statement-uri poate sa fie goala sau formata din mai multe statement-uri*/
statement_list : 
               | statement_list statement
               ;

    /*aici avem ce poate fi un statement: asignare, if statement, while statement, print statement, chemarea unei functii, returnare, sau un alt block de statement-uri*/
statement : assignment ';'
          | if_statement
          | else_statement
          | while_statement
          | print_statement ';'
          | func_call ';'
          | RETURN expr ';'

            {
                // aici am putea verifica daca tipul returnat corespunde cu cel al functeii

            }

          | '{' statement_list '}'
          ;


    /*definitia asignarii, pentru variabile normale, dar si pentru cele care fac parte din clase*/
assignment : ID ASSIGN expr

             {
                
                string typeId = manager.getTypeOf($1);
                if (typeId == "error") 
                {
                    char err[100]; 
                    sprintf(err,"Variabila '%s' nu este definita.", $1);
                    yyerror(err);
                    exit(1);
                }

                if (typeId != string($3)) 
                {
                    char err[100]; 
                    sprintf(err,"Tipuri incompatibile la atribuire: '%s' vs '%s'", typeId.c_str(), $3);
                    yyerror(err);
                    exit(1);
                }

             }
           | ID '.' ID ASSIGN expr


           {
                // verificam obj.prop

                string typeObj = manager.getTypeOf($1); // ex: Dreptunghi
                string typeMember = manager.getClassMemberType(typeObj, $3);

                if (typeMember == "error_no_class") 
                {
                    char err[100]; 
                    sprintf(err,"Variabila '%s' nu este un obiect sau clasa nu exista.", $1);
                    yyerror(err);
                    exit(1);
                }

                if (typeMember == "error_no_member")
                {
                    char err[100]; 
                    sprintf(err,"Clasa '%s' nu are membrul '%s'.", typeObj.c_str(), $3);
                    yyerror(err);
                    exit(1);
                }

                if (typeMember != string($5)) 
                {
                    char err[100]; 
                    sprintf(err,"Tip incorect la atribuirea membrului: '%s' vs '%s'", typeMember.c_str(), $5);
                    yyerror(err);
                    exit(1);


                }


           }
           ;

    /*statement tip if*/
if_statement : IF '(' expr ')' statement
             ;
    /*statement tip else*/
else_statement : ELSE statement
               ;
    /*statement tip while*/
while_statement : WHILE '(' expr ')' statement
                ;
    /*statement pentru print*/
print_statement : PRINT '(' expr ')'
                ;


    /*definim cum folosim functiile: ori functii normale, ori functii din clase*/
func_call : ID '('
            {
                callArgs.clear(); // resetam argumentele inainte de a parsa
            }

            args ')'

            {

                SymbolInfo* func = manager.lookupSymbol($1);

                if(!func || func->kind != "function")
                {
                    char err[100]; 
                    sprintf(err,"Functia '%s' nu este definita.", $1);
                    yyerror(err);
                    exit(1);
                }

                // verificare nr parametri

                if(func->paramTypes.size() != callArgs.size())
                {
                    char err[100]; 
                    sprintf(err,"Functia '%s' asteapta %lu argumente, dar a primit %lu.", $1, func->paramTypes.size(), callArgs.size());
                    yyerror(err);
                    exit(1);
                }

                // verificare tipuri parametrii 

                for(size_t i=0; i<callArgs.size(); ++i)
                {

                    if(func->paramTypes[i] != callArgs[i])
                    {

                        char err[100]; 
                        sprintf(err,"Argumentul %lu la functia '%s' are tip gresit (%s vs %s).", i+1, $1, callArgs[i].c_str(), func->paramTypes[i].c_str());
                        yyerror(err);
                        exit(1);

                    }

                }

                // returnam tipul functiei (pentru a fi folosin in expresii)
                $$ = strdup(func->type.c_str());

            }
          | ID '.' ID '(' 

                {
                    callArgs.clear();


                }

           args ')'

           {
                string typeObj = manager.getTypeOf($1);

                if(typeObj == "error")
                {
                    char err[100]; 
                    sprintf(err,"Obiectul '%s' nu este definit.", $1);
                    yyerror(err);
                    exit(1);
                }

                // cautam metoda in scope-ul clasei respective
                // folosim $3 pentru numele metodei (al doilea ID)

                SymbolInfo* method = manager.getClassMemberSymbol(typeObj, $3);

                if (method == nullptr)
                {
                    char err[100]; 
                    sprintf(err,"Clasa '%s' nu are membrul '%s'.", typeObj.c_str(), $3);
                    yyerror(err);
                    exit(1);
                }

                if(method->kind != "function") {

                    char err[100]; 
                    sprintf(err,"'%s' din clasa '%s' nu este o functie.", $3, typeObj.c_str());
                    yyerror(err);
                    exit(1);

                }

                // verificam nr de parametrii

                    if (method->paramTypes.size() != callArgs.size())
                    {
                        char err[100]; 
                        sprintf(err,"Metoda '%s'.'%s' asteapta %lu argumente dar a primit %lu", typeObj.c_str(), $3, method->paramTypes.size(), callArgs.size());
                        yyerror(err);
                        exit(1);
                        
                    }
                // verificam tipul parametrilor
                for(size_t i = 0; i < callArgs.size(); ++i) {
                    if (method->paramTypes[i] != callArgs[i]) {
                        char err[150]; 
                        sprintf(err, "Argumentul %lu la metoda '%s.%s' are tip gresit (%s vs %s).", 
                                i+1, typeObj.c_str(), $3, callArgs[i].c_str(), method->paramTypes[i].c_str());
                        yyerror(err); exit(1);
                    }

                    $$ = strdup(method->type.c_str());
                }

           }

          ;


    /* lista de argumente din funtie, poate fi goala*/
args : 
     | args_list
     ;

     
    /*lista de argumente poate fi un argument sau mai multe*/
args_list : expr { callArgs.push_back($1); }
          | args_list ',' expr { callArgs.push_back($3); }
          ;

expr : INT_VAL { $$ = strdup("int"); }
     | FLOAT_VAL { $$ = strdup("float"); }
     | STRING_VAL { $$ = strdup("string"); }
     | BOOL_TRUE { $$ = strdup("bool"); }
     | BOOL_FALSE { $$ = strdup("bool"); }
     | ID
       {

            string t = manager.getTypeOf($1);

            if(t == "error")
            {
                char err[100]; 
                sprintf(err,"Variabila '%s' folosita este nedeclarata.", $1);
                yyerror(err);
                exit(1);
            }

            $$ = strdup(t.c_str());
       }
     | ID '.' ID
       {
            string tObj = manager.getTypeOf($1);
            string tMem = manager.getClassMemberType(tObj, $3);
            if (tMem.find("error") != string::npos )
            {
                yyerror("Acces invalid la membru de clasa.");
                exit(1);
            }

            $$ = strdup(tMem.c_str());
       }
     | func_call { $$ = $1; }
     | expr '+' expr
        {
            if (strcmp($1 , $3) != 0)
            {
                yyerror("Tipuri diferite la adunare.");
                exit(1);
            }
            $$ = $1;
        }

     | expr '-' expr
        {
            if (strcmp($1 , $3) != 0)
            {
                yyerror("Tipuri diferite la scadere.");
                exit(1);
            }
            $$ = $1;
        }
     | expr '*' expr
        {
            if (strcmp($1 , $3) != 0)
            {
                yyerror("Tipuri diferite la inmultire.");
                exit(1);
            }
            $$ = $1;
        }
     | expr '/' expr
        {
            if (strcmp($1 , $3) != 0)
            {
                yyerror("Tipuri diferite la impartire.");
                exit(1);
            }
            $$ = $1;
        }
     | expr '<' expr
        {
            if (strcmp($1 , $3) != 0)
            {
                yyerror("Tipuri diferite la <.");
                exit(1);
            }
            $$ = $1;
        }
     | expr '>' expr
     {
            if (strcmp($1 , $3) != 0)
            {
                yyerror("Tipuri diferite la >.");
                exit(1);
            }
            $$ = $1;
        }
     | expr LEQ expr
     {
            if (strcmp($1 , $3) != 0)
            {
                yyerror("Tipuri diferite la LEQ.");
                exit(1);
            }
            $$ = $1;
        }
     | expr GEQ expr
        {
            if (strcmp($1 , $3) != 0)
            {
                yyerror("Tipuri diferite la GEQ.");
                exit(1);
            }
            $$ = $1;
        }
     | expr EQ expr
     {
            if (strcmp($1 , $3) != 0)
            {
                yyerror("Tipuri diferite la EQ.");
                exit(1);
            }
            $$ = $1;
        }
     | expr NEQ expr
        {
            if (strcmp($1 , $3) != 0)
            {
                yyerror("Tipuri diferite la NEQ.");
                exit(1);
            }
            $$ = $1;
        }
     | expr AND expr
     {
            if (strcmp($1 , $3) != 0)
            {
                yyerror("Tipuri diferite la AND.");
                exit(1);
            }
            $$ = $1;
        }
     | expr OR expr
     {
            if (strcmp($1 , $3) != 0)
            {
                yyerror("Tipuri diferite la OR.");
                exit(1);
            }
            $$ = $1;
        }
     | '(' expr ')' { $$ = $2; }
     ;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Eroare la linia %d: %s\n", yylineno, s);
}

int main (int argc, char* argv[]) {

    yyparse();
    return 0;


}


