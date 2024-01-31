#include <iostream>
#include <deque>

using namespace std;

typedef long long int_64;

int_64 qstack[100001]; // 각 자료구조가 큐인지 스택인지 여부 저장

int main(void)
{
    // 문제가 이해하기 좀 힘드네
    // 이문제 시간제한은 빡센데 메모리제한은 널널함
    // 시간복잡도가 민감
    // 직접 바꾸는 선택을 하면 시간초과
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int_64 n;
    cin >> n;
    for(int_64 i = 1; i <= n; i++) // 큐인지 스택인지 여부 저장
    {
        cin >> qstack[i];
    }
    deque<int_64> stk; // 스택 저장
    deque<int_64> q; // 큐 저장
    int_64 temp;
    for(int_64 i = 1; i <= n; i++) // 초기상태 입력
    {
        cin >> temp;
        if(qstack[i] == 0) // 큐
        {
            q.push_back(temp);
        }
        else { // 스택
            stk.push_back(temp);
        }
    }
    int_64 m;
    cin >> m;
    // 보면 스택인 부분은 전혀 바뀌지 않음
    // 대신 큐인 부분이 한칸씩 밀려남 -> 우리는 출력값만 보면 되므로 큐만 뒷값 뿜으면 됨
    for(int_64 i = 0; i < m; i++)
    {
        cin >> temp;
        if(!q.empty())
        {
            cout << q.back() << ' ';
            q.pop_back();
            q.push_front(temp);
        }
        else {
            cout << temp << ' ';
        }
    }
    cout << '\n';
    return 0;
}