//By longlong233, contest: Codeforces Round #615 (Div. 3), problem: (D) MEX maximizing, Accepted, #, hack it!
//after contest check ans
//this is simpler, m increasing and check condition

#include<iostream>
using namespace std;
int a[400005];
int main()
{
	int n,x;
	int m=0;
	cin>>n>>x;
	for(int i=0;i<n;i++)
	{
		int k;
		cin>>k;
		a[k%x]++;
		while(a[m%x]>m/x)
		m++;
		cout<<m<<"\n";
	}

}
