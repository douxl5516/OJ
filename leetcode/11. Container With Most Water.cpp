#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0,j=height.size()-1,res=0;
        while(i!=j) {
            res = max(res, min(height[i], height[j]) * (j - i));
            if (height[i] < height[j]) {
                i++;
            } else {
                j--;
            }
        }
        return res;
    }
};

int main(){
    vector<int> v={1,1};
    Solution s;
    s.maxArea(v);
    return 0;
}