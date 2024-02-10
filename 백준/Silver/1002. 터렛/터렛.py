import math

def turret_positions(x1, y1, r1, x2, y2, r2):
    # 두 터렛 사이의 거리
    distance = math.sqrt((x2 - x1)**2 + (y2 - y1)**2)
    
    # 두 터렛의 반지름 합
    radius_sum = r1 + r2
    
    # 두 터렛의 반지름 차의 절댓값
    radius_diff = abs(r1 - r2)
    
    # 두 터렛이 같은 위치에 있을 때
    if distance == 0:
        if r1 == r2:
            return -1  # 무한대의 위치
        else:
            return 0   # 만나지 않음
    
    # 두 터렛이 외접하거나 내접하는 경우
    if distance == radius_sum or distance == radius_diff:
        return 1
    
    # 그 외의 경우
    if radius_diff < distance < radius_sum:
        return 2
    else:
        return 0

# 테스트 케이스의 개수 입력
T = int(input())

# 각 테스트 케이스에 대해 결과 출력
for _ in range(T):
    x1, y1, r1, x2, y2, r2 = map(int, input().split())
    print(turret_positions(x1, y1, r1, x2, y2, r2))