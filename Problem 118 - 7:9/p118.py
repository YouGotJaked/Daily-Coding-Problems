#
# Given a sorted list of integers, square the delements and give the output in sorted order.
# For example, given [-9, -2, 0, 2, 3], return [0, 4, 4, 9, 81].
#

def sort_squares(arr, n):
	for i in range(n):
		arr[i] = arr[i] * arr[i]
	arr.sort()

def main():
	arr = [-9, -2, 0, 2, 3]
	print arr
	sort_squares(arr, len(arr))
	print arr

if __name__ == '__main__':
	main()
