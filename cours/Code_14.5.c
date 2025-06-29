int main(int argc, char **argv) {
  FILE *file = fopen("test.bin", "wb");
  if (file == NULL) {
    perror("Error while openning the file.\n");
    return 1;
  } 
  serialize_bool(file, true);
  serialize_int(file, 35);
  serialize_string(file, "Hello world!Bye bye...\n");
  fclose(file); 
  return 0;
}
