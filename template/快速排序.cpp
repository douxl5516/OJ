#include <stdio.h>
#include <stdlib.h>

int Partition(int *a, int i, int j)
{
    int key = a[i];
    while(i < j)
    {
        while(i < j && key <= a[j]) j--;
        a[i] = a[j];
        while(i < j && key >= a[i]) i++;
        a[j] = a[i];
    }
    a[i] = key;
    return i;
}

void sort(int *a, int left, int right)
{
    if(left >= right)
    {
        return ;
    }

    int i = Partition(a,left,right);
    sort(a, left, i - 1);
    sort(a, i + 1, right);

}

int main()
{
	int i, a[10] = {0,5,8,4,9,8,5,8,2,6};
	sort(a,0,9);
	for(i=0;i<10;i++)
		printf("%d",a[i]);
	system("pause");
	return 0;
}
