#include<iostream>
#include<cstdio>
#define MAX_SIZE 10000

void merge(int a[],int tem[],int l,int mid,int r)
{
	int m=l,n=mid+1,i=l;
	while(m<=mid && n<=r)
	{
		if(a[m]<a[n])
			tem[i++]=a[m++];
		else
			tem[i++]=a[n++];
	}
	while(m<=mid)
		tem[i++]=a[m++];
	while(n<=r)
		tem[i++]=a[n++];
	for(i=l;i<=r;i++)
		a[i]=tem[i];
}
void merge_sort(int a[],int tem[],int l,int r)
{
	if(l>=r)
		return;
	int mid=(l+r)/2;
	merge_sort(a,tem,l,mid);
	merge_sort(a,tem,mid+1,r);
	merge(a,tem,l,mid,r);
}

int main()
{
	int n,i;
	int a[MAX_SIZE];
	int tem[MAX_SIZE];
	scanf("%d",&n);
	FILE *in=fopen("num.in","r");
	FILE *out=fopen("num.out","w");
	for(i=0;i<n;i++)
	{
		fscanf(in,"%d\n",&a[i]);
	}
	merge_sort(a,tem,0,n-1);
	for(i=0;i<n;i++)
	{
		fprintf(out,"%d\n",a[i]);
	}
	fclose(in);
	fclose(out);
	return 0;
}
