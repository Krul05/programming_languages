void array_reverse(int* array, int size) {
    for (int i = 0; i<size/2; i+=1) {
        int sw = array[i];
        array[i] = array[size-i-1];
        array[size-i-1] = sw;
    }
}

void array_reverse_ptr(int* array, int* limit) {
    array_reverse(array, limit-array);
}
