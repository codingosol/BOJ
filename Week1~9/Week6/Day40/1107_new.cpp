#include <iostream>
#include <cmath>
using namespace std;

// 복잡할 필요 없이 브루트포스로

int button[10];

int check(int n) // n이 만들어 질 수 있는 수인지
{
    if (n == 0) {
        if (button[0]) { // 망가졌다면
            return 0;
        }
        else {
            return 1;
        }
    }
    int len = 0;
    while (n > 0) {
        if (button[n % 10]) return 0;
        n = n / 10;
        len += 1;
    }

    return len;
}

int main(void)
{
    int channel;
    cin >> channel;
    int broken;
    cin >> broken;
    int temp;
    for(int i = 0; i < broken; i++)
    {
        cin >> temp;
        button[temp] = 1; // 망가짐 표시
    } // input
    int min_num = abs(channel - 100);
    for(int i = 0; i < 1000000; i++)
    {
        int c = i;
        int len = check(c);
        if (len > 0) {
            int press = abs(c - channel);
            if (min_num > press + len)
                min_num = press + len;
        }
    }
    cout << min_num << '\n';
    return 0;
}