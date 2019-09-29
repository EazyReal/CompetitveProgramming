/*
By NCTU_Oimo, contest: 2018 Benelux Algorithm Programming Contest (BAPC 18), problem: (G) Game Night, Accepted
*/

#include<bits/stdc++.h>
using namespace std;
int main(void){
    ios_base::sync_with_stdio(false);
    int n;
    while(cin>>n){
        string seat;
        cin>>seat;
        int acount=0,bcount=0,ccount=0;
        for(int i =0; i < n; i++){
            if(seat[i]=='A'){
                acount++;
            }
            else if(seat[i]=='B'){
                bcount++;
            }
            else {
                ccount++;
            }
        }
        int astart = 0,aend = astart+acount-1,aorigin = astart;
        int bstart = aend+1,bend =bstart+bcount-1,borigin =bstart;
        int cstart = bend+1,ccend = cstart+ccount-1,corigin = cstart;
        //cout<<astart<<' '<<aend<<' '<<bstart<<' '<<bend<<' '<<cstart<<' '<<ccend<<'\n';
        int curmove = 0;
        int mxmove = n;
        for(int i = 0; i < n; i++){
            if(i <= aend && i >= astart&&seat[i]!='A'){
                curmove++;
            }
            if(i <= bend && i>= bstart && seat[i]!='B'){
                curmove++;
            }
            if(i<= ccend && i >= cstart && seat[i]!='C'){
                curmove++;
            }
        }
        //cout<<curmove<<'\n';
        mxmove = min(curmove,mxmove);
        while(true){
            if(acount!=0){
                if(seat[astart]!='A'){
                    curmove--;
                }
                astart = (astart+1)%n;
                if(astart == aorigin){
                    break;
                }
                aend = (aend+1)%n;
                if(seat[aend]!='A'){
                    curmove++;
                }
            }
            if(bcount != 0){
                if(seat[bstart]!='B'){
                    curmove--;
                }
                bstart = (bstart+1)%n;
                if(bstart == borigin){
                    break;
                }
                bend = (bend+1)%n;
                if(seat[bend]!='B'){
                    curmove++;
                }
            }
            if(ccount != 0){
                if(seat[cstart]!='C'){
                    curmove--;
                }
                cstart = (cstart+1)%n;
                if(cstart == corigin){
                    break;
                }
                ccend = (ccend+1)%n;
                if(seat[ccend]!='C'){
                    curmove++;
                }
            }

            //cout<<astart<<' '<<aend<<' '<<bstart<<' '<<bend<<' '<<cstart<<' '<<ccend<<'\n';
            //cout<<curmove<<'\n';
            mxmove = min(curmove,mxmove);
        }
         astart = 0,aend = astart+acount-1,aorigin = astart;
        cstart = aend+1,ccend = cstart+ccount-1,corigin = cstart;
         bstart = ccend+1,bend =bstart+bcount-1,borigin = bstart;
         curmove = 0;
        for(int i = 0; i < n; i++){
            if(i <= aend && i >= astart&&seat[i]!='A'){
                curmove++;
            }
            if(i <= bend && i>= bstart && seat[i]!='B'){
                curmove++;
            }
            if(i<= ccend && i >= cstart && seat[i]!='C'){
                curmove++;
            }
        }
       // cout<<astart<<' '<<aend<<' '<<bstart<<' '<<bend<<' '<<cstart<<' '<<ccend<<'\n';
         //   cout<<curmove<<'\n';
        mxmove = min(curmove,mxmove);
        while(true){
            if(acount!=0){
                if(seat[astart]!='A'){
                    curmove--;
                }
                astart = (astart+1)%n;
                if(astart == aorigin){
                    break;
                }
                aend = (aend+1)%n;
                if(seat[aend]!='A'){
                    curmove++;
                }
            }
            if(bcount != 0){
                if(seat[bstart]!='B'){
                    curmove--;
                }
                bstart = (bstart+1)%n;
                if(bstart == borigin){
                    break;
                }
                bend = (bend+1)%n;
                if(seat[bend]!='B'){
                    curmove++;
                }
            }
            if(ccount != 0){
                if(seat[cstart]!='C'){
                    curmove--;
                }
                cstart = (cstart+1)%n;
                if(cstart == corigin){
                    break;
                }
                ccend = (ccend+1)%n;
                if(seat[ccend]!='C'){
                    curmove++;
                }
            }

            //cout<<astart<<' '<<aend<<' '<<bstart<<' '<<bend<<' '<<cstart<<' '<<ccend<<'\n';
            //cout<<curmove<<'\n';
            mxmove = min(curmove,mxmove);
        }
        cout<<mxmove<<'\n';
    }
}
