// Fast Fibonacci mod 10^9 + 7
// Fastest implementation of https://dmoj.ca/problem/fibonacci2/
// Fundamental algorithm derived from https://www.nayuki.io/res/fast-fibonacci-algorithms/fastfibonacci.py
// Possibly useful: https://en.wikipedia.org/wiki/Pisano_period#Fibonacci_integer_sequences_modulo_n

#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"

#include <stdio.h>

typedef unsigned long long ull;

const ull MODCONST = 1000000007;
const ull MODCONST21 = 2000000016;

ull fib(register ull N) {
  register ull mask = 1ull<<(sizeof(ull) * 8 - __builtin_clzll(N) - 1);
  register ull a = 0;
  register ull b = 1;
  register ull tmpa;

  while(mask) {
    tmpa = a;
    if(mask & N) {
      a = (a * a + b * b) % MODCONST; // a^2 + b^2
      b = ((tmpa * 2 + b) * b) % MODCONST; // 2ab - a^2 + a^2 + b^2
    } else {
      a = (a * (b * 2 + MODCONST - a)) % MODCONST; //2ab - a^2
      b = (tmpa * tmpa + b * b) % MODCONST; //a^2 + b^2
    }
    mask >>= 1;
  }
  return a;
}

#define BUFSIZE 65536
#define repeat(x) x x x x x x x x // must be a power of 2, dividing BUFSIZE
char _buf[BUFSIZE + 1];

int main() {
  register char * _pbuf = _buf;
  register char _;
  register ull N = 0;
  while(1){
    if(!*_pbuf) _buf[fread_unlocked(_pbuf = _buf, 1, BUFSIZE, stdin)] = 0;
    repeat(
      if(__builtin_expect((_ = *_pbuf++) < '0', 0)) break;
      N = (N * 10 + _ - '0');
    )
    N %= MODCONST21;
  }

  printf("%llu\n", fib(N % MODCONST21));
}
