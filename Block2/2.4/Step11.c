void list_add_front( struct list** old, int64_t value );

// создать перевернутую копию списка
struct list* list_reverse( const struct list * list ) {
    struct list * reversed_list = NULL;
    struct list * el = (struct list *)list;
    while (el!=NULL) {
        list_add_front(&reversed_list, (*el).value);
        el = (*el).next;
    }
    return reversed_list;
}
