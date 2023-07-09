#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef long long int_64;

int_64 prime[4000001];
vector<int_64> sum_p;

int main(void)
{
    int n;
    cin >> n;
    sum_p.push_back(0);
    for(int i = 2; i <= sqrt(4000000); i++) // 에라스토테네스의 체
    {
        if(prime[i] == 0)
        {
            for(int j = i*2; j <= 4000000; j += i)
            {
                prime[j] = 1; // 소수가 아님을 표시
            }
        }
    }
    int_64 sum = 0;
    for(int i = 2; i <= 4000000; i++)
    {
        if(prime[i] == 0) // 소수라면
        {
            sum += i; // 누적합
            sum_p.push_back(sum);
        }
    }
    /*
        하지만 연속된 소수의 합으로 나타낼 수 없는 자연수들도 있는데, 20이 그 예이다. 
        7+13을 계산하면 20이 되기는 하나 7과 13이 연속이 아니기에 적합한 표현이 아니다. 
        또한 한 소수는 반드시 한 번만 덧셈에 사용될 수 있기 때문에, 3+5+5+7과 같은 표현도 적합하지 않다.
    */
    // 따라서 dp[j] + dp[i - j]로 계산 할 수는 없다
    int left = 0;
    int right = 0;
    int ans = 0;
    while(left <= right && right < sum_p.size())
    {
        // 1. 현재 누적합이 n보다 작다면 우측 증가
        if(sum_p[right] - sum_p[left] < n)
        {
            right++;
        }
        // 2. 현재 누적합이 n보다 크다면 좌측 증가
        else if(sum_p[right] - sum_p[left] > n)
        {
            left++;
        }
        // 3. 같다면 ans++;
        else {
            ans++;
            right++;
        }
    }
    cout << ans << '\n';
    return 0;
}