# Makefile - hashtable
SRC := Nom_hashtable
LIB := hashtable
EXE := ht
CFLAGS=-Wall -O2 -g -fsanitize=address

.PHONY: clean

$(EXE): $(SRC).c $(LIB).o $(LIB).h
	gcc $(CFLAGS) -o $@ $(SRC).c $(LIB).o 

$(LIB).o: $(LIB).c $(LIB).h
	gcc -c $< -o $@

clean:
	rm $(SRC).o $(LIB).o $(EXE) *~
