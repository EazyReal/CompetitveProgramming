#include <bits/stdc++.h>

#include <iostream>

using namespace std;
using namespace std::string_literals;
namespace rng = ranges;
namespace rvs = views;

auto add(auto a, auto b) { return a + b; }

// template <typename T>
// concept Iterable = requires(T t) {
//   begin(t);
//   end(t);
// };

struct A {
  int a;
};

template <typename A, typename B>
vector<B> fmap(function<B(A)> f, vector<A> v) {
  vector<B> res;
  std::transform(v.begin(), v.end(), std::back_inserter(res), f);
  return res;
}

void wrapper(auto v) { accumulate(begin(v), end(v), 0); }

template <typename T>
void print_iter(T v) {
  std::ranges::for_each(v, [](auto i) { std::cout << i << " "; });
  cout << endl;
}

int add1(int a) { return a + 1; }

std::vector<int> nums{3, 4, 2, 8, 15, 267};

struct Sum {
  void operator()(int n) { sum += n; }
  int sum{0};
};

int main() {
  string a{"HELLO"};
  string b{"WORLD"};
  print_iter(a);
  // auto v = vector<A>{{1}, {2}, {3}, {4}, {5}, {6}, {7}, {8}, {9}, {10}};
  // auto [i, s] = std::ranges::for_each(nums.begin(), nums.end(), Sum());
  // auto v = nums | std::views::filter([](int i) { return i % 2 == 0; });
  // print_iter(v);
  // auto a = action::sort(nums);
  auto lifted_add1 = [](auto v) { return fmap(std::function{add1}, v); };
  auto n = 5;
  auto const animals = std::array{"bear"s, "cat"s, "dragon"s, "spider"s};
  // animals | rvs::join_with(' ');
  auto v = rvs::iota(0, n) | rvs::take(2);
  // auto v1 = rvs::enumerate(nums);
  auto v2 = lifted_add1(nums);
  print_iter(v2);
  // print_iter(v);
  // wrapper(v);  // compile error
  cout << add(a, b) << std::endl;
  return 0;
};