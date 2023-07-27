#include <iostream>
#include <cmath>

using namespace std;

typedef long long int_64;

int_64 n, k;

int_64 lessnum(int_64 mid) // mid보다 작은 수의 개수를 세줌
{
    int_64 cnt = 0;
    for(int i = 1; i <= n; i++)
    {
        cnt += min(n, (mid/i));
        if(i > mid) break;
    }
    return cnt;
}

void solve(int_64 n)
{
    int_64 low = 1;
    int_64 high = n*n;
    int res = 0;

    while(low <= high)
    {
        int_64 mid = (low+high) / 2;
        if(lessnum(mid) < k)
        {
            low = mid + 1;
        }
        else {
            res = mid;
            high = mid - 1;
        }
    }
    cout << res << '\n';
}

int main(void)
{
    /*  세준이는 크기가 N×N인 배열 A를 만들었다. 배열에 들어있는 수 A[i][j] = i×j 이다. 
        이 수를 일차원 배열 B에 넣으면 B의 크기는 N×N이 된다. B를 오름차순 정렬했을 때, B[k]를 구해보자.
    */
    cin >> n >> k;
    // 3 7 -> 1 2 3 2 4 6 3 6 9 순
    // 근데 이 수를 전부 입력받은 뒤 정렬하면 무조건 시간초과겠지? 
    // N = 10^5 이므로 총 수는 10^10개이며 이걸 정렬한다면 ㅈㄴ김
    // 이 수열을 보자
    /*  1   2   3   4   5   6           
        2   4   6   8   10  12
        3   6   9   12  15  18
        4   8   12  16  20  24
        5   10  15  20  25  30
        6   12  18  24  30  36
    */
    // 이걸 어떻게 이분탐색으로 풀어?
    solve(n);
    return 0;
}