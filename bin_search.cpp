#include <iostream>
using namespace std;

int binarySearch(int arr[], int low, int high, int target) {
    if (low > high) return -1; 
    int mid = low + (high - low) / 2;

    if (arr[mid] == target) return mid;
    else if (arr[mid] < target) 
        return binarySearch(arr, mid + 1, high, target);
    else 
        return binarySearch(arr, low, mid - 1, target);
}

int main() {
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int target;
    cin >> target;

    int result = binarySearch(arr, 0, n - 1, target);

    if (result != -1)
        cout << "Found at index: " << result << endl;
    else
        cout << "Not found" << endl;

    cout << "This program is executed by Shivam Maurya (Roll No: 2400320101044)" << endl;

    return 0;
}
