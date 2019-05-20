#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll hashFun(const char* str,int len){
        ll result=0;
        for(int i=0;i<len;i++){
                char cur=str[i];
                int val=0;
                if(cur>='a' && cur<='z'){
                        val=cur-'a';
                }else if(cur>='A'&&cur<='Z'){
                        val=cur-'A'+26;
                }
                result*=26;
                result+=val;
        }
        return result;
}
int main(){
        int n,m;
        ll hashtable[26*26*26+10]={};
        string s;
        cin>>n>>m;
        for(int i=0;i<n;i++){
                cin>>s;
                hashtable[hashFun(s.c_str(),s.size())]++;
        }
        for(int i=0;i<m;i++){
                cin>>s;
                hashtable[hashFun(s.c_str(),s.size())];
        }
        return 0;
}