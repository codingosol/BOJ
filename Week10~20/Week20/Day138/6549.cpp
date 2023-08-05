#include <iostream>
#include <stack>

using namespace std;

typedef long long int_64;

int_64 arr[100001];

int main(void)
{
    // 스택풀이를 보고 풀었다
    while(true)
    {
        int n;
        cin >> n;
        if(n == 0)
            break;
        fill_n(arr,100001,0);
        stack<int_64> stk;
        for(int i = 1; i <= n; i++)
        {
            cin >> arr[i];
        }
        int_64 ans = 0;
        stk.push(0); // 0번 기둥 push
        for(int i = 1; i <= n+1; i++)
        {
            while(!stk.empty() && arr[stk.top()] > arr[i]) // 스택이 비거나 기둥의 크기가 역전되기 전까지 계속 스택 쌓음
            {
                // 높이의 역전이 일어났다면
                int_64 check = stk.top(); // 인덱스 기록
                stk.pop(); // 스택 pop
                // 높이가 arr[check]라면 밑변은 arr[i] 보다 큰 기둥의 위치 ~ i-1(현재 i의 위치보다 한칸 뒤이므로) 이므로 이렇게 된다
                ans = max(ans,arr[check] * (i - 1 - stk.top()));
            }
            stk.push(i);
        }
        cout << ans << '\n';
    }
}