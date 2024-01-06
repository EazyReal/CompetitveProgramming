#wonder why my on-contest way is wrong:(
#linearity of expectations should be true even when dependent
#only ~500 people get pB righton contest 
import math

mod = 10**9 + 7

n = int(input())
x = list(map(int,input().split()))
dis = [x[i]-x[i-1] for i in range(1,n)]
f = (math.factorial(n-1))%mod
def modinv(a, mod=mod):
    return pow(a, mod-2, mod)

count = 0
suminv = 0
for i in range(1,n):
    suminv += modinv(i)
    suminv %= mod
    count += dis[i-1]*suminv
    count %= mod
count = (count*f)%mod

print(int(count))
