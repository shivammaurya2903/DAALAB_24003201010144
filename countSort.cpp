#include <bits/stdc++.h>
using namespace std;

void counting_sort(vector<int>& arr) {
    int n = arr.size();
    if (n == 0) return;

    int max_val = *max_element(arr.begin(), arr.end());

    vector<int> count(max_val + 1, 0);

    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    int index = 0;
    for (int i = 0; i <= max_val; i++) {
        while (count[i] > 0) {
            arr[index++] = i;
            count[i]--;
        }
    }
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements (non-negative integers): ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    counting_sort(arr);

    cout << "Sorted array: ";
    for (int x : arr) cout << x << " ";
    cout << "\n";

    cout << "This program is executed by Shivam Maurya (Roll No: 2400320101044)" << endl;

    return 0;
}
