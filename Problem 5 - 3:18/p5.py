#!/usr/bin/python
#
# cons(a, b) constricts a pair, and car(pair) and cdr(pair) returns the first and last elements of that pair.
# For example, car(cons(3, 4)) returns 3, and cdr(cons(3, 4)) returns 4.
#
# Given this implementation of cons:
#   def cons(a, b):
#       return lambda f : f(a, b)
#
# Implement car and cdr.
#

def cons(a, b):
    return lambda f : f(a, b)

def car(pair):
    return lambda pair : pair[0]

def cdr(pair):
    return lambda pair : pair[1:]

def main():
    print cons(3, 4)
    print car(cons(3, 4))
    print cdr(cons(3, 4))

if __name__ == '__main__':
    main()
