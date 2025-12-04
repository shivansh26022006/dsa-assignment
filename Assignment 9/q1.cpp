#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
#include <algorithm>
using namespace std;
void BFS(int start, vector<vector<int>> &adj, int V) {
    vector<int> visited(V, 0);
    queue<int> q;

    visited[start] = 1;
    q.push(start);

    cout << "BFS: ";
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int neigh : adj[node]) {
            if (!visited[neigh]) {
                visited[neigh] = 1;
                q.push(neigh);
            }
        }
    }
    cout << endl;
}

void DFSUtil(int node, vector<vector<int>> &adj, vector<int> &vis) {
    vis[node] = 1;
    cout << node << " ";

    for (int neigh : adj[node]) {
        if (!vis[neigh])
            DFSUtil(neigh, adj, vis);
    }
}

void DFS(int start, vector<vector<int>> &adj, int V) {
    vector<int> vis(V, 0);
    cout << "DFS: ";
    DFSUtil(start, adj, vis);
    cout << endl;
}

struct Edge {
    int u, v, w;
};

struct DSU {
    vector<int> parent, rank;
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i=0; i<n; i++) parent[i] = i;
    }

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a != b) {
            if (rank[a] < rank[b]) swap(a, b);
            parent[b] = a;
            if (rank[a] == rank[b]) rank[a]++;
        }
    }
};

int KruskalMST(vector<Edge> &edges, int V) {
    sort(edges.begin(), edges.end(),
         [](Edge a, Edge b){ return a.w < b.w; });

    DSU ds(V);
    int mstWeight = 0;

    cout << "Kruskal MST Edges:\n";

    for (auto &e : edges) {
        if (ds.find(e.u) != ds.find(e.v)) {
            cout << e.u << " -- " << e.v << " = " << e.w << endl;
            mstWeight += e.w;
            ds.unite(e.u, e.v);
        }
    }
    return mstWeight;
}

int PrimMST(vector<vector<int>> &graph, int V) {
    vector<int> key(V, INT_MAX);
    vector<int> mst(V, 0);
    key[0] = 0;

    int mstWeight = 0;

    cout << "Prim MST Edges:\n";

    for (int i = 0; i < V; i++) {
        int u = -1;

        for (int j = 0; j < V; j++)
            if (!mst[j] && (u == -1 || key[j] < key[u]))
                u = j;

        mst[u] = 1;
        mstWeight += key[u];

        for (int v = 0; v < V; v++) {
            if (graph[u][v] != 0 && !mst[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
            }
        }
    }
    return mstWeight;
}

void Dijkstra(vector<vector<int>> &graph, int src, int V) {
    vector<int> dist(V, INT_MAX);
    vector<int> visited(V, 0);
    dist[src] = 0;

    for (int i = 0; i < V; i++) {
        int u = -1;

        for (int j = 0; j < V; j++)
            if (!visited[j] && (u == -1 || dist[j] < dist[u]))
                u = j;

        visited[u] = 1;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] != 0 && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
        }
    }

    cout << "Dijkstra Shortest Distances:\n";
    for (int i = 0; i < V; i++)
        cout << src << " -> " << i << " = " << dist[i] << endl;
}

int main() {
    int V = 5;

    vector<vector<int>> adj = {
        {1, 2},
        {0, 3},
        {0, 3},
        {1, 2, 4},
        {3}
    };

   
    vector<vector<int>> graph = {
        {0, 2, 3, 0, 0},
        {2, 0, 1, 4, 0},
        {3, 1, 0, 5, 0},
        {0, 4, 5, 0, 6},
        {0, 0, 0, 6, 0}
    };

    vector<Edge> edges = {
        {0,1,2}, {0,2,3}, {1,2,1}, {1,3,4},
        {2,3,5}, {3,4,6}
    };

    BFS(0, adj, V);
    DFS(0, adj, V);

    cout << "Kruskal MST Weight = " << KruskalMST(edges, V) << endl;

    cout << "Prim MST Weight = " << PrimMST(graph, V) << endl;

    Dijkstra(graph, 0, V);

    return 0;
}
