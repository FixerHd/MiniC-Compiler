#include <stdio.h>
#include <stdlib.h>
// Descriptor de archivo del que lee yylex()
extern FILE *yyin;
// Función del analizador léxico
extern int yylex();
extern int yyparse();


int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Uso: %s archivo\n", argv[0]);
        exit(1);
    }
    yyin = fopen(argv[1],"r");
    if (yyin == NULL) {
        fprintf(stderr, "No se puede abrir %s\n", argv[1]);
        exit(2);
    }
    yyparse();
    fclose(yyin);
}