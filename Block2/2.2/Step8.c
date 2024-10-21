int64_t* array_int_min( int64_t* array, size_t size ) {
    if (size != 0) {
        int64_t min_a = array[0];
        size_t index = 0;
        for(size_t i = 0; i<size; i++) {
            if(array[i]<min_a) {
                min_a = array[i];
                index = i;
            }
        }
        return array+index;
    } else {
        return NULL;
    }
}
