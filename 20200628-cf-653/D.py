import sys
from bisect import bisect_left
from collections import defaultdict

input = lambda: sys.stdin.readline().rstrip()
R = lambda : map(int,input().split())

#print("executing")
T, = R()
for _ in range(T):
    n, k = R()
    a = list(R())
    cnt = defaultdict(int)
    for i in range(n):
        cnt[a[i]%k] += 1
    
    mx = -1
    #print(cnt)
    for kk, vv in cnt.items():
        #print(kk,vv)
        if(kk != 0): 
            mx = max(mx, k*(vv-1) + (k-kk))
    
    print(mx+1)
