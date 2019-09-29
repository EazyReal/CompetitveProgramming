//2017 Taiwan Online Programming Contest pC
//competitive programming 2 week 1 assignment 1 2019fall
//author = YT Lin
//date = 2019.9.29

#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

typedef long long LL;

int T, n;
struct Node{
	LL val; //should use long long ><
	int type;
}node[200005];

bool cmp(const Node& l, const Node& r)
{
	return ((l.val < r.val) || ( (l.val == r.val) && (l.type > r.type)));
}

int main()
{
	//std::ios::sync_with_stdio(false);
	//cin.tie(0);
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n);
		int tmp = 1;
		for(int i = 0; i < 2*n; i++)
		{
			scanf("%lld", &node[i].val);
			node[i].type = tmp;
			tmp = -tmp;
		}
		sort(node, node+ (2*n), cmp);
		int cnt = 0;
		int maxc = 0;
		for(int i = 0; i < 2*n; i++)
		{
			cnt += node[i].type;
			maxc = max(maxc, cnt);
		}
		printf("%d\n", maxc);
	}
	return 0;
}
