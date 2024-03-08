#include <iostream>

using namespace std;

int main(void)
{
    int n;
    cin >> n;
    int score[1001];
    int max = 0;
    for(int i = 1; i <= n; i++)
    {
        cin >> score[i]; // 초기 점수 기록
        if(max < score[i])
            max = score[i]; // 최댓값 기록
    }
    double totalscore = 0;
    for(int i = 1; i <= n; i++)
    {
        double newscore;
        newscore = (double)score[i] / max * 100;
        totalscore += newscore;
    }
    totalscore /= n;
    cout << totalscore << '\n';
    return 0;
}