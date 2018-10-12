#
# Given a string of digits, generate all possible valid IP address combinations.
#
# IP addresses must follow the format A.B.C.D, where A, B, C, and D are numbers between 0 and 255.
# Zero-prefixed numbers, such as 01 and 065, are not allowed, except for 0 itself.
#
# For example, given "2542540123", you should return ['254.25.40.123', '254.254.0.123']
#

def valid_ip(ip):
    # divide by octets
    ip = ip.split(".")

    for i in ip:
        # case 1: not between 0 and 255
        if len(i) > 3 or int(i) < 0 or int(i) > 255:
            return False
        # case 2: multiple zeroes
        if len(i) > 1 and int(i) == 0:
            return False
        # case 3: zero-prefixed
        if len(i) > 1 and int(i) != 0 and int(i[0]) == 0:
            return False
    return True

def str_to_ip(str):
    l_str = len(str)
    # base case
    if (l_str > 12):
        return []
    tmp = str
    lst = [] # store combinations
    for i in range(1, l_str - 2): # first octet
        for j in range(i + 1, l_str - 1): # second octet
            for k in range(j + 1, l_str): # third octet
                tmp = tmp[:k] + "." + tmp[k:] # add first .
                tmp = tmp[:j] + "." + tmp[j:] # add second .
                tmp = tmp[:i] + "." + tmp[i:] # add third .
                print(tmp)
                if valid_ip(tmp):
                    lst.append(tmp)
                tmp = str
    return lst

def main():
    print(str_to_ip("2542540123"))

if __name__ == '__main__':
    main()
