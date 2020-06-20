import sys
from bisect import bisect_left
from collections import defaultdict

input = lambda: sys.stdin.readline().rstrip()
R = lambda : map(int,input().split())

#print("executing")
#T, = R()
#for _ in range(T):
n, = R()
s = input()
t = input()

pre = 0
mn = n+5
mx = 0

for i,j in zip(s,t):
    if(i > j):
         pre += 1
    elif(i < j):
         pre -= 1
    mn = min(mn, pre)
    mx = max(mx, pre)

if(pre != 0):
    print(-1)
else:
    print(mx-mn)