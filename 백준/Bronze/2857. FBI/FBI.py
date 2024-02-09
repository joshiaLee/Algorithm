
agent_list = []

for i in range(5):
    agent = input()
    agent_list.append(agent)
flag = 1
for i, s in enumerate(agent_list):
    if s.find("FBI") != -1:
        flag = 0
        print(i+1)


if flag:
    print("HE GOT AWAY!")