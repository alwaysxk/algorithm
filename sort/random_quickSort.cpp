#include <bits/stdc++.h>

/**
    普通的快速排序算法的pivot是从最后面开始选得
    随机化的快速排序算法的pivot是随机选的，然后再放到当前子数组的最后一个元素
**/
using namespace std;
// 交换数组的两个元素
void swapEleOfArray(vector<int> &arr, int first, int second){
    int tmp = arr[first];
    arr[first] = arr[second];
    arr[second] = tmp;

}

//
int randomized_part(vector<int> &arr, int l, int r){
    int pivot = rand() % (r - l) + l;  // 随机的从数组选择一个
    swapEleOfArray(arr, pivot, r); // 放到当前子数组的最后
    return part(arr, l, r);
}

int part(vector<int> &arr, int l, int r){
    int x = arr[r];
    int i = l-1;
    for(int j = l; j<r; j++){
        if(arr[j]<=x){
            i++;
            swapEleOfArray(arr, i, j);
        }
    }
    swapEleOfArray(arr, i+1, r);
    return i + 1;
}
void random_quickSort(vector<int> &arr, int l, int r){
    if(l < r){
        int q = randomized_part(arr, l, r);
        random_quickSort(arr, l, q-1);
        random_quickSort(arr, q+1, r);
    }
}
