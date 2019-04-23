#include <iostream>
#include <limits>
#define ll long long
using namespace std;

ll gcd(ll a, ll b){
    if(b == 0)
        return a;
    return gcd(b, a % b);
}

int main(){
    int n,m;
    ll* x;
    ll* x_diff;
    ll* p;
    cin>>n>>m;
    x=new ll[n];
    x_diff=new ll[n-1];
    p=new ll[m];
    for(int i=0;i<n;i++){
        cin>>x[i];
    }
    for(int i=0;i<n-1;i++){
        x_diff[i]=x[i+1]-x[i];
    }
    for(int i=0;i<m;i++){
        cin>>p[i];
    }
    ll pre=x_diff[0];
    ll min=x[0];
    for(int i=0;i<n-1;i++){
        pre=gcd(pre,x_diff[i]);
        if (x[i+1]<min)
            min=x[i+1];
    };
    for(int i=0;i<m;i++){
        if (pre%p[i]==0) {
            cout << "YES" << endl;
            cout<<min<<" "<<i+1<<endl;
            return 0;
        }
    }
    cout<<"NO"<<endl;

    delete[] x;
    delete[] x_diff;
    delete[] p;
    return 0;
}