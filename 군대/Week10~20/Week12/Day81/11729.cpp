#include <iostream>
#include <cmath>

using namespace std;

void towerofhanoi(int from, int by, int to, int n) // n개의 원판을 from에서 by를 거쳐 to로 옮김
{
    if(n == 1)
    {
        cout << from << ' ' << to << '\n';
        return;
    }
    else {
        // 1. n-1번까지의 원판을 1에서 2로 옮김
        // 2. n번째 원판을 1에서 3으로 옮김
        // 3. n-1번까지의 원판을 2에서 3으로 옮김
        towerofhanoi(from, to, by, n-1);
        towerofhanoi(from, by, to, 1);
        towerofhanoi(by, from, to, n-1);
    }
}

int main(void)
{
    // 하노이의 탑 문제
    // n번 원판을 1에서 3으로 옮기는 문제는
    // 1. n-1번까지의 원판을 1에서 2로 옮김
    // 2. n번째 원판을 1에서 3으로 옮김
    // 3. n-1번까지의 원판을 2에서 3으로 옮김
    // 의 3단계로 분해할 수 있다
    int n;
    cin >> n;
    cout << int(pow(2,n)) - 1 << '\n';
    towerofhanoi(1,2,3,n);
    return 0;
}