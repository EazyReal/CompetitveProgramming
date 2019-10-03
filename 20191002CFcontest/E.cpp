//By NCTU_Oimo, contest: NCTU PCCA [191002], problem: (E) Fixed Points, Accepted, #

#include<bits/stdc++.h>
using namespace std;
int main(void){
    ios_base::sync_with_stdio(false);
    int n;
    while(cin>>n){
        int cnt = 0;
        int num[n];
        int add = 0;
        for(int i = 0; i < n; i++){
            cin>>num[i];
        }
        for(int i = 0; i < n; i++){
            if(num[i]==i){
                cnt++;
            }
            else{
                int other = num[i];
                if(num[other]==i){
                    add = 2;
                }
                else{
                    add = max(add,1);
                }
            }
        }
        cout<<cnt+add<<'\n';
    }
}
