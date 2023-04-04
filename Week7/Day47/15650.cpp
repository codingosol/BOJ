#include <iostream>
#include <cstring>

using namespace std;

int check[9]; // 각 원소가 방문되었는지 확인하기 위함
int n, m;

void solve(int node, int depth, string str)
{
    str += char(node + '0'); // 현재 노드 추가
    str += ' '; // 띄어쓰기 추가
    depth--; // 깊이 줄이기
    if(depth == 0) // 더 탐색할 수 없다면
    {
        cout << str << '\n';
    }
    else { // 더 탐색할 수 있다면
        for(int i = 1; i <= n; i++)
        {
            if(check[i] != 1 && node < i) // 방문하지 않았고 오름차순이라면
            {
                check[i] = 1;
                solve(i,depth,str);
                check[i] = 0;
            }
        }
    }
    return;
}

int main(void)
{
    cin >> n >> m;
    // n은 수의 개수 m은 연속되는 수열의 수 
    // m의 depth를 가지는 수열을 찾아야 함
    memset(check,0,sizeof(check));
    for(int i = 1; i <= n; i++)
    {
        string ans;
        check[i] = 1;
        solve(i, m, ans);
        check[i] = 0;
    }
    return 0;
}