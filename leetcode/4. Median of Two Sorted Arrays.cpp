#include <vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> sorted;
        int i=0,j=0;
        while(i<nums1.size() or j<nums2.size()){
            if(i<nums1.size() and j<nums2.size()) {
                if (nums1[i] < nums2[j])
                    sorted.push_back(nums1[i++]);
                else
                    sorted.push_back(nums2[j++]);
                continue;
            }
            if(i<nums1.size()){
                sorted.push_back(nums1[i++]);
            }
            if(j<nums2.size()){
                sorted.push_back(nums2[j++]);
            }
        }
        if (sorted.size()%2==1){
            return sorted[sorted.size()/2];
        }else{
            return (sorted[sorted.size()/2]+sorted[sorted.size()/2-1]+0.0)/2;
        }

    }
};
