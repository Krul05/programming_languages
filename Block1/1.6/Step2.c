int read_int() {
    int res = 0; 
    scanf("%d", &res);
    return res; 
}

int main() {
    int i = read_int();
    if (i>10) {
        printf("No");
    }
    while (i<=10) {
        printf("%d ", i);
        i += 1;
    }
    return 0;
}
