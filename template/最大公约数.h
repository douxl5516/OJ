/*
    |շת�����|
    |ŷ������㷨|
    |�����Լ��|
    |16/11/05ztx|
*/

int gcd(int big, int small)
{
    if (small > big) swap(big, small);
    int temp;
    while (small != 0){ //  շת�����
        if (small > big) swap(big, small);
        temp = big % small;
        big = small;
        small = temp;
    }
    return(big);
}
