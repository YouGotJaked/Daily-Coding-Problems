#
# Find the minimum number of coins required to make n cents.
# You can use standard American denominations, that is, 1c, 5c, 10c, and 25c.
# For example, given n = 16, return 3 since we can make it with a 10c, a 5c, and a 1c.
#

import sys, argparse
denom = [1, 5, 10, 25]

# DP implementation
def minCoins(arr, n):
	# use list comprehension to construct tavble
	table = [[0 for x in range(len(arr))] for y in range(n + 1)]

	# fill entries for base case
	for i in range(len(arr)):
		table[0][i] = 1

	# fill remaining entries using bottom-up approach
	for i in range(1, n + 1):
		for j in range(len(arr)):
			# count solutions including arr[j]
			x = table[i - arr[j]][j] if i - arr[j] >= 0 else 0
			
			# count solutions excluding arr[j]
			y = table[i][j - 1] if j >= 1 else 0

			# total count
			table[i][j] = x + y

	return table[n][len(arr) - 1]

def check_argv(n):
    # argv[0] is always name of script
    num_args = len(sys.argv) - 1
    if num_args != n:
        print "Incorrect number of arguments. There are", num_args, "and should be", n
        sys.exit(1)

def main():
    check_argv(1)
    print minCoins(denom, int(sys.argv[1]))

if __name__ == '__main__':
	main()
