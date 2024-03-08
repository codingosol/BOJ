#include <iostream>

using namespace std;

int main(void)
{
    int n;
    cin >> n;
    // 가장 작은 분해합을 찾아야 함
    for(int i = 1; i <= n; i++)
    {
        int temp = i;
        int sum = temp;
        while(temp > 0)
        {
            sum += temp % 10;
            temp /= 10;
        }
        if(sum == n)
        {
            cout << i << '\n';
            break;
        }
        if(i == n)
        {
            cout << "0\n";
        }
    }
    return 0;
}