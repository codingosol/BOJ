#include <iostream>
#include <vector>

using namespace std;

#define INF 987654321

int n, m;
int edge[101][101]; // i에서 j도시로 가는 값 저장

void solve()
{
    for(int m = 1; m <= n; m++) // 중간 노드
    {
        for(int s = 1; s <= n; s++) // 시작 노드
        {
            for(int e = 1; e <= n; e++) // 도착 노드
            {
                if(edge[s][e] > edge[s][m] + edge[m][e]) // 중간 노드를 거쳐가는게 더 작다면
                {
                    edge[s][e] = edge[s][m] + edge[m][e]; // 갱신
                }
            }
        }
    }
}

int main(void)
{
    /* n(2 ≤ n ≤ 100)개의 도시가 있다. 그리고 한 도시에서 출발하여 다른 도시에 도착하는 m(1 ≤ m ≤ 100,000)개의 버스가 있다. 각 버스는 한 번 사용할 때 필요한 비용이 있다.
    모든 도시의 쌍 (A, B)에 대해서 도시 A에서 B로 가는데 필요한 비용의 최솟값을 구하는 프로그램을 작성하시오. */
    // 자기 도시로 돌아오는 경우는 항상 0
    cin >> n >> m;
    int from, to, w;
    fill_n(edge[0],101*101,INF);
    for(int i = 0; i < m; i++)
    {
        cin >> from >> to >> w;
        edge[from][to] = min(edge[from][to], w); // 최솟값으로 갱신
    }
    solve();
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(i == j){
                edge[i][j] = 0;
            }
            if(edge[i][j] >= INF){ // 도달할 수 없다면
                cout << "0 ";
            }
            else{
                cout << edge[i][j] << ' ';
            }
        }
        cout << '\n';
    }
    return 0;
}