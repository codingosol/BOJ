#include <iostream>

using namespace std;

int arr[1000001];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    arr[1] = 1; // 1은 소수가 아님
    for(int i = 2; i <= 1000000; i++)
    {
        if(arr[i] == 0) // 어떤 수 i가 소수라면
        {
            for(int j = i*2; j <= 1000000; j += i)
            {
                arr[j] = 1;
            }
        }
    }
    while(true)
    {
        int n;
        cin >> n;
        bool flag = false;
        // n에 대하여 a+b 형태로 출력, 단, b-a의 값이 가장 큰 것으로 출력
        // 만약 증명할 수 없을 경우 Goldbach's conjecture is wrong. 출력
        if(n == 0)
            break;
        // 에라토스테네스의 체로 1000000 이하의 모든 소수를 찾은 후 
        // 가장 작은 소수 선택 후 n-a가 소수인지 판정 -> n/2까지 반복
        for(int i = 2; i <= n/2; i++)
        {
            if(arr[i] == 0) // 이 수가 소수라면
            {
                int a = i;
                if(arr[n-a] == 0) // 합을 구성하는 수도 소수라면
                {
                    cout << n << " = " << a << " + " << n-a << '\n';
                    flag = true;
                    break;
                }

            }
        }
        if(flag == false)
        {
            cout << "Goldbach's conjecture is wrong.\n";
        }
    }
}