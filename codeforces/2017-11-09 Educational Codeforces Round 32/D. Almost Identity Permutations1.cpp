#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int n,k;
int main()
{
    scanf("%d%d",&n,&k);
    if(k==1)
    {
        puts("1");
        return 0;
    }
    if(k==2)
    {
        printf("%d\n",(n*(n-1)>>1)+1);
        return 0;
    }
    LL ans = (n*(n-1)>>1)+1;
    ans+=(1LL*n*(n-1)*(n-2)/3);
    if(k==4)
        ans+=1LL*n*(n-1)*(n-2)*(n-3)/8*3;
    printf("%I64d\n",ans);
    return 0;
}
