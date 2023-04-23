#include <iostream>
#include <vector>
using namespace std;

int n; // 노드의 개수
// 정점의 개수가 100000까지 될 수 있으므로 2차원 배열로는 불가능
// 2차원 벡터로 해보자
int maxnode = 0;
int maxdist = 0;

vector<pair<int,int>> v[100001];
int check[100001]; // 방문 여부 표기

void solve(int i, int dist) // i로부터 가장 먼 노드의 번호를 리턴함
{
    if(check[i] == 1) // 방문한 적이 있다면
        return;
    else // 방문한 적 없다면
    {
        if(maxdist < dist)
        {
            maxdist = dist;
            maxnode = i;
        }
        check[i] = 1; // 방문 표시
        // 다음 방문 노드 찾음
        for(int j = 0; j < v[i].size(); j++)
        {
            solve(v[i][j].first, dist + v[i][j].second);
        }
    }
    
}

int main(void)
{
    cin >> n;
    int node; // 정점 번호를 받음
    int link; // 연결된 노드의 번호를 받음
    int len; // 정점 간의 거리를 받음
    for(int i = 0; i < n; i++)
    {
        // 처음은 정점 번호를 받음
        cin >> node;
        while(true)
        {
            cin >> link;
            if(link == -1)
                break;
            // -1을 받으면 탈출
            // 아니면 계속 진행
            cin >> len;
            v[node].push_back({link,len});
            v[link].push_back({node,len});
        }
    } // input
    // 이제 트리의 지름을 찾아야 -> 임의의 두 노드 중 가장 먼 것
    // 1->5와 5->1이 같으므로 중복해서 계산할 필요는 없음
    // 간선이 쌍방향인가 단방향인가?
    // 쌍방향인듯
    // 먼저 1에서 가장 먼 노드를 찾고 거기서 다시 가장 먼 노드를 찾음
    solve(1,0); // 가장 먼 노드 찾기
    // 이제 방문 초기화
    fill_n(check,100001,0);
    maxdist = 0;
    solve(maxnode,0); // 가장 먼 노드에서 다시 가장 먼 노드를 찾음
    cout << maxdist << '\n';
    return 0;
}