#include <algorithm>
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int edge[1001][1001]; // 노드의 비용 저장
int check[1001]; // 가는데 드는 총 비용 저장
int node; // 도시의 수

void solve(int start, int end)
{
    check[start] = 0; // 시작
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,start});
    while(!pq.empty())
    {
        pair<int,int> cur = pq.top();
        pq.pop();
        for(int i = 1; i <= node; i++){			
			int next = i;
			int exp = edge[cur.second][i];
			
			if(exp == 987654321) 
                continue;
			if(cur.first + exp < check[next]){
				check[i] = cur.first + exp;
				pq.push(make_pair(cur.first + exp ,i));
			}
		}
    }
    cout << check[end] << '\n';
}

int main(void)
{
    cin >> node;
    int bus;
    cin >> bus;
    int start, end;
    int exp;
    // 비용은 0~100000 십만을 넘는 값을 배열이 비었을 때로 설정
    // fill(&check[0], &check[1000], 987654321);
    // fill(&edge[0][0],&edge[1000][1000],987654321);
    for(int i = 1;i <= node ;i++)
		for(int j = 1;j <= node; j++)
			edge[i][j] = 987654321;
	
	for(int i = 1;i <= node; i++){
		edge[i][i] = 0;
		check[i] = 987654321;
	}
    for(int i = 0; i < bus; i++) // 버스 정보 입
    {
        cin >> start >> end >> exp; // 각각 출발, 도착, 비용
        if(edge[start][end] > exp)
        {
            edge[start][end] = exp;
        }
    }
    cin >> start >> end;
    solve(start,end);
}