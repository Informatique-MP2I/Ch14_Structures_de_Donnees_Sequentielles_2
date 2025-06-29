// Writes byte on a given file
void write_byte(FILE *f, unsigned char c) {
  fwrite(&c, sizeof(unsigned char), 1, f);
  return;
}
