dic = {'A+': 4.3, 'A0': 4.0, 'A-': 3.7,
       'B+': 3.3, 'B0': 3.0, 'B-': 2.7,
       'C+': 2.3, 'C0': 2.0, 'C-': 1.7,
       'D+': 1.3, 'D0': 1.0, 'D-': 0.7,
       'F': 0.0}
n = int(input())
sum = 0
total = 0
for i in range(n):
    _, credit, grade = input().split(" ")
    credit = int(credit)
    total += credit
    sum += credit * dic[grade]

sum = int((sum / total) * 1000)
if sum % 10 >= 5:
    sum = sum - (sum % 10) + 10
else:
    sum = sum - (sum % 10)

print('{:.2f}'.format(sum / 1000))
