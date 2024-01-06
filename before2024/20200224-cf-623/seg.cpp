long long seg[maxn*8],mx[maxn*8],a[maxn],p[maxn];
int u,v;
void pull(int id)
{
  mx[id] = max(mx[id*2],mx[id*2+1]) + seg[id];
}
void push(int id)
{
  seg[id*2] += seg[id];
  seg[id*2+1] += seg[id];
  seg[id] = 0;
  pull(id*2);
  pull(id*2+1);
  pull(id);
}
void add(int l,int r,int val,int id)
{
  if(u <= l && r <= v)
  {
    seg[id] += val;
    pull(id);
    return;
  }
  push(id);
  int m = (l + r) / 2;
  if(u <= m) add(l,m,val,id*2);
  if(v > m) add(m+1,r,val,id*2+1);
  pull(id);
  return;
}
