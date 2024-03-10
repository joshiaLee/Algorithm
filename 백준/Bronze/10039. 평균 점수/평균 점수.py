import sys
print(sum(int(i) if int(i) > 40 else 40 for i in sys.stdin.read().strip().split("\n")) // 5)