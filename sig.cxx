#include <bits/stdc++.h>

using namespace std;

struct Node {
  int val = 0;
  int lazy = 0;
  Node *lc, *rc;
};

// void pullUp(Node* v) {

// }

void pushDown(Node *v) {
  v->lc = new Node{v->lazy, 0, nullptr, nullptr};
  v->rc = new Node{v->lazy, 0, nullptr, nullptr};
}

int query(Node *v, int i, int L, int R) {
  if (L <= i && i < R) {
    return v->val + v->lazy;
  }
  int M = (L + R) / 2;
  if (i <= M)
    return query(v->lc, i, L, M);
  else
    return query(v->rc, i, M, R);
}

void add(Node *v, int l, int r, int L, int R,
         vector<pair<int, int>> &intervals) {
  if (L <= l && r <= R) {
    v->lazy += 1;
    return;
  }
  int M = (L + R) / 2;
  if (!v->lc) {
    pushDown(v);
  }
  if (l <= M) add(v->lc, l, r, L, M, intervals);
  if (r >= M) add(v->rc, l, r, M, R, intervals);
  return;
}

vector<vector<int>> solution(int blockCount, vector<vector<int>> writes,
                             int threshold) {
  Node *root;
  vector<pair<int, int>> intervals;
  for (auto &write : writes) {
    add(root, 0, blockCount, write[0], write[1], intervals);
  }
  vector<vector<int>> ans;
  int prev = -2;
  int l, r;
  for (int i = 0; i < blockCount; ++i) {
    if (query(root, i, 0, blockCount) >= threshold) {
      if (prev == i - 1) {
        r++;
        prev = i;
      } else {
        l = i;
      }
    }
  }
  return ans;
}
