CC=clang++
CFLAGS = -std=c++17
DEPS = CompilerInstance.h Lexer.h Token.h Parser.h

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

compiler: main.o CompilerInstance.o Lexer.o Parser.o
	$(CC) -o compiler main.o CompilerInstance.o Lexer.o Parser.o

clean:
	rm compiler *.o
