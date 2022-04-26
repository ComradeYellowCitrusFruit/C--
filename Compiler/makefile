INC = `pwd`/include
SRC = `pwd`/src
LIB = `pwd`/lib
BIN = `pwd`/bin

CMM_Compiler: $(BIN)/main.o $(BIN)/C_Conversion.o $(BIN)/compile.o $(LIB)/libtcc.a
	g++ $(BIN)/main.o $(BIN)/C_Conversion.o $(BIN)/compile.o -o $@ -L$(LIB)/libtcc.a

$(BIN)/main.o: $(SRC)/main.cpp
	g++ -c -o $@ $^

$(BIN)/C_Conversion.o: $(SRC)/C_Conversion.cpp $(INC)/C_Conversion.hpp
	g++ -c -o $@ $<

$(BIN)/compile.o: $(SRC)/compile.c $(INC)/compile.h $(LIB)/libtcc.a
	gcc -c -o $@ $(SRC)/compile.c -L$(LIB)/libtcc.a

$(LIB)/libtcc.a: $(BIN)/libtcc.o
	ar rcs $@ $^

$(BIN)/libtcc.o: $(LIB)/libtcc.c $(LIB)/libtcc.h
	gcc -c -o $@ $<
