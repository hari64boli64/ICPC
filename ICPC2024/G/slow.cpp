#ifndef hari64
#include <bits/stdc++.h>
// #pragma GCC target("avx2")
// #pragma GCC optimize("O3")
// #pragma GCC optimize("unroll-loops")
#define debug(...)
#else
#include "../../util/viewer.hpp"
#define debug(...) viewer::_debug(__LINE__, #__VA_ARGS__, __VA_ARGS__)
#endif
// #include <atcoder/all>
// clang-format off
using namespace std;
template <typename T> using vc = vector<T>;
template <typename T> using vvc = vector<vc<T>>;
template <typename T> using vvvc = vector<vvc<T>>;
using ll = long long; using ld = long double;
using pii = pair<int, int>; using pll = pair<ll, ll>;
using tiii = tuple<int, int, int>; using tlll = tuple<ll, ll, ll>;
using vi = vc<int>; using vvi = vvc<int>; using vvvi = vvvc<int>;
using vll = vc<ll>; using vvll = vvc<ll>; using vvvll = vvvc<ll>;
using vb = vc<bool>; using vvb = vvc<bool>; using vvvb = vvvc<bool>;
using vpii = vc<pii>; using vvpii = vvc<pii>; using vpll = vc<pll>; using vvpll = vvc<pll>;
using vtiii = vc<tiii>; using vvtiii = vvc<tiii>; using vtlll = vc<tlll>; using vvtlll = vvc<tlll>;
#define ALL(x) begin(x), end(x)
#define RALL(x) (x).rbegin(), (x).rend()
constexpr int INF = 1001001001; constexpr long long INFll = 1001001001001001001;
template <class T> bool chmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
template <class T> bool chmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
// clang-format on

void solve() {
  ll N;
  cin >> N;
  cout << fixed << setprecision(16) << sqrt(N * 2) / 2 << endl;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int numOfTestCases;
  cin >> numOfTestCases;
  while (numOfTestCases--) {
    solve();
  }

  return 0;
}
