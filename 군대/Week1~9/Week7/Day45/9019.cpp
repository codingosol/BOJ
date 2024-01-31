#include <iostream>
#include <queue>
#include <cstring>

using namespace std;


/*
D: D 는 n을 두 배로 바꾼다. 결과 값이 9999 보다 큰 경우에는 10000 으로 나눈 나머지를 취한다. 그 결과 값(2n mod 10000)을 레지스터에 저장한다.
S: S 는 n에서 1 을 뺀 결과 n-1을 레지스터에 저장한다. n이 0 이라면 9999 가 대신 레지스터에 저장된다.
L: L 은 n의 각 자릿수를 왼편으로 회전시켜 그 결과를 레지스터에 저장한다. 이 연산이 끝나면 레지스터에 저장된 네 자릿수는 왼편부터 d2, d3, d4, d1이 된다.
R: R 은 n의 각 자릿수를 오른편으로 회전시켜 그 결과를 레지스터에 저장한다. 이 연산이 끝나면 레지스터에 저장된 네 자릿수는 왼편부터 d4, d1, d2, d3이 된다.
*/ // 가능한 명령어 나열이 여러가지면, 아무거나 출력한다.
int check[10000]; // 방문 여부를 표시

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int testcase;
    cin >> testcase;
    for(int i = 0; i < testcase; i++)
    {
        memset(check,0,sizeof(check));
        int a, b; // a에서 b가 되는 최단경로를 bfs해야함
        cin >> a >> b;
        queue<pair<int,string>> q; // first에는 현재 수, string에는 현재 명령어 나열을 저장할 것
        string ans; // 답안을 저장할 ans
        int len = 987654321;
        q.push({a,""});
        check[a] = 1; // 방문 표시
        while(!q.empty()) // 기본적으로 bfs이므로 먼저 도착한 값을 수정할 필요는 없을듯
        {
            pair<int,string> p = q.front();
            q.pop();
            if(p.first == b) // 찾고자 하는 값에 도달했다면
            {
                if(p.second.length() < len) // 최소한의 명령어 나열이라면
                {
                    len = p.second.length();
                    ans = p.second;
                }
            }
            else {
                int temp;
                // D 연산 시작
                temp = p.first; // temp 초기화
                temp = (temp * 2) % 10000; // 2배 후 나머지 취함
                if(check[temp] != 1) // 방문한 적 없다면
                {
                    q.push({temp,p.second + 'D'});
                    check[temp] = 1; // 방문 표시
                }
                // D연산 종료
                // S 연산 시작
                temp = p.first;
                temp--; // -1 취함
                if(temp < 0)
                {
                    temp = 9999;
                }
                if(check[temp] != 1)
                {
                    q.push({temp,p.second + 'S'});
                    check[temp] = 1;
                }
                // S 연산 종료
                // L 연산과 R 연산은 4회 이상 하는것이 의미가 없음(다시 원래 문자열로 돌아와버리기 때문)
                // 왼쪽이든 오른쪽이든 3회 하면 구별하는 의미가 없으므로 L,R 연산은 하나라고 볼 수 있음
                // 최단거리를 위해서는 우측 1회, 좌측 1회, 우측 2회 또는 좌측 2회 이렇게 3번만 할 수 있음 (좌측 3회는 우측 1회와 같기 때문)
                temp = p.first;
                int left_flip1 = (temp * 10 + temp / 1000) % 10000; // 좌로 1회전
                if(check[left_flip1] != 1)
                {
                    q.push({left_flip1,p.second + 'L'});
                    check[left_flip1] = 1;
                }
                int right_flip1 = (temp / 10 + (temp % 10) * 1000); // 우로 1회전
                if(check[right_flip1] != 1)
                {
                    q.push({right_flip1, p.second + 'R'});
                    check[right_flip1] = 1;
                }
            }
        } // 기본적으로 10000회 탐색을 하게 됨
        cout << ans << '\n';
    }
    return 0;
}