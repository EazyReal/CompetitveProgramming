//By NCTU_Oimo, contest: NCTU PCCA [191002], problem: (F) On Sum of Fractions, Accepted,

#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

inline LL bin_mul(LL a, LL n, const LL& MOD){
    LL re = 0;
    while(n>0){
        if(n&1)re+=a;
        a+=a; if(a>=MOD) a-=MOD;
        n>>=1;
    }
    return re%MOD;
}

inline LL bin_pow(LL a, LL n, const LL& MOD){
    LL re = 1;
    while(n>0){
        if(n&1) re = bin_mul(re,a,MOD);
        a = bin_mul(a,a,MOD);
        n>>=1;
    }
    return re;
}

bool is_prime(LL n){
    static LL sprp[3] = {2LL,7LL,61LL};
    if(n == 1 ||(n&1)==0)return n == 2;
    int u = n-1, t = 0;
    while((u&1)==0) u >>=1, t++;
    for(int i = 0; i < 3; i++){
        LL x = bin_pow(sprp[i]%n,u,n);
        if(x == 0|| x == 1||x==n-1)continue;
        for(int j= 1; j <t; j++){
            x = x*x%n;
            if(x==1||x==n-1)break;
        }
        if(x==n-1)continue;
        return 0;
    }
    return 1;
}
LL gcd(LL a, LL b){
    if( b== 0){
        return a;
    }
    else {
        return gcd(b,a%b);
    }
}

int main(void){
    int cases;
    cin>>cases;
    while(cases--){
        LL n;
        cin>>n;
        n++;
        LL smaller;
        for(LL i = n; i >= 2; i--){
            if(is_prime(i)){
                smaller = i;
                break;
            }
        }
        LL larger;
        for(LL i = n+1;i <= 10000000000000; i++){
            if(is_prime(i)){
                larger = i;
                break;
            }
        }
        LL num = smaller*larger-2*larger+(n-smaller)*2
        , denum = smaller*larger*2;
        LL red = gcd(num,denum);
        num /=red;
        denum /=red;
        cout<<num<<'/'<<denum<<'\n';


    }
}
