#include<bits/stdc++.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    int T;
    fstream fs("fetiera.in");
    fs>>T;
    while(T--){
        double total = 0;
        int n,k;
        fs>>n>>k;
        //long long tt = n*(n+1)/2*n*(n+1)/2;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                int cur;
                fs>>cur;
                double flipped = (double((i*j))/((n*(n+1))/2)) * ((n-i+1)*(n-j+1)/((n*(n+1)/2)));
                double curc = cur;
                for(int l = 1; l <= k; l++){
                    curc = curc*(1.0-flipped)+(1.0-curc)*flipped;
                }
                total += curc;
            }
        }
        cout<<fixed<<setprecision(5)<<total<<'\n';
    }
}
