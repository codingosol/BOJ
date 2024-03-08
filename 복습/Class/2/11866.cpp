#include <iostream>
#include <queue>

using namespace std;

int main(void)
{
    int n, k;
    cin >> n >> k;
    // 요세푸스 순열 구하기
    queue<int> q;
    for(int i = 1; i <= n; i++)
    {
        q.push(i);
    }
    int cnt = 0;
    int temp;
    cout << "<";
    while(!q.empty())
    {
        // 큐의 앞부분에서 빼고 뒤로 넘겨주기 반복
        // n번째 사람을 빼므로 n-1번 넘기고 n번째 사람 출력 후 제거
        while(cnt < k - 1)
        {
            temp = q.front();
            q.push(temp);
            q.pop();
            cnt++;
        }
        if(q.size() != 1)
        {
            cout << q.front() << ", ";
            q.pop();
            cnt = 0;
        }
        else {
            cout << q.front() << ">";
            q.pop();
            cnt = 0;
        }
    }
    cout << '\n';
    return 0;
}