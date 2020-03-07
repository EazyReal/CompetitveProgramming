//https://codeforces.com/contest/1323/submission/72669850
//n*logC, merge sort technique

#include<bits/stdc++.h>
using namespace std;
using ll = unsigned int;
int n;
ll a[400400], ca[30], ans;
vector<int> va[30][2];
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];

    for(int i=1;i<=n;i++) va[0][a[i] & 1].push_back(a[i]);

    for(int k=0;k<30;k++){
        vector<int> pa = va[k][0], pb = va[k][0];
        pa.insert(pa.end(), va[k][1].begin(), va[k][1].end());
        pb.insert(pb.end(), va[k][1].begin(), va[k][1].end());

        int cnt = 0, l1 = 0, l2 = 0, r1 = 0, r2 = 0;
        for(int i=n-1;i>=0;i--){
            int v = pa[i] & ((1<<k+1)-1);
            while(l1 < n && (pb[l1]&((1<<k+1)-1)) < (1<<k)   - v) l1++;
            while(r1 < n && (pb[r1]&((1<<k+1)-1)) < (1<<k)*2 - v) r1++;

            while(l2 < n && (pb[l2]&((1<<k+1)-1)) < (1<<k)*3 - v) l2++;
            while(r2 < n && (pb[r2]&((1<<k+1)-1)) < (1<<k)*4 - v) r2++;

            cnt += r1 - l1 + r2 - l2;
        }
        for(int i=1;i<=n;i++) if((a[i] + a[i]) & (1<<k)) cnt--;
        if(cnt / 2 % 2) ans += 1 << k;

        if(k < 29) for(int i=0;i<n;i++) va[k+1][(pa[i]>>k+1)&1].push_back(pa[i]);
    }
    cout << ans;
}
