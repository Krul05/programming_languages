/*
struct list {
    int64_t value;
    struct list* next;
};
*/
/* Вы можете пользоваться следующими функциями */
void print_int64(int64_t i);
struct list* node_create( int64_t value );


static int64_t copy( int64_t x ) { return x; }
static int64_t my_abs( int64_t x ) { 
    return x>=0 ? x : x*(-1); 
}
/*  Создать новый список, в котором каждый элемент получен из соответствующего
    элемента списка l путём применения функции f */
struct list* list_map( const struct list * l, int64_t (f) (int64_t))  {
    struct list * new_list = NULL;
    struct list * el = (struct list *) l;
    struct list * i;
    while (el!=NULL) {
        struct list* l = node_create(f(el -> value));
        if (new_list==NULL) {
            new_list = l;
            i = new_list;
        } else {
            (*i).next = l;
            i = (*i).next;
        }
        el = (*el).next;
    }
    return new_list;
}

struct list* list_copy( const struct list * l ) {
    return list_map(l, copy);
}

struct list* list_abs( const struct list * l ) {
    return list_map(l, my_abs);
}
