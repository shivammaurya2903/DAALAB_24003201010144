#include <iostream>
#include <vector>
using namespace std;

void swap(int &a, int &b) {   
    int temp = a;
    a = b;
    b = temp;
}

int partition(vector<int> &arr, int low, int high) {  
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int> &arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printArr(vector<int> &arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int main() {
    vector<int> arr = {20, 5, 6, 1, 19};

    cout << "Unsorted Array:\n";
    printArr(arr);

    quickSort(arr, 0, arr.size() - 1);

    cout << "Sorted Array:\n";
    printArr(arr);

     cout << "This program is executed by Shivam Maurya (Roll No: 2400320101044)"  << endl;

    return 0;
}
