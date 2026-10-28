#include <bits/stdc++.h>
using namespace std;

struct Item {
    int value, weight;
    Item(int v, int w) : value(v), weight(w) {}
};

// Comparator to sort items by value/weight ratio
bool cmp(Item a, Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

class Solution {
public:
    double fractionalKnapsack(int W, vector<int>& val, vector<int>& wt) {
        int n = val.size();
        vector<Item> arr;
        for (int i = 0; i < n; i++) arr.push_back(Item(val[i], wt[i]));

        sort(arr.begin(), arr.end(), cmp);

        double finalValue = 0.0;

        for (int i = 0; i < n; i++) {
            if (arr[i].weight <= W) {
                W -= arr[i].weight;
                finalValue += arr[i].value;
            } else {
                finalValue += arr[i].value * ((double)W / arr[i].weight);
                break;
            }
        }
        return finalValue;
    }
};

int main() {
    int W = 50;
    vector<int> val = {60, 100, 120};
    vector<int> wt  = {10, 20, 30};

    Solution ob;
    cout << fixed << setprecision(6) 
         << ob.fractionalKnapsack(W, val, wt) << endl;
         
    cout << "This program is executed by Shivam Maurya (Roll No: 2400320101044)" << endl;


    return 0;
}
