#
# A Collatz sequence in mathematics can be defined as follows
# Starting with any positive integer:
#	If n is even, the next number in the sequence is n / 2
#	If n is odd, the next number in the sequence is 3n + 1
# It is conjectured that every such sequence eventually reaches the number 1.
# Test this conjecture.
#
# Bonus: What input n <= 1000000 gies the longest sequence?

from sys import exit

def collatz(n):
    # base cases
    try:
        n = int(n)
    except TypeError:
        print("ERROR: Input must be an integer.")
        exit(1)
    try:
        if n < 1:
            raise ValueError
    except ValueError:
        print("ERROR: Input must be positive.")
        exit(1)

    seq = [n]
    while (n != 1):
        n = n//2 if n%2 == 0 else 3*n+1
        seq.append(n)
    return seq

def main():
    max = 0
    max_n = 0
    for n in range(1000000, 1, -1):
        l_seq = len(collatz(n))
        if l_seq > max:
            max = l_seq
            max_n = n
    print("The longest sequence goes to n={} of length {}".format(max_n,max))

if __name__ == '__main__':
    main()
