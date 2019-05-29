/*
    |辗转相除法|
    |欧几里得算法|
    |求最小公倍数|
    |16/11/05ztx|
*/

int gcd(int big, int small)
{
    if (small > big) swap(big, small);
    int temp;
    while (small != 0){ //  辗转相除法
        if (small > big) swap(big, small);
        temp = big % small;
        big = small;
        small = temp;
    }
    return(big);
}
