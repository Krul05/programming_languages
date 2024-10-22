/*
struct list {
    int64_t value;
    struct list* next;
};
*/
void print_int64(int64_t i);

struct list* node_create( int64_t value );
void list_destroy( struct list* list );


/*  Сгенерировать список длины sz с помощью значения init и функции f
 Результат: init, f(init), f(f(init)), ... */
struct list* list_iterate( int64_t init, size_t sz, int64_t(f)(int64_t)) {
    struct list * new_list = NULL;
    size_t size = 0;
    struct list * i;
    while (size<sz) {
        struct list* l;
        if (new_list==NULL) {
            l = node_create(init);
            new_list = l;
            i = new_list;
        } else {
            l = node_create(f(init));
            (*i).next = l;
            i = (*i).next;
            init = l -> value;
        }
        size+=1;
    }
    return new_list;
}
