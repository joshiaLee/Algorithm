import sys
score = sys.stdin.read().strip() 
print(sum(int(i) if int(i) > 40 else 40 for i in score.split("\n")) // 5)
