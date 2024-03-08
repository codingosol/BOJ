#include <iostream>

using namespace std;

int main(void)
{
    int t;
    cin >> t;
    int h, w, n;
    for(int i = 0; i < t; i++)
    {
        cin >> h >> w >> n;
        // 3층까지라고 하면 101 -> 201 -> 301 -> 102 -> ... 순
        // 높이로 나눠서 몫이 호수, 나머지가 층수. 단 호수와 층수는 0이 될 수 없음
        int room = (n-1) / h + 1; // 호수
        int floor = n % h; // 층수, 꼭대기 층에서 멈출 경우 0이 되는게 문제 -> 예외처리
        if(floor == 0)
            floor = h;
        // 그리고 출력 시 호수가 10 미만일 경우에는 0을 붙이고 아닐 경우에는 제외
        if(room < 10)
        {
            cout << floor << '0' << room << '\n';
        }
        else
        {
            cout << floor << room << '\n';
        }
    }
    return 0;
}