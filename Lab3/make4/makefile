# makefile
#

all: calc

calc: calc.l calc.y
	bison -d calc.y
	flex calc.l
	gcc -o $@ calc.tab.c lex.yy.c -lfl

clean:
	rm -f calc
	rm -f lex.yy.c
	rm -f calc.tab.c
	rm -f calc.tab.h

