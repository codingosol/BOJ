#include <iostream>
#include <stack>

using namespace std;
typedef long long int_64;

int n;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    stack<pair<int_64,int_64>> stk;
    // 시간을 줄일 수 있는 법을 생각해보자
    // 스택으로? -> 자기보다 작은 탑들은 pop해버리고 큰 탑을 만나면 그 값 리턴 후 자기 push하는걸로?
    int_64 temp;
    for(int i = 0; i < n; i++)
    {
        cin >> temp; // 높이 저장
        while(!stk.empty())
        {
            // 자기보다 작은 값 전부 pop
            if(temp < stk.top().second) // 자기보다 높은 탑 발견하면 그거 first 출력
            {
                cout << stk.top().first << " ";
                break;
            }
            stk.pop();
        }
        if(stk.empty())
        {
            cout << "0 ";
        }
        // 현재 높이 stk에 넣기
        stk.push({i+1,temp});
    }
    cout << '\n';
    return 0;
}