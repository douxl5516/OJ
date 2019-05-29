#include <bits/stdc++.h>
using namespace std;
char s[100005];
int len;
bool can(int L)
{
    int cnt[26]={0};    //������ĸ���ִ���������
    bool vis[26]={0};   //������ĸ�Ƿ񱻷��ʹ�������
    for(int i=1;i<=L;++i)
        ++cnt[s[i]-'a'];    //ͳ��1��L����ĸ���ֵĴ���,����cnt���飬��ĸ����һ��++
    for(int i=0;i<26;++i)
        vis[i]=!!cnt[i];    //!!�����еķ�0��ת��Ϊ1
    for(int i=2;i+L-1<=len;++i)
    {
        ++cnt[s[i+L-1]-'a'];    //ͳ��L+1��len֮�����ĸ���ֵĴ���������cnt���飬��ĸ����һ��++
        --cnt[s[i-1]-'a'];      //ͳ��1��len-L֮�����ĸ���ֵĴ���������cnt���飬��ĸ����һ��--
        for(int j=0;j<26;++j)
            vis[j]&=!!cnt[j];   //!!�����еķ�0��ת��Ϊ1
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
