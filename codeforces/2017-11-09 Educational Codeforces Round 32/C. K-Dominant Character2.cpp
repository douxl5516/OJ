#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  string s;
  cin >> s;
  vector<vector<int> > a(255, vector<int>(1, 0));
  for (int i = 0; i < s.size(); i++) {
    a[s[i]].push_back(i + 1);
  }
  int b = s.size();
  for (int i = 'a'; i <= 'z'; i++) {
    a[i].push_back(s.size() + 1);
    int mx = 0;
    for (int j = 1; j < a[i].size(); j++) {
      mx = max(mx, a[i][j] - a[i][j - 1]);
    }
    b = min(b, mx);
  }
  cout << b << endl;
  return 0;
}
