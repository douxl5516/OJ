/*
 * 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。

给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
    unordered_map<char,string> dic;

public:
    vector<string> letterCombinations(string digits) {
        dic['2']="abc";
        dic['3']="def";
        dic['4']="ghi";
        dic['5']="jkl";
        dic['6']="mno";
        dic['7']="pqrs";
        dic['8']="tuv";
        dic['9']="wxyz";
        vector<string> result;
        if(digits.length()==0){
            return result;
        }
        dfs(digits,0,result);
        return result;
    }

    string combination;
    void dfs(string digits, int idx, vector<string>& result){
        if (idx==digits.length()){
            result.push_back(combination);
        }
        char digit=digits[idx];
        string letters=dic[digit];
        for (int i=0;i<letters.length();i++){
            combination.push_back(letters.at(i));
            dfs(digits,idx+1,result);
            combination.pop_back();
        }
    }
};

int main(){
    Solution s;
    vector<string> res=s.letterCombinations("123");
}