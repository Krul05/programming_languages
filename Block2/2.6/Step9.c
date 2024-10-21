// Мы хотим, чтобы в структуре user хранились ссылки только на строчки из кучи.
typedef struct { char* addr; } string_heap ;
/*  Тип для идентификаторов пользователей
    и его спецификаторы ввода и вывода для printf */
typedef uint64_t uid;
#define PRI_uid PRIu64
#define SCN_uid SCNu64
enum city {C_SARATOV, C_MOSCOW, C_PARIS, C_LOS_ANGELES, C_OTHER};

/*  Массив, где элементам перечисления сопоставляются их текстовые представления */
const char* city_string[] = {
  [C_SARATOV] = "Saratov",
  [C_MOSCOW] = "Moscow",
  [C_PARIS] = "Paris",
  [C_LOS_ANGELES] = "Los Angeles",
  [C_OTHER] = "Other"
};


struct user {
  const uid id;
  const string_heap name;
  enum city city;
};
int uid_comparer(const struct user * u1, const struct user * u2) {
  if ((*u1).id > (*u2).id) return 1;
  if ((*u1).id < (*u2).id) return -1;
  return 0;
}
int uid_void_comparer(const void* _u1, const void* _u2 ) {
  return uid_comparer(_u1, _u2 );
}
int name_comparer(const struct user * u1, const struct user * u2) {
    int result = strcmp((*u1).name.addr, (*u2).name.addr);
    return result;
}
int name_void_comparer(const void* _u1, const void* _u2 ) {
  return name_comparer(_u1, _u2 );
}
int city_comparer(const struct user * u1, const struct user * u2) {
    int result = strcmp(city_string[(*u1).city], city_string[(*u2).city]);
    return result;
}
int city_void_comparer(const void* _u1, const void* _u2 ) {
  return city_comparer(_u1, _u2 );
}



/* Сортировать массив пользователей по полю uid по возрастанию */
void users_sort_uid(struct user users[], size_t sz) {
    qsort(users, sz,  sizeof(struct user), uid_void_comparer);
}

/* Сортировать массив пользователей по полю name */
/* Порядок строк лексикографический; можно использовать компаратор 
   строк -- стандартную функцию strcmp */
void users_sort_name(struct user users[], size_t sz) {
  qsort(users, sz,  sizeof(struct user), name_void_comparer);
}

/* Сортировать массив по _текстовому представлению_ города */
void users_sort_city(struct user users[], size_t sz) {
  qsort(users, sz,  sizeof(struct user), city_void_comparer);
}
