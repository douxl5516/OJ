/*
    |01背包|
    |完全背包|
    |多重背包|
    |16/11/05ztx|
*/

//  01背包：

void bag01(int cost,int weight)  {
    for(i = v; i >= cost; --i)
    dp[i] = max(dp[i], dp[i-cost]+weight);
}

//  完全背包：

void complete(int cost, int weight)  {
    for(i = cost ; i <= v; ++i)
    dp[i] = max(dp[i], dp[i - cost] + weight);
}

//  多重背包：

void multiply(int cost, int weight, int amount)  {
    if(cost * amount >= v)
        complete(cost, weight);
    else{
        k = 1;
        while (k < amount){
            bag01(k * cost, k * weight);
            amount -= k;
            k += k;
        }
        bag01(cost * amount, weight * amount);
    }
}


// other

int dp[1000000];
int c[55], m[110];
int sum;

void CompletePack(int c) {
    for (int v = c; v <= sum / 2; ++v){
        dp[v] = max(dp[v], dp[v - c] + c);
    }
}

void ZeroOnePack(int c) {
    for (int v = sum / 2; v >= c; --v) {
        dp[v] = max(dp[v], dp[v - c] + c);
    }
}

void multiplePack(int c, int m） {
    if (m * c > sum / 2)
        CompletePack(c);
    else{
        int k = 1;
        while (k < m){
            ZeroOnePack(k * c);
            m -= k;
            k <<= 1;
        }
        if (m != 0){
            ZeroOnePack(m * c);
        }
    }
}
