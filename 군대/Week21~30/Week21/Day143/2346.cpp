#include <iostream>
#include <deque>

using namespace std;

// 메모리제한이 4MB
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    deque<pair<int,int>> dq;
    int temp;
    for(int i = 1; i <= n; i++)
    {
        cin >> temp;
        dq.push_back({i,temp});
    }
    // 처음에는 1번 풍선을 터트림
    int move; // 움직일 횟수 저장
    for(int i = 0; i < n; i++)
    {
        cout << dq.front().first << ' '; // 현재 풍선의 번호 출력
        move = dq.front().second;
        // cout << move << ' ';
        dq.pop_front();
        if(move > 0) // 맨 앞의 원소를 뒤로 옮겨야 함
        {
            move--;
            while(move > 0)
            {
                dq.push_back(dq.front());
                dq.pop_front();
                move--;
            }
        }
        else if(move < 0) // 맨 뒤의 원소를 앞으로 옮겨야 함
        {
            while(move < 0)
            {
                dq.push_front(dq.back());
                dq.pop_back();
                move++;
            }
        }
        //cout << dq.front().first << '\n'; // 현재 풍선의 번호 출력
    }
    cout << '\n';
    return 0;
}