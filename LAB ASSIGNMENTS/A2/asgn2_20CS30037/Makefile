a.out: main.o libass2_20CS30037.a
	cc main.o -L. -lass2_20CS30037 

main.o: main.c myl.h
	cc -Wall -c main.c

libass2_20CS30037.a: ass2_20CS30037.o
	ar -rcs libass2_20CS30037.a ass2_20CS30037.o

ass2_20CS30037.o: ass2_20CS30037.c myl.h
	cc -Wall -c ass2_20CS30037.c

clean:
	rm a.out main.o libass2_20CS30037.a ass2_20CS30037.o