/*
 * Given an unsigned 8-bit integer, swap its even and odd bits.
 * The 1st and 2nd bit should be swapped, the 3rd and 4th bit should be swapped, and son on.
 * For example, 10101010 should be 01010101. 11100010 should be 11010001.
 * Bonus: Can you do this in one line?
 */

#include <stdio.h>
#include <stdint.h>

// right shift even bits, left shit odd bits, and combine
uint8_t swap_bits(uint8_t num) {
    return ((num & 0xAAAAAAAA) >> 1 | (num & 0x55555555) << 1);
}

void print_swap(uint8_t num) {
    printf("%u shifts to %u\n", num, swap_bits(num));
}

int main() {
    uint8_t x = 170, y = 226; // 10101010 and 11100010
    print_swap(x); // 01010101 (85)
    print_swap(y); // 11010001 (209)
    return 0;
}
