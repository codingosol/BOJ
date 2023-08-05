#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<pair<int,int>> v; // 집, 편의점, 도착점 좌표 저장
vector<int> graph[103]; // 연결관계 저장
int visit[103];
int num;

int dist(pair<int,int> p1, pair<int,int> p2)
{
    int d1 = abs(p1.first - p2.first);
    int d2 = abs(p1.second - p2.second);
    return d1 + d2;
}

void dfs(int x){ 
	visit[x] = 1; 
	for(int i = 0; i < graph[x].size(); i++){
		int y = graph[x][i]; 
		if(!visit[y]){ 
			dfs(y); 
		}
	}
}

void reset(){
	v.clear();
	for(int i = 0; i < num + 2; i++){ 
		graph[i].clear(); 
	} 
	fill_n(visit,101,0);
}

int main(void)
{
    int testcase;
    cin >> testcase;
    int x, y;
    while(testcase--)
    {
        // n+2개 줄에는 상근이네 집, 편의점, 펜타포트 락 페스티벌 좌표가 주어진다. 각 좌표는 두 정수 x와 y로 이루어져 있다.
        // 두 좌표 사이의 거리는 x 좌표의 차이 + y 좌표의 차이
        // 50미터를 가기 전에 한 병을 마시고 출발해야 함
        cin >> num;
        for(int i = 0; i < num + 2; i++) // 편의점 좌표 저장
        {
            cin >> x >> y;
            v.push_back({x,y});
        }
        // v[0]은 집 좌표, v[num+1]은 도착지 좌표임
        for(int i = 0; i < num + 2; i++){ 
			for(int j = i + 1; j < num + 2; j++){ 
				// 거리가 1000이내인 지점들만 연결 
				if(dist(v[i], v[j]) <= 50 * 20){
					graph[i].push_back(j); 
					graph[j].push_back(i); 
				}
			}
		}
        // 연결한 그래프 bfs 후 가능한지 여부
        dfs(0);
        if(visit[num + 1] == 0)
            cout << "sad\n";
	    else
            cout << "happy\n";
		reset();
    }
}