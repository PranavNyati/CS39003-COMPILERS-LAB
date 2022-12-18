DIR_NAME=asgn4_20CS30037_20CS30049

output_txt:	a.out $(DIR_NAME)_test.c
		./a.out < $(DIR_NAME)_test.c > output.txt

a.out:	lex.yy.o y.tab.o $(DIR_NAME).o 
	gcc lex.yy.o y.tab.o $(DIR_NAME).o -lfl

lex.yy.o: lex.yy.c
	gcc -c lex.yy.c

y.tab.o: y.tab.c
	gcc -c y.tab.c

$(DIR_NAME).o: $(DIR_NAME).c
	gcc -c $(DIR_NAME).c

lex.yy.c: $(DIR_NAME).l y.tab.h
	flex $(DIR_NAME).l

y.tab.c: $(DIR_NAME).y
	bison -dty $(DIR_NAME).y

y.tab.h: $(DIR_NAME).y
	bison -dty $(DIR_NAME).y

$(DIR_NAME).c: 
	touch $(DIR_NAME).c
	
clean:
	rm a.out output.txt lex.yy.* y.tab.* $(DIR_NAME).o

