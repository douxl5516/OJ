//
// Created by douxl on 19-5-22.
//

#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& A) {
        int n=A.size();
        int p=0,q=0;
        for(int i=n-1;i>=p;i--){
            for(int j=p;j<i;j++){
                if(A[j]>A[i]){
                    if(p==0&&q==0){
                        p=j;
                        q=i;
                    }else if(A[i]>=A[q] && p==j){
                        p=j;
                        q=i;
                    }
                }
            }
        }
        swap(A[p],A[q]);
        return A;
    }
};


int main(){
    vector<int> vec={3,1,1,3};
    Solution s;
    auto v=s.prevPermOpt1(vec);
    for(auto val:v){
        cout<<val<<endl;
    }
}
