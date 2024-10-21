int64_t list_sum( const struct list * list ) {
    int64_t summ = 0;
    struct list * el = (struct list *)list;
    while (el!=NULL) {
        summ+=(*el).value;
        el = (*el).next;
    }
    return summ;
}
