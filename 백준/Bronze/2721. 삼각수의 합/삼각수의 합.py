t = [sum(range(i+1)) for i in range(302)]
w = [sum(k*t[k+1] for k in range(n+1)) for n in range(301)]
for i in range(int(input())):
    print(w[int(input())])