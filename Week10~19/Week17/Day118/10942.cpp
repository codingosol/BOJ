#include <iostream>

using namespace std;

int n; // 수열의 길이
int m; // 계산 횟수
int arr[2001]; // 저장
int dp[2001]; // dp배열

bool palindrom(int start, int end)
{
    bool flag = true; // 팰린드롬인지 여부 판단
    if(arr[start] == arr[end])
    {
        if(start+1 <= end-1)
            flag = palindrom(start+1, end-1);
    }
    else
        flag = false;
    return flag;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    cin >> m;
    // 어떻게 dp배열로 팰린드롬인지 판단하지?
    // 각 자릿수는 1~9의 9가지 경우의 수가 있음
    // 이중배열로 선언하면 됨
    // 근데 그렇게 해도 누적 수만 알수있고 순서는 알 수 없음
    // 순서를 알 수 있는 방법이 있나?
    // a~b까지 팰린드롬이려면 arr[a] == arr[b] 이면서 그 내부가 팰린드롬이면 됨
    // -> 재귀로 탐색? -> 시간초과 dp를 써야함
    int s, e;
    for(int i = 0; i < m; i++)
    {
        cin >> s >> e;
        if(palindrom(s, e))
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}