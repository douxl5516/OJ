#include <bits/stdc++.h>
using namespace std;

const int maxn=100;
int heap[maxn],n=10;

void downAdjust(int low,int high){
	int i=low,j=i*2;
	while(j<high){
		if(j+1<=high && heap[j+1]>heap[j]){
			j=j+1;
		}
		if(heap[j]>heap[i]){
			swap(heap[j],heap[i]);
			i=j;
			j=2*i;
		} else{
			break;
		}
	}
}
void upAdjust(int low,int high){
	int i=high,j=i/2;
	while(j>=low){
		if(heap[j]<heap[i]){
			swap(heap[j],heap[i]);
			i=j;
			j=i/2;
		}else{
			break;
		}
	}
}

void deleteTop(){
	heap[1]=heap[n--];
	downAdjust(1,n);
}

void insert(int x){
	heap[++n]=x;
	upAdjust(1,n);
}

void createHeap(){
	for(int i=n/2;i>=1;i--){
		downAdjust(i,n);
	}
}

void heapSort(){
	createHeap();
	for(int i=n;i>1;i--){
		swap(heap[i],heap[1]);
		downAdjust(1,i-1);
	}
}

int main(){

	return 0;
}
