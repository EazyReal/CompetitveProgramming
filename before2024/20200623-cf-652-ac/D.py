import sys
from bisect import bisect_left
from collections import defaultdict

input = lambda: sys.stdin.readline().rstrip()
R = lambda : map(int,input().split())

#print("executing")
maxn = int(2e6+5)
mod = int(1e9+7)
dp = [0, 0, 0]
for i in range(3, maxn):
    dp.append( (dp[i-1] + dp[i-2]*2 + int(i%3==0)) % mod)

T, = R()
for _ in range(T):
    n, = R()
    print(dp[n]*4%mod)
