//#define SUBMIT

#ifdef SUBMIT
#define LOGLEVEL 0
#define NDEBUG
#else
#define LOGLEVEL 1
#endif

#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cassert>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <cstdlib>
#include <array>
#include <type_traits>
#include <queue>
#include <stack>
#include <functional>
#include <sstream>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <climits>
#include <cfloat>
#include <random>
#include <bitset>

using namespace std;

#define LOG(l, x) if (l <= LOGLEVEL) cout << x << endl

#define int64 long long
#define repeat(x) for (auto repeat_var = 0; repeat_var < x; ++repeat_var)

#define for_inc(i, x) for (auto i = 0; i < x; ++i)
#define for_dec(i, x) for (auto i = x - 1; i >= 0; --i)
#define for_inc_range(i, x, y) for (auto i = x; i <= y; ++i)
#define for_dec_range(i, x, y) for (auto i = x; i >= y; --i)

#define fill0(x) memset(x, 0, sizeof(x))
#define INT_INF ((int)2E9L)
#define INT64_INF ((int64)1E18L)
#define MOD 1000000007
int MODP(int64 x) {
  int r = x % MOD;
  if (r < 0) r += MOD;
  return r;
}

void testGen() {
  freopen("biginput1.txt", "w", stdout);
  fclose(stdout);
}

int main() {
  ios::sync_with_stdio(false);
#ifndef SUBMIT
  freopen("input2.txt", "r", stdin);
#endif
  
  int n;
  cin >> n;
  n = (1 << (n + 1)) - 1;
  
  vector<int> down(n + 1);
  vector<int> edge(n + 1);
  
  for_inc_range(i, 2, n) {
    cin >> edge[i];
  }
  
  int ans = 0;
  for (int i = n; i > 1; i -= 2) {
    int c1 = down[i] + edge[i];
    int c2 = down[i - 1] + edge[i - 1];
    int extra = 0;
    if (c1 != c2) {
      extra = abs(c2 - c1);
    }
    ans += extra;
    int parent = i / 2;
    down[parent] += max(c1, c2);
  }
  
  cout << ans << endl;
  return 0;
}
