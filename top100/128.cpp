#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> len;
        int max_len=0;
        for(int num : nums){
            if (!len[num]){
                int l=len[num-1];
                int r=len[num+1];
                int cur_len=l+r+1;
                max_len=max(max_len,cur_len);
                len[num-l]=cur_len;
                len[num]=cur_len;
                len[num+r]=cur_len;
            }
        }

    }
};

int main(){
    vector<int> a = {100,4,200,1,3,2};
    Solution s;
    s.longestConsecutive(a);
}