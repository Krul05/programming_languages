struct list* list_last( struct list * list ) {
    if (list == NULL) {
        return list;
    }
  struct list * el = list;
    
    while ((*el).next!=NULL) {
        el = (*el).next;
    }
    return el;
}
