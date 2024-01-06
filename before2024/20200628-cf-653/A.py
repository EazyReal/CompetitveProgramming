import sys
from bisect import bisect_left
from collections import defaultdict

input = lambda: sys.stdin.readline().rstrip()
R = lambda : map(int,input().split())

#print("executing")
T, = R()
for _ in range(T):
    x, y, n = R()
    b = x*((n)//x)+y
    if(b > n):
        b -= x
    print(b)
