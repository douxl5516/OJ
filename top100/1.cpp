#include <vector>
#include <map>
#include <iostream>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]=i;
            if (m[target-nums[i]]){

            }
        }

    }
};

int main(){

    Solution s;
    vector<int> v={1,2,3,4};
    int target = 3;
    s.twoSum(v,target);
    return 0;
}