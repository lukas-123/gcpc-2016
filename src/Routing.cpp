#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<string>
#include<list>
#include<tuple>
#include<vector>
#include<limits>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    
    size_t serv_cnt;
    cin >> serv_cnt;

    vector<int> proc_times(serv_cnt);
    unordered_map<size_t, unordered_map<size_t, unordered_set<size_t>>> graph; 
    for (size_t curr_serv = 0; curr_serv < serv_cnt; ++curr_serv) {
        size_t conn_cnt;
        cin >> conn_cnt;
        cin >> proc_times[curr_serv];

        for (size_t conn_idx = 0; conn_idx < conn_cnt; ++conn_idx) {
            size_t blocked_cnt;
            size_t to_serv;
            cin >> blocked_cnt >> to_serv;
            to_serv -= 1;
            graph[curr_serv][to_serv] = {};
            for (size_t blocked_idx = 0; blocked_idx < blocked_cnt; ++blocked_idx) {
                size_t blocked_from;
                cin >> blocked_from;
                blocked_from -= 1;
                graph[curr_serv][to_serv].insert(blocked_from);
            }
        }
    }

    vector<int> dist(serv_cnt, numeric_limits<int>::max());
    vector<int> visited_cnt(serv_cnt);
    using CurrNode = tuple<int, size_t, size_t>;
    list<CurrNode> queue = { make_tuple(0, 0, 0) };
    while (!queue.empty()) {
        int curr_dist;
        size_t curr_node;
        size_t prev_node;

        tie(curr_dist, curr_node, prev_node) = queue.front();
        queue.pop_front();

        if (visited_cnt[curr_node]++ >= 2) {
            continue;
        }

        dist[curr_node] = curr_dist;

        if (curr_node == serv_cnt - 1) {
            break;
        }

        for (auto const& neighbor : graph[curr_node]) {
            if (graph[curr_node][neighbor.first].find(prev_node) == graph[curr_node][neighbor.first].end()) {
                queue.push_back(make_tuple(curr_dist + proc_times[curr_node], neighbor.first, curr_node));
            }
        }
    }

    if (dist.back() != numeric_limits<int>::max()) {
        cout << (dist.back() + proc_times.back()) << endl;
    } else {
        cout << "impossible" << endl;
    }
}
