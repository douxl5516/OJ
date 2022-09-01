#include <bits/stdc++.h>
using namespace std;


class Edge{
    public:
    double w;
    int next;
    Edge(double w_,int next_){w=w_;next=next_;}
};

class Solution {
public:
    vector<vector<Edge>> G;
    vector<bool> vis;
    vector<double> dist;

    void init(int n,vector<vector<int>>& edges, vector<double>& succProb, int start){
        G=vector<vector<Edge>>(n,vector<Edge>());
        vis=vector<bool>(n);
        dist=vector<double>(n);
        dist[start]=1;
        for (int i=0;i<edges.size();i++){
            G[edges[i][0]].push_back(Edge(succProb[i],edges[i][1]));
            G[edges[i][1]].push_back(Edge(succProb[i],edges[i][0]));
        }
    }

    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        init(n,edges,succProb,start);
        queue<int> q;
        q.push(start);
        vis[start]=true;
        while(!q.empty()){
            int now=q.front();
            q.pop();
            vis[now]=false;
            for(int i=0;i<G[now].size();i++){
                Edge edge=G[now][i];
                int next=edge.next;
                double w=edge.w;
                if(dist[now]*w>dist[next]){
                    dist[next]=dist[now]*w;
                    q.push(next);
                    vis[next]=true;
                }
            }
        }
        return dist[end];
    }
};

int main(){
    Solution s;
    int n=5;
    vector<vector<int>> edges;
    edges.push_back(vector<int>({1,4}));
    edges.push_back(vector<int>({2,4}));
    edges.push_back(vector<int>({0,4}));
    edges.push_back(vector<int>({0,3}));
    edges.push_back(vector<int>({0,2}));
    edges.push_back(vector<int>({2,3}));
    vector<double> succProb({0.37,0.17,0.93,0.23,0.39,0.04});
    int start=3;
    int end=4;

    cout<<s.maxProbability(n,edges,succProb,start,end);

    return 0;
}