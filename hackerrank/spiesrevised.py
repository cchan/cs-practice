# 999 deep
# 999 children per node
# do a dfs of course

# 0 - 998
import sys
import operator

size = 13

def go(prevPositions):
  if len(prevPositions) == size:
    for x in prevPositions:
      sys.stdout.write(str(x + 1) + " ")
    print()
    for i, x in sorted(enumerate(prevPositions), key=operator.itemgetter(1)):
      print(i * "." + "x" + (size-1-i)*".")
    sys.exit(0)
  # 1. Automatically can't be in same column
  # 2. Can't be in same row
  valid = set(range(size)).difference(prevPositions)
  for left, top in enumerate(prevPositions):
    # 3. Can't be in same diagonal
    hzntl_dist = len(prevPositions) - left
    valid.discard(top - hzntl_dist)
    valid.discard(top + hzntl_dist)
  for x1, y1 in enumerate(prevPositions[:-1]):
    for x2, y2 in enumerate(prevPositions[x1+1:], start=x1+1):
      # 4. Can't be in same line (0,0) (1,2)
      thing = (y2 - y1) * (len(prevPositions) - x1)
      if thing % (x2 - x1) == 0:
        valid.discard(y1 + thing / (x2 - x1))
        #print(len(prevPositions), y1 + thing / (x2 - x1), x1, y1, x2, y2)
  for i, position in enumerate(valid):
    if i > 4:
      break
    if len(prevPositions) < 5:
      print((" " * len(prevPositions)), position)
    go(prevPositions + [position])

# go([])

from math import gcd

grid = [[0 for i in range(size)] for j in range(size)]
positions = [None] * size

def reduce_slope(dx, dy):
  g = gcd(dx, dy)
  if dx < 0:
    g = -g
  return dx//g, dy//g

def gridify(x, y, inc):
  for x1 in range(size):
    if x1 == x:
      continue
    grid[x1][y] += inc
    if y+x-x1 >= 0 and y+x-x1 < size:
      grid[x1][y+x-x1] += inc
    if y-x+x1 >= 0 and y-x+x1 < size:
      grid[x1][y-x+x1] += inc
  for x1, y1 in enumerate(positions):
    if y1 is not None and x != x1 and y != y1:
      dx, dy = reduce_slope(x-x1, y-y1)
      initx, inity = x % dx, y - (x // dx) * dy
      for x2 in range(initx, size, dx):
        if x2 == x:
          continue
        y2 = inity + (x2 - initx) * dy // dx
        if y2 >= 0 and y2 < size:
          grid[x2][y2] += inc

def add(x, y):
  if positions[x] is not None:
    raise "tried adding a position that already exists"
  positions[x] = y
  gridify(x, y, 1)

def remove(x, y = None):
  if positions[x] is None:
    raise "tried removing a position that does not exist"
  if y is None:
    y = positions[x]
  positions[x] = None
  gridify(x, y, -1)

def printgrid():
  print("-" * (size * 3 + 2))
  for y in range(size):
    sys.stdout.write("|")
    for x in range(size):
      sys.stdout.write((str(grid[x][y]) if grid[x][y] > 9 else " "+str(grid[x][y]))+" ")
    print("|")
  print("-" * (size * 3 + 2))

from random import randint
def addMinCountInCol(colnum):
  if positions[colnum] is not None:
    remove(colnum)
  minj = -1
  mincount = float('inf')
  for j in range(size):
    if mincount > grid[colnum][j] or mincount == grid[colnum][j] and randint(0,1) == 0:
      mincount = grid[colnum][j]
      minj = j
  add(colnum, minj)

for x in range(1000):
  for i in range(size):
    addMinCountInCol(i)

printgrid()
print(positions)
print([grid[col][positions[col]] for col in range(size)])
