import sys
from bisect import bisect_left
from collections import defaultdict

input = lambda: sys.stdin.readline().rstrip()
R = lambda : map(int,input().split())

#print("executing")
T, = R()
for _ in range(T):
    n, = R()
    s = input()
    ba = 0
    mx = 0
    for i in range(n):
        ba += 1 if (s[i] == '(') else -1
        mx = max(mx, -ba)
    # print("hi", _)
    #if ba == 0 :
    #   print(0)
    #else :
    print(mx)
