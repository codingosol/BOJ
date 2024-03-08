#include <iostream>

using namespace std;

int main(void)
{
    int n;
    cin >> n;
    // 실제로 계산하면 무조건 int범위 초과에 시간도 오래걸림
    // 뒤의 0의 수는 곱해지는 2와 5의 수로 결정됨
    // 이를 통해서 계산
    int cnt_two = 0, cnt_five = 0;
    for(int i = n; i > 0; i--)
    {
        int temp = i;
        while(temp % 2 == 0)
        {
            cnt_two++;
            temp /= 2;
        }
        while(temp % 5 == 0)
        {
            cnt_five++;
            temp /= 5;
        }
    }
    cout << min(cnt_two,cnt_five) << '\n';
    return 0;
}