struct maybe_int64 list_at(  const struct list* list, size_t idx ) {
    if (list == NULL) {
        return (struct maybe_int64) {0};
    }
    size_t size = 0;
    struct list * el = (struct list *)list;
    while (size!=idx && el!=NULL) {
        size++;
        el = (*el).next;
    }
    if (el == NULL) {
        return (struct maybe_int64) {0};
    }
    return (struct maybe_int64) {.value = (*el).value, .valid = true};
}
