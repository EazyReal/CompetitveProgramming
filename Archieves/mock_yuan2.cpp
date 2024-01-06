#include <bits/stdc++.h>
using namespace std;

// n floors
// s solidness
// p+q, q, p : price, q: exp cost
// (p+q) log n
// q->0 min floor incremental
// p->0 binary search

//  min_x max_\pi cost(\pi, s)
// q/(p+q) mid
// f(p, q)
// f(0, q) = mid
// f(p, 0) = 0

int get_cost(int n, int s, auto f, int p, int q) {
  int l = 0;
  int r = n + 1;
  // 1, 10
  // 101, 110
  int cost = 0;
  // [l, r)
  // [l, l)
  // [l, l+1) i dont know {l}
  // i want to know the last that does not break
  // {l}
  while (l < r) {
    int gap = r - l;
    int cut = l + f(p, q, gap);
    assert(l <= cut && cut < r);
    if (cut <= s) {  // cut not break
      l = cut + 1;
      cost += q;
    } else {
      r = cut;
      cost += p + q;
    }
  }
  // cout << endl << l - 1 << " " << s << endl;
  assert(l - 1 == s);
  return cost;
}

// n = 100
// F(n) = \sum_i F(i)F(n-i)
// n, 0/n->n/n
// cut(gap) -> ratio (effective ratio only n)
// # possible cut funtcions

// max cost
// cost(N) = min_i max(q + cost(i),  p+q + cost(N-i)) // get i by some
// slide i
// condition cost(1) = p+q

int main() {
  int n = 100;
  int p = 1;
  int q = 1;
  auto f = [](int p, int q, int x) { return x / 2 * q / (p + q); };
  vector<int> argmax;
  int maxv;
  for (int s = 0; s <= n; s++) {
    int cost = get_cost(n, s, f, p, q);
    if (argmax.empty() || cost > maxv) {
      argmax = {s};
      maxv = cost;
    } else if (cost == maxv) {
      argmax.push_back(s);
    }
    cout << s << " " << get_cost(n, s, f, p, q) << endl;
  }
  cout << "max value: " << maxv << endl << "argmax ";
  for (auto x : argmax) {
    cout << x << " ";
  }
}