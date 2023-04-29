#include <iostream>

using namespace std;
typedef long long int_64;
int main(void)
{
    int_64 n;
    cin >> n;
    int_64 cnt = 0;
    int_64 total = 0;
    int_64 temp = 1;
    while(total <= n)
    {
        cnt++;
        total += temp;
        temp++;
    }
    cout << cnt - 1 << '\n';
    return 0;
}