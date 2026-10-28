#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

class TSP {
private:
    int n; // number of cities
    vector<vector<int>> dist;
    vector<vector<int>> dp;

public:
    TSP(int n, vector<vector<int>> &dist) {
        this->n = n;
        this->dist = dist;
        dp.assign(1 << n, vector<int>(n, -1));
    }

    int solve(int mask, int pos) {
        if (mask == (1 << n) - 1) {
            return dist[pos][0]; // return to starting city
        }

        if (dp[mask][pos] != -1) return dp[mask][pos];

        int ans = INF;
        for (int city = 0; city < n; city++) {
            if ((mask & (1 << city)) == 0) {
                int newAns = dist[pos][city] + solve(mask | (1 << city), city);
                ans = min(ans, newAns);
            }
        }
        return dp[mask][pos] = ans;
    }
};

int main() {
    int n = 4;
    vector<vector<int>> dist = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    TSP tsp(n, dist);
    cout << "Minimum cost of travelling all cities: "
         << tsp.solve(1, 0) << endl;

    cout << "This program is executed by Shivam Maurya (Roll No: 2400320101044)" << endl;
    return 0;
}
