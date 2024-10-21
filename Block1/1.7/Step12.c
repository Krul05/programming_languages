void array_fib(int* array, int* limit) {
    int n = limit-array;
    if (n==0) {
        return;
    } else if (n==1) {
        array[0] = 1;
    } else {
        array[0] = 1;
        array[1] = 1;
        for (int i = 2; i<n; i+=1) {
            array[i] = array[i-2]+array[i-1];
        }
    }
}
