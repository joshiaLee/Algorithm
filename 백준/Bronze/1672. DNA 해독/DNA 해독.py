num = int(input())
s = input()

dic = {"AA": "A", "AG": "C", "AC": "A", "AT": "G",
       "GA": "C", "GG": "G", "GC": "T", "GT": "A",
       "CA": "A", "CG": "T", "CC": "C", "CT": "G",
       "TA": "G", "TG": "A", "TC": "G", "TT": "T"}

pre = s[num-1]

# if num is 10, this loop repeat 9 times(0~8) 
for i in range(num-2,-1,-1):
    dic_s = s[i] + pre
    pre = dic[dic_s]
    

print(pre) 

    
        