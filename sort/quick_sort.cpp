#include <bits/stdc++.h>

using namespace std;

void swapEleOfArray(vector<int> &arr, int first, int second){
    int tmp = arr[first];
    arr[first] = arr[second];
    arr[second] = tmp;

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
void quickSort(vector<int> &arr, int l, int r){
    if(l < r){
        int q = part(arr, l, r);
        quickSort(arr, l, q-1);
        quickSort(arr, q+1, r);
    }
}
