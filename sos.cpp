#include <iostream>
#include <vector>
using namespace std;

bool found = false;

void subsetSum(vector<int>& set, vector<int>& subset,
               int index, int currentSum, int target) {
    if (currentSum == target) {
        found = true;
        cout << "{ ";
        for (int num : subset)
            cout << num << " ";
        cout << "}" << endl;
        return;
    }
    if (index == set.size() || currentSum > target)
        return;
    // Include current element
    subset.push_back(set[index]);
    subsetSum(set, subset, index + 1,
              currentSum + set[index], target);
    // Exclude current element
    subset.pop_back();
    subsetSum(set, subset, index + 1,
              currentSum, target);
}

int main() {
    vector<int> set = {1, 2, 5, 6, 8};
    int target = 9;
    vector<int> subset;
    cout << "Subsets with sum " << target << " are:\n";
    subsetSum(set, subset, 0, 0, target);

    if (!found) {
        cout << "No subset exists with the given sum." << endl;
    }
    cout << "\nThis program is executed by Shivam Maurya (Roll No: 2400320101044)" << endl;
    return 0;
}