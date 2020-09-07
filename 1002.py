import math

T = int(input())
for _ in range(T):
  [x1, y1, r1, x2, y2, r2] = map(int, input().split())
  if x1 == x2 and y1 == y2:
    if r1 == r2:
      print (-1)
    else:
      print (0)
  else:
    r = math.sqrt((y2 - y1) ** 2 + (x2 - x1) ** 2)
    if r > r1 + r2:
      print (0)
    elif r == r1 + r2:
      print (1)
    elif r + r1 == r2 or r + r2 == r1:
      print (1)
    elif r + r1 < r2 or r + r2 < r1:
      print (0)
    else:
      print (2)
      