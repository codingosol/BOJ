#include <iostream>

using namespace std;

int main(void)
{
    int a, b, v;
    cin >> a >> b >> v;
    // 낮에 a만큼 오르고 b만큼 미끄러지고 v에 닿는데 걸리는 최소 일수는?
    // 브루트포스로 풀면 시간낭비
    // 낮에 올라서 v를 넘으면 종료이므로 v-a까지 닿거나 v-a 이상이 되면 계산 종료
    // 마지막 하루 오르므로 +1
    int day = (v - a) / (a - b);
    v = v - (a-b) * day; // 남은 거리 판정
    // 남은 거리가 a보다 크다면 +2
    // 아니라면 +1
    if(v > a)
        day += 2;
    else
        day++;
    cout << day << '\n';
    return 0;
}