#include <iostream>
#include <cmath>
#include <math.h>

using namespace std;

int main(void)
{
    int testcase;
    cin >> testcase;
    while(testcase--)
    {
        int xs, ys, xe, ye;
        cin >> xs >> ys >> xe >> ye; // 출발점, 도착점 입력
        int planet;
        cin >> planet; // 행성계의 수
        int x, y, r;
        int cnt = 0;
        for(int i = 0; i < planet; i++)
        {
            cin >> x >> y >> r;
            double dist_s = sqrt(pow(abs(x-xs),2) + pow(abs(y-ys),2)); // 출발점과 이 원과의 거리관계
            double dist_e = sqrt(pow(abs(x-xe),2) + pow(abs(y-ye),2)); // 도착점과 이 원과의 거리관계
            // 두 점이 모두 이 원 안에 위치함 -> 경계를 넘을 필요 없음
            // 두 점이 모두 이 원 밖에 위치함 -> 경계를 넘을 필요 없음
            // 두 점중에 하나만 원 안에 있을 때 넘음
            if((dist_s < r && dist_e > r) || (dist_s > r && dist_e < r))
                cnt++;
        }
        cout << cnt << '\n';
    }
    return 0;
}