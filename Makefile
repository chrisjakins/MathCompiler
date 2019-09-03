CC=clang++
CFLAGS=
DEPS = CompilerInstance.h

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

compiler: main.o CompilerInstance.o
	$(CC) -o compiler main.o CompilerInstance.o

clean:
	rm compiler *.o
