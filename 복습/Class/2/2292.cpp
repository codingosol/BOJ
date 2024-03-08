#include <iostream>

using namespace std;

typedef long long int_64;

int main(void)
{
    // 2->8->20->38->62
    // 6 12 18 24 순으로 증가하는 수열이라는 것을 알 수 있음
    int_64 n;
    cin >> n;
    // 1번방에서 n번방까지 몇 개의 방을 지나가야 하는지에 대한 문제
    // 브루트포스 말고 수학적으로 생각해보자 
    // 3n(n-1) + 1로 생각할 수 있음
    if(n == 1)
    {
        cout << "1\n";
        return 0;
    }
    for(int i = 1;;)
    {
        if(3*i*i - 3*i + 1 < n)
        {
            i++;
        }
        else
        {
            cout << i << '\n';
            break;
        }
    }
    return 0;
}