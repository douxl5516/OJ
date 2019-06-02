#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll n,x,dp[3],ans;
int main(){
    cin>>n>>x;
    for(int i=0;i<n;i++){
        ll a;
        cin>>a;
        dp[0]=max(0ll,dp[0]+a);
        dp[1]=max(dp[0],dp[1]+a*x);
        dp[2]=max(dp[1],dp[2]+a);
        ans=max(dp[2],ans);
    }
    cout<<ans;
    return 0;
}