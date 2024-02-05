#include <iostream>

using namespace std;

int main(void)
{
    int n;
    cin >> n;
    //666이 연달아 나오는 n번째 숫자를 출력
    int cnt = 0;
    for(int i = 666; ; i++)
    {
        // 666이 연속되는지 판단해야함
        int streak = 0;
        int temp = i;
        while(temp > 0)
        {
            if(temp % 10 == 6)
            {
                streak++;
                if(streak == 3)
                {
                    cnt++;
                    break;
                }
            }
            else {
                streak = 0;
            }
            temp /= 10;
        }
        if(cnt == n)
        {
            cout << i << '\n';
            break;
        }
    }
    return 0;
}