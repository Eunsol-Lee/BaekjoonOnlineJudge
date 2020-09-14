T = int(input())

for _ in range(T):
  x1, y1, x2, y2 = map(int, input().split())
  N = int(input())
  count = 0
  for _ in range(N):
    cx, cy, r = map(int, input().split())
    in1 = r ** 2 > (x1 - cx) ** 2 + (y1 - cy) ** 2
    in2 = r ** 2 > (x2 - cx) ** 2 + (y2 - cy) ** 2
    count += in1 != in2
  print (count)
