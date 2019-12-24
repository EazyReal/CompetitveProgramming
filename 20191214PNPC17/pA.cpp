#include <bits/stdc++.h>

using namespace std;
#define pb push_back

typedef long long ll;

int n, k;
const int maxn = 16;

int main()
{
  ios::sync_with_stdio(false);
  //cin.tie(0); cout.tie(0);
  string str;
  cin>>str;
  int happy=0,sad=0;
  for(int i = 0; i < str.size();i++)
  {
    if(str[i]==':'){
      if(i!=0){
        if(str[i-1]=='(') happy++;
        if(str[i-1]==')')sad++;
      }
      if(i != str.size()-1){
        if(str[i+1]==')')happy++;
        if(str[i+1]=='(')sad++;
      }
    }
  }
  cout<<happy<<' '<<sad<<'\n';


  return 0;
}
