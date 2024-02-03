#include <iostream>

using namespace std;

int main(void)
{
    int res[42] = {0,};
    int cnt = 0;
    for(int i = 0; i < 10; i++)
    {
        int n;
        cin >> n;
        res[n % 42]++;
    }
    for(int i = 0; i < 42; i++)
    {
        if(res[i] != 0)
        {
            cnt++;
        }
    }
    cout << cnt << '\n';
    return 0;
}