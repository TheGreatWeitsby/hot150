#include <iostream>
#include <vector>

using namespace std;

int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    // minDist, recording the minimum distance from node i to node k
    vector<int> minDist(n + 1, INT_MAX); // index 0 not use
    minDist[k] = 0;

    // visited, recording whether the node is visited
    vector<bool> visited(n + 1, false);
    
    for (int j = 1; j <= n; j++) {
        // select the nearest node to node k
        int nearestNode;
        int tmpDist = INT_MAX;
        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                if (minDist[i] <= tmpDist) {
                    nearestNode = i;
                    tmpDist = minDist[i];
                }
            }
        }
        cout << "nearest node: " << nearestNode << endl;
        cout << "the distance of nearest node: " << tmpDist << endl;


        // label the nearest node as visited
        visited[nearestNode] = true;
        for (int i = 1; i <= n; i++) {
            if (visited[i]) cout << i << " t, ";
            else cout << i << " f, ";
        }
        cout << endl;

        // update the minDist of the node (not visited) near the nearest node
        for (int i = 0; i < times.size(); i++) {
            if (times[i][0] == nearestNode && !visited[times[i][1]]) {
                int node = times[i][1];
                minDist[node] = min(minDist[node], minDist[nearestNode] + times[i][2]);
            }
        }
        for (int i = 1; i <= n; i++) {
            cout << i << ':' << minDist[i] << ", ";
        }
        cout << endl;
    }

    int timeToWait = 0;
    for (int i = 1; i <= n; i++) {
        if (minDist[i] == INT_MAX) return -1;
        if (minDist[i] != 0) timeToWait = max(timeToWait, minDist[i]);
    }
    return timeToWait;
}

int main() {
    vector<vector<int>> times = {{1,2,1}, {2,1,3}};
    int timeToWait = networkDelayTime(times, 2, 2);
    cout << timeToWait;
}