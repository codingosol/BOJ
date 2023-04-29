#include <iostream>

using namespace std;

int n; // 공장의 수
int buy[100001]; // 공장에서 살 라면 개수 저장
int cnt = 0; // 쓴 돈

// 최소 금액으로 사기 위해서는 한번에 많이 구매하는게 이득임
// 7원으로 3개 구매 -> 5원으로 2개 구매 -> 3원으로 1개 구매 순으로 검사
// 처음부터 끝까지 직선으로 검사하면 중간이 튀어나온 블럭같은 경우에 막힘
// 어떻게하노?
// i번 공장을 검색할 때 i+1번 공장의 라면 개수가 i+2번 공장의 라면 개수보다 많다면
// 중간이 볼록하게 튀어나온 모양이 됨
// i번과 i + 1번 공장의 라면을 같이 사서 i+2번 공장의 라면 개수와 같을 때까지 줄이고 
// 7원으로 3개를 한꺼번에 삼
// 이후에는 i번 공장과 i+1번 공장의 라면을 5원으로 구매하고 남았다면 3원으로 i번 공장 전부 구매
// 1번부터 n번까지 차례대로 검사하므로 i번 공장이 먼저 소진되더라도 괜찮음
// i+1 < i+2 라면 문제가 없으므로 7원 -> 5원 -> 3원 순으로 구매

// 요약 : i+1 > i+2 일 때 5원 -> 7원 -> 3원 // i+1 <= i+2 일 때 7 -> 5 -> 3


int main(void)
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> buy[i];
    } // input;
    for(int i = 1; i <= n; i++)
    {
        if(buy[i + 1] <= buy[i + 2]) // 정순서일때
        {
            // 7원 -> 5원 -> 3원 순
            int cnt_abc = min(min(buy[i],buy[i+1]),buy[i+2]); // i, i+1, i+2 중 최솟값
            cnt += cnt_abc * 7;
            buy[i] -= cnt_abc;
            buy[i+1] -= cnt_abc;
            buy[i+2] -= cnt_abc;
            // 7원 끝
            int cnt_ab = min(buy[i],buy[i+1]);
            cnt += cnt_ab * 5;
            buy[i] -= cnt_ab;
            buy[i+1] -= cnt_ab;
            // 5원 끝
        }
        else {
            // 5원 -> 7원 -> 3원 순
            // i+1의 수가 i+2와 같을 때까지 줄여야 함
            int cnt_ab = min(buy[i],buy[i+1] - buy[i+2]);
            cnt += cnt_ab * 5;
            buy[i] -= cnt_ab;
            buy[i+1] -= cnt_ab;
            // 5원 끝
            int cnt_abc = min(min(buy[i],buy[i+1]),buy[i+2]); // i, i+1, i+2 중 최솟값
            cnt += cnt_abc * 7;
            buy[i] -= cnt_abc;
            buy[i+1] -= cnt_abc;
            buy[i+2] -= cnt_abc;
            // 7원 끝
        }
        // 3원은 공통이므로
        cnt += buy[i] * 3;
        buy[i] = 0;
    }
    cout << cnt << '\n';
    return 0;
}