//
// Created by douxl on 19-6-8.
//

#include <bits/stdc++.h>
#define N 1000005
using namespace std;

int n, m, l, r;
int arr[110];
int S[110];
map<int,int> h;
int t[N];
int ans[N];

typedef struct note {
    int l, r, id;
} ask;
inline int lowbit(int x) {
    return x & (-x);
}
int insert(int x,int d){
    for(;x<=n;x+=lowbit(x)){
        t[x]^=d;
    }
}
int query(int x){
    int sum=0;
    for(;x;x-lowbit(x)){
        sum^=t[x];
    }
}

int cmp(ask a, ask b) {
    return a.r < b.r;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        S[i] = S[i - 1] ^ arr[i];
    }
    cin >> m;
    ask *asks = new ask[m];
    for (int i = 0; i < m; i++) {
        cin >> asks[i].l >> asks[i].r;
        asks[i].id = i;
    }
    sort(asks, asks + m, cmp);
    int j = 0;

    for(int i=1; i<=n; i++){
        if (h[arr[i]]) insert(h[arr[i]], arr[i]);
        insert(i, arr[i]);
        h[arr[i]] = i;
        while (asks[j + 1].r == i) {
            j++;
            int l = asks[j].l, r = asks[j].r;
            ans[asks[j].id] = S[r] ^ S[l - 1] ^ query(r) ^ query(l - 1);
        }
    }


    for(int i=0;i<m;i++){
        cout<<ans[i]<<endl;
    }
    delete asks;
    return 0;
}