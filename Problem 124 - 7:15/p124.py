#
# You have 100 fair coins and you flip them all at the same time.
# Any that come up tails you set aside.
# The ones that come up heads you flip again.
# How many rounds do you expect to play before only one coin remains?
# Write a function that, given n, returns the number of rounds you'd expect to play until one coin remains.
#

import random

def p124():
	rounds = 0
	coins = 100
	
	while coins > 1:
		heads = 0
		for i in xrange(coins):
			if random.random() <= 0.5:
				heads += 1
		rounds += 1
		coins = heads
	
	print "It took {0} rounds until one coin remained".format(rounds)

def main():
	p124()

if __name__ == '__main__':
	main()
