#include <bits/stdc++.h>
using namespace std;

int n,a[1005];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
        scanf("%d",a+i);
    int cnt=0;
    for(int i=2;i<n;++i)
    {
        if(a[i]>a[i-1]&&a[i]>a[i+1])
            ++cnt;
        else if(a[i]<a[i-1]&&a[i]<a[i+1])
            ++cnt;
    }
    printf("%d\n",cnt);
    return 0;
}
