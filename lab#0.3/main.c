#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char *str = NULL;
    size_t len = 0;
    printf("Enter a string: ");
    if (getline(&str, &len, stdin) == -1) return 1;

    const int min = 32,
            max = 255;

    for (int i = 0; i < len; i++) {
        char ch = str[i];
        if (ch < min || ch > max) {
            printf("%c is not in range\n", ch);
        } else {
            printf("%c - %i\n", ch, ch);
        }
    }


    free(str);
    return 0;
}
