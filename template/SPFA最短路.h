/*
    |SPFA�㷨|
    |�����Ż�|
    |�ɴ�����|
*/

vector<node> G[maxn];
bool inqueue[maxn];
int dist[maxn];

void Init()
{
    for(int i = 0 ; i < maxn ; ++i){
        G[i].clear();
        dist[i] = INF;
    }
}
int SPFA(int s,int e)
{
    int v1,v2,weight;
    queue<int> Q;
    memset(inqueue,false,sizeof(inqueue)); // ����Ƿ��ڶ�����
    memset(cnt,0,sizeof(cnt)); // ������еĴ���
    dist[s] = 0;
    Q.push(s); // ���������
    inqueue[s] = true; // ���
    while(!Q.empty()){
        v1 = Q.front();
        Q.pop();
        inqueue[v1] = false; // ȡ�����
        for(int i = 0 ; i < G[v1].size() ; ++i){ // ����v1������
            v2 = G[v1][i].vex;
            weight = G[v1][i].weight;
            if(dist[v2] > dist[v1] + weight){ // �ɳڲ���
                dist[v2] = dist[v1] + weight;
                if(inqueue[v2] == false){  // �ٴμ������
                    inqueue[v2] = true;
                    //cnt[v2]++;  // �и���
                    //if(cnt[v2] > n) return -1;
                    Q.push(v2);
                } } }
    }
    return dist[e];
}

/*
    ���ϵĽ�s���ڽӵ������У�ȡ�����ϵĽ����ɳڲ�����ֱ������Ϊ��

    ���һ����㱻������г���n-1�Σ���ô��Ȼͼ���и���
*/
