/*
    |Kruskal�㷨|
    |������ ϡ��ͼ ����С������|
    |16/11/05ztx thanks to wangqiqi|
*/

/*
    ��һ�����㡢�ߡ�����vector�������б߰���С��������
    �ڶ��������鼯���� + �����code
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