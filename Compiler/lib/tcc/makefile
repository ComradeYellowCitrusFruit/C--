SRC=$(wildcard *.c)
OBJ=$(SRC:%.c=%.o)

libtcc.a: $(OBJ)
	ar rcs $@ $^

$(OBJ): $(SRC)
	gcc -o $@ -c $< -I../lib