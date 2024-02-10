while True:
    balance, act, money = input().split(" ")
    if balance == '0' and act == 'W' and money == '0':
        break
    
    balance = int(balance)
    money = int(money)
    
    if act == 'W':
        if balance - money < -200:
            print("Not allowed")
        else:
            print(balance - money)
    else:
        print(balance + money)