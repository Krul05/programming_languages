// position -- адрес указателя на первый элемент E в массиве,
// для которого predicate(E) выполняется.
// Функция возвращает 0 если элемент не найден.
int array_contains(int* array, int* limit, int** position) {
    for (*position = array; *position < limit; ++(*position))
        if (predicate(**position))
            return 1;
    return 0;
}
