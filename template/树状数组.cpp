/*
    |16/11/06ztx|
*/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>

using namespace std;

int lowbit(const int t) {
    return t & (-t);
}

void insert(int t, int d) {
    while (t <= n){
        a[t] += d;
        t = t + lowbit(t);
    }
}

ll getSum(int t) {
    ll sum = 0;
    while (t > 0){
        sum += a[t];
        t = t - lowbit(t);
    }
    return sum;
}


int main() {
    int t, k, d;
    scanf("%d", &t);
    k= 1;
    while (t--){
        memset(a, 0, sizeof(a));
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &d);
            insert(i, d);
        }
        string str;
        printf("Case %d:\n", k++);
        while (cin >> str) {
            if (str == "End")   break;
            int x, y;
            scanf("%d %d", &x, &y);
            if (str == "Query")
                printf("%lld\n", getSum(y) - getSum(x - 1));
            else if (str == "Add")
                insert(x, y);
            else if (str == "Sub")
                insert(x, -y);
        }
    }
    return 0;
}
