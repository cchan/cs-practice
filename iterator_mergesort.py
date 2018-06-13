# This is a horrifying example of Pythonicity gone too far.

import itertools

class peekable(object):
  NoneLeft = object()
  def __init__(self, iterator):
    self.iterator = iterator
    try:
      self.peeked = next(iterator)
    except StopIteration:
      self.peeked = self.NoneLeft
  def __iter__(self):
    return self
  def __next__(self):
    if self.peeked is self.NoneLeft:
      raise StopIteration
    else:
      oldPeeked = self.peeked
      try:
        self.peeked = next(self.iterator)
      except StopIteration:
        self.peeked = self.NoneLeft
      return oldPeeked
  def __peek__(self):
    return self.peeked

def peek(x):
  return x.__peek__()

def itermerge(iter1, iter2):
  iter1 = peekable(iter1)
  iter2 = peekable(iter2)
  while True:
    if peek(iter1) is peekable.NoneLeft or peek(iter2) is peekable.NoneLeft:
      yield from iter1
      yield from iter2
      break
    if peek(iter1) < peek(iter2):
      yield next(iter1)
    else:
      yield next(iter2)

def sort(arr):
  width = 1
  while True:
    if width > len(arr):
      break
    for i in range(0, len(arr), 2 * width):
      left = i
      mid = i + width
      right = i + 2 * width
      arr[left:right] = list(itermerge(itertools.islice(arr, left, mid),itertools.islice(arr, mid, right)))
    width *= 2

a = [1,4,3,9,2]
print(a)
sort(a)
print(a)
