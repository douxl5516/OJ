#include <bits/stdc++.h>

using namespace std;

int solution(string &S) {
    int length = S.length();
    unordered_map<int,int> pos;
    for(int i=0;i<26;i++){
        pos[i+'a']=-1;
    }
    int ans = 0, status = 0;

    pos[0] = 0;
    for (int i = 0; i < length; i++) {
        char ch = S[i];
        status ^= 1<<(ch - 'a');
        if (pos.find(status)!=pos.end() and pos[status]>=0){
            ans=max(ans,i+1-pos[status]);
        }else{
            pos[status]=i+1;
        }
    }
    return ans;
}

int main(){
    string s="zthtzh";
    cout<<solution(s);
}