#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isBoomerang(vector<vector<int>>& points) {
        if(dis(points[0],points[1])==0 or dis(points[2],points[1])==0 or dis(points[0],points[2])==0)
            return false;
        if((points[0][0]==points[1][0] and points[1][0]==points[2][0])||(points[0][1]==points[1][1] and points[1][1]==points[2][1]))
            return false;
        else{
            double k1=(points[0][1]-points[1][1]+0.0)/(points[0][0]-points[1][0]);
            double k2=(points[1][1]-points[2][1]+0.0)/(points[1][0]-points[2][0]);
            if(fabs(k1-k2)<0.001)
                return false;
            else
                return true;
        }
    }
    double dis(vector<int>&p1,vector<int>&p2){
        return sqrt((p1[0]-p2[0])*(p1[0]-p2[0])+(p1[1]-p2[1])*(p1[1]-p2[1]))
    }

};

int main(){

    return 0;
}