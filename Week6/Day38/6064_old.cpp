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
        int cnt = 1; // 몇번째 해인지 세줄 친구
        // 1,1이 1번째 해이므로 1로
        // 범위가 4만이므로 브루트포스로는 1.6억회 연산 -> 시간초과
        // 뒤 수가 기준이므로 먼저 뒷 수를 맞추고 yn만큼 더해가면서 앞 수가 맞는지 체크
        int curx = 1, cury = 1;
        for(; cury < y; cury++) // 뒷 수 먼저 맞춰주기
        {
            curx = (curx + 1) % xn;
            if(curx == 0)
            {
                curx = xn;
            }
            cnt++;
        }
        // 최대로 반복할 수 있는 횟수는 최소공배수만큼임
        while(true)
        {
            if(curx == x && cury == y) // 찾고자 하는 수를 찾았다면
            {
                cout << cnt << '\n';
                break;
            }
            else { // 찾지 못했다면
                curx = (curx + yn - 1) % xn + 1; // 최대 수를 넘을 수 없게 
                cnt += yn;
                if(cnt > lcm(xn,yn)) // 최대치를 초과했다면
                {
                    cout << "-1\n";
                    break;
                }
            }
        }
    }
    return 0;
}