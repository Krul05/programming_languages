/*
struct list {
    int64_t value;
    struct list* next;
};
*/
void print_int64(int64_t i);


/* Запустить функцию f на каждом элементе списка  */
void list_foreach( const struct list * l, void (f)(int64_t)) {
    struct list * el = (struct list *) l;
    while (el!=NULL) {
        f(el -> value);
        el = (*el).next;
    }
}

/* Вывести список с помощью foreach и дополнительной функции */
void list_print(const struct list * l) { 
    list_foreach(l, print_int64_space);
}
