#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <fstream>

using namespace std;


//informatii despre simboluri
struct SymbolInfo{

    string name; 
    string type; //int, float, class, etc
    string kind; // "variable", "function", "class", "parameter"
    string value; // pentru variabile
    

    //pentru functii: lista de parametrii
    vector<string> paramTypes;

    SymbolInfo(string n, string t, string k) : name(n), type(t), kind(k) {}

};


//tabelul de simboluri pentru un scope
class SymbolTable{

    public:
        string scopeName;
        SymbolTable* parent;
        map<string, SymbolInfo> symbols;

    SymbolTable(string name, SymbolTable* p = nullptr) : scopeName(name), parent(p) {}
    

    bool addSymbol(SymbolInfo symbol) {
        
        if (symbols.find(symbol.name) != symbols.end()) {
            return false; //simbolul deja exista
        }

        symbols.insert({symbol.name, symbol});
        return true;
    }


    //functie ca sa afisam tabelul in fisier
    void printTable(ofstream& out) {

        out <<"=== Symbol Table: " << scopeName <<" ===" << endl;

        if(parent){
            out<< "Parent Scope: " << parent->scopeName << " ===" << endl;
        }
        
        else {
            out << "Parent Scope: NULL (global)" << endl;
        }

        out<< "___________________________________________________"<<endl;
        out<<"Name\t\tKind\t\tType\t\tDetails"<<endl;
        out<<"____________________________________________________"<<endl;

        for(auto const& [key,val] : symbols) {

            out << val.name << "\t\t" << val.kind << "\t\t" << val.type;

            if(val.kind == "function") {

                out<< "\t\tParams: (";
                for(size_t i = 0; i < val.paramTypes.size(); ++i) {

                    out << val.paramTypes[i] << ( i < val.paramTypes.size() - 1 ? ", " : "");
                }
                out << ")";
            }
            out<<endl;
        }
        out<<endl;
    }

};

//managerul care de ocupa de tabele

class SymbolTableManager{

    public:

    SymbolTable* currentScope;
    vector<SymbolTable*> allTables; // pastram o lista cu toate tablele create pentru printrare la final

    map<string, SymbolTable*> classScopes; // avem nevoie de asta sa retinem scope-urile claselor pentru a verifica membrii (ex: obj.x)

    vector<string> currentFunctionParams; // avem nevoie de asta pentru a construi o lista de parametrii la declararea functiei


    SymbolTableManager(){

        //initializam scope-ul global

        currentScope = new SymbolTable("Global");
        allTables.push_back(currentScope);
    }


    //intram intr-un scope nou (cand definim o functie sau o clasa)
    void enterScope(string name) {

        SymbolTable* newScope = new SymbolTable(name, currentScope);
        allTables.push_back(newScope);
        currentScope = newScope;

    }

    //iesim din scope-ul curent (s-a terminat functia)
    void exitScope(){
        if (currentScope->parent != nullptr) {
            currentScope = currentScope->parent;
        }
    }


    //cautam un simbol in scope-ul curent sau in parinti;
    SymbolInfo* lookupSymbol(string name) {

            SymbolTable* searchScope = currentScope;
            while (searchScope != nullptr ) {
                if(searchScope->symbols.find(name) != searchScope->symbols.end()) {

                    return &searchScope->symbols.at(name);

                }

                searchScope = searchScope->parent;

            }

            return nullptr;
    }


    //verifica daca o variabila exista
    bool exists(string name){

        return lookupSymbol(name) != nullptr;
    }


    //returneaza tipul unei variabile sau error daca nu exista
    string getTypeOf(string name){
        SymbolInfo* res = lookupSymbol(name);

        if(res) return res->type;

        return "error";
    }


    //salvaza scope-ul unei clase pentru verificari ulterioare (ex: obj.prop)
    void saveClassScope (string className){

        classScopes[className] = currentScope;

    }


    //verifica daca un membru exista intr-o clasa
    string getClassMemberType(string className, string memberName){
        if(classScopes.find(className) == classScopes.end()) {
            return "error_no_class";
        }

        SymbolTable* classTable = classScopes[className];

        if(classTable->symbols.find(memberName) != classTable->symbols.end()){
            return classTable->symbols.at(memberName).type;
        }

        return "error_no_member";
    }

    // functie ca sa verificam obiectele claselor

    SymbolInfo* getClassMemberSymbol(string className, string memberName) 
    {

        //verificam daca clasa exista

        if(classScopes.find(className) == classScopes.end())
        {
            return nullptr;
        }

        // luam tabelul clasei

        SymbolTable* classTable = classScopes[className];

        // acum cautam membrul

        if (classTable->symbols.find(memberName) != classTable->symbols.end()) {

            return &classTable->symbols.at(memberName);

        }

        return nullptr;

    }



    //adaugam o variabila in scope-ul curent
    void addVariable(string name, string type){

        //verificam daca exista deja doar in scope-ul curent 

        if(currentScope->symbols.find(name) != currentScope->symbols.end())
        {

            cerr<< "Eroare Semantica: Variabila '" << name << "' este redefinita in scope-ul " << currentScope->scopeName << endl;
            exit(1);
        }

        SymbolInfo sym(name,type,"variable");
        currentScope->addSymbol(sym);
    
    }

    
    //adaugam o functie in scope-ul curent (de obicei global sau clasa)
    //nota: functie se adauga in scope-ul parinte, dar creeaza si scope nou

    void addFunction(string name, string returnType) {
        

        if(currentScope->symbols.find(name) != currentScope->symbols.end()) {
            cerr << "Eroare semantica: Functia '" << name <<"' este redefinita." << endl;
            exit(1);
        }

        SymbolInfo sym(name, returnType, "function");

        currentScope->addSymbol(sym);
    }

    //actualizam semnatura functiei dupa ce am parsat parametrii
    void updateFunctionParams(string funcName, vector<string> params) {

        ///cautam functia in scope-ul curent (unde a fost declarata)

        if(currentScope->symbols.find(funcName) != currentScope->symbols.end())
        {
            currentScope->symbols.at(funcName).paramTypes = params;
        }
    }

    //adaugam o clasa
    void addClass(string name) {

        if(currentScope->symbols.find(name) != currentScope->symbols.end()){

            cerr << "Eroare semantica: Clasa '" << name << "' este redefinita." << endl;
            exit(1);
        }

        SymbolInfo sym(name, "class", "class");
        currentScope->addSymbol(sym);
    }

    //printam toate tabelele din fisier
    void printAllTables(const string& filename){

        ofstream out(filename);
        for(SymbolTable* table : allTables) {
            table->printTable(out);
        }

        out.close();
        cout<< "Tabelele de simboluri au fost scrise in " << filename << endl;

        for(SymbolTable* table : allTables) table->printTable(out);
        
        out.close();
    }

};