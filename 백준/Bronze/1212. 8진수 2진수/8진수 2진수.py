s = input()

dic1 = {"1": "1", "2":"10", "3": "11"}

dic2 = {"0": "000", "1": "001", "2": "010",
       "3": "011", "4": "100", "5": "101",
       "6": "110", "7": "111"}

if s == "0":
    print(s)
    exit()

ans = []
if int(s[0]) <= 3:
    ans.append(dic1[s[0]])
else:
    ans.append(dic2[s[0]])

for i in range(1, len(s)):
    ans.append(dic2[s[i]])

print("".join(ans))
