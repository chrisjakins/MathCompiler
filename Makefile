CC=clang++
CFLAGS=
DEPS = CompilerInstance.h Lexer.h Token.h

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

compiler: main.o CompilerInstance.o Lexer.o
	$(CC) -o compiler main.o CompilerInstance.o Lexer.o

clean:
	rm compiler *.o
