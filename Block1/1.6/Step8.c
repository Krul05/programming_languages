int is_prime(int n) {
    int i = 2;
    if (n<=1) {
        return 0;
    }
    while (i<n) {
        if (n%i==0) {
            return 0;
        }
        i+=1;
    }
    return 1;
}
