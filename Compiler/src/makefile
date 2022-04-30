INC = ../include
SRC = ../src
LIB = ../lib
BIN = ../bin

$(BIN)/CMM_Compiler: $(BIN)/main.o $(BIN)/C_Conversion.o $(BIN)/compile.o $(LIB)/tcc/libtcc.a
	g++ $(BIN)/main.o $(BIN)/C_Conversion.o $(BIN)/compile.o -o $@ -L$(LIB)/tcc/ -ltcc -I$(INC)

$(BIN)/main.o: $(SRC)/main.cpp
	g++ -c -o $@ $^ -I$(INC)

$(BIN)/C_Conversion.o: $(SRC)/C_Conversion.cpp $(INC)/C_Conversion.hpp
	g++ -c -o $@ $< -I$(INC)

$(BIN)/compile.o: $(SRC)/compile.c $(INC)/compile.h $(LIB)/tcc/libtcc.a
	gcc -c -o $@ $(SRC)/compile.c -L$(LIB)/tcc/ -ltcc -I$(INC)

$(LIB)/tcc/libtcc.a:
	$(MAKE) -C $(LIB)/tcc

clean:
	./clean
