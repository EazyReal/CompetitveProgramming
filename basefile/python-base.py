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
    n, m = R()
