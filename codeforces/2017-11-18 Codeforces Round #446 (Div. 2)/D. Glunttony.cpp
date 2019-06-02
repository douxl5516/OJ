#include <bits/stdc++.h>

using namespace std;

int n;
pair <long long, int> a[25];
int ord[25];

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i].first, a[i].second = i;
    sort(a, a + n);
    for (int i = 0; i < n; ++i) ord[a[i].second] = i;
    for (int i = 0; i < n; ++i) cout << a[(ord[i] + 1) % n].first << ' ';
}
