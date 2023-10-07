%code requires {
	#include "listaCodigo.h"
}


%{	
    #include <stdio.h>
    #include <stdlib.h>
	#include <string.h>
	#include "listaSimbolos.h"
    extern int yylex();
    void yyerror (const char *msg);
	void liberarReg(char *s);
	char *obtenerReg();
	char *nuevaEtiqueta();
	

    extern int yylineno;
	extern char* yytext;
	extern int errores;
	extern int yynerrs;

	int cont_semantico = 0;
	int contador_etiq = 1;
	int contador_cadena = 0;

	int registros[10]={0,0,0,0,0,0,0,0,0,0};

	Lista tS;
	Tipo tipo;
%}


%union {
       char * cadena;
	   ListaC codigo;}	   	   

%token PRI SUM RES MUL DIV ASI PAI PAD LLI LLD COM PYC VAR ELS REA IFF VOI CON WHI
%token <cadena> IDE
%token <cadena> ENT
%token <cadena> CAD

%left SUM RES
%left MUL DIV
%left RES2

%type <codigo> expression statement read_list print_item print_list program statement_list declarations identifier_list asig


%%

 
 
program   : VOI IDE PAI PAD LLI  { tS = creaLS(); } declarations statement_list LLD {
			/*Volcar lista de simbolos a salida para generar .data*/
			if(cont_semantico == 0 && errores == 0 && yynerrs==0){
				printf("\n");
				printf(".data\n\n");
				imprimirLS(tS);
				printf("\n");
				printf(".text\n.globl main\n\n");
				concatenaLC($7,$8);
				Operacion oper;
				oper.op = strdup("li");
				oper.res = strdup("$v0");
				oper.arg1 = strdup("10");
				oper.arg2 = NULL;
				insertaLC($7, finalLC($7), oper);
				Operacion oper2;
				oper2.op = strdup("syscall");
				oper2.res = NULL;
				oper2.arg1 = NULL;
				oper2.arg2 = NULL;
				insertaLC($7, finalLC($7), oper2);
				imprimirCodigo($7);
				liberaLC($8);
			} 
			}
          ; 

declarations : declarations VAR {tipo = VARIABLE; } identifier_list PYC {
				$$=$1;
				concatenaLC($$,$4);
				liberaLC($4);
			 }
			 | declarations CON {tipo = CONSTANTE; } identifier_list PYC {
				$$=$1;
				concatenaLC($$,$4);
				liberaLC($4);
			 }
			 | {
				 $$=creaLC();
			 }
			 ;

identifier_list  : asig {
				$$=$1;
}
			 | identifier_list COM asig {
				$$=$1;
				concatenaLC($$,$3);
				liberaLC($3);
			 }
             ;

asig         : IDE {
				PosicionLista p1;
				p1 = buscaLS(tS, $1);
				if(p1 == finalLS(tS)){
					Simbolo s;
					s.nombre = strdup($1);
					s.tipo = tipo;
					insertaLS(tS, p1, s);
					$$=creaLC();
				} else {
					cont_semantico++;
					yyerror("error semantico, identificador ya declarado");
				}

				}
			 | IDE ASI expression {
				PosicionLista p1;
				p1 = buscaLS(tS, $1);
				if(p1 == finalLS(tS)){
					Simbolo s;
					s.nombre = strdup($1);
					s.tipo = tipo;
					insertaLS(tS, p1, s);
					
				} else {
					cont_semantico++;
					yyerror("error semantico, identificador ya declarado");
				}
					$$=$3;
					Operacion oper;
					oper.op = strdup("sw");
					oper.res = recuperaResLC($3);
					char str[18];
					sprintf(str, "_%s", $1);
					oper.arg1 = strdup(str);
					free($1);
					oper.arg2 = NULL;
					liberarReg(oper.res);
					insertaLC($$, finalLC($$), oper);

				}
             ;

statement_list : statement_list statement{
				$$=$1;
				concatenaLC($$,$2);
				liberaLC($2);
			}
			 | 	{
				 $$  = creaLC();
			 }
			 ; 

statement    : IDE ASI expression PYC {
				PosicionLista p2;
				p2 = buscaLS(tS, $1);
				if(p2 != finalLS(tS)){	
					Simbolo s = recuperaLS(tS, p2);
					if(s.tipo != CONSTANTE){		
						$$=$3;
						Operacion oper;
						oper.op=strdup("sw");
						oper.res = recuperaResLC($3);
						char c[18];
						sprintf(c, "_%s", $1);
						free($1);
						oper.arg1=strdup(c);
						oper.arg2=NULL;
						insertaLC($$,finalLC($$),oper);
						liberarReg(oper.res);
					} else {
						cont_semantico++;
						yyerror("error semantico, asignacion a una constante");
						$$=$3;
					}
				} else {
					cont_semantico++;
					yyerror("error semantico, no se encuentra en la lista");
					$$=$3;
				}

				}
			 | LLI statement_list LLD {
				 $$=$2;

			 }
			 | IFF PAI expression PAD statement ELS statement {
				$$=creaLC();
				concatenaLC($$,$3);
				Operacion oper;
				oper.op=strdup("beqz");
				oper.res = recuperaResLC($3);
				oper.arg1 = nuevaEtiqueta();
				oper.arg2 = NULL;
				insertaLC($$,finalLC($$),oper);
				concatenaLC($$,$5);
				Operacion oper2;
				oper2.op=strdup("b");
				oper2.res = nuevaEtiqueta();
				oper2.arg1 = NULL;
				oper2.arg2 = NULL;
				insertaLC($$,finalLC($$),oper2);
				Operacion oper3;
				char c[18];
				sprintf(c, "%s:", oper.arg1);
				oper3.op=strdup(c);
				oper3.res = NULL;
				oper3.arg1 = NULL;
				oper3.arg2 = NULL;
				insertaLC($$,finalLC($$),oper3);
				concatenaLC($$,$7);
				Operacion oper4;
				char d[18];
				sprintf(d, "%s:", oper2.res);
				oper4.op=strdup(d);
				oper4.res = NULL;
				oper4.arg1 = NULL;
				oper4.arg2 = NULL;
				insertaLC($$,finalLC($$),oper4);
				liberarReg(oper.res);


			 }
 			 | IFF PAI expression PAD statement {
				$$=creaLC();
				concatenaLC($$,$3);
				Operacion oper;
				oper.op=strdup("beqz");
				oper.res = recuperaResLC($3);
				oper.arg1 = nuevaEtiqueta();
				oper.arg2 = NULL;
				insertaLC($$,finalLC($$),oper);
				concatenaLC($$,$5);
				Operacion oper2;
				char c[18];
				sprintf(c, "%s:", oper.arg1);
				oper2.op=strdup(c);
				oper2.res = NULL;
				oper2.arg1 = NULL;
				oper2.arg2 = NULL;
				insertaLC($$,finalLC($$),oper2);
				liberarReg(oper.res);

			 }
	         | WHI PAI expression PAD statement {
				$$=creaLC();
				Operacion oper;
				char d[19];
				char a[18];
				sprintf(a, "%s", nuevaEtiqueta());
				sprintf(d, "%s:", a);
				oper.op=strdup(d);
				oper.res = NULL;
				oper.arg1 = NULL;
				oper.arg2 = NULL;
				insertaLC($$,finalLC($$),oper);
				concatenaLC($$,$3);
				Operacion oper2;
				oper2.op=strdup("beqz");
				oper2.res = recuperaResLC($3);
				oper2.arg1 = nuevaEtiqueta();
				oper2.arg2 = NULL;
				insertaLC($$,finalLC($$),oper2);
				concatenaLC($$,$5);
				Operacion oper3;
				oper3.op=strdup("b");
				oper3.res = strdup(a); 
				oper3.arg1 = NULL;
				oper3.arg2 = NULL;
				insertaLC($$,finalLC($$),oper3);
				Operacion oper4;
				char c[18];
				sprintf(c, "%s:", oper2.arg1);
				oper4.op=strdup(c);
				oper4.res = NULL;
				oper4.arg1 = NULL;
				oper4.arg2 = NULL;
				insertaLC($$,finalLC($$),oper4);
				liberarReg(oper2.res);


			 }			 
			 | PRI print_list PYC {
				 
					$$=$2;
			 }
             | REA read_list PYC {
					$$=$2;
			 }	
			 ;

print_list   : print_item {
					$$=$1;
			}	
		 	 | print_list COM print_item {
					$$=$1;
					concatenaLC($$,$3);
					liberaLC($3);
			 }
			 ;

print_item   : expression{
					$$=$1;
					Operacion oper;
					oper.op=strdup("li");
					oper.res = strdup("$v0");
				 	oper.arg1=strdup("1");
					oper.arg2=NULL;
					insertaLC($$,finalLC($$),oper);
					Operacion oper2;
					oper2.op=strdup("move");
					oper2.res = strdup("$a0");
				 	oper2.arg1=recuperaResLC($1);
					oper2.arg2=NULL;
					insertaLC($$,finalLC($$),oper2);
					Operacion oper3;
					oper3.op=strdup("syscall");
					oper3.res = NULL;
				 	oper3.arg1=NULL;
					oper3.arg2=NULL;
					insertaLC($$,finalLC($$),oper3);
					liberarReg(oper2.arg1);
				}
			 | CAD {
				 	$$=creaLC(); 
					Operacion oper;
					oper.op=strdup("li");
					oper.res = strdup("$v0");
				 	oper.arg1=strdup("4");
				 	oper.arg2=NULL;
					insertaLC($$,finalLC($$),oper);
					Operacion oper2;
					oper2.op=strdup("la");
					oper2.res = strdup("$a0");
					PosicionLista p;
					p = buscaLS(tS, $1);
					Simbolo s;
					if(p==finalLS(tS)){
						s.nombre = $1;
						s.tipo = CADENA;
						s.valor = contador_cadena;
						insertaLS(tS, p, s);
						contador_cadena++;
					}else{
						s=recuperaLS(tS, p);
					}
					char c[18];
					sprintf(c, "$str%d", s.valor);
				 	oper2.arg1=strdup(c);
					oper2.arg2=NULL;
					insertaLC($$,finalLC($$),oper2);
					Operacion oper3;
					oper3.op=strdup("syscall");
					oper3.res = NULL;
				 	oper3.arg1=NULL;
					oper3.arg2=NULL;
					insertaLC($$,finalLC($$),oper3);
			 }
			 ;

read_list    : IDE {
				PosicionLista p2;
				p2 = buscaLS(tS, $1);
				if(p2 != finalLS(tS)){
					Simbolo s = recuperaLS(tS, p2);
					if(s.tipo != CONSTANTE){
						$$=creaLC();
						Operacion oper;
						oper.op=strdup("li");
						oper.res = strdup("$v0");
						oper.arg1=strdup("5");
						insertaLC($$,finalLC($$),oper);
						Operacion oper2;
						oper2.op=strdup("syscall");
						oper2.res = NULL;
						oper2.arg1=NULL;
						oper2.arg2=NULL;
						insertaLC($$,finalLC($$),oper2);
						Operacion oper3;
						oper3.op = strdup("sw");
						oper3.res = strdup("$v0");
						char c[18];
						sprintf(c, "_%s", $1);
						free($1);
						oper3.arg1 = strdup(c);
						oper3.arg2=NULL;
						insertaLC($$,finalLC($$),oper3);					
					} else {
						cont_semantico++;
						yyerror("error semantico, asignacion a una constante");
						$$=creaLC();
					}	
				} else {
					cont_semantico++;
					yyerror("error semantico, no se encuentra en la lista");
					$$=creaLC();
					
				}
				}
			 | read_list COM IDE {
				PosicionLista p2;
				p2 = buscaLS(tS, $3);
				if(p2 != finalLS(tS)){
					Simbolo s = recuperaLS(tS, p2);
					if(s.tipo != CONSTANTE){
						$$=$1;
						Operacion oper;
						oper.op=strdup("li");
						oper.res = strdup("$v0");
						oper.arg1=strdup("5");
						insertaLC($$,finalLC($$),oper);
						Operacion oper2;
						oper2.op=strdup("syscall");
						oper2.res = NULL;
						oper2.arg1=NULL;
						oper2.arg2=NULL;
						insertaLC($$,finalLC($$),oper2);
						Operacion oper3;
						oper3.op = strdup("sw");
						oper3.res = strdup("$v0");
						char c[18];
						sprintf(c, "_%s", $3);
						free($3);
						oper3.arg1 = strdup(c);
						oper3.arg2=NULL;
						insertaLC($$,finalLC($$),oper3);		
					} else {
						cont_semantico++;
						yyerror("error semantico, asignacion a una constante");
						$$=$1;
					}
				} else {
					cont_semantico++;
					yyerror("error semantico, no pertenece a la lista");
					$$=$1;
				}	
				}
			 ;

expression   : expression SUM expression 
			   {
				   $$=$1; concatenaLC($$,$3);
				   Operacion oper;
				   oper.op=strdup("add");
				   oper.res = recuperaResLC($1);
				   oper.arg1=recuperaResLC($1);
				   oper.arg2 = recuperaResLC($3);
				   insertaLC($$,finalLC($$),oper);
				   liberaLC($3);
				   liberarReg(oper.arg2);
			   }
			 | expression RES expression
			 {
				   $$=$1; concatenaLC($$,$3);
				   Operacion oper; oper.op=strdup("sub"); oper.res = recuperaResLC($1);
				   oper.arg1=recuperaResLC($1); oper.arg2 = recuperaResLC($3);
				   insertaLC($$,finalLC($$),oper); liberaLC($3);
				   liberarReg(oper.arg2);
			   }
			 | expression MUL expression
			 {
				   $$=$1; concatenaLC($$,$3);
				   Operacion oper; oper.op=strdup("mul");; oper.res = recuperaResLC($1);
				   oper.arg1=recuperaResLC($1); oper.arg2 = recuperaResLC($3);
				   insertaLC($$,finalLC($$),oper); liberaLC($3);
				   liberarReg(oper.arg2);
			   }
			 | expression DIV expression
			 {
				   $$=$1; concatenaLC($$,$3);
				   Operacion oper; oper.op=strdup("div");; oper.res = recuperaResLC($1);
				   oper.arg1=recuperaResLC($1); oper.arg2 = recuperaResLC($3);
				   insertaLC($$,finalLC($$),oper); liberaLC($3);
				   liberarReg(oper.arg2);
			   }
			 | RES expression %prec RES2
			 {
				 $$=$2;
				 Operacion oper;
				 oper.op=strdup("neg");
				 oper.res=recuperaResLC($2);
				 oper.arg1=recuperaResLC($2);
				 oper.arg2=NULL;
				 insertaLC($$,finalLC($$),oper);

			 }
			 | PAI expression PAD
			 {
                $$ = $2;

             }
			 | IDE {
				PosicionLista p2;
				p2 = buscaLS(tS, $1);
				if(p2 != finalLS(tS)){
					$$=creaLC();
					
				} else {
					$$=creaLC();
					cont_semantico++;
					yyerror("error semantico, identificador no declarado");
				}
				Operacion oper;
					oper.op=strdup("lw");
					oper.res=obtenerReg();
					char c[18];
					sprintf(c, "_%s", $1);
					oper.arg1=strdup(c);
					oper.arg2=NULL;
					insertaLC($$,finalLC($$),oper);
					guardaResLC($$,oper.res);
				}
			 | ENT {
				  $$ = creaLC();
				 Operacion oper;
				 oper.op=strdup("li");
				 oper.res = obtenerReg();
				 oper.arg1=$1;
				 oper.arg2=NULL;
				 insertaLC($$,finalLC($$), oper);
				 guardaResLC($$, oper.res);
				 
			 }
			 ;
%%


void yyerror(const char *msg){
    fprintf(stderr, "Error en linea %d: %s, hay %d errores semanticos\n", yylineno, msg, cont_semantico);
}

char *obtenerReg(){
	int i=0; 
	while(registros[i]!=0){
		i++;
	}
	registros[i]=1;
	char str[10];
	sprintf(str, "$t%d", i);
	return strdup(str);
}

void liberarReg(char *s){
	registros[s[2]-'0']=0;
}

char *nuevaEtiqueta() {
	char aux[10];
	sprintf(aux,"$l%d",contador_etiq++);
	return strdup(aux);
}


