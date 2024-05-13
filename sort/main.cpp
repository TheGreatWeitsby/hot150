#include<iostream>
#include<vector>
using namespace std;

void printArr(int arr[], int len) {
    for (int i = 0; i < len; i++) {
        cout << arr[i] << ", ";
    }
    cout << endl;
}


/*
* @brief 确定一个pivot, 将其放在指定位置并返回这个指定位置的下标
*/
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            swap(arr[j], arr[i]);
            i++;
        }
    }
    swap(arr[high], arr[i]);

    return i;
}



/**
* @brief 快速排序入口
*
* @param arr[] 数组
* @param low 最小下标
* @param high 最大下标
*/
void quick_sort(int arr[], int low, int high) {
    if (low < high) {
        int mid = partition(arr, low, high);
        printArr(arr, 8);
        quick_sort(arr, low, mid - 1);
        quick_sort(arr, mid + 1, high);
    }
}


int main(int argc, char const *argv[]) {
    int arr[8] = {4, 2, 5, 1, 7, 6, 8, 3};
    int len = 8;
    quick_sort(arr, 0, len - 1);
    return 0;
}