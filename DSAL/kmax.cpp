//
// Created by douxl on 19-6-7.
//

#include <bits/stdc++.h>

using namespace std;

int partition(int *arr, int i, int j) {
        int key = arr[i];
        while (i < j) {
                while (i < j && arr[j] <= key) {
                        j--;
                }
                arr[i] = arr[j];
                while (i < j && arr[i] >= key) {
                        i++;
                }
                arr[j] = arr[i];

        }
        arr[i] = key;
        return i;
}

int kmax(int *array, int n, int k) {
        int l = 0;
        int r = n - 1;
        while (l < r) {
                int mid = partition(array, l, r);
                if(mid==k-1){
                        return array[mid];
                }
                if(mid<k-1){
                        l=mid;
                }else if(mid>k-1){
                        r=mid;
                }
        }
}

int main() {
        int i, a[10] = {0, 1, 3, 4, 9, 8, 5, 7, 2, 6};
        cout << kmax(a, 10, 3) << endl;

        return 0;
}