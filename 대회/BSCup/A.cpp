#include <iostream>

using namespace std;

int main(void)
{
    int a, b;
    cin >> a >> b;
    int score, wide;
    cin >> score >> wide;
    // a~b까지의 점수가 있음
    // score-wide ~ score+wide의 사람 수를 세면 됨
    // 단, a보다 작거나 B보다 크면 안됨
    int ans = 0;
    for(int i = score-wide; i <= score+wide; i++)
    {
        if(a <= i && i <= b)
        {
            ans++;
        }
    }
    if(ans == 0)
    {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    cout << ans << '\n';
    return 0;
}