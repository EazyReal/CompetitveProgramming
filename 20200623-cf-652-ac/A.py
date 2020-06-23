import sys
from bisect import bisect_left
from collections import defaultdict

input = lambda: sys.stdin.readline().rstrip()
R = lambda : map(int,input().split())

#print("executing")
T, = R()
for _ in range(T):
    n,  = R()
    print( "YES" if n%4==0 else  "NO")
