SRC := Grimaud_magic_square
EXE := magic_square

.PHONY: clear

$(EXE): $(SRC).ml
	ocamlopt -o $@ $<

clean:
	rm *.cmi *.cmo *.cmx $(SRC).o $(EXE) *~
