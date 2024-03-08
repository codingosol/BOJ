#include <iostream>
#include <queue>

using namespace std;

int main(void)
{
    int n;
    cin >> n;
    queue<int> q;
    for(int i = 1; i <= n; i++)
    {
        q.push(i);
    }
    while(!q.empty())
    {
        // 먼저 맨 위에 있는 카드 버리고 그 아래는 맨 밑으로 옮김
        if(q.size() != 1)
        {
            q.pop();
            int temp = q.front();
            q.push(temp);
            q.pop();
        }
        else {
            cout << q.front() << '\n';
            break;
        }
    }
    return 0;

}