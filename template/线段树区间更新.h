const int INFINITE = INT_MAX;
const int MAXNUM = 1000;
struct SegTreeNode
{
    int val;
    int addMark;//�ӳٱ��
}segTree[MAXNUM];//�����߶���

/*
���ܣ������߶���
root����ǰ�߶����ĸ��ڵ��±�
arr: ���������߶���������
istart���������ʼλ��
iend������Ľ���λ��
*/
void build(int root, int arr[], int istart, int iend)
{
    segTree[root].addMark = 0;//----���ñ��ӳټ���
    if(istart == iend)//Ҷ�ӽڵ�
        segTree[root].val = arr[istart];
    else
    {
        int mid = (istart + iend) / 2;
        build(root*2+1, arr, istart, mid);//�ݹ鹹��������
        build(root*2+2, arr, mid+1, iend);//�ݹ鹹��������
        //���������������ڵ��ֵ�����µ�ǰ���ڵ��ֵ
        segTree[root].val = min(segTree[root*2+1].val, segTree[root*2+2].val);
    }
}

/*
���ܣ���ǰ�ڵ�ı�־�����ӽڵ㴫��
root: ��ǰ�߶����ĸ��ڵ��±�
*/
void pushDown(int root)
{
    if(segTree[root].addMark != 0)
    {
        //�������Һ��ӽڵ�ı�־����Ϊ���ӽڵ���ܱ�����ӳٱ����û�����´���
        //������ ��+=��
        segTree[root*2+1].addMark += segTree[root].addMark;
        segTree[root*2+2].addMark += segTree[root].addMark;
        //���ݱ�־�����ú��ӽڵ��ֵ����Ϊ��������������Сֵ����˵�������ÿ��Ԫ
        //�ؼ���һ��ֵʱ���������СֵҲ�������ֵ
        segTree[root*2+1].val += segTree[root].addMark;
        segTree[root*2+2].val += segTree[root].addMark;
        //���ݺ󣬵�ǰ�ڵ��������
        segTree[root].addMark = 0;
    }
}

/*
���ܣ��߶����������ѯ
root����ǰ�߶����ĸ��ڵ��±�
[nstart, nend]: ��ǰ�ڵ�����ʾ������
[qstart, qend]: �˴β�ѯ������
*/
int query(int root, int nstart, int nend, int qstart, int qend)
{
    //��ѯ����͵�ǰ�ڵ�����û�н���
    if(qstart > nend || qend < nstart)
        return INFINITE;
    //��ǰ�ڵ���������ڲ�ѯ������
    if(qstart <= nstart && qend >= nend)
        return segTree[root].val;
    //�ֱ������������ѯ���������߲�ѯ����Ľ�Сֵ
    pushDown(root); //----�ӳٱ�־�����´���
    int mid = (nstart + nend) / 2;
    return min(query(root*2+1, nstart, mid, qstart, qend),
               query(root*2+2, mid + 1, nend, qstart, qend));

}

/*
���ܣ������߶�����ĳ��������Ҷ�ӽڵ��ֵ
root����ǰ�߶����ĸ��ڵ��±�
[nstart, nend]: ��ǰ�ڵ�����ʾ������
[ustart, uend]: �����µ�����
addVal: ���µ�ֵ��ԭ����ֵ����addVal��
*/
void update(int root, int nstart, int nend, int ustart, int uend, int addVal)
{
    //��������͵�ǰ�ڵ�����û�н���
    if(ustart > nend || uend < nstart)
        return ;
    //��ǰ�ڵ���������ڸ���������
    if(ustart <= nstart && uend >= nend)
    {
        segTree[root].addMark += addVal;
        segTree[root].val += addVal;
        return ;
    }
    pushDown(root); //�ӳٱ�����´���
    //�������Һ��ӽڵ�
    int mid = (nstart + nend) / 2;
    update(root*2+1, nstart, mid, ustart, uend, addVal);
    update(root*2+2, mid+1, nend, ustart, uend, addVal);
    //��������������ֵ���ݸ��µ�ǰ�ڵ��ֵ
    segTree[root].val = min(segTree[root*2+1].val, segTree[root*2+2].val);
}
