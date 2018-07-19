#
# Write a function that rotates a list by K elements.
# For example, [1, 2, 3, 4, 5, 6] rotated by two becomes [3, 4, 5, 6, 1, 2].
# Try solving this without creating a copy of the list.
# How many swap or move operations do you need?
#

def rotate_left(arr, k):
	for i in xrange(k):
		rotate_left_one(arr)

def rotate_left_one(arr):
	last = len(arr) - 1
	temp = arr[0]
	for i in range(last):
		arr[i] = arr[i + 1] 
	arr[last] = temp

def main():
	arr = [1, 2, 3, 4, 5, 6]
	rotate_left(arr, 2)
	print arr

if __name__ == '__main__':
	main()
