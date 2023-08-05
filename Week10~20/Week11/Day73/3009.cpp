#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    // 네 번째 점은 다른 세 점에서 나온 점 중 홀수인 점을 모으면 됨
    int x, y;
    int xpoints[1001];
    int ypoints[1001];
    fill_n(xpoints, 1001, 0);
    fill_n(ypoints, 1001, 0);
    for(int i = 0; i < 3; i++)
    {
        cin >> x >> y;
        xpoints[x]++;
        ypoints[y]++;
    }
    for(int i = 0; i <= 1000; i++)
    {
        if(xpoints[i] % 2 == 1)
        {
            cout << i << ' ';
        }
    }
    for(int i = 0; i <= 1000; i++)
    {
        if(ypoints[i] % 2 == 1)
        {
            cout << i << '\n';
        }
    }
    return 0;
}