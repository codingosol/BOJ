#include <iostream>
#include <cmath>

using namespace std;

int main(void)
{
    int r;
    cin >> r;
    cout << fixed;
    cout.precision(10);
    // 유클리드 원의 넓이는 pow로 구함
    double euclid = pow(r,2) * M_PI;
    // 비유클리드 원의 넓이...
    // 비유클리드 거리는 
    // |x1-x2| + |y1-y2| == r이 되는 모든 점들의 집합이므로 
    double taxi = pow(r,2) * 2;
    cout << euclid << '\n';
    cout << taxi << '\n';
    return 0;
}