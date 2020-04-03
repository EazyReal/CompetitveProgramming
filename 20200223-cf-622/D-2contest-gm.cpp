//By SARS-CoV-2, contest: Codeforces Round #622 (Div. 2), problem: (D) Happy New Year, Accepted, #, Copy
//nlogn sort+unique+lower_bound coordinate compression

#include<bits/stdc++.h>
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
int L[100010],R[100010],U[200010],u;
int f[200010][1<<8|1];
std::vector<int>v[200010];
int MX[1<<8|1],par[1<<8|1],pos[200010];
int main(){
#ifdef LOCAL
	freopen("in.in","r",stdin);
	//freopen("out.out","w",stdout);
#endif
	int n=gi(),____=gi(),___=gi();
	for(int i=1;i<=n;++i)L[i]=gi(),R[i]=gi()+1,U[++u]=L[i],U[++u]=R[i];
	std::sort(U+1,U+u+1);u=std::unique(U+1,U+u+1)-U-1;
	for(int i=1;i<=n;++i)L[i]=std::lower_bound(U+1,U+u+1,L[i])-U;
	for(int i=1;i<=n;++i)R[i]=std::lower_bound(U+1,U+u+1,R[i])-U-1;
	for(int i=1;i<=n;++i)for(int j=L[i];j<=R[i];++j)v[j].push_back(i);
	memset(f,-63,sizeof f);
	for(int i=0;i<1<<8;++i)par[i]=__builtin_parity(i);
	f[0][0]=0;
	memset(pos,-1,sizeof pos);
	for(int i=0;i<u;++i){
		int o=v[i].size();
		memset(MX,-63,sizeof MX);
		for(int j=0;j<1<<o;++j){
			int S=0;
			for(int k=0;k<o;++k)if((j>>k&1)&&R[v[i][k]]>i)S|=1<<k;
			if(par[j]&&f[i][j]>=0)f[i][j]+=U[i+1]-U[i];
			MX[S]=std::max(MX[S],f[i][j]);
		}
		int old=0;
		for(int j=0;j<v[i].size();++j)pos[v[i][j]]=-1;
		for(int j=0;j<v[i+1].size();++j)pos[v[i+1][j]]=j;
		for(int j=0;j<o;++j)if(~pos[v[i][j]])old|=1<<pos[v[i][j]];
		int O=v[i+1].size();
		for(int j=0;j<1<<o;++j){
			if(MX[j]>=0){
				int nS=0;
				for(int k=0;k<o;++k)
					if((j>>k&1)&&R[v[i][k]]>i)
						nS|=1<<pos[v[i][k]];
				int E=((1<<O)-1)^old;
				for(int k=E;;k=(k-1)&E){
					f[i+1][k|nS]=std::max(f[i+1][k|nS],MX[j]);
					if(!k)break;
				}
			}
		}
	}
	printf("%d\n",f[u][0]);
	return 0;
}