BASE=assn6_20CS30037_20CS30049

tinyC: lex.yy.o $(BASE).tab.o $(BASE)_translator.o $(BASE)_target_translator.o
	g++ lex.yy.o $(BASE).tab.o $(BASE)_translator.o $(BASE)_target_translator.o -lfl -o tinyC
	@echo "\nMake process successful. The binary generated is tinyC\n"

$(BASE)_target_translator.o: $(BASE)_target_translator.cxx
	g++ -c $(BASE)_target_translator.cxx

$(BASE)_translator.o: $(BASE)_translator.h $(BASE)_translator.cxx
	g++ -c $(BASE)_translator.h
	g++ -c $(BASE)_translator.cxx

lex.yy.o: lex.yy.c
	g++ -c lex.yy.c

$(BASE).tab.o: $(BASE).tab.c
	g++ -c $(BASE).tab.c

lex.yy.c: $(BASE).l $(BASE).tab.h $(BASE)_translator.h
	flex $(BASE).l

$(BASE).tab.c: $(BASE).y
	bison -dtv $(BASE).y

$(BASE).tab.h: $(BASE).y
	bison -dtv $(BASE).y

lib$(BASE).a: $(BASE).o
	ar -rcs lib$(BASE).a $(BASE).o

$(BASE).o: $(BASE).c myl.h
	gcc -c $(BASE).c

$(BASE).c:
	touch $(BASE).c

test: tinyC lib$(BASE).a
	@mkdir -p test_outputs
	@mkdir -p bin

	@echo "\nTesting tinyC on sample test C files ...\n"
	@echo "\nTEST 1 ...\n"
	./tinyC 1 < test_inputs/$(BASE)_test1.c > test_outputs/$(BASE)_quads1.out
	mv $(BASE)_1.s test_outputs/$(BASE)_1.s
	gcc -c test_outputs/$(BASE)_1.s -o test_outputs/$(BASE)_1.o
	gcc test_outputs/$(BASE)_1.o -o bin/test1 -L. -l$(BASE) -no-pie

	@echo "\nTEST 2\n"
	./tinyC 2 < test_inputs/$(BASE)_test2.c > test_outputs/$(BASE)_quads2.out
	mv $(BASE)_2.s test_outputs/$(BASE)_2.s
	gcc -c test_outputs/$(BASE)_2.s -o test_outputs/$(BASE)_2.o
	gcc test_outputs/$(BASE)_2.o -o bin/test2 -L. -l$(BASE) -no-pie

	@echo "\nTEST 3\n"
	./tinyC 3 < test_inputs/$(BASE)_test3.c > test_outputs/$(BASE)_quads3.out
	mv $(BASE)_3.s test_outputs/$(BASE)_3.s
	gcc -c test_outputs/$(BASE)_3.s -o test_outputs/$(BASE)_3.o
	gcc test_outputs/$(BASE)_3.o -o bin/test3 -L. -l$(BASE) -no-pie

	@echo "\nTEST 4\n"
	./tinyC 4 < test_inputs/$(BASE)_test4.c > test_outputs/$(BASE)_quads4.out
	mv $(BASE)_4.s test_outputs/$(BASE)_4.s
	gcc -c test_outputs/$(BASE)_4.s -o test_outputs/$(BASE)_4.o
	gcc test_outputs/$(BASE)_4.o -o bin/test4 -L. -l$(BASE) -no-pie

	@echo "\nTEST 5\n"
	./tinyC 5 < test_inputs/$(BASE)_test5.c > test_outputs/$(BASE)_quads5.out
	mv $(BASE)_5.s test_outputs/$(BASE)_5.s
	gcc -c test_outputs/$(BASE)_5.s -o test_outputs/$(BASE)_5.o
	gcc test_outputs/$(BASE)_5.o -o bin/test5 -L. -l$(BASE) -no-pie

	@echo "\nTAC quads and asm files saved to test_outputs .../\n"
	@echo "The binaries for the test files are in bin/\n"

clean:
	rm -f lex.yy.c *.tab.c *.tab.h *.output *.o *.s *.a *.out *.gch tinyC test_outputs/* bin/*
	rm -rf bin
