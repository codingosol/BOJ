#include <iostream>
#include <cmath>

using namespace std;

int gcd(int a, int b)
{
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int lcm(int a, int b)
{
    return (a * b) / gcd(a,b);
}



int main(void)
{
    int n; // testcase
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int xn, yn; // 달력의 최대수
        int x, y; // 찾고자 하는 수
        cin >> xn >> yn >> x >> y;
        int cnt; // 몇번째 해인지 세줄 친구
        // 1,1이 1번째 해이므로 1로
        // 범위가 4만이므로 브루트포스로는 1.6억회 연산 -> 시간초과
        for(cnt = x; cnt <= lcm(xn,yn); cnt += xn)
        {
            int temp = (cnt % yn == 0) ? yn : cnt % yn;
            if(temp == y)
            {
                cout << cnt << '\n';
                break;
            }
        }
        if(cnt > lcm(xn,yn))
        {
            cout << "-1\n";
        }
    }
    return 0;
}