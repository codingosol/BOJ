#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int n;
stack<int> s;
int arr[1000001];
int ans[1000001];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    // 오큰수는 Ai보다 오른쪽에 있으면서 큰 수중에 가장 왼쪽에 있는 수임
    // 선형 검색으로 찾으면 굉장히 긴 시간이 걸리겠지?
    for(int i = n-1; i >= 0; i--)
    {
        // 스택에 자신보다 작은 수가 있다면 그 수는 정답이 될 가능성이 없음
        while(!s.empty() && s.top() <= arr[i]) // 자기보다 작거나 같은 수를 전부 없앰
        {
            s.pop();
        } // 자기보다 큰 수를 스택에서 찾는다면 나감
        if(s.empty()) // 자기보다 큰 수가 없다면 -1
            ans[i] = -1;
        else // 찾은 답 설정
            ans[i] = s.top();
		s.push(arr[i]); // 자신도 스택에 추가
    }
    for(int i = 0; i < n; i++)
    {
        cout << ans[i] << ' ';
    }
    cout << '\n';
    return 0;
}