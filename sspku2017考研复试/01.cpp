#include <bits/stdc++.h>
using  namespace std;
int main(){
        string s;
        getline(cin,s);
        stringstream ss;
        ss<<s;
        while(ss>>s){
                reverse(s.begin(),s.end());
                cout<<s<<" ";
        }
        return 0;
}