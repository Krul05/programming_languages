int is_square(int a) {
    if (a==0) {
        return 1;
    }
    int i = 0;
    while (i*i<a) {
        i += 1;
        if (i*i==a) {
            return 1;
        }
    }
    return 0;
}
