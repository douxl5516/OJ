#include <bits/stdc++.h>
using namespace std;
int s1,s2,n,m,a[100],b[100];
set<int>st1,st2;
void init(set<int>& st,int*a,int len)
{
    for(int mask=(1<<len)-1;~mask;--mask)
    {
        int sum=0;
        for(int i=0;i<len;++i)
            if(mask&(1<<i))
                (sum+=a[i])%=m;
        st.insert(sum);
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    s1=n>>1;
    s2=n-s1;
    for(int i=0;i<s1;++i)
        scanf("%d",a+i);
    for(int i=0;i<s2;++i)
        scanf("%d",b+i);
    init(st1,a,s1);
    init(st2,b,s2);
    int ans=0;
    set<int>::iterator it;
    for(const int& x: st1)
    {
        if(x==m-1)
        {
            ans=m-1;
            break;
        }
        it=st2.upper_bound(m-1-x);
        --it;
        ans=max(ans,x+*it);
    }
    printf("%d\n",ans);
    return 0;
}
