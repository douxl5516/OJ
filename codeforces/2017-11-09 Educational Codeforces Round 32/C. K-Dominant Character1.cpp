#include <bits/stdc++.h>
using namespace std;
char s[100005];
int len;
bool can(int L)
{
    int cnt[26]={0};    //储存字母出现次数的数组
    bool vis[26]={0};   //储存字母是否被访问过的数组
    for(int i=1;i<=L;++i)
        ++cnt[s[i]-'a'];    //统计1到L间字母出现的次数,进入cnt数组，字母出现一次++
    for(int i=0;i<26;++i)
        vis[i]=!!cnt[i];    //!!将所有的非0数转化为1
    for(int i=2;i+L-1<=len;++i)
    {
        ++cnt[s[i+L-1]-'a'];    //统计L+1到len之间的字母出现的次数，进入cnt数组，字母出现一次++
        --cnt[s[i-1]-'a'];      //统计1到len-L之间的字母出现的次数，进入cnt数组，字母出现一次--
        for(int j=0;j<26;++j)
            vis[j]&=!!cnt[j];   //!!将所有的非0数转化为1
    }
    for(int i=0;i<26;++i)
        if(vis[i])
            return 1;
    return 0;
}
int bin(int l,int r)
{
    int mid;
    while(l<=r)
    {
        mid=l+r>>1;
        if(can(mid))
            r=mid-1;
        else l=mid+1;
    }
    return l;
}
int main()
{
    scanf(" %s",s+1);
    len=strlen(s+1);
    printf("%d\n",bin(1,len));
    return 0;
}
