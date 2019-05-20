#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<cstring>
#define E_Type vector<Edge>
#define E_It vector<Edge>::iterator
using namespace std;

const int Maxn=50;
const int INF=~(1<<31);

struct Edge{
    int nxt,weight;
    Edge(int _nxt=0,int _weight=0){nxt=_nxt;weight=_weight;}
};

E_Type edge[Maxn];
bool vis[Maxn+5];
int path[Maxn+5];
int dis[Maxn+5];
int cnt[Maxn+5];
int m;
int n;
int u,v,w;

inline void init(){
    memset(vis,false,sizeof(vis));
    memset(path,-1,sizeof(path));
    memset(cnt,0,sizeof(cnt));
    for(int i=0;i<Maxn+5;i++){ dis[i] = INF; }
}

inline void addDoubleEdge(int u,int v,int w){
    edge[u].push_back(Edge(v,w));
    edge[v].push_back(Edge(u,w));
}
inline void addSingleEdge(int u,int v,int w){
    edge[u].push_back(Edge(v,w));
}


int SPFA(int i){
    //var
    queue<int> q;
    //init
    init();
    //solve
    q.push(i);
    cnt[i]++;
    vis[i]=true;
    dis[i]=0;
    while(!q.empty())
    {
        int now=q.front();
        q.pop();
        vis[now]=false;
        for(int i=0;i<edge[now].size();i++)
        {
            int nxt=edge[now][i].nxt;
            int weight=edge[now][i].weight;

            if(dis[now]+weight<dis[nxt])
            {
                dis[nxt]=dis[now]+weight;
                if(!vis[nxt])
                {
                    if(cnt[nxt]>Maxn)
                        return -1;
                    q.push(nxt);
                    vis[nxt]=true;
                    cnt[nxt]++;
                }
                path[nxt]=now;
            }
        }

    }
    return 0;
}

void printInfo(){
    for(int i=0;i<m;i++)
    {
        cout<<dis[i]<<" "<<path[i]<<endl;
    }
}

int main()
{
    //init
    init();
    //input
    scanf("%d",&m);
    scanf("%d",&n);
    while(~scanf("%d%d%d",&u,&v,&w))
    {
        addSingleEdge(u,v,w);
    }
    //solve and output
    if(SPFA(0))
        cout<<"fuhuan"<<endl;
    else
        printInfo();
}
