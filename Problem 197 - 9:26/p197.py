#
# Given an array and a number k that's smaller than the length of the array, rotate the array to the right k elements in-place.
#

def rotate_right(arr, k):
    return arr[-k:] + arr[:-k]

def main():
    arr = [1, 2, 3, 4, 5, 6, 7]
    print("Before rotate: {}\nAfter rotate: {}".format(arr, rotate_right(arr,2)))

if __name__ == '__main__':
    main()
