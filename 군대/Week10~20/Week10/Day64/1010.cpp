#include <iostream>

using namespace std;

int dp[31][31];

int solve(int east, int west)
{
    // nCm = n-1Cm + n-1Cm-1 임을 이용함
    if(west == east || west == 0)
    {
        return 1;
    }
    if(dp[east][west]) // 이미 구한 값이라면
    {
        return dp[east][west];
    }
    else { // 없는 값이라면
        dp[east][west] = solve(east-1,west) + solve(east-1,west-1); // 새로 값 투입
        return dp[east][west];
    }
}

int main(void)
{
    int testcase;
    cin >> testcase;
    while(testcase--)
    {
        int west, east; // 각각 서쪽과 동쪽의 사이트 수
        cin >> west >> east;
        // west C east의 조합 개수를 찾으면 됨 -> 반대임  east C west임
        int ans = solve(east,west);
        cout << ans << '\n';
    }
    return 0;
}