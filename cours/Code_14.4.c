// Binary serialization function for booleans
void serialize_bool(FILE *f, bool b) {
  // 0 for false, 255 for true
  unsigned char c = b ? 255 : 0;
  write_byte(f, c);
  return;
}
// Binary serialization function for integers
void serialize_int(FILE *f, int n) {
  // Writing byte by byte taking into account endianness
  for (int i = 0; i < sizeof(int); ++i) {
    int byte = n >> (i*8) & 0xFF;
    write_byte(f, (unsigned char)byte);
  }
  return;
}
// Binary serialization function for a string
void serialize_string(FILE *f, char *s) {
  size_t length = strlen(s);
  for (size_t i = 0; i < length; ++i) {
    write_byte(f, (unsigned char)s[i]);
  }
  write_byte(f, '\0'); // final character
  return;
}
