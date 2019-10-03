By NCTU_Oimo, contest: NCTU PCCA [191002], problem: (H) Alice and Bob, Accepted, #

#include<bits/stdc++.h>
using namespace std;
int gcd( int a, int b){
    if(b == 0){
        return a;
    }
    else {
        return gcd(b, a%b);
    }
}
int main(void){
    int n;
    while(cin>>n){
        int num[n];
        for(int i = 0; i < n; i++){
            cin>>num[i];
        }
        int gd = gcd(num[0],num[1]);
        for(int i= 2; i < n; i++){
            gd = gcd(gd,num[i]);
        }
        for(int i= 0; i < n; i++){
            num[i]=num[i]/gd;
        }
        int mx=-1;
        for(int i = 0; i < n; i++){
            mx = max(mx,num[i]);
        }
        int remain = mx-n;
        if(remain %2 == 1){
            cout<<"Alice\n";
        }
        else {
            cout<<"Bob\n";
        }
    }
}
close
