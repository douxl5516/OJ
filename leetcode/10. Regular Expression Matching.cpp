//
// Created by douxl on 19-5-31.
//

#include <bits/stdc++.h>
using namespace std;


//dp 倒推
class Solution {
public:
    bool isMatch(string s, string p) {
            int lens=s.length();
            int lenp=p.length();
            vector<vector<bool> > dp(lens+1,vector<bool>(lenp+1,0));
            dp[lens][lenp]=true;
            for(int i=lens;i>=0;i--){
                    for(int j=lenp-1;j>=0;j--){
                            bool first_match = (i < s.length() &&(p.at(j) == s.at(i) ||p.at(j) == '.'));
                            cout<<first_match<<endl;
                            if (j + 1 < p.length() && p.at(j+1) == '*'){
                                    dp[i][j] = dp[i][j+2] || first_match && dp[i+1][j];
                                    cout<<"dp"<<i<<" "<<j<<"="<<dp[i][j]<<endl;
                            } else {
                                    dp[i][j] = first_match && dp[i+1][j+1];
                                    cout<<"dp"<<i<<" "<<j<<"="<<dp[i][j]<<endl;
                            }
                    }
            }
            for(int i =0;i<lens;i++){
                    for(int j=0;j<lenp;j++){
                            cout<<dp[i][j]<<" ";
                    }
                    cout<<endl;
            }
            return dp[0][0];
    }
};

int main(){
        Solution s;
        bool res=s.isMatch("mississippi","mis*is*ip*.");
        if(res){
                cout<<"true";
        }else{
                cout<<"false";
        };
        return 0;
}