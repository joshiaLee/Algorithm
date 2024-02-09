dic = {"a": 1, "e": 1, "i": 1, "o": 1, "u": 1,
       "A": 1, "E": 1, "I": 1, "O": 1, "U": 1}

while True:
    ans = 0
    s = input()
    if s == "#":
        break
    for c in s:
        if c in dic:
            ans += dic[c]
    print(ans)

        
