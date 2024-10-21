struct heap_string {
  char* addr;
};

// скопировать в кучу
struct heap_string halloc( const char* s ) {
    struct heap_string h;
    h.addr = malloc(sizeof( char ) * (strlen(s)+1));
    strcpy(h.addr, s);
    return h;
}

// освободить память
void heap_string_free( struct heap_string h ) {
    free(h.addr);
}
