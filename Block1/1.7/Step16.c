int is_whitespace(char c) { return c == ' ' || c == '\t' || c == '\n'; }

int string_count(char* str) { 
    int i = 0;
    int count = 0;
    while((str[i])!=0) {
        count+=1;
        i+=1;
    }
    return count;
}

int string_words(char* str)  {
    int i = 1;
    int count = 0;
    if (!is_whitespace(str[0]) && str[0]!=0) {
        count+=1;
    }
    while((str[i])!=0) {
        if(is_whitespace(str[i-1]) && !is_whitespace(str[i])) {
            count+=1;
        }
        i+=1;
    }
    return count;
}
