#include <bits/stdc++.h>

using namespace std;

int binarySearch(int *arr, int target, int len) {
        int i = 0, j = len - 1;
        while (i < j) {
                int mid = (i + j) / 2;
                if (arr[mid] == target) {
                        return mid;
                } else if (arr[mid] > target) {
                        j = mid;
                } else if (arr[mid] < target) {
                        i = mid;
                }
        }
        return -1;
}

int main() {
        int array[10]={1,5,2,512,531,32,2312,412,213,23};
        sort(array,array+10);
        cout<<binarySearch(array,32,10)<<endl;
        return 0;
}