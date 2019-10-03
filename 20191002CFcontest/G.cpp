//By NCTU_Oimo, contest: NCTU PCCA [191002], problem: (G) Friends and Presents, Accepted

#include<bits/stdc++.h>
using namespace std;
int main(void){
    long long cnt1, cnt2, x,y;
    while(cin>>cnt1>>cnt2>>x>>y){
        long long l = cnt1+cnt2, r = 100000000000000;
        long long mn = r;
        while(l <= r){
            long long mid = (l+r)/2;
            long long lcm = x*y;
            long long both = mid / lcm;
            long long yonly = mid/x - both;
            long long xonly = mid/y - both;
            long long remain = mid - both - yonly- xonly;
            long long required = max(0ll,cnt1-xonly)+max(0ll,cnt2-yonly);
            if(required <= remain){
                mn = mid;
                r = mid-1;
            }
            else {
                l = mid+1;
            }
        }
        cout<<mn<<'\n';
    }
}
