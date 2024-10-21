struct maybe_int64 maybe_read_int64() {
    int64_t a;
    if(scanf ("%"SCNd64,  &a)>0) {
        return (struct maybe_int64) {.value=a, .valid = true};
    } else {
        return (struct maybe_int64) {0};
    }
}
