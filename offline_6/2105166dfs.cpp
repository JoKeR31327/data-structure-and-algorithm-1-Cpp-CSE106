#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Node {
public:
    int id;
    vector<int> neighbors;

    Node() {
        id = 0;
    }

    Node(int a) {
        id = a;
    }

    void addadjacent(int neighbor) {
        neighbors.push_back(neighbor);
    }
};

class Map {
public:
    unordered_map<int, Node> nodes;

    void addnode(int id) {
        nodes.emplace(id, Node(id));
    }

    void addedge(int u, int v) {
        nodes[u].addadjacent(v);
    }
};

bool dfs(Map& graph, int current, int end, vector<int>& path, vector<int>& visited) {
    visited[current] = 1;

    if (current == end) {
        path.push_back(current);
        return true;
    }

    for (int neighbor : graph.nodes[current].neighbors) {
        if (!visited[neighbor] && dfs(graph, neighbor, end, path, visited)) {
            path.push_back(current);
            return true;
        }
    }

    return false;
}

int main() {
    int n, m;
    cin >> n >> m;

    Map graph;

    for (int i = 1; i <= n; ++i) {
        graph.addnode(i);
    }

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        graph.addedge(u, v);
    }

    int source, destination;
    cin >> source >> destination;

    vector<int> path;
    vector<int> visited(n + 1, 0);

    bool found = dfs(graph, source, destination, path, visited);

    if (found) {
        cout << path.size() - 1 << endl;
        for (int i = path.size() - 1; i >= 0; --i) {
            cout << path[i] << " ";
        }
        cout << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}
