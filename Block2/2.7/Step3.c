/*
struct list {
    int64_t value;
    struct list* next;
};
*/

/* Изменить каждый элемент списка с помощью функции f  */
void list_map_mut(const struct list * l, int64_t (f) (int64_t))  {
    struct list * el = (struct list *) l;
    while (el!=NULL) {
        el -> value = f(el -> value);
        el = (*el).next;
    }
}


static int64_t triple( int64_t x ) { return x * 3; }

/* Используя list_map_mut умножьте все элементы списка на 3 */
void list_triple(const struct list * l) { 
    list_map_mut(l, triple);
}
