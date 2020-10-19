import sys
import random

random.seed()

n = int(sys.argv[1])

high = []
low = []

for i in range(0, n):
  a = random.randint(1, 10000000)
  b = random.randint(1, 10000000)

  if a > b:
    low.append(b)
    high.append(a)
  else:
    low.append(a)
    high.append(b)

max = sum(high)
min = sum(low)

C = random.randint(min, max)
X = random.randint(min, C)

print C
print X

for i in low:
  print i,

print ""

for i in high:
  print i,

print ""
