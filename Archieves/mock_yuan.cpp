#include <bits/stdc++.h>
using namespace std;

void solve(vector<string>& board) {
  int n = board.size();
  int m = board[0].size();
  // vector<vector<bool>> vis(n, vector<bool>(m, false));
  queue<pair<int, int>> q;
  // push into the queue sorted by their alphabet order
  // {x, y} according key board[x][y]
  // O(n^2 + n^2)
  // radix sort: k log c
  // sort: k log k
  // n^2 < k log k => n^2
  // map k -> coords
  unordered_map<char, vector<pair<int, int>>> starts;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      char c = board[i][j];
      starts[c].push_back({i, j});
    }
  }

  for (char c = 'a'; c <= 'z'; c++) {
    for (auto [x, y] : starts[c]) {
      q.push({x, y});
    }
  }
  //
  int dx[4] = {1, 0, -1, 0};
  int dy[4] = {0, 1, 0, -1};

  //
  while (!q.empty()) {
    auto [x, y] = q.front();
    q.pop();
    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
      if (board[nx][ny] != '.') continue;
      board[nx][ny] = board[x][y];
      q.push({nx, ny});
    }
  }
}

int main() {
  vector<string> board = {"a...", "....", ".c..", "...b"};
  solve(board);
  for (auto& s : board) {
    cout << s << endl;
  }
}