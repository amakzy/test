#include "shell.h"

void print_string_to_stderr(char *str) {
    if (!str) {
        return;
    }
    for (int i = 0; str[i] != '\0'; i++) {
        print_char_to_stderr(str[i]);
    }
}
int print_char_to_stderr(char c) {
    static int index;
    static char buffer[WRITE_BUFFER_SIZE];
    if (c == BUFFER_FLUSH || index >= WRITE_BUFFER_SIZE) {
        write(2, buffer, index);
        index = 0;
    }
    else if (c != BUFFER_FLUSH) {
        buffer[index++] = c;
    }
    return 1;
}
int print_char_to_fd(char c, int fd) {
    int i = 0;
    static int index;
    static char buffer[WRITE_BUFFER_SIZE];
    if (c == BUFFER_FLUSH || index >= WRITE_BUFFER_SIZE) {
int print_char_to_fd(char c, int fd);
        write(fd, buffer, index);
        index = 0;
    }
    else if (c != BUFFER_FLUSH) {
        buffer[index++] = c;
    }
    return 1;
}
int print_string_to_fd(char *str, int fd) {
    if (!str) {
        return 0;
    }
    int count = 0;
    while (*str) {
        count += print_char_to_fd(*str++, fd);
    }
    return count;
}
