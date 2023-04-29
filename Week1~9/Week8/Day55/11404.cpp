#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;

#define INF 987654321
int node;
int bus;
int weight[101][101]; // i는 세로 j는 가로 저장된 값은 최소의 가중치
int map[101][101]; // 최단 거리를 저장할 배열

void solve(int mid) // 중간 노드를 통해 최단거리 배열을 수정함
{
    for(int i = 1; i <= node; i++) // 각 노드를 순회하면서 최솟값으로 바꿔줌
    {
        for(int j = 1; j <= node; j++)
        {
            map[i][j] = min(map[i][j], map[i][mid] + map[mid][j]);
        }
    }
}

int main(void)
{
    cin >> node;
    cin >> bus;
    int start, end, w;
    // 시작 전 weight 최댓값으로 초기화
    fill_n(weight[0], 101*101, INF);
    fill_n(map[0],101*101,INF);
    /*for(int i = 1; i <= node; i++)
    {
        for(int j = 1; j <= node; j++)
        {
            cout << weight[i][j] << ' ';
        }
        cout << '\n';
    }*/
    // 노선이 여러 개 있을 수 있으나 최단거리 구할거니까 최단거리로만 남겨줄 것
    for(int i = 0; i < bus; i++) // 버스가 단방향인가? -> yes
    {
        cin >> start >> end >> w;
        if(weight[start][end] > w) // 최소치라면
        {
            weight[start][end] = w;
        }
    } // input
    for(int i = 1; i <= node; i++)
    {
        for(int j = 1; j <= node; j++)
        {
            if(i == j) // 같은 도시로 가는 경우는 없으므로
            {
                map[i][j] = 0;
            }
            else {
                if(weight[i][j] != INF) // 가는 길이 있다면
                {
                    map[i][j] = weight[i][j];
                }
            }
        }
    } // 최단거리 초기화
    for(int i = 1; i <= node; i++)
    {
        solve(i);
    } // 돌면서 최단거리 수정
    for(int i = 1; i <= node; i++)
    {
        for(int j = 1; j <= node; j++)
        {
            if(map[i][j] != INF)
                cout << map[i][j] << ' ';
            else
                cout << "0 ";
        }
        cout << '\n';
    }
    // output;
    return 0;
}