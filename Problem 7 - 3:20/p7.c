/*
 * Given the mapping a = 1, b = 2, ... , z = 26, and an encoded message, count the number of ways it can be decoded.
 * For example, the message '111' would be 3, since it could be decoded as 'aaa', 'ka', and 'ak'.
 * You can assume that the messages are decodable.
 * For example, '001' is not allowed.
 */

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int count_decoding(char *msg, int n) {
    // base cases
    if (n == 0 || n == 1) {
        return 1;
    }
    
    int count = 0;
    
    // last digit must add to number of words if it is not 0
    if (msg[n - 1] > '0') {
        count = count_decoding(msg, n-1);
    }
    
    // consider last two digits and recur if they form a number less than or equal to 26
    if (msg[n - 2] == '1' || (msg[n - 2] == '2' && msg[n - 1] < '7')) {
        count += count_decoding(msg, n-2);
    }
    
    return count;
}

int main() {
    char msg1[] = "111";
    char msg2[] = "1234";
    printf("Count of %s is %d\n", msg1, count_decoding(msg1, strlen(msg1)));
    printf("Count of %s is %d\n", msg2, count_decoding(msg2, strlen(msg2)));
}
