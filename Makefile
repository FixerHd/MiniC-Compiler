compminic: lex.yy.c minic.tab.c minic.tab.h main.c listaSimbolos.h listaCodigo.h
	gcc lex.yy.c minic.tab.c minic.tab.h main.c listaSimbolos.c listaCodigo.c -lfl -o compminic

minic.tab.c minic.tab.h: minic.y listaSimbolos.h listaCodigo.h
	bison -d -v minic.y

lex.yy.c: lexico.l
	flex lexico.l

listaSimbolos.c: listaSimbolos.c listaSimbolos.h
	gcc listaSimbolos.c listaSimbolos.h

listaCodigo.c: listaCodigo.c listaCodigo.h
	gcc listaCodigo.c listaCodigo.h	

clean: 
	rm -f lex.yy.c minic.tab.c minic.tab.h

run: compminic codigo.mc
	./compminic codigo.mc > programa.s 2> errores.txt
	cat errores.txt
	spim -file programa.s
