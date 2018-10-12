#
# Given n numbers, find the greatest common denominator between them.
# For example, given the numbers [42, 56, 14], return 14.
#

def find_gcd(x, y):
	while (y):
		x,y = y, x % y
	return x

def main():
	lst = [42, 56, 14]
	n1 = lst[0]
	n2 = lst[1]
	gcd = find_gcd(n1,n2)

	for i in range(2, len(lst)):
		gcd = find_gcd(gcd, lst[i])
	
	print lst
	print gcd

if __name__ == '__main__':
	main()
