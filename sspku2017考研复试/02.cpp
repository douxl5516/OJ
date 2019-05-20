#include <bits/stdc++.h>
using namespace std;
int main(){
        double matrix[3][3];
        for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                        cin>>matrix[i][j];
                }
        }
        cout<<matrix[0][0]+matrix[1][1]+matrix[2][2];
        return 0;
}