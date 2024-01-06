/*
By NCTU_Oimo, contest: 2018 Benelux Algorithm Programming Contest (BAPC 18), problem: (C) Cardboard Container, Accepted, #
*/

#include<bits/stdc++.h>
using namespace std;
int main(void){
    int v;
    while(cin>>v){
        long long mn = -1;
        for(int i = 1; i <= sqrt(v); i++){
            for(int j = 1; j <= i; j++){
                if(v%(i*j)==0){
                    long long temp = v/(i*j);
                    long long area = 2*i*j+2*temp*i+2*temp*j;
                    if(mn == -1||area < mn){
                        mn = area;
                    }
                }
            }
        }
        cout<<mn<<'\n';
    }
}
