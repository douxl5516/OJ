/*
    |��������|
    |Ҫ��������|
    |16/11/05ztx, thanks to wangxiaocai|
*/

//  leftΪ�ʼԪ��, right��ĩβԪ�ص���һ������x��Ҫ�ҵ���
int bsearch(int *A, int left, int right, int x){
    int m;
    while (left < right){
        m = left + (right - left) / 2;
        if (A[m] >= x)  right = m;   else left = m + 1;
        // ���Ҫ�滻Ϊ upper_bound, ��Ϊ:if (A[m] <= v) x = m+1; else y = m;
    }
    return left;
}

/*
    ���left == right

    ���û���ҵ�135577��6������7

    ������ж��ٵ�x��������lower_bound����һ�飬upper_bound����һ�飬�±����

    C++�Դ���lower_bound(a,a+n,x)�������������һ��x����һ�����ĵ�ַ

    upper_bound(a,a+n,x)���������е�һ��x�ĵ�ַ

    ���a+n��û���ҵ�x��x����һ����ַ������a+n�ĵ�ַ

    lower_bound(a,a+n,x��-upper_bound(a,a+n,x)����������x�ĸ���
*/
