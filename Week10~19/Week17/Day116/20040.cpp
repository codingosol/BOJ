#include <iostream>
#include <vector>

using namespace std;

int n, m; // n은 점 수 m은 간선 수
vector<pair<int,int>> v;
int parent[500001];

int getparent(int n)
{
    if(parent[n] == n)
        return n;
    else
        return getparent(parent[n]);
}

void unionparent(int a, int b) // a와 b의 부모를 같게 설정
{
    a = getparent(a);
    b = getparent(b);
    if(a > b)
        parent[a] = b;
    else
        parent[b] = a;
}

bool cycle(int a, int b) // a와 b를 연결했을 때 사이클이 생기는지 점검
{
    if(getparent(a) == getparent(b)) // a와 b의 부모가 같다면 연결 시 사이클이 생김
    {
        return true;
    }
    else {
        return false;
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    int a, b;
    for(int i = 1; i <= n; i++)
    {
        parent[i] = i;
    }
    for(int i = 0; i < m; i++)
    {
        cin >> a >> b;
        v.push_back({a,b});
    }
    int cnt = 0;
    bool flag = false;
    for(int i = 0; i < v.size(); i++)
    {
        cnt++;
        if(!cycle(v[i].first,v[i].second))
        {
            unionparent(v[i].first, v[i].second);
        }
        else {
            flag = true;
            break;
        }
    }
    if(flag)
        cout << cnt << '\n';
    else
        cout << "0\n";
    return 0;
}