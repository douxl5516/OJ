const int MAXNUM = 1000;
struct SegTreeNode
{
    int val;
}segTree[MAXNUM];//定义线段树

/*
功能：构建线段树
root：当前线段树的根节点下标
arr: 用来构造线段树的数组
istart：数组的起始位置
iend：数组的结束位置
*/
void build(int root, int arr[], int istart, int iend)
{
    if(istart == iend)//叶子节点
        segTree[root].val = arr[istart];
    else
    {
        int mid = (istart + iend) / 2;
        build(root*2+1, arr, istart, mid);//递归构造左子树
        build(root*2+2, arr, mid+1, iend);//递归构造右子树
        //根据左右子树根节点的值，更新当前根节点的值
        segTree[root].val = min(segTree[root*2+1].val, segTree[root*2+2].val);
    }
}

/*
功能：线段树的区间查询
root：当前线段树的根节点下标
[nstart, nend]: 当前节点所表示的区间
[qstart, qend]: 此次查询的区间
*/
int query(int root, int nstart, int nend, int qstart, int qend)
{
    //查询区间和当前节点区间没有交集
    if(qstart > nend || qend < nstart)
        return INFINITE;
    //当前节点区间包含在查询区间内
    if(qstart <= nstart && qend >= nend)
        return segTree[root].val;
    //分别从左右子树查询，返回两者查询结果的较小值
    int mid = (nstart + nend) / 2;
    return min(query(root*2+1, nstart, mid, qstart, qend),
               query(root*2+2, mid + 1, nend, qstart, qend));

}
/*
功能：更新线段树中某个叶子节点的值
root：当前线段树的根节点下标
[nstart, nend]: 当前节点所表示的区间
index: 待更新节点在原始数组arr中的下标
addVal: 更新的值（原来的值加上addVal）
*/
void updateOne(int root, int nstart, int nend, int index, int addVal)
{
    if(nstart == nend)
    {
        if(index == nstart)//找到了相应的节点，更新之
            segTree[root].val += addVal;
        return;
    }
    int mid = (nstart + nend) / 2;
    if(index <= mid)//在左子树中更新
        updateOne(root*2+1, nstart, mid, index, addVal);
    else updateOne(root*2+2, mid+1, nend, index, addVal);//在右子树中更新
    //根据左右子树的值回溯更新当前节点的值
    segTree[root].val = min(segTree[root*2+1].val, segTree[root*2+2].val);
}


