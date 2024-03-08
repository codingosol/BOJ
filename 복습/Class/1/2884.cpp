#include <iostream>

using namespace std;

int main(void)
{
    int hour, min;
    cin >> hour >> min;
    // 여기서 45분 일찍 일어나야 함
    min -= 45;
    if(min < 0)
    {
        min += 60;
        hour -= 1;
    }
    if(hour < 0)
    {
        hour = 23;
    }
    cout << hour << ' ' << min << '\n';
    return 0;
}