#include <bits/stdc++.h>

using namespace std;

int n;
int a[2005];

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    int d = 0;
    for (int i = 1; i <= n; ++i) cin >> a[i], d = __gcd(d, a[i]);
    if (d > 1) return cout << -1 << endl, 0;
    for (int i = 1; i <= n; ++i) if (a[i] == 1) {
        int ans = 0;
        for (int j = 1; j <= n; ++j) if (a[j] > 1) ++ans;
        cout << ans << endl;
        return 0;
    }
    int ans = 1e9;
    for (int i = 1; i <= n; ++i) {
        d = 0;
        for (int j = i; j <= n; ++j) {
            d = __gcd(d, a[j]);
            if (d == 1) {
                ans = min(ans, j - i + n - 1);
                break;
            }
        }
    }
    cout << ans << endl;
}
