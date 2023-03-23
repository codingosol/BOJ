#include <iostream>
#include <queue>
using namespace std;

int connection[101][101];
int check[101];

int main(void)
{
    int node , edge; // 사람 수 , 관계 수
    cin >> node >> edge;
    // bfs로 풀어야 할듯
    int min = 987654321;
    int index = 987654321;
    int x, y;
    for(int i = 0; i < edge; i++)
    {
        cin >> x >> y;
        connection[x][y] = 1;
        connection[y][x] = 1; // 쌍방향 연결임
    }
    for(int i = 1; i <= node; i++)
    {
        fill_n(check,sizeof(check),0);
        queue<pair<int,int>> q;
        // 초기화
        // i에서 스타트해서 찾음
        q.push({i,0});
        check[i] = 1;
        int depth = 0;
        while(!q.empty())
        {
            pair<int,int> cur = q.front();
            q.pop();
            depth = depth + cur.second;
            for(int j = 1; j <= node; j++) // node 안의 수를 찾음
            {
                if(check[j] != 1) // 아직 가보지 않았다면
                {
                    if(connection[cur.first][j] == 1 || connection[j][cur.first] == 1) // 연결되어 있다면
                    {
                        q.push({j,cur.second + 1}); // 큐에 추가하고 
                        check[j] = 1; // 방문 표시
                    }
                }
            }
        };
        if(depth <= min) // 최소 베이컨 수라면
        {
            if(depth < min) // 더 적은 경우 
            {
                min = depth;
                index = i;
            }
            else // 같은 경우
            {
                if(i < index)
                    index = i;
            }
        }
    }
    cout << index << "\n";
    return 0;
}