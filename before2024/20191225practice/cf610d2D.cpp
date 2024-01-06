#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

int q(string s)
{
	int x;
	cout << s << endl;
	cin >> x;
	if(!x || x==-1) exit(0);
	else return x;
}

int main()
{
  //ios::sync_with_stdio(false);
  int l = q("a"); //for l-1 or l if no a
  string s(l,'b');
  int best = q(s);
  //if all b, AC
  //if no b, return l, ans = (l+1)*a with len l+1, finish at len+2
  //if with a and b, len = l+1
  ++l, s+='b';
  for(int i = 0; i < l; i++)
  {
  	s[i] = 'a';
  	int now = q(s);
  	if(now>best) s[i] = 'b';
  	else best = now;
  }
  return 0;
}
