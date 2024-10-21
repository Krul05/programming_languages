// Возвращает 1 если в числе одна цифра, иначе 0
int is_single_digit(int n) {
    if ((n>=0 && n<=9) || (n<0 && n>=-9)) {
        return 1;
    } else {
        return 0;
    }
}

// Возвращает 1 если в числе ровно две цифры, иначе 0
int is_double_digit(int n) {
    if ((n>=10 && n<=99) || (n<-10 && n>=-99)) {
        return 1;
    } else {
        return 0;
    }
}
