import sys
from bisect import bisect_left
from collections import defaultdict

input = lambda: sys.stdin.readline().rstrip()
R = lambda : map(int,input().split())

def readint():
    return [int(w) for w in input.split()]

#print("executing")
T, = R()
for _ in range(T):
    n,  = R()
    a  = R()
    n = len(a)
    cnt = 0
    for i in range(1, n):
        if(a[i] <= a[i-1]):
            d = 10
            a[i] *= 10
            cnt += 1
            while(a[i]+d-1 <= a[i-1]):
                a[i] *= 10
                cnt += 1
                d *= 10
            if(a[i] <= a[i-1]):
                a[i] = a[i-1]+1
    print("Case #{}: {}".format(_+1, cnt))

