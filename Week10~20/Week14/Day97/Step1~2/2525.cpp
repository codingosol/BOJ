#include <iostream>

using namespace std;

int main(void)
{
    int hour, min;
    cin >> hour >> min;
    int time;
    cin >> time;
    min += time;
    hour += min / 60;
    hour %= 24;
    min %= 60;
    cout << hour << ' ' << min << '\n';
    return 0;
}