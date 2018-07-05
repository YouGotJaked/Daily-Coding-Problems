/*
 * Given a string of words delimited by spaces, reverse the words in string.
 * For example, given "hello world here", return "here world hello".
 * Follow-up: given a mutable string representation, can you perform this operation in place?
 */

#include <stdio.h>

void reverse(char *start, char *end);

void reverse_words(char *str) {
    char *start = NULL;
    char *temp = str;
    
    // reverse individual words
    while (*temp) {
        if (start == NULL && *temp != ' ') {
            start = temp;
        } else if ((start && *(temp + 1) == ' ') || (*(temp + 1) == '\0')) {
            reverse(start, temp);
            start = NULL;
        }
        temp++;
    }
    
    // reverse whole string
    reverse(str, temp - 1);
}

void reverse(char *start, char *end) {
    char temp;
    while (start < end) {
        temp = *start;
        *start++ = *end;
        *end-- = temp;
    }
}

int main() {
    char str[] = "hello world here";
    char *temp = str;
    reverse_words(str);
    printf("%s\n", str);
    return 0;
}
