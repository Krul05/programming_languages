size_t list_length(const struct list * l ) {
    size_t size = 0;
    struct list * el = (struct list *)l;
    while (el!=NULL) {
        size++;
        el = (*el).next;
    }
    return size;
}
