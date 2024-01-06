/*
By NCTU_Oimo, contest: 2018 Benelux Algorithm Programming Contest (BAPC 18), problem: (F) Financial Planning, Accepted
*/


#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

int n;
LL M;
const int maxn = 100005;
LL p[maxn];
LL c[maxn];
LL d[maxn];

LL L, R;

bool C(LL x)
{
    LL sum = 0;
    for(int i = 0; i<n; i++)
    {
        sum += max(p[i]*x-c[i], 0LL);
        if (sum >= M) return true;
    }
    return sum >= M;
}


int main(void){
    cin >> n;
    cin >> M;
    for(int i = 0; i<n; i++)
    {
        cin >> p[i] >> c[i];
        //d[i] = c[i]/p[i] + ((c[i]%p[i])?1:0);
    }
    LL bst = 2000000010;
    L = 0, R = 2000000005;
    while(L <= R)
    {
//        LL m = L+(R-L)/2;
        LL m = (L + R) / 2LL;
        if(C(m)) {
//                bst = min(bst,m);
                R = m-1;}
        else L = m+1;
    }

    cout << L;

    return 0;
}
