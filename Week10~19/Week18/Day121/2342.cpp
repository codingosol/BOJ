#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int dp[100001][5][5];
int size;
int INF = 978654321;

int dist(int from, int to) // 발이 from에서 to로 가는 가격 출력
{
    if(from == 0)
    {
        return 2;
    }
    else if(from == to)
    {
        return 1;
    }
    from--, to--;
    if((from+1) % 4 == to || (from+3) % 4 == to) 
        return 3;
    else if((from+2) % 4 == to) 
        return 4;
    else 
        return INF;

}

int main(void)
{
    int temp;
    // 최초에 두 발은 가운데에 있음
    // 중앙 -> 다른 위치 : 2
    // 인접한 위치 : 3
    // 반대 위치 : 4
    // 같은 지점 한번 더 누르기 : 1
    // 어떻게 dp로 풀지?
    int left = 0, right = 0; // 각각 오른발과 왼발이 밟고 있는 위치
    fill_n(dp[0][0],100001*5*5,INF);
    dp[0][0][0] = 0;
    int i;
    for(i = 1; ; i++)
    {
        cin >> temp;
        if(temp == 0)
            break;
        else
        {
            for(int x = 0; x < 5; x++)
            {
                for(int y = 0; y < 5; y++)
                {
                    if(dp[i-1][x][y] >= INF) // 이 노드의 방문 정보가 없다면
                        continue;
                    int a = dist(x,temp);
                    int b = dist(y,temp);
                    dp[i][x][temp] = min(dp[i][x][temp], dp[i-1][x][y] + b); // y -> n
                    dp[i][temp][y] = min(dp[i][temp][y], dp[i-1][x][y] + a); // x -> n
                }
            }
        }
    }
    int ans = INF;
    for(int x = 0; x < 5; x++)
    {
        for(int y = 0; y < 5; y++)
        {
            ans = min(ans,dp[i-1][x][y]);
        }
    }
    cout << ans << '\n';
    return 0;
}