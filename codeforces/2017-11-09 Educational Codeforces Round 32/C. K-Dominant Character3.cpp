#include <cstdio>
#include <iostream>
#include <cstring>
#include <map>

using namespace std;

const int maxn=100000+5;
char s[maxn];
int last[50];
int dis[50];

int main()
{
    scanf("%s",s);
    memset(last,-1,sizeof(last));
    int len=strlen(s);
    for(int i=0; i<len; i++)
    {
        int c=s[i]-'a';
        dis[c]=max(dis[c],i-last[c]);
        last[c]=i;

    }
    for(int i=0; i<26; i++)
        dis[i]=max(dis[i],len-last[i]);
    int ans=len;
    for(int i=0; i<26; i++)
    {
        //cout<<dis[i]<<' ';
        ans=min(ans,dis[i]);
    }
    printf("%d\n",ans);
    return 0;
}
