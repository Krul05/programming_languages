/*

struct maybe_int64 {
  int64_t value;
  bool valid;
};

struct maybe_int64 some_int64(int64_t i) {
  return (struct maybe_int64) { i, true };
}

const struct maybe_int64 none_int64 = { 0 };
*/

size_t read_size() { size_t sz = 0; scanf("%zu", &sz); return sz; }

struct array_int {
    int64_t* data;
    size_t size;
};

void array_int_fill( int64_t* array, size_t sz ) {
  for( size_t i = 0; i < sz; i = i + 1 ) {
    array[i] = read_int64();
  }
}

struct array_int array_int_read() {
  const size_t size = read_size();
  if (size > 0) {
    int64_t* array = malloc( sizeof(int64_t) * size);
    array_int_fill( array, size );
    return (struct array_int) { .data = array, .size = size };
  }
  else return (struct array_int) {0};
}

// возвращает ошибку если индекс за пределами массива
struct maybe_int64 array_int_get( struct array_int a, size_t i ) {
    if (i>=0 && i<a.size) {
      return (struct maybe_int64) { .value = *(a.data+i), .valid = true };
  } else {
      return (struct maybe_int64) {0};
  }
}

// возвращает false если индекс за пределами массива
bool array_int_set( struct array_int a, size_t i, int64_t value ) {
  if (i>=0 && i<a.size) {
      *(a.data+i) = value;
      return true;
  } else {
      return false;
  }
}

void array_int_print( struct array_int array ) {
  for (size_t i = 0; i < array.size; i = i + 1) {
    printf("%" PRId64 " " , array_int_get( array, i).value);
  }
}

struct maybe_int64 array_int_min( struct array_int array ) {
    if (array.size>0) {
        int64_t min_e = *array.data;
        for (size_t i = 1; i<array.size; i++) {
            if (*(array.data + i) < min_e) {
                min_e = *(array.data + i);
            }
        }
        return (struct maybe_int64) { .value = min_e, .valid = true };
    } else {
        return (struct maybe_int64) {0};
    }
}

void array_int_free( struct array_int a ) { 
    if ( a.size > 0 ) {
        free(a.data); 
        a.size = 0;
    } 
}
