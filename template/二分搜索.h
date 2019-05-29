/*
    |二分搜索|
    |要求：先排序|
    |16/11/05ztx, thanks to wangxiaocai|
*/

//  left为最开始元素, right是末尾元素的下一个数，x是要找的数
int bsearch(int *A, int left, int right, int x){
    int m;
    while (left < right){
        m = left + (right - left) / 2;
        if (A[m] >= x)  right = m;   else left = m + 1;
        // 如果要替换为 upper_bound, 改为:if (A[m] <= v) x = m+1; else y = m;
    }
    return left;
}

/*
    最后left == right

    如果没有找到135577找6，返回7

    如果找有多少的x，可以用lower_bound查找一遍，upper_bound查找一遍，下标相减

    C++自带的lower_bound(a,a+n,x)返回数组中最后一个x的下一个数的地址

    upper_bound(a,a+n,x)返回数组中第一个x的地址

    如果a+n内没有找到x或x的下一个地址，返回a+n的地址

    lower_bound(a,a+n,x）-upper_bound(a,a+n,x)返回数组中x的个数
*/
