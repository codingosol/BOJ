#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

vector<pair<int,int>> tree[10001];
int n; // 트리의 노드 개수
int check[10001];
int max_val = 0;
int max_node;

pair<int,int> solve(int node, int weight) // node는 현재 노드, weight는 누적 가중치임
{
    // dfs방식이므로 재귀로
    for(int i = 0; i < tree[node].size(); i++) // 연결된 노드의 개수만큼
    {
        if(check[tree[node][i].first] != 1) // 미방문일 시
        {
            check[tree[node][i].first] = 1; // 방문 표시
            solve(tree[node][i].first, weight + tree[node][i].second); // 가중치 추가
            if(weight + tree[node][i].second > max_val) // 가장 먼 노드라면
            {
                max_val = weight + tree[node][i].second;
                max_node = tree[node][i].first;
            }
        }
    }
    return {max_node,max_val};
}


int main(void)
{
    // 트리를 잡아당겼을 때 최대 지름이 되도록 구해야 함
    // 먼저 시작 정점인 1에서 가장 먼 노드를 탐색한 후 그 노드에서 가장 먼 노드를 고르면 됨
    cin >> n;
    int parent, child, w; // 각각 부모 노드/자식 노드/가중치
    for(int i = 0; i < n - 1; i++)
    {
        cin >> parent >> child >> w;
        tree[parent].push_back({child,w}); 
        // 부모로도 갈 수 있으므로 쌍방향으로 해야 함
        tree[child].push_back({parent,w});
    } // input;
    check[1] = 1;
    pair<int,int> end = solve(1,0); // 이 함수는 1에서 시작하여 가장 먼 정점을 찾음
    max_val = 0, max_node = -1;
    fill_n(check, 10001, 0);
    check[end.first] = 1;
    pair<int,int> ans = solve(end.first,0); // 이 함수는 가장 먼 정점에서 시작하여 반대쪽 정점을 찾음
    cout << ans.second << '\n';
}