#include <iostream>

using namespace std;

typedef long long int_64;

int main(void)
{
    int_64 n;
    cin >> n;
    // 최대한 많은 고양이를 한번에 복사하고 작은 문제로 나누는 것이 빠름
    // 생성은 절대로 복제보다 많은 고양이를 만들 수 없음 -> 따라서 생성 후 복제로 최댓값까지 가는게 나음
    int_64 cur = 0;
    int cnt = 0;
    while(true)
    {
        if(n == 1)
        {
            cnt = 1;
            break;
        }
        if(n == 0)
        {
            break;
        }
        if(cur * 2 < n)
        {
            if(cur == 0)
            {
                cur = 1;
                cnt++;
            }
            else {
                cnt++;
                cur *= 2;
            }
        }
        else {
            cnt++;
            break;
        }
    }
    cout << cnt << '\n';
    return 0;
}