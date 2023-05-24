#include <iostream>
#include <vector>

using namespace std;

int n, m; // n은 노드의 수, m은 연산의 횟수
int parent[1000001];

int find_parent(int n)
{
    if(parent[n] == n)
        return n;
    else
        return parent[n] = find_parent(parent[n]);
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    int oper, a, b;
    for(int i = 1; i <= n; i++)
    {
        parent[i] = i; // 자기 자신을 집합으로 가짐
    }
    while(m--)
    {
        cin >> oper;
        if(oper == 0) // 합치는 연산
        {
            // 둘 중에 더 낮은 수로 합치기로 설정
            cin >> a >> b;
            // a가 작은 수, b가 큰 수로 유지
            // 이러면 b의 하위 집합이 a와 합쳐지지 못하는 문제점 발생
            // 가장 위의 집합원소는 자기 자신을 원소로 가질테니 그때까지 부모 찾음
            int pa = find_parent(a); // a의 부모 찾음
            int pb = find_parent(b); // b의 부모 찾음
            if(pa > pb)
                swap(pa,pb);
            parent[pb] = pa;
        }
        else if(oper == 1)
        {
            cin >> a >> b;
            // 두 수가 같은 집합에 있는지 확인
            if(find_parent(a) == find_parent(b))
            {
                cout << "YES\n";
            }
            else {
                cout << "NO\n";
            }
        }
    }
    return 0;
}