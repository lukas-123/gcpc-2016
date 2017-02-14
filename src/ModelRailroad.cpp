#include<iostream>
#include<cstdint>
#include<unordered_map>
#include<vector>
#include<cmath>
#include<queue>
using namespace std;

typedef uint64_t u64;

int main() {
    size_t n, m, l;
    cin >> n >> m >> l;

    vector<unordered_map<size_t, u64>> graph(n);
    u64 l_value = 0;
    for (size_t e_idx = 0; e_idx < m; ++e_idx) {
        size_t from, to;
        u64 c;
        cin >> from >> to >> c;
        from -= 1;
        to -= 1;
        if (e_idx < l) {
            l_value += c;
        }

        if (graph[from].find(to) != graph[from].end()) {
            graph[from][to] = min(graph[from][to], c);
            graph[to][from] = min(graph[to][from], c);
        } else {
            graph[from][to] = c;
            graph[to][from] = c;
        }
    }

    typedef pair<u64, size_t> Node;
    priority_queue<Node, vector<Node>, greater<Node>> q;
    q.push(Node(0, 0));
    vector<bool> vis(n);
    size_t vis_cnt = 0; 
    u64 c_sum = 0;
    while(!q.empty() && vis_cnt < n) {
        size_t curr_node;
        u64 curr_c;
        tie(curr_c, curr_node) = q.top();
        q.pop();
        if (vis[curr_node]) {
            continue;
        }
        vis[curr_node] = true;
        ++vis_cnt;
        c_sum += curr_c;
        for (auto nb : graph[curr_node]) {
            if (!vis[nb.first]) {
                q.push(Node(nb.second, nb.first));
            }
        }
    }

    if (c_sum <= l_value && vis_cnt == n) {
        cout << "possible" << endl;
    } else {
        cout << "impossible" << endl;
    }

}
