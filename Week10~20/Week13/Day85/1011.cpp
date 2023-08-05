#include <iostream>
#include <cmath>

using namespace std;

int main(void)
{
    int testcase;
    cin >> testcase;
    while(testcase--)
    {
        int start, end;
        cin >> start >> end;
        // 이동해야 할 광년수를 구함
        int dist = end - start;
        int cnt = 0;
        int d = sqrt(dist); // 1. 제곱근 계산
        pow(d, 2) == dist ? cnt = 2 * d - 1 : cnt = 2 * d; // 2. 제곱 수 case
        if (dist > d * (d + 1)) cnt += 1; // 3. 중간 값 case
        cout << cnt << '\n';
    }
    return 0;
}