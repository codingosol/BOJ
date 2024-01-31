#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int n;
    cin >> n;
    int min_x, min_y, max_x, max_y;
    min_x = 987654321, min_y = 987654321;
    max_x = -987645321, max_y = -987654321;
    int a, b;
    while(n--)
    {
        cin >> a >> b;
        if(a < min_x)
            min_x = a;
        if(a > max_x)
            max_x = a;
        if(b < min_y)
            min_y = b;
        if(b > max_y)
            max_y = b;
    }
    // 최소 좌표와 최대 좌표가 이루는 직사각형의 넓이 리턴
    cout << (max_x - min_x) * (max_y - min_y) << '\n';
    return 0;
}