
Limbaj Compiler

A robust compiler frontend designed in C++ using Flex for lexical analysis and Bison for parsing. This project implements a custom programming language with support for Object-Oriented Programming (OOP), nested scoping, and strict static type checking.

The lexer (limbaj.l) tokenizes a wide range of language components:

    Data Types: Supports int, float, bool, and string.
  
    Control Flow: Recognizes if, else, and while structures.

    OOP Keywords: Identifies class, void, and return.

    Literals: Handles integer values, floating-point numbers, and string literals.

    Operators: Supports assignment (:=), comparison (==, !=, <=, >=), and logical operators (&&, ||).

The parser (limbaj.y) defines a structured grammar:

    Program Structure: A program consists of global declarations followed by a mandatory Main block.

    Declarations: Supports global and local variables, functions, and classes.

    Expression Evaluation: Implements operator precedence for arithmetic and logical operations.

The project utilizes a SymbolTableManager to handle complex naming environments:

    Scope Tracking: Automatically manages entering and exiting scopes for classes, functions, and the main block.

    Class Scopes: Specifically saves class-level scopes to facilitate member access verification later.

    Persistence: Outputs the final state of all symbol tables to a file (tables.txt) upon successful parsing.

The compiler performs rigorous checks to ensure code integrity:

    Assignment Validation: Verifies that the variable exists and that the assigned expression's type matches the variable's declared type.

    Function Integrity: Checks that function calls provide the correct number of arguments and that each argument matches the expected parameter type.

    OOP Member Access: Validates object.member syntax by checking if the object exists and if the member is defined within that specific class.

    Operation Safety: Ensures arithmetic and logical operations are performed on compatible types.


To compile the project on a Linux environment, you will need flex, bison, and g++.

# Generate the parser files
bison -d limbaj.y

# Generate the lexer file
flex limbaj.l

# Compile everything together
g++ limbaj.tab.c lex.yy.c -o compiler

# Run the compiler on a source file
./compiler < your_code_file.txt
