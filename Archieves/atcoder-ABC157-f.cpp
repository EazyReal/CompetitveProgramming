#include <bits/stdc++.h>
using namespace std;

#define rep(i, s, t) for(int i = (s); i < (t); ++i)
using namespace std;

typedef long long ll;

//slightly modified template from
//https://atcoder.jp/contests/abc157/submissions/10551937

//L = 0, R = 1e9, time = 100, eps for collision = 1e-12
//their may be some problems in his implementation
// rep(i,1,n)rep(j, 0, i) get WA on 38
//rep(i, 0, n)rep(j, i+1, n) get AC


////
const double eps = 1e-12;

struct Point {
	double x;
	double y;
  Point(double x = 0, double y = 0) : x(x), y(y) {};
	double dist(const Point& p) {
		double dx = x - p.x, dy = y - p.y;
		return sqrt(dx * dx + dy * dy);
	}
};

struct Circle {
	Point p;
	double c;
	double r;

  bool contains(const Point &P)
  {
    return p.dist(P) <= r + eps;
  }

	vector<Point> intersections(const Circle& c) {
		vector<Point> pp;
		double dist = p.dist(c.p);
		if (dist <= r + c.r && r <= dist + c.r && r + dist >= c.r) {
			double dx = c.p.x - p.x, dy = c.p.y - p.y;
			double a = (dx * dx + dy * dy + r * r - c.r * c.r) / 2, dd = dx * dx + dy * dy;
			pp.push_back(Point(
				(a * dx + dy * sqrt(dd * r * r - a * a)) / dd + p.x,
				(a * dy - dx * sqrt(dd * r * r - a * a)) / dd + p.y
			));
			pp.push_back(Point(
				(a * dx - dy * sqrt(dd * r * r - a * a)) / dd + p.x,
				(a * dy + dx * sqrt(dd * r * r - a * a)) / dd + p.y
			));
		}
		return pp;
	}
};
////

int n, k;

vector<Circle> cs;
vector<int> c;

bool C(double T)
{
  rep(i, 0, n) cs[i].r = T/double(c[i]); //given c[i]!=0
  //point is intersection of itself
  vector<Point> all_candicates;
  rep(i, 0, n) all_candicates.push_back(cs[i].p);
  rep(i, 0, n)rep(j, i+1, n)
  {
    auto cur = cs[i].intersections(cs[j]);
    if(cur.size() == 0) continue;
    //if(i==j) assert(cur.size());
    all_candicates.insert(all_candicates.end(), cur.begin(), cur.end());
  }
  //rep(i, 0, all_candicates.size()) cout << all_candicates[i].x << " " << all_candicates[i].y << " \n"[i==all_candicates.size()-1];
  for(auto x : all_candicates)
  {
    int cnt = 0;
    rep(i, 0, n) cnt += int(cs[i].contains(x));
    if(cnt >= k) return true;
  }
  return false;
};

signed main()
{
  cin.tie(0);
  ios::sync_with_stdio(0);
  cin >> n >> k;
  cs.resize(n);
  c.resize(n);
  rep(i, 0, n) cin >> cs[i].p.x >> cs[i].p.y >> c[i];

  //Circle a(0, 0, 1), b(0, 1 ,1);
  //cout << (a.intersections(b)[0].x) << " " << (a.intersections(b)[0].y);

  /*std::function<bool(double)> C = [](double T)
  {
    rep(i, 0, n) cs[i].r = T/double(c[i]); //given c[i]!=0
    //point is intersection of itself
    vector<Point> all_candicates;
    rep(i, 0, n)rep(j, 0, n)
    {
      auto cur = cs[i].intersections(cs[j]);
      all_candicates.insert(all_candicates.end(), cur.begin(), cur.end());
    }
    for(auto x : all_candicates)
    {
      bool inall = 1;
      rep(i, 0, n) inall &= c[i].includes(x);
      if(inall) return true;
    }
    return false;
  };*/

  double L = 0, R = 1e9; //
  double M;
  //const double ans_eps = 1e-10;
  //while(R-L > ans_eps)
  rep(t, 0, 100)
  {
    M = (L+R)/2.0;
    //cout << "M "<<M<<endl;
    if(C(M)) R = M;
    else L = M;
  }
  cout << fixed << setprecision(20) << L << endl;

  return 0;
}

//need to learn how to set eps and precusion
