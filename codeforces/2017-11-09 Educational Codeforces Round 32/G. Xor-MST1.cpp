#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200005;
int n,a[N],cnt;
LL ans=0;
struct node
{
    node* ch[2];
    void init()
    {
        ch[0]=ch[1]=0;
    }
}buff[N<<5],*root;
node* newnode()
{
    buff[++cnt].init();
    return buff+cnt;
}
void ins(int x,int len)
{
    node* cur =  root;
    for(int i,j=len;~j;--j)
    {
        i=(x>>j)&1;
        if(!cur->ch[i])
            cur->ch[i]=newnode();
        cur=cur->ch[i];
    }
}
int qry(int x,int len)
{
    int ans=0;
    node* cur =  root;
    for(int i,j=len;~j;--j)
    {
        i=(x>>j)&1;
        if(cur->ch[i])
            cur=cur->ch[i];
        else
        {
            ans|=1<<j;
            cur=cur->ch[!i];
        }
    }
    return ans;
}
void solve(set<int>* s , int flag)
{
    if(s->empty())
        return;
    cnt=0;
    root = newnode();
    int c=0;
    for(const int x : *s)
    {
        if(x&(1<<flag))
        {
            ++c;
            ins(x,flag);
        }
    }
    if(!c||c==s->size())
    {
        if(flag)
            solve(s,flag-1);
        return;
    }
    int tmp=0x7fffffff;
    for(const int x : *s)
    {
        if(!(x&(1<<flag)))
            tmp=min(tmp,qry(x,flag));
    }
    ans+=tmp;
    if(!flag)
        return;
    set<int> *it1, *it2;
    it1 = new set<int>;
    it2 = new set<int>;
    for(const int x : *s)
        if(x&(1<<flag))
            it1->insert(x);
        else it2->insert(x);
    solve(it1,flag-1);
    solve(it2,flag-1);
    delete it1;
    delete it2;
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;++i)
        scanf("%d",a+i);
    set<int>* s = new set<int>;
    for(int i=0;i<n;++i)
        s->insert(a[i]);
    solve(s,29);
    delete s;
    printf("%I64d\n",ans);
    return 0;
}
