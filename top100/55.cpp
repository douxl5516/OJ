#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int k=0;
        for (int i=0; i<nums.size(); i++){
            if (i>k) return false;

            k=max(k,nums[i]);

        }
        return true;
    }
};

int main(){
    vector<int> v={2,3,1,1,4};
    Solution s;
    cout<<s.canJump();
}