#include <iostream>

using namespace std;

int main(void)
{
    int n;
    cin >> n;
    int ans = 1;
    for(int i = 1; i <= n; i++)
    {
        ans *= 2;
    }
    cout << ans << '\n';
    return 0;
}