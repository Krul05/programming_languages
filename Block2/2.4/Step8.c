void list_add_back( struct list** old, int64_t value ) {
    if (*old == NULL) {
        list_add_front(old, value);
    } else {
        struct list* l = node_create(value);
        (*list_last(*old)).next = l;
    }
}
