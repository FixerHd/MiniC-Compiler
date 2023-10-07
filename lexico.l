/* Definiciones y código C literal */

%{
    #include <stdio.h>
    #include "minic.tab.h"
    #include <math.h>
    /* Variable con el número de línea en el que
       comienza un comentario multilínea */
    int comienzo_comentario = 0;
    int errores = 0;
%}


D    [0-9]
L    [a-zA-Z]
panico [^ \n\t\ra-zA-Z_0-9+\-*/;,()"{}=]+

/* Contexto para reconocer comentarios multilínea */
%x comentario

%option yylineno
/* %option debug */

%%
 /* Blancos */
[ \n\t\r]+        ;
"//".*            ;
"/*"              { comienzo_comentario = yylineno;
                    BEGIN(comentario); }
<comentario>"*/"  { BEGIN(INITIAL); }
<comentario>.|\n    ;
<comentario><<EOF>> { 
                      errores++;
                      fprintf(stderr, "error en linea %d: error lexico comentario sin cerrar, hay %d errores lexicos en total\n", comienzo_comentario, errores);
                      return 0; // Detener el análisis
                    }

 /* Palabras clave */
print          { return PRI; }
var            { return VAR; }
read           { return REA; }
else           { return ELS; }
if             { return IFF; }
while          { return WHI; }
void           { return VOI; }
const          { return CON; }

 /* Identificadores */
({L}|_)({L}|{D}|_)* { int i = strlen(yytext);
                     if(i > 17) {
                       errores++;
                       fprintf(stderr, "error en línea %d: error lexico identificador fuera de rango, hay %d errores lexicos en total: identificador de tamaño %d \n", yylineno, errores, i);
                     }
                     yylval.cadena=strdup(yytext);
                     return IDE; }

 /* Enteros */
{D}+                { long i = atol(yytext);
                     if(i > pow(2,31)-1 || i< -pow(2,31)) {
                       errores++;
                       fprintf(stderr, "error en línea %d: error lexico entero fuera de rango, hay %d errores lexicos en total: %ld \n", yylineno, errores, i);
                     }
                     yylval.cadena=strdup(yytext);
                     return ENT; 
                    }
 /* Operadores */
"+"             { return SUM; }
"-"             { return RES; }
"*"             { return MUL; }
"/"             { return DIV; }
"="             { return ASI; }
 /* Cadenas de caracteres */
(\"([^\"\n])+\")|(\'([^\'\n])+\')     { yylval.cadena=strdup(yytext); return CAD; }
\"[^"\n]+\n      {  errores++;
  fprintf(stderr, "error en linea %d: error lexico, cadena sin cerrar, hay %d errores lexicos en total\n",
                        yylineno, errores);
                         }
 /* Puntuación */
";"             { return PYC; }
","             { return COM; }
"("             { return PAI; }
")"             { return PAD; }
"{"             { return LLI; }
"}"             { return LLD; }
 /* Errores léxicos */
{panico}+        { errores++; 
  fprintf(stderr, "error en linea %d: error lexico, hay %d errores lexicos en total: %s\n",
                            yylineno, errores, yytext); 
                            }
%%





