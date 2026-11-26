#include <iostream>
#include <vector>
using namespace std;

int V;
bool found = false;

bool isSafe(int v, vector<vector<int>>& graph,
            vector<int>& path, int pos) {

    if (graph[path[pos - 1]][v] == 0)
        return false;

    for (int i = 0; i < pos; i++) {
        if (path[i] == v)
            return false;
    }

    return true;
}

void hamiltonianCycle(vector<vector<int>>& graph,
                      vector<int>& path, int pos) {

    if (pos == V) {
        if (graph[path[pos - 1]][path[0]] == 1) {
            found = true;

            cout << "Hamiltonian Cycle: ";
            for (int i = 0; i < V; i++)
                cout << path[i] << " ";

            cout << path[0] << endl;
        }
        return;
    }

    for (int v = 1; v < V; v++) {

        if (isSafe(v, graph, path, pos)) {
            path[pos] = v;

            hamiltonianCycle(graph, path, pos + 1);

            path[pos] = -1; // Backtrack
        }
    }
}

int main() {

    vector<vector<int>> graph = {
        {0,1,1,0,1},
        {1,0,1,1,1},
        {1,1,0,1,0},
        {0,1,1,0,1},
        {1,1,0,1,0}
    };

    V = graph.size();

    vector<int> path(V, -1);
    path[0] = 0;

    hamiltonianCycle(graph, path, 1);

    if (!found) {
        cout << "No Hamiltonian Cycle exists in the graph." << endl;
    }

    cout << "\nThis program is executed by Shivam Maurya (Roll No: 2400320101044)" << endl;

    return 0;
}