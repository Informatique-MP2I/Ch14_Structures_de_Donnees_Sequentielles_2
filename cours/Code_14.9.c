typedef struct {
  char *name;
  int age;
  bool hero;
} character_s; 
// JSON format serialization function of a character
void serialize_character(FILE *f, character_s c) {
  fprintf(f, "{ \"name\": \"%s\", \"age\": %d, \"hero\": %s }",
    c.name, c.age, c.hero ? "true" : "false");
  return;
}
