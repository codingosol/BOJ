#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

int n;
vector<pair<double,double>> star;
double dist[101]; // 각 별의 누적거리 저장할 배열
double INF = 987654321; // 무한대값
int finish[101]; // 이 별의 탐색이 끝났는지 판단

double calcdist(int a, int b)
{
    pair<double,double> p1 = star[a];
    pair<double,double> p2 = star[b];
    // 두 점 사이의 거리는 각 좌표의 값을 뺀것의 제곱의 합의 제곱근
    double ans;
    ans = sqrt(pow(p1.first - p2.first,2) + pow(p1.second - p2.second,2));
    return ans;
}

int main(void)
{
    cin >> n;
    double x, y;
    fixed(cout);
    cout.precision(2);
    for(int i = 0; i < n; i++)
    {
        cin >> x >> y;
        star.push_back({x,y});
    }
    // 0 ~ n-1번 별까지 있음
    fill_n(dist,101,INF);
    // 2차원 평면 위에 놓여 있으며 모든 별이 이어져야 함
    // -> 최소 스패닝 트리
    // 어느 한 별에서 시작해서 크루스칼 알고리즘 쓰면 됨
    // n개의 별을 잇는 데는 n-1개의 간선만 있으면 됨
    dist[0] = 0; // 첫번째 별 누적거리 0으로 만듬
    priority_queue<pair<double,int>,vector<pair<double,int>>,greater<pair<double,int>>> pq; // first는 거리를 저장하고, second는 다음 별의 번호를 저장함
    pq.push({0,0});
    while(!pq.empty())
    {
        double curdist = pq.top().first; // 현재 별까지의 거리
        int curp = pq.top().second; // 현재 별의 번호
        pq.pop();
        if(finish[curp] == 1) // 이미 이 별에서 탐색을 시도했다면
            continue;
        finish[curp] = 1; // 이 별의 탐색이 끝났음을 표시
        //cout << curdist << '\n';
        // cout << curp << '\n';
        // 1. 현재 별과 다른 별들까지의 거리를 갱신
        for(int i = 0; i < n; i++)
        {
            if(curp == i) // 현재 별과 같은 번호면 무시
                continue;
            double temp = calcdist(curp,i); // 두 별 간의 거리 구함
            //cout << temp << ' ';
            if(dist[i] > temp && finish[i] != 1) 
            {
                dist[i] = temp; // 거리값 갱신되었으면(여기서 이미 탐색한 놈을 갱신해버림)
                pq.push({temp,i}); // 우선순위 큐에 추가
            }
        }
        //cout << '\n';
    }
    // 이제 모든 별의 거리 값을 합해서 출력
    double ans = 0;
    for(int i = 0; i < n; i++)
    {
        ans += dist[i];
        //cout << dist[i] << '\n';
    }
    cout << ans << '\n';
    return 0;
}