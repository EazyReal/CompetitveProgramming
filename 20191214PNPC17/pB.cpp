#include<bits/stdc++.h>
using namespace std;
int main(void){
  int t;
  cin>>t;
  while(t--){
    int q;
    string s,a;
    cin>>q;
    cin.get();
    getline(cin,s);
    getline(cin,a);
    vector<string> sls, als;
    bool shasbee = false, ahasbee = false;
    vector<int> sbee;
    int abee;
    string stemp;
    for(int i= 0;i<s.size();i++){
      if(s[i]==' '){
        sls.push_back(stemp);
        stemp.clear();
      }
      else stemp.push_back(s[i]);
    }
    if(stemp!=""){
      sls.push_back(stemp);
      stemp.clear();
    }
    for(int i= 0;i<a.size();i++){
      if(a[i]==' '){
        als.push_back(stemp);
        stemp.clear();
      }
      else stemp.push_back(a[i]);
    }
    if(stemp!=""){
      als.push_back(stemp);
      stemp.clear();
    }
    long long addition = 0;
    vector<int> bees;
    for(int i= 0; i<sls.size();i++){
      if(sls[i]=="bee"){
        shasbee = true;
        sbee.push_back(i);
        bees.push_back(addition+i);
        addition+= als.size();
      }
    }
    for(int i = 0; i < als.size();i++){
      if(als[i]=="bee"){
        ahasbee = true;
        abee=i;
        break;
      }
    }
    //cout<<shasbee<<' '<<ahasbee<<'\n';
    for(int i = 0; i < q; i++){
      long long cur;
      cin>>cur;
      --cur;
      if(!shasbee){
        if(cur < sls.size()) cout<<sls[cur]<<"\n";
        else cout<<"DONE\n";
      }
      else if(ahasbee){
        //cout<<sbee[0]<<' '<<abee<<'\n';
        if(cur <= sbee[0]){
          cout<<sls[cur]<<"\n";
        }
        else{
          cout<<als[(cur-sbee[0]-1)%(abee+1)]<<'\n';
        }
      }
      else{
        int iter = -1;
        int l = 0, r = bees.size()-1;
        while(l <= r){
          int mid = (l+r)/2;
          if(bees[mid]<=cur){
            iter = mid;
            l = mid+1;
          }
          else{
            r = mid-1;
          }
        }
        // cout<<iter<<"\n";
        // if(iter != -1)cout<<bees[iter]<<'\n';
        // cout<<als.size()<<"\n";
        if(iter == -1){
          cout<<sls[cur]<<"\n";
        }
        else if(cur-bees[iter]!=0&&cur-bees[iter]<=als.size()){
          cout<<als[cur-bees[iter]-1]<<"\n";
        }
        else if(cur-bees[iter]==0){
          cout<<sls[cur-als.size()*(iter)]<<"\n";
        }
        else{
          cout<<sls[cur-als.size()*(iter+1)]<<"\n";
        }
      }
    }
  }
}
