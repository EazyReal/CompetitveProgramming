import sys
from bisect import bisect_left
from collections import defaultdict

input = lambda: sys.stdin.readline().rstrip()
R = lambda : map(int,input().split())

def readint():
    return [int(w) for w in input.split()]

#print("executing")
T, N = R()
for _ in range(T):
    for i in range(1, N):
        print("M {} {}".format(i, N))
        X, = R()
        if( i != X):
            print("S {} {}".format(i, X))
            X, = R()
    print("D")
    X, = R()
