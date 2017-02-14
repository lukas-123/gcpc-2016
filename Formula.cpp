#include<iostream>
#include<cstdint>
#include<cmath>

using namespace std;

typedef int32_t i32;

int main() {
    ios_base::sync_with_stdio(false);
    cout.precision(4);

    i32 p_x, p_y, q_x, q_y, r_x, r_y; 
    cin >> p_x >> p_y >> q_x >> q_y >> r_x >> r_y;
    double rad;
    cin >> rad;

    double a, b, c;
    a = sqrt((p_x - q_x) * (p_x - q_x) + (p_y - q_y) * (p_y - q_y));
    b = sqrt((p_x - r_x) * (p_x - r_x) + (p_y - r_y) * (p_y - r_y));
    c = sqrt((r_x - q_x) * (r_x - q_x) + (r_y - q_y) * (r_y - q_y));

    double rad_o = (0.5 * sqrt(4 * a * a * b * b - (a * a + b * b - c * c) * (a * a + b * b - c * c))) / (a + b + c);

    double ratio = (1 - rad_o/rad) * 100;
    cout << fixed << -ratio << endl;
}
