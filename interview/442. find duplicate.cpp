#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i) {
            int idx = abs(nums[i]) - 1;
            if (nums[idx] < 0) res.push_back(idx + 1);
            nums[idx] = -nums[idx];
        }
        return res;
    }
};
int main(){
	vector<int> v={4,3,2,85,8,2,85,1};
	Solution s;
	auto res=s.findDuplicates(v);
	for(auto r:res){
        cout<<r<<endl;
	}
	return 0;
}
