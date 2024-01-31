#include <iostream>
#include <cmath>

using namespace std;

int arr[100001];
int dp[100001];
int main(void)
{
    int n; // 정수의 개수
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    } // input
    // 총합이 음수가 되기 전에는 계속해서 갱신하다가 총합이 음수가 되면 끊고 0부터 다시 출발하는 방법
    // 기존 총합이 음수가 되지 않는 이상 더 커질 가능성이 있음
    int max_val = arr[1];
    dp[1] = arr[1];
    int temp;
    // 현재 생기는 문제는 첫 원소가 음수이고 계속 음수만 나올 경우 total이 0으로 초기화되기 때문에 max_val이 0이 되는 것
    for(int i = 2; i <= n; i++)
    {
        dp[i] = max(dp[i-1] + arr[i], arr[i]);
        if(dp[i] > max_val)
            max_val = dp[i];
    }
    cout << max_val << '\n';
    return 0;
}