a, b = input().split(" ")
m_a, m_b = ["", ""]
M_a, M_b = ["", ""]
for c,d in zip(a, b):
    if c == '5':
        c = '6'
    if d == '5':
        d = '6'
    
    M_a += c
    M_b += d
    
    if c == '6':
        c = '5'
    if d == '6':
        d = '5'
    
    m_a += c
    m_b += d

print(int(m_a) + int(m_b), int(M_a) + int(M_b))