/*
    |Kruskal算法|
    |适用于 稀疏图 求最小生成树|
    |16/11/05ztx thanks to wangqiqi|
*/

/*
    第一步：点、边、加入vector，把所有边按从小到大排序
    第二步：并查集部分 + 下面的code
*/

void Kruskal() {    
    ans = 0;    
    for (int i = 0; i<len; i++) {    
        if (Find(edge[i].a) != Find(edge[i].b)) {    
            Union(edge[i].a, edge[i].b);    
            ans += edge[i].len;    
        }    
    }    
}    