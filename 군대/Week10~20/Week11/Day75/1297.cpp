#include <iostream>
#include <cmath>

using namespace std;

int main(void)
{
    int d,h,w;
    cin >> d >> h >> w;
    // d는 대각선 길이 h와 w는 세로와 가로 비율
    // h : w 를 단위 x라고 두고 nx mx로 가정
    double x;
    // d^2 = n^2x^2 + m^2x^2
    // x^2 = d^2 / (n^2 + m^2);
    // x = sqrt(d^2 / (n^2 + m^2))
    x = sqrt((pow(d,2) / (pow(h,2) + pow(w,2))));
    // cout << x << '\n';
    cout << floor(h*x) << ' ' << floor(w*x) << '\n';
    return 0;
}