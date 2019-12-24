CXX := clang++
CXXFLAGS := -std=c++17
DEPS := CompilerInstance.h CodeGen.h Lexer.h Token.h Parser.h Expression.h

%.o: %.cpp $(DEPS)
	$(CXX) -c -o $@ $< $(CXXFLAGS)

compiler: main.o CompilerInstance.o CodeGen.o Lexer.o Parser.o
	$(CXX) $(CXXFLAGS) -o compiler main.o CompilerInstance.o CodeGen.o Lexer.o Parser.o

clean:
	rm compiler *.o
