#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> dp = vector<int>(s.length()+1);
        dp[0]=true;
        for(int i = 1; i < s.length()+1; i++){
            for(string word:wordDict){
                int word_len=word.length();
                if (i<word_len){
                    continue;
                }else if(dp[i-word_len] and s.substr(i-word_len,word_len)==word){
                    dp[i]=1;
                    break;
                }
            }
        }

        return dp[s.length()];
    }
};

int main(){
    string s = "leetcode";
    vector<string> dic;
    dic.push_back("leet");
    dic.push_back("code");
    Solution solution;
    cout<<solution.wordBreak(s,dic);
}