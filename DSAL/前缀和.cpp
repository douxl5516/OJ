//
// Created by douxl on 19-6-7.
//

#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+9;
int a[maxn],b[maxn];
int main(){
        int i,j,k,n,m,p;
        cin>>n>>m;
        for(i=1;i<=n;i++){
                cin>>a[i];
        }
        for(i=1;i<=m;i++){
                int L,R,t;
                cin>>t>>L>>R>>p;
                if(t==1){
                        b[L]+=p;b[R+1]-=p; //仔细想想为什么b[R+1]要减去p
                }
                else{
                        b[L]-=p;b[R+1]+=p;
                }
        }
        int add=0;
        for(i=1;i<=n;i++){
                add+=b[i];
                a[i]+=a[i-1]+add;
        }
        int x,y;
        cin>>x>>y;
        cout<<a[y]-a[x-1]<<endl;
}
