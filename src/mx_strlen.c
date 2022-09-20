int mx_strlen(const char *s) {
    int lenth = 0;
    while (*s != '\0') {
        lenth++;
        s++;
    }
    return lenth;
}
