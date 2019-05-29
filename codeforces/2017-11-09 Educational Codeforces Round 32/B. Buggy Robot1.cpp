#include <bits/stdc++.h>
using namespace std;
int a,b,c,d,n;
int main()
{
    scanf("%d",&n);
    char t;
    for(int i=1;i<=n;++i)
    {
        scanf(" %c",&t);
        if(t=='L')++a;
        else if(t=='R')++b;
        else if(t=='U')++c;
        else ++d;
    }
    printf("%d\n",(min(a,b)+min(c,d))<<1);
    return 0;
}
