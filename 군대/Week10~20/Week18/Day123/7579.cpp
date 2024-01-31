#include <iostream>

using namespace std;

typedef long long int_64;

int n, m;
int_64 mem[101]; // 각 앱의 용량을 저장
int_64 cost[101]; // 각 앱을 비활성화하는데 들어가는 비용
int_64 knapsack[101][10001]; // 비용이 1~100이고 노드 수가 1~100이므로 최대 10000의 비용임

int main(void)
{
    cin >> n >> m; // n개의 앱이 있고 새 앱을 실행하기 위해 m바이트를 확보해야 함
    int_64 total = 0;
    for(int i = 1; i <= n; i++)
    {
        cin >> mem[i];
    }
    for(int i = 1; i <= n; i++)
    {
        cin >> cost[i];
        total += cost[i];
    }
    // input
    // 용량을 확보하는데 들어가는 최소의 비용을 구해야 함
    // 원래 배낭 문제는 정해진 용량에서 최대한 많이 담는 문제지만 지금은 그보다 많은 용량을 차지해도 되지만 최소의 비용을 구해야 함
    // 주어진 용량보다 더 많이 담는 경우의 수가 있음을 생각 -> 어떻게 해야할까
    // 비용에서 얻을 수 있는 최대의 메모리가 m을 넘는 최초의 경우를 구하면 됨
    // knapsack[i][j]는 i번째 앱까지 탐색했을때 j의 비용으로 얻을 수 있는 최대 메모리임
    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j <= total; j++)
        {
            if(j - cost[i] >= 0) // i번째 물건을 담을 수 있을 경우
            {
                knapsack[i][j] = max(knapsack[i][j],knapsack[i-1][j-cost[i]] + mem[i]); // 현재 비용과 담기 전 최대비용 비교
            }
            knapsack[i][j] = max(knapsack[i][j],knapsack[i-1][j]); // 이 물건을 담지 않는 경우와 비교
        }
    }
    for(int i = 0; i <= total; i++)
    {
        if(knapsack[n][i] >= m)
        {
            cout << i << '\n';
            break;
        }
    }
    return 0;
}