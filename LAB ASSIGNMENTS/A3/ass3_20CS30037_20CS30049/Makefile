output.txt: a.out ass3_20CS30037_20CS30049_test.c
	./a.out < ass3_20CS30037_20CS30049_test.c > output.txt

a.out: lex.yy.c ass3_20CS30037_20CS30049.c	
	gcc lex.yy.c ass3_20CS30037_20CS30049.c -lfl

lex.yy.c: ass3_20CS30037_20CS30049.l
	flex ass3_20CS30037_20CS30049.l

clean:
	rm lex.yy.c a.out output.txt