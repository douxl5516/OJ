#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 200005 * 30;
const int inf = (1 << 30);

int ch[N][2], val[N], idx[N], top;
ll ans = 0;

void insert(int x) {
  int now = 0;
  for (int i = 30; i >= 0; i--) {
    bool c = ((1 << i) & x);
    if (!ch[now][c]) {
      ch[now][c] = ++top;
    }
    now = ch[now][c];
    val[now]++;
  }
}

int cal(int r1, int r2, int d) {
  if (d < 0) return 0;
  int ret = inf;
  if (ch[r1][0] && ch[r2][0]) {
    ret = min(ret, cal(ch[r1][0], ch[r2][0], d - 1));
  }
  if (ch[r1][1] && ch[r2][1]) {
    ret = min(ret, cal(ch[r1][1], ch[r2][1], d - 1));
  }
  if (ret == inf) {
    int v = (1 << d);
    if (ch[r1][0] && ch[r2][1]) {
      ret = min(ret, v + cal(ch[r1][0], ch[r2][1], d - 1));
    }
    if (ch[r1][1] && ch[r2][0]) {
      ret = min(ret, v + cal(ch[r1][1], ch[r2][0], d - 1));
    }
  }
  return ret;
}

void dfs(int u, int d) {
  int sz1 = 0, sz2 = 0;
  if (ch[u][0]) dfs(ch[u][0], d - 1), sz1 = val[ch[u][0]];
  if (ch[u][1]) dfs(ch[u][1], d - 1), sz2 = val[ch[u][1]];
  if (sz1 && sz2) {
    ans += (1 << d) + cal(ch[u][0], ch[u][1], d - 1);
  }
}

int main(int argc, char *argv[]) {
  cin.sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    insert(a[i]);
  }
  dfs(0, 30);
  cout << ans << endl;
  return 0;
}

