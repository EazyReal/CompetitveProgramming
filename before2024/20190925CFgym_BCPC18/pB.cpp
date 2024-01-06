/*
 By NCTU_Oimo, contest: 2018 Benelux Algorithm Programming Contest (BAPC 18), problem: (B) Birthday Boy, Accepted, #
*/

#include<bits/stdc++.h>
using namespace std;
int total[13];
int main(void){
    total[1]=0;
    total[2]=31;
    total[3]=total[2]+28;
    total[4]=total[3]+31;
    total[5]=total[4]+30;
    total[6]=total[5]+31;
    total[7]=total[6]+30;
    total[8]=total[7]+31;
    total[9]=total[8]+31;
    total[10]=total[9]+30;
    total[11]=total[10]+31;
    total[12]=total[11]+30;
    int n;
    const int oct27 = total[10]+27;
    while(cin>>n){
        vector<int> birth;
        for(int i = 0; i < n; i++){
            string temp;
            cin>>temp;
            string date;
            cin>>date;
            int tempdate = total[(date[0]-'0')*10+(date[1]-'0')]+(date[3]-'0')*10+(date[4]-'0');
            birth.push_back(tempdate);
        }
        sort(birth.begin(),birth.end());
        int last_birthday = 365-birth.back();
        int bestbirthday = 0,diff = 0;
        int cur = 0;
        for(int i = 1; i <=365; i++){
            if(birth[cur]==i){
                while(birth[cur]==i){
                                   last_birthday = 0;
                cur++;
                if(cur >n){
                    cur = 0;
                }
                }
            }
            else {
                last_birthday++;
                if(last_birthday > diff){
                    bestbirthday = i;
                    diff = last_birthday;
                }
                else if(last_birthday == diff){
                    int curdiff = bestbirthday - oct27;
                    int checkdiff = i - oct27;
                    if(curdiff <= 0){
                        curdiff += 365;
                    }
                    if(checkdiff <= 0){
                        checkdiff +=365;
                    }
                    if(checkdiff < curdiff){
                        bestbirthday = i;
                        diff = last_birthday;
                    }
                }
            }
        }
        bool output = false;
        for(int i = 1; i <=12; i++){
            if(total[i]>=bestbirthday){
                if(i-1<10){
                    cout<<'0';
                }
                cout<<i-1;
                cout<<'-';
                int remain = bestbirthday - total[i-1];
                if(remain < 10){
                    cout<<'0';
                }
                cout<<remain<<'\n';
                output = true;
                break;
            }
        }
        if(!output){
            cout<<"12-";
            int remain = bestbirthday -total[12];
            if(remain < 10){
                    cout<<'0';
                }
                cout<<remain<<'\n';
        }
    }
}
