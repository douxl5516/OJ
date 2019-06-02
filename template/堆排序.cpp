#include <stdio.h>
#include <windows.h>
#define MAX_SIZE 10000

//����ֵ����
inline void swap(int& a,int& b)
{
    a=a^b;
    b=a^b;
    a=a^b;
}

//array�Ǵ������Ķ����飬i�Ǵ�����������Ԫ�ص�λ�ã�nlength������ĳ���
//�����������ǣ���������array���������
void HeapAdjust(int array[], int i, int nLength)
{
	int nChild;
	int nTemp;
	for (; 2 * i + 1<nLength; i = nChild)
	{
		//�ӽ���λ��=2*�������λ�ã�+1
		nChild = 2 * i + 1;
		//�õ��ӽ���нϴ�Ľ��
		if (nChild<nLength - 1 && array[nChild + 1]>array[nChild])++nChild;
		//����ϴ���ӽ����ڸ������ô�ѽϴ���ӽ�������ƶ����滻���ĸ����
		if (array[i]<array[nChild])
		{
			swap(array[i],array[nChild]);
		}
		else break; //�����˳�ѭ��
	}
}
//�������㷨
void HeapSort(int array[], int length)
{
	int i;
	//�������е�ǰ�벿��Ԫ�أ�������֮���һ��Ԫ�������е�����Ԫ��
	//length/2-1�����һ����Ҷ�ڵ㣬�˴�"/"Ϊ����
	for (i = length / 2 - 1; i >= 0; --i)
		HeapAdjust(array, i, length);
	//�����һ��Ԫ�ؿ�ʼ�����н��е��������ϵ���С�����ķ�Χֱ����һ��Ԫ��
	for (i = length - 1; i>0; --i)
	{
		//�ѵ�һ��Ԫ�غ͵�ǰ�����һ��Ԫ�ؽ�����
		//��֤��ǰ�����һ��λ�õ�Ԫ�ض��������ڵ��������֮������
		swap(array[0],array[i]);
		//������С����heap�ķ�Χ��ÿһ�ε�����ϱ�֤��һ��Ԫ���ǵ�ǰ���е����ֵ
		HeapAdjust(array, 0, i);
	}
}
int main()
{
    //Init
	int n,i;
	int a[MAX_SIZE];

	//read
	scanf("%d",&n);
	freopen("num.in","r",stdin);
	freopen("num.out","w",stdout);
	for(i=0;i<n;i++)
	{
		scanf("%d\n",&a[i]);
	}

	//solve
	HeapSort(a,n);

	//output
	for(i=0;i<n;i++)
	{
		printf("%d\n",a[i]);
	}
	return 0;
}
