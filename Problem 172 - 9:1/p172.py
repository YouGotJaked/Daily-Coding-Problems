#
# Given a string s and a list of words words, where each word is the same length, find all starting indices of substrings in s that is a concatenation of every word in words exactly once.
# For example, given s = "dogcatcatcodecatdog" and words = ["cat", "dog"], return [0, 13], since "dogcat" starts at index 0 and "catdog" starts at index 13.
# Given s = "barfoobazbitbyte" and words = ["dog", "cat"], return [] since there are no substrings composed of "dog" and "cat" in s.
# The order of the indices does not matter.
#

def find_substring_indices(s, words):
    # list to store indices
    lst = []
    # check for empty string
    if not words:
        return lst
    # length of word in words list
    len_word = len(words[0])
    # number of words in words list
    num_words = len(words)
    # total characters in words list
    tot_char = len_word * num_words
    # return empty list if total characters in words is greater than length of s
    if tot_char > len(s):
        return lst
    # use dictionary to store words in list against its occurences
    hash_map = dict()
    for i in xrange(num_words):
        hash_map.update({words[i] : 1})
    for i in xrange(len(s) - tot_char + 1):
        temp_map = hash_map.copy()
        j = i
        # traverse substring
        while (j < i + tot_char):
            # extract word
            word = s[j:j+len_word]
            # break if not found
            if word not in hash_map:
                break
            # else decrement word count from hash
            else:
                temp_map[word] = temp_map[word] - 1
            j = j + len_word
        count = 0
        for k,v in temp_map.items():
            if v > 0:
                count = count + 1
        # store starting index of substring
        if count == 0:
            lst.append(i)
    return lst

def main():
    s = "dogcatcatcodecatdog"
    words = ["cat", "dog"]
    print s, words, find_substring_indices(s, words)
    s1 = ""
    words1 = ["foo", "bar"]
    print s1, words1, find_substring_indices(s1, words1)
    s2 = "wordgoodgoodgoodbestword"
    words2 = ["word","good","best","word"]
    print s2, words2, find_substring_indices(s2, words2)
if __name__ == '__main__':
	main()
