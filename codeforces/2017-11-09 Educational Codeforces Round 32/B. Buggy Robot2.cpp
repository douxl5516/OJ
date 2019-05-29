#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  int n;
  string s;
  cin >> n >> s;
  vector<int> a(255);
  for (auto c : s) {
    a[c]++;
  }
  cout << 2 * min(a['U'], a['D']) + 2 * min(a['L'], a['R']) << endl;
  return 0;
}
