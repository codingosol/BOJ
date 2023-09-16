#include <iostream>

using namespace std;

int main(void)
{
    int n;
    int plan[1001];
    int real[1001];
    int ans = 0;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> plan[i];
    }
    for(int i = 1; i <= n; i++)
    {
        cin >> real[i];
        if(real[i] >= plan[i])
            ans++;
    }
    cout << ans << '\n';
    return 0;
}