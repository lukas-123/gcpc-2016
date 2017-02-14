#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<string>
#include<list>
#include<vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    
    size_t relation_cnt;
    cin >> relation_cnt;

    unordered_map<string, size_t> d_num; 
    unordered_map<size_t, unordered_set<size_t>> d_g;
    size_t dwarf_cnt = 0;
    vector<size_t> in_degree(2 * relation_cnt);

    for (size_t relation_idx = 0; relation_idx < relation_cnt; ++relation_idx) {
        string fst_dwarf;
        string snd_dwarf;
        char op;
        cin >> fst_dwarf >> op >> snd_dwarf;

        if (d_num.find(fst_dwarf) == d_num.end()) {
            d_num[fst_dwarf] = dwarf_cnt;
            ++dwarf_cnt;
        }
        if (d_num.find(snd_dwarf) == d_num.end()) {
            d_num[snd_dwarf] = dwarf_cnt;
            ++dwarf_cnt;
        }


        if (op == '>' && d_g[d_num[fst_dwarf]].find(d_num[snd_dwarf]) == d_g[d_num[fst_dwarf]].end()) {
            d_g[d_num[fst_dwarf]].insert(d_num[snd_dwarf]);
            ++in_degree[d_num[snd_dwarf]];
        } else if (op == '<' && d_g[d_num[snd_dwarf]].find(d_num[fst_dwarf]) == d_g[d_num[snd_dwarf]].end()) {
            d_g[d_num[snd_dwarf]].insert(d_num[fst_dwarf]);
            ++in_degree[d_num[fst_dwarf]];
        }
    }

    list<size_t> queue;
    for (size_t dwarf_idx = 0; dwarf_idx < dwarf_cnt; ++dwarf_idx) {
        if (in_degree[dwarf_idx] == 0) {
            queue.push_back(dwarf_idx);
        }
    }

    size_t visited_cnt = 0;
    while (!queue.empty()) {
        size_t curr_dwarf = queue.front();
        queue.pop_front();
        ++visited_cnt;

        for (size_t neighbor_dwarf : d_g[curr_dwarf]) {
            if (--in_degree[neighbor_dwarf] == 0) {
                queue.push_back(neighbor_dwarf);
            }
        }
    }

    cout << (visited_cnt == dwarf_cnt ? "possible" : "impossible") << endl;
}
