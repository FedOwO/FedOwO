void memory_set(char *dest, char val, unsigned int len) {
    char *temp = (char *)dest;
    for ( ; len != 0; len--) *temp++ = val;
}
