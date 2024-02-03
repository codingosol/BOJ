#include <iostream>

using namespace std;

int main(void)
{
    // 숫자 9개로 고정
    int max = 0;
    int index = -1;
    int temp;
    for(int i = 1; i <= 9; i++)
    {
        cin >> temp;
        if(temp > max)
        {
            max = temp;
            index = i;
        }
    }
    cout << max << '\n' << index << '\n';
    return 0;
}