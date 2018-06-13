import sys
import operator

m = 2**32 - 5

"""
m = 2**10 - 5

f = 1
for x in range(1, m+1):
  f = (f * x) % m
  if f % 100 == 0:
    print(x, "! = ", f)

exit()
"""

precomputed = []

sys.stdin.readline()
numbers = {int(x): i for i, x in enumerate(sys.stdin.read().split('\n')) if len(x) and int(x) > 0}
results = [1] * len(numbers)
for x,i in numbers.items():
  results[i] = precomputed[x // 10000000]
minimum, maximum = min(numbers.keys()), max(numbers.keys())

f = 1
for x in range(1, minimum):
  f = (f * x) % m
for x in range(minimum, maximum + 1):
  f = (f * x) % m
  if x in numbers:
    results[numbers[x]] *= = f

for i in range(len(numbers)):
  print(results[i])

"""
results = [1] * len(numbers)
def sieve(max):
  ...
  yield primes until max
  ...

for p in sieve(max(numbers)): // 50M
  for i, n in enumerate(numbers): // 1000
    results[i] *= p**(n // p + n // p // p + ...) % m
    
def factorialMod(n):
  if n >= p:
    return 0

  n! mod p

z = n + 1
(z/e)^z sqrt(2pi/z) ( 1 + 1/12z + 1/288z^2 - 139/51940z^3 - 571/2488320z^4)...
"""
