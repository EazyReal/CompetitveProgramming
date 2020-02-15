#include <bits/stdc++.h>
using namespace std;

int main(){

    int T;
    cin >> T;
    for (int t=0; t<T; t++){

    int r, c, k;
    cin >> r >> c >> k;
    if (k==r*c-1){
        cout << "Case #" << t+1 << ": ";
        cout << "IMPOSSIBLE\n";
    }else{
        cout << "Case #" << t+1 << ": POSSIBLE\n";
        k=r*c-k;//有k个人不能走
        int anz=0;
        if (c==1){//c==1的特判

            //不能走的人里一个人往南走，另外k-1个人往北走，形成死路。
            cout << "S\n";
            for (int i=1; i<k; i++){
                cout << "N\n";
            }
            //剩下的人往南走
            int e=1;
            for (int i=max(k, e); i<r*c; i++){
                cout << "S\n";
            }
            continue;
        }

        for (int i=0; i<r; i++){
            for (int j=0; j<c; j++){
                if (i==0 && j==0){
                    cout << "E";//第一格固定往东走
                    anz++;
                }else{
                    if (i==0){
                        if (anz<k){
                            cout << "W";//第一行在有人没走的时候往西走，否则往东走
                            anz++;
                        }else{
                            cout << "E";
                        }
                    }else{
                        if(anz<k){
                            cout << "N"; //其他行在有人没走的时候往北走，否则往南走
                            anz++;
                        }else{
                            cout << "S";
                        }
                    }
                }
            }
            cout << "\n";
        }

    }
    }

}
