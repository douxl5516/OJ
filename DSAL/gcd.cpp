//
// Created by douxl on 19-5-19.
//

#include <bits/stdc++.h>
using  namespace std;
int gcd(int a,int b){
        return b==0?a:gcd(b,a%b);
}
int lcm(int a,int b){
        return a*b/gcd(a,b);
}
int main(){
        int i=30;
        int j=14;
        cout<<gcd(i,j)<<endl<<lcm(i,j);
        return 0;
}