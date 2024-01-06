#pythonic solution
#71796537	Feb/24/2020 23:43UTC+8	eugalt	B - WeirdSort	Python 3	Accepted	109 ms	4 KB

R=lambda:map(int,input().split())
t,=R()
for _ in[0]*t:
 n,m=R();a=[*R()];b=sorted({*range(1,n+1)}-{*R()})
 for i,j in zip([0]+b,b+[n]):a[i:j]=sorted(a[i:j])
 print('YNEOS'[a>sorted(a)::2])
