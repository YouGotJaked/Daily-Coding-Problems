#
# Given an even number (greater than 2), return two prime numbers whose sum will be equal to the given number.
# A solution will always exist. See Goldbach's conjecture.
#
# Example:
# Input: 4
# Output: 2 + 2 = 4
#
# If there are more than one solution possible, return the lexicographically smaller solution.
# If [a,b] is one solution with a <= b, and [c,d] is another solution with c <= d, then [a,b] < [c,d] if a < c OR a == c AND b < d.
# use Sieve of Eratosthenes algorithm to generate all prime numbers less than n
#

from __future__ import print_function

def generatePrimeList(n, isPrime):
    isPrime[0] = isPrime[1] = False
    for i in range(2, n + 1):
        isPrime[i] = True

    p = 2
    while (p*p <= n):
        # prime if isPrime[p] not changed
        if (isPrime[p] == True):
            # update multiples of p
            i = p * 2
            while (i <= n):
                isPrime[i] = False
                i += p
        p += 1

# print prime pair with given sum
def primePair(sum):
    isPrime = [0] * (sum + 1)
    generatePrimeList(sum, isPrime)

    for i in xrange(0,sum):
        if (isPrime[i] and isPrime[sum - i]):
            print("n = {}\n{} + {} = {}".format(sum, i, sum - i, sum))
            return

def main():
    n = 4
    primePair(n)

if __name__ == '__main__':
    main()
