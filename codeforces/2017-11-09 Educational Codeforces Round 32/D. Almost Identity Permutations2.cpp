#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll choose(int n, int k) {
  ll c = 1, to = min(k, n - k);
  if (k > n) return 0;
  for (int i = 0; i < to; i++) {
    assert(c * (n - i) % (i + 1) == 0);
    c = c * (n - i) / (i + 1);
  }
  return c;
}

int main(int argc, char *argv[]) {
  int n, k;
  cin >> n >> k;
  k = min(n, k);
  ll ans = 1;
  if (k >= 2) {
    ans += choose(n, 2);
  }
  if (k >= 3) {
    ans += choose(n, 3) * 2;
  }
  if (k >= 4) {
    ans += choose(n, 4) * 9;
  }
  cout << ans << endl;
  return 0;
}
