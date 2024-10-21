struct list* list_read() {
    struct list * list = NULL;
    struct maybe_int64 el = maybe_read_int64();
    struct list * i;
    while (el.valid) {
        struct list* l = node_create(el.value);
        if (list==NULL) {
            list = l;
            i = list;
        } else {
            (*i).next = l;
            i = (*i).next;
        }
        el = maybe_read_int64();
    }
    return list;
}
