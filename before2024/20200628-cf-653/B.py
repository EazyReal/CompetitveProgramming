import sys
from bisect import bisect_left
from collections import defaultdict

input = lambda: sys.stdin.readline().rstrip()
R = lambda : map(int,input().split())

#print("executing")
T, = R()
for _ in range(T):
    n, = R()
    c2 = 0
    c3 = 0
    while(n%2 == 0):
        c2 += 1
        n /= 2
    while(n%3 == 0):
        c3 += 1
        n /= 3
    
    if(n != 1 or c3 < c2):
        print(-1)
    else:
        print(2*c3-c2)
