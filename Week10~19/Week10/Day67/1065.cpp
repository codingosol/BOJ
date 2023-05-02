#include <iostream>
#include <queue>
using namespace std;

int num[1001];

bool isright(int n) // 한수가 맞는지 판단
{
    // 어차피 1000은 한수가 아니므로 3자리라고 가정해도 됨
    if(((n/10)%10) - (n%10) == (n/100) - ((n/10)%10))
    {
        return true;
    }
    return false;
}

int main(void)
{
    int n;
    cin >> n;
    // 1보다 크거나 같고 n보다 크거나 작은 한수의 개수
    // 두자리 수까지는 무조건 등차수열임, 비교할 대상이 없기 떄문
    // 따라서 100부터 비교한 후 99를 더해준다
    if(n <= 99)
    {
        cout << n << '\n';
        return 0;
    }
    else {
        int cnt = 0;
        for(int i = 100; i <= n; i++)
        {
            if(isright(i))
                cnt++;
        }
        cout << 99 + cnt << '\n';
        return 0;
    }
}