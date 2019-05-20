#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    int tmp;
    int nums[4]={0,0,0,0};
    for(int i=0;i<n;i++){
        cin>>tmp;
        if(tmp%2==0){
            nums[1]++;
        }else{
            nums[0]++;
        }
    }
    for(int i=0;i<m;i++){
        cin>>tmp;
        if(tmp%2==0){
            nums[3]++;
        }else{
            nums[2]++;
        }
    }
    cout<<min(nums[0],nums[3])+min(nums[1],nums[2]);

    return 0;
}