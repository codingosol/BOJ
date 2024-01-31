#include <iostream>
#include <cmath>

using namespace std;

int main(void)
{
    int score_a, score_b, score_c;
    cin >> score_a >> score_b;
    // 이제 a과 b가 맞힌 과녁을 체크해야 함
    int score = 512;
    score_c = 0;
    while(score > 0)
    {
        int cnt = 0;
        if(score_a >= score)
        {
            cnt++;
            score_a -= score;
        }
        if(score_b >= score)
        {
            cnt++;
            score_b -= score;
        }
        if(cnt == 1)
        {
            score_c += score;
        }
        score /= 2;
    }
    cout << score_c << '\n';
    return 0;
}