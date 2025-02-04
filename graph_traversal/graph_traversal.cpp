#include <vector>
#include <iostream>
#include <queue>

using namespace std;                    

void dfs (vector<vector<int>>& graph, vector<bool>& visited, int node) {

    visited[node] = true;
    std::cout << node << std::endl;

    for (int i : graph[node]) {

        if (visited[i] == true) continue;
        dfs(graph, visited, i);
    }
    
}

void bfs (vector<vector<int>>& graph, vector<bool>& visited, int node) {

    queue<int> queue;
    queue.push(node);
    visited[node] = true;


    while (!queue.empty()) {

        int current = queue.front();
        queue.pop();
        std::cout << current << std::endl;

        for (int i: graph[current]) {

            if (visited[i] == true) continue;
            visited[i] = true;
            queue.push(i);
        }
    }
}


int connected(vector<vector<int>>& graph, int start, int end) {
    
    vector<bool> visited(graph.size(), false);
    queue<int> queue;
    queue.push(start);
    visited[start] = true;

    while (!queue.empty()) {

        int current = queue.front();
        queue.pop();

        for (int i: graph[current]) {

            if (visited[i] == true) continue;
            visited[i] = true;
            queue.push(i);
        }
    }

    return visited[end];
}

vector<vector<int>> shortestPath(vector<vector<int>>& graph, int start, int end) {

    

}