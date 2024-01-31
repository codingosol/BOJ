#include <iostream>

using namespace std;

int main(void)
{
    cout.precision(10);
    double d1, d2, p;
    cin >> d1 >> d2 >> p;
    // perc는 밀도가 더 높은 쪽의 '질량'의 비율임...!!
    /* 물질을 혼합한 후의 부피는 혼합 전 두 물질의 부피의 합이고, 물질을 혼합한 후의 질량도 혼합 전 두 물질의 질량의 합이다.
        ex) 8 10 50의 경우 합친 물질에서 10의 질량 %가 50이라는 뜻 -> 8짜리가 부피로는 더 많이 들어가게 됨
    */
    double lar, sml; // 각각 질량이 더 높은 / 낮은 값
    if(d1 >= d2)
    {
        lar = d1;
        sml = d2;
    }
    else {
        sml = d1;
        lar = d2;
    }
    double ans;
    double mass;
    // 밀도 = 질량 / 부피임
    // 1. 질량을 구하기 위해선 lar과 sml 각각의 질량을 구해야 함
    // 2. 질량 비율을 만족하는 sml의 배율 변수 n을 구해야 함
    // 만족해야 할 질량비는 p : 100-p 이므로
    // lar : sml*n = p : 100-p => lar(1-p) = sml*n*p
    // n = lar(100-p) / sml*p
    // 부피는 1+n이 됨
    // 따라서 밀도는 lar+sml*n / 1+n;
    // 식 전개
    // cout << lar*(100-p) << ' ' << sml*p << '\n';
    double mult = (lar*(100-p)) / (sml*p);
    //cout << mult << '\n';
    ans = (lar+(sml*mult)) / (1+mult);
    cout << ans << '\n';
    return 0;
}