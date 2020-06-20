import sys
from bisect import bisect_left
from collections import defaultdict

input = lambda: sys.stdin.readline().rstrip()
R = lambda : map(int,input().split())

def readint():
    return [int(w) for w in input.split()]

#print("executing")
for _ in range(1):
    s = "codeforces"
    n = len(s)
    k = int(input())
    l = 1
    r = 100
    m = 50
    while(l+1 < r):
        m = (l+r)//2
        #print(m)
        if(pow(m-1, n) >= k): # if not ok
            r = m
        else:
            l = m
    
    lll = l

    l = 0
    r = n+3
    # how much lll
    while(l+1  < r):
        m = (l+r)//2
        if(pow(lll, m-1) * pow(lll-1, n-m+1) >= k): # if not ok
            r = m
        else:
            l = m
    
    howmuch = l
    # print(howmuch, lll)
    # sys.stdout.write('q'*10)

    for i in range(howmuch):
        sys.stdout.write( s[i]*lll )
    for i in range(howmuch, n):
        sys.stdout.write( s[i] *(lll-1))
    print()

