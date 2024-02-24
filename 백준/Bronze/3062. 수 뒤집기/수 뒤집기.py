t = int(input())
for _ in range(t):
  s = input()
  r_s = s[::-1]
  sum = str(int(s) + int(r_s))
  print("YES" if sum == sum[::-1] else "NO")