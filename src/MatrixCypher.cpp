#include<iostream>
#include<algorithm>
#include<string>
#include<cstdint>
#include<vector>

using namespace std;

typedef uint64_t u64;
typedef  __uint128_t u128;

u128 parse(string s) {
    u128 res = 0;
    for (char c : s) {
        res *= 10;
        res += static_cast<u64>(c - 48);
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);

    vector<vector<u128>> matrix = {vector<u128>(2), vector<u128>(2)};

    for (size_t row = 0; row < 2; ++row) {
        for (size_t col = 0; col < 2; ++col) {
            string s;
            cin >> s;
            matrix[row][col] = parse(s);
        }
    }

    string res;
    while (!(matrix[0][0] == 1 && matrix[1][0] == 0 && matrix[0][1] == 0 && matrix[1][1] == 1)) {
        if (matrix[0][0] >= matrix[0][1] && matrix[1][0] >= matrix[1][1]) {
            res.push_back('0');
            matrix[0][0] -= matrix[0][1];
            matrix[1][0] -= matrix[1][1];
        } else {
            res.push_back('1');
            matrix[0][1] -= matrix[0][0];
            matrix[1][1] -= matrix[1][0];
        }
    }

    reverse(res.begin(), res.end());
    cout << res << endl;
}
