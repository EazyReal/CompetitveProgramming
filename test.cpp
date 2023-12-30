#include <algorithm>

using namespace std;

int main() {
  vectorM<int> v = {1, 2, 3, 4, 5};
  auto it = find(v.begin(), v.end(), 3);
  if (it != v.end()) {
    cout << *it << endl;
  }
  return 0;
}
