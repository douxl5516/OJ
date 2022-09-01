#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount+1);
        dp[0]=1;
        for(int coin:coins){
            for(int i=1;i<=amount;i++){
                if(i-coin>=0)
                    dp[i]=dp[i]+dp[i-coin];
            }
        }
        return dp[amount];
    }
};

int main(){
    Solution s;
    vector<int> coins({1,2,5});
    int result=s.change(5,coins);
    cout<<result<<endl;
}