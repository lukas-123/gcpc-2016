#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    
    int cpu_cnt;
    int merch_cnt;
    cin >> cpu_cnt >> merch_cnt;
   
    vector<int> prev_max_money(cpu_cnt + 1);
    for (int merch_idx = 0; merch_idx < merch_cnt; ++merch_idx) {
        vector<int> curr_max_money(prev_max_money);
        for (int offer = 1; offer <= cpu_cnt; ++offer) {
            int money;
            cin >> money;
            for (int prev_cpu_cnt = 0; prev_cpu_cnt <= cpu_cnt; ++prev_cpu_cnt) {
                if (prev_cpu_cnt - offer >= 0) {
                    curr_max_money[prev_cpu_cnt - offer] =
                        max(
                                curr_max_money[prev_cpu_cnt - offer],
                                prev_max_money[prev_cpu_cnt] + money 
                           );
                }
            }
        }
        prev_max_money = std::move(curr_max_money);
    }

    cout << *max_element(prev_max_money.begin(), prev_max_money.end());
}
