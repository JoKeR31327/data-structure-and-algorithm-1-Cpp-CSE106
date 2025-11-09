#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

class node{
    public:
    int id;
    vector<int> neighbors;

    node(){
        id=0;
    }

    node(int a){
        id=a;
    }

    void addNeighbor(int neighbor) {
        neighbors.push_back(neighbor);
    }
};
class Map{
    public:

    unordered_map<int, node> nodes;

    void addnode(int id) {
        nodes.emplace(id, node(id));
    }
    void addedge(int u, int v) {
        nodes[u].addNeighbor(v);
    }
    
};

vector<int> bfs(Map& graph, int start, int end) {
    vector<int> done(100, 0);
    vector<int> parent(100, -1);
    queue<int> q;
    q.push(start);
    done[start] = 1;

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        for (int neighbor : graph.nodes.at(current).neighbors) {
            if (!done[neighbor]) {
                q.push(neighbor);
                done[neighbor] = 1;
                parent[neighbor] = current;
            }
        }
    }

    if (!done[end]) {
        return vector<int>();
    }

    vector<int> path;
    int node = end;
    while (node != -1) {
        path.push_back(node);
        node = parent[node];
    }
    int left = 0;
    int right = path.size() - 1;
    while (left < right) {
    swap(path[left], path[right]);
    left++;
    right--;
}

    return path;
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

    vector<int> path = bfs(graph, source, destination);

    if (!path.empty()) {
        cout << path.size() - 1 << endl;
        for (int node : path) {
            cout << node << " ";
        }
        cout << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}
