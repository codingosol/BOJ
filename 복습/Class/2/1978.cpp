#include <iostream>

using namespace std;

int isprime[1001] = {0,};

int main(void)
{
    isprime[1] = 1; // 1은 소수가 아님
    for(int i = 2; i <= 1000; i++) // 2부터 체크
    {
        if(isprime[i] == 0) // 소수일 경우
        {
            for(int j = i*2; j <= 1000; j += i) // 배수를 전부 소수가 아니게 체크
            {
                //cout << j << ' ';
                isprime[j] = 1;
            }
            //cout << '\n';
        }
    }
    int n;
    cin >> n;
    int cnt = 0;
    for(int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        if(isprime[temp] == 0)
        {
            cnt++;
        }
    }
    cout << cnt << '\n';
    return 0;
}