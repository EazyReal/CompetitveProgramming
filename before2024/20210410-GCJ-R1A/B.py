import sys
from bisect import bisect_left
from collections import defaultdict

input = lambda: sys.stdin.readline().rstrip()
R = lambda : map(int,input().split())

def readint():
    return [int(w) for w in input.split()]

## build p table
ps = []
pid = defaultdict(int)

for i in range(2, 500):
    flag = 1
    for j in range(2, i):
        if(i%j==0):
            flag = 0
            break
    if flag:
        pid[i] = len(ps)
        ps.append(i)

# print(len(ps))
#for i in range(len(ps)):
#    print(ps[i])

T, = R()
for _ in range(T):
    M,  = R()
    cnt = defaultdict(int)
    ans = 0
    summ = 0
    for i in range(M):
        a, b, = R()
        cnt[a] = b
        summ += a*b
    
    for val in range(summ, 1, -1): # from 2 to summ enum there prime factor and cmp
        flag = 0
        cur = val
        cnt2 = cnt.copy()
        for p in ps:
            # divide
            while(cur%p==0):
                if(cnt2[p] == 0):
                    flag = 1 
                    break
                cnt2[p] -= 1
                cur /= p
            if flag:
                break
        if flag or cur != 1:
            continue
        cur_sum = 0
        for pp, cc in cnt2.items():
            cur_sum += pp*cc
        # print(cur_sum)
        if(cur_sum == val):
            ans = val
            break
    
    print("Case #{}: {}".format(_+1, ans))

