#!/usr/local/bin/python3

import math
import numpy

_ = int(input())

def all_primes(start, end):
   return list(sorted(set(range(start, end + 1)).difference(set((p * f) for p in range(2, int(end ** 0.5) + 2) for f in range(2, (end // p) + 1)))))

def primesfrom2to(n):
   “”" Input n>=6, Returns a array of primes, 2 <= p < n “”"
   sieve = numpy.ones(n//3 + (n%6 == 2), dtype=numpy.bool)
   for i in range(1, int(n**0.5)//3+1):
       if sieve[i]:
           k=3*i+1|1
           sieve[k*k//3::2*k] = False
           sieve[k*(k-2*(i&1)+4)//3::2*k] = False
   return numpy.r_[2,3,((3*numpy.nonzero(sieve)[0][1:]+1)|1)]

for i in range(_):
   x = int(input())
   if x < 6:
       l = all_primes(2, x)
   else:
       l = primesfrom2to(x)
   ans = 0
   for i, p in enumerate(l):
       if 2*p > x:
           break
       if x - p in l:
           ans += 1
   print(ans)

