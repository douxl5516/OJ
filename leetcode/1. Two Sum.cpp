#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<int> twoSum_two_pointer(vector<int> &nums, int target)
    {
            /*
             * 双指针法，只适用于按顺序排列的数组
             * */
            vector<int> result;
            int i=0,j=nums.size()-1;
            while(i<j){
                    if(nums[i]+nums[j]==target){
                            result.push_back(i);
                            result.push_back(j);
                            return result;
                    }else if(nums[i]+nums[j]>target){
                            j--;
                    } else{
                            i++;
                    }
            }
            return result;
    }
    vector<int> twoSum_map(vector<int> &numbers, int target)
    {
        unordered_map<int, int> hash;
        vector<int> result;
        for (int i = 0; i < numbers.size(); i++) {
            int numberToFind = target - numbers[i];
                if (hash.find(numberToFind) != hash.end()) {
                result.push_back(hash[numberToFind]);
                result.push_back(i);
                return result;
            }
            hash[numbers[i]] = i;
        }
        return result;
    }
};
int main(){
        Solution s;
        vector<int> nums={3,2,4};
        int target=6;
        vector<int> result=s.twoSum_two_pointer(nums,target);
        for(auto i : result){
                cout<<i<<endl;
        }
        return 0;
}