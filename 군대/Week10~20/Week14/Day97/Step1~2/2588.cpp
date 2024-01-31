#include <iostream>

using namespace std;

int main(void)
{
    int n, m;
    cin >> n >> m;
    int sum = 0;
    int val = 1;
    for(int i = 0; i < 3; i++)
    {
        int digit = m % 10;
        int temp = n * digit;
        cout << temp << '\n';
        sum += temp * val;
        val *= 10;
        m /= 10;
    }
    cout << sum << '\n';
    return 0;
}