#include <bits/stdc++.h>

/**
    ��ͨ�Ŀ��������㷨��pivot�Ǵ�����濪ʼѡ��
    ������Ŀ��������㷨��pivot�����ѡ�ģ�Ȼ���ٷŵ���ǰ����������һ��Ԫ��
**/
using namespace std;
// �������������Ԫ��
void swapEleOfArray(vector<int> &arr, int first, int second){
    int tmp = arr[first];
    arr[first] = arr[second];
    arr[second] = tmp;

}

//
int randomized_part(vector<int> &arr, int l, int r){
    int pivot = rand() % (r - l) + l;  // ����Ĵ�����ѡ��һ��
    swapEleOfArray(arr, pivot, r); // �ŵ���ǰ����������
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
