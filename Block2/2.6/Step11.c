enum move_dir { MD_UP, MD_RIGHT, MD_DOWN, MD_LEFT, MD_NONE };

// Определите тип обработчика событий move_callback с помощью typedef
typedef void move_callback(enum move_dir);

struct list {
  move_callback * value;
  struct list* next;
};
struct list* node_create( move_callback * value ) {
    struct list* l = malloc(sizeof(struct list));
    l -> value = value;
    return l;
}
void list_add_front( struct list ** old, move_callback * value ) {
  struct list* l = node_create(value);
    l -> next = *old;
    *old = l;
}
void list_destroy( struct list* list ) {
  while (list) {
      struct list * l1 = list;
      list = list -> next;
      free( l1);
      
   }
}
// Робот и его callback'и
// callback'ов может быть неограниченное количество
struct robot {
  const char* name;
  struct list * callbacks;
};



// Добавить callback к роботу, чтобы он вызывался при движении
// В callback будет передаваться направление движения
void register_callback(struct robot* robot, move_callback * new_cb) {
    list_add_front(&(robot -> callbacks), new_cb);
}

// Отменить все подписки на события.
// Это нужно чтобы освободить зарезервированные ресурсы
// например, выделенную в куче память
void unregister_all_callbacks(struct robot* robot) {
    list_destroy(robot -> callbacks);
}

// Вызывается когда робот движется
// Эта функция должна вызвать все обработчики событий
void move(struct robot* robot, enum move_dir dir) {
    struct list * el = robot -> callbacks;
    while (el!=NULL) {
        (*(el -> value))(dir);
        el = el -> next;
    }
}
