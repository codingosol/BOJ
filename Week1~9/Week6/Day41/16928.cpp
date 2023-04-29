#include <algorithm>
#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

int board[101]; // 이어져 있는 칸을 표기하기 위해
int check[101]; // 이 칸에 몇번만에 도착했는지 표기할 배열

void bfs(int start)
{
    queue<int> q;
    q.push(1);
    check[1] = 0; // 시작이므로 0
    while(!q.empty()) // 갈 수 있을 때까지
    {
        int cur = q.front();
        q.pop();
        for(int i = 1; i <= 6; i++) // 주사위 1~6
        {
            if(cur + i > 100)
                break; 
            // 현재 칸에서 뱀이나 사다리가 있다면 쭉 타고 올라감
            if(board[cur + i])
            {
                if(check[board[cur + i]] > check[cur] + 1) // 더 작아질 수 있다면
                {
                    q.push(board[cur + i]);
                    check[board[cur + i]] = check[cur] + 1;
                }
            }
            else { // 뱀이나 사다리가 없다면
                if(check[cur + i] > check[cur] + 1)
                {
                    q.push(cur + i);
                    check[cur + i] = check[cur] + 1;
                }
            }
        }
    }
    return;
}

int main(void)
{
    int n, m; // 각각 사다리와 뱀의 수
    cin >> n >> m;
    for(int i = 0; i < n + m; i++)
    {
        int head, tail;
        cin >> head >> tail;
        board[head] = tail;
    } // 사다리와 뱀을 입력해줌
    fill_n(check, 101, 9999);
    bfs(1);
    cout << check[100] << '\n';
    return 0;
}