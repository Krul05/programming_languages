void list_destroy( struct list* list ) {
  while (list) {
      struct list * l1 = list;
      list = list -> next;
      free( l1);
      
   }
}
