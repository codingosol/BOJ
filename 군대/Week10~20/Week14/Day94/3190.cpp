#include <iostream>
#include <queue>
#include <deque>

using namespace std;

int n;
int board[101][101];
queue<pair<int,char>> v;
int dy[4] = {0,1,0,-1};
int dx[4] = {1,0,-1,0};
// 오른쪽 0 아래 1 왼쪽 2 위 3

void solve()
{
    int time = 0; // 걸리는 시간
    // 뱀은 처음 시작할 때 맨 위 맨 왼쪽 1,1에서 시작함
    board[1][1] = 1;
    // 최초 방향은 오른쪽을 향하고 있음
    int direction = 0;
    // 오른
    // 뱀이 계속 앞부분을 따라가야 하므로 뱀은 앞 노드와 어떤 식으로 연결되어 있어야 할 필요가 있음
    deque<pair<int,int>> snake;
    snake.push_front({1,1});
    while(true)
    {
        //cout << time << '\n';
        time++; // 시간 증가
        // 1. 먼저 머리를 한 칸 늘림
        // 2. 벽이나 자기 자신과 부딪히면 게임 끝
        // 3. 이동한 칸에 사과가 있다면 꼬리 감소 X
        // 4. 아니라면 꼬리 감소
        pair<int,int> head = snake.front(); // 맨 앞 머리 부분 
        pair<int,int> tail = snake.back(); // 맨 뒤 꼬리 부분
        pair<int,int> nh; // 머리의 다음 위치
        //cout << "head pos : " << "[" << head.first << "][" << head.second << "]\n";
        nh.first = head.first + dy[direction];
        nh.second = head.second + dx[direction];
        //cout << "nh pos : " << "[" << nh.first << "][" << nh.second << "]\n"; 
        if(nh.first <= 0 || nh.first > n || nh.second <= 0 || nh.second > n) // 벽에 부딪히는 경우
        {
            cout << time << '\n';
            break;
        }
        if(board[nh.first][nh.second] == 1) // 몸에 박았을 경우
        {
            cout << time << '\n';
            break;
        }
        if(board[nh.first][nh.second] != 2) // 사과를 먹었다면 꼬리부분 감소 X
        {
            // 못먹었으므로
            board[tail.first][tail.second] = 0; // 꼬리 비움
            snake.pop_back(); // 꼬리부분 감소
        }
        snake.push_front(nh); // 새로운 머리 
        board[nh.first][nh.second] = 1; // 머리 채움
        // X초가 끝난 후에 방향 전환을 하는지 파악함
        // 아니라면 현재 방향 그대로
        if(time == v.front().first) // 방향 전환을 하는 시간이라면
        {
            // 방향 전환
            if(v.front().second == 'L') // 왼쪽으로 턴
            {
                direction = direction - 1;
                if(direction < 0)
                    direction = 3;
            }
            else if(v.front().second == 'D') // 오른쪽으로 턴
            {
                direction = (direction+1) % 4;
            }
            v.pop();
        }
    }
}

int main(void)
{
    cin >> n;
    int apple; // 사과의 수
    cin >> apple;
    int x, y;
    // 사과는 2 뱀의 몸은 1
    for(int i = 0; i < apple; i++)
    {
        cin >> x >> y;
        board[x][y] = 2; // 사과 있음을 나타냄
    }
    //cout << "apple\n";
    int dir; // 뱀의 방향 전환 횟수
    cin >> dir;
    //cout << dir << '\n';
    int t;
    char ch;
    for(int i = 0; i < dir; i++)
    {
        //cout << i << '\n';
        cin >> t >> ch;
        v.push({t,ch});
    }
    //cout << "dir\n";
    solve();
    return 0;
}