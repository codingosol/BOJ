#include <iostream>
#include <queue>

using namespace std;

int node, edge;

int link[801][801];
int check[801];

int solve(int v1, int v2) // 1에서 node로 이동하며 v1, v2를 포함하는 최단 경로
{
    int min_val = 987654321; // 최솟값
    // bfs로 풀면 안됨
    // dfs로 가야함
    // 1에서 출발에서 n으로 가야 함
    dfs(1,n)
}

int main(void)
{
    cin >> node >> edge;
    for(int i = 0; i < edge; i++)
    {
        int s, e, w;
        cin >> s >> e >> w;
        link[s][e] = w;
        link[e][s] = w; 
    } // input;
    int v1, v2; // 반드시 방문해야 하는 두 개의 정점
    int ans = solve(v1,v2);
}