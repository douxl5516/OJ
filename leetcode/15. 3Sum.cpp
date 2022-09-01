#include <bits/stdc++.h>
using namespace std;


int part(vector<int>& arr, int l, int r){
    int pivot = arr[l];
    while(l<r){
        while (l<r && arr[r]>=pivot) r--;
        arr[l]=arr[r];
        while (l<r && arr[l]<=pivot) l++;
        arr[r]=arr[l];
    }
    arr[l]=pivot;
    return l;
}

void qsort(vector<int>& arr,int l, int r){
    if(l>=r) return;
    int p=part(arr,l,r);
    qsort(arr,l,p-1);
    qsort(arr,p+1,r);
}

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        qsort(nums,0,nums.size()-1);

    }
};

int main(){
    vector<int> nums({-1,0,1,2,-1,-4});
    Solution s;
    vector<vector<int>> result=s.threeSum(nums);

}