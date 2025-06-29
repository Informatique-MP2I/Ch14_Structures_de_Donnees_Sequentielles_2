SRC := Grimaud_golden_ratio
EXE := golden_ratio

.PHONY: clear

$(EXE): $(SRC).ml
	ocamlopt -o $@ $<

clean:
	rm *.cmi *.cmo *.cmx $(SRC).o $(EXE) *~
