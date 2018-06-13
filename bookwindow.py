from collections import OrderedDict # linkedhashmap
import math

# book is an array of strings, of length N
# words is a set of strings, of length k
# find the smallest window in book where all the words in words are present, order ignored
def solution(book, words):
  smallestWindow = (float("-inf"), float("inf"))
  lastPos = OrderedDict()
  for i, word in enumerate(book): # N times the below
    if word in words: # O(1)
      if word in lastPos:
        del lastPos[word]
      lastPos[word] = i
    else:
      continue
    if len(lastPos) == len(words):
      newWindow = (next(iter(lastPos.values())), next(reversed(lastPos.values()))) # O(1)
      if newWindow[1] - newWindow[0] < smallestWindow[1] - smallestWindow[0]: # O(1)
        smallestWindow = newWindow # O(1)

  return None if math.isinf(smallestWindow[1] - smallestWindow[0]) else smallestWindow

  # TOTAL: O(N) time
  #        O(k) space

print(solution("the quick brown fox jumped over the lazy dog".split(" "), set("the jumped lazy".split(" "))))
