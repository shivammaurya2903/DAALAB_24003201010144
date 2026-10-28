#include <bits/stdc++.h>
using namespace std;

void selection_sort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        swap(arr[min_idx], arr[i]);
    }
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    selection_sort(arr);
    cout << "Sorted array: ";
    for (int x : arr) cout << x << " ";
    cout << "\n";
    cout << "This program is executed by Shivam Maurya (Roll No: 2400320101044)" << endl;
    return 0;
}
