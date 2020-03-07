#include <bits/stdc++.h>
using namespace std;

int n;
int a[400000+5];

inline int read() {
    int x;
    cin >> x;
    return x;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
	n=read();
	for(int i=0; i<n; i++) a[i]=read();
  int ans = 0;
	for(int i=25; i>=0; i--){
		int x=0,b=(1<<i);
		sort(a, a+n);
		for(int j=0; j<n; j++){
			if((b<=2*a[j] && 2*a[j]<2*b) || 2*a[j]>=3*b) x--;
			x-=lower_bound(a, a+n, max(0, b-a[j]))-a;
			x+=lower_bound(a, a+n, max(0, 2*b-a[j]))-a;
			x-=lower_bound(a, a+n, max(0, 3*b-a[j]))-a;
			x+=n;
		}
		x>>=1;
		if(x&1) ans+=(1<<i);
		for(int j=0; j<n; j++) a[j]&=b-1;
	}
	cout<<ans<<endl;
	return 0;
}
