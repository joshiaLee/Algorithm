while True:
    num = input()
    if num == "0":
        break
    while(len(num) != 1):
        num = str(sum(int(x) for x in num))
    print(num)
            