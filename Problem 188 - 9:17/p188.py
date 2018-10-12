# What will this code print out?

def make_functions():
	flist = []
	for i in [1, 2, 3]:
		def print_i():
			print(i)
		flist.append(print_i)
	return flist

functions = make_functions()
for f in functions:
	f()

# This code prints out:
# 3
# 3
# 3

# How can we make it print out what we apparently want?


