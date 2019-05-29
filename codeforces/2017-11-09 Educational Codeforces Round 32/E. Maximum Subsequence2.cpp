#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  int n, m;
  cin >> n >> m;
  vector<int> a, b;
  for (int i = 0; i < n; i++) {
    int t;
    cin >> t;
    if (i > 17) {
      b.push_back(t);
    } else {
      a.push_back(t);
    }
  }
  vector<int> vec;
  for (int i = 0; i < 1 << b.size(); i++) {
    int sum = 0;
    for (int j = 0; j < b.size(); j++) {
      if ((1 << j) & i) {
        sum = (sum + b[j]) % m;
      }
    }
    vec.push_back(sum);
  }
  sort(vec.begin(), vec.end());
  int ans = 0;
  for (int i = 0; i < 1 << a.size(); i++) {
    int sum = 0;
    for (int j = 0; j < a.size(); j++) {
      if ((1 << j) & i) {
        sum = (sum + a[j]) % m;
      }
    }
    int z = m - sum;
    auto it = lower_bound(vec.begin(), vec.end(), z);
    --it;
    ans = max(ans, *it + sum);
  }
  cout << ans << endl;
  return 0;
}
