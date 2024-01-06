import sys
from bisect import bisect_left
from collections import defaultdict

input = lambda: sys.stdin.readline().rstrip()
R = lambda : list(map(int,input().split()))

#print("executing")
T, = R()
for _ in range(T):
    n, m = R()
    a = R()
    w = R()
    a.sort(reverse=True)
    w.sort()
    ans = 0
    l, r = 0, n-1
    mark = m
    for i in range(m):
        if(w[i] == 1):
            ans += a[l]*2
            l += 1
        else:
            mark = i
            break
    for i in range(m-1, mark-1, -1):
        hid = w[i]-2
        ans += a[l] + a[r]
        r -= hid+1
        l += 1
    print(ans)
