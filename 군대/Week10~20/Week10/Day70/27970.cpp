#include <iostream>

using namespace std;

typedef long long int_64;

int main(void)
{
    /*O와 X로 이루어진 문자열이 주어진다. 모든 문자를 X로 만들 때까지 다음 연산을 반복할 때, 시행하는 연산의 횟수를 구하시오.
    문자열의 가장 왼쪽에 있는 O를 X로 바꾸고, 그보다 왼쪽에 있는 X를 전부 O로 바꾼다.*/
    string str;
    cin >> str;
    // 브루트포스로는 절대 풀 수 없는 문제
    // 문자열의 가장 왼쪽에 있는 O를 X로 바꾸고 왼쪽의 X전부를 O로 바꾼다....
    // 진짜모르겠는데?
    // 보고풀었다 -> i번쨰 인덱스의 O를 바꾸기 위해서는 2^i번의 연산이 필요함
    int_64 ans = 0, mul = 1, div = 1000000007;
    for(int i = 0; i < str.length(); i++)
    {
        if(str[i] == 'O')
        {
            ans += mul;
        }
        ans %= div;
        mul *= 2;
        mul %= div;
    }
    cout << ans << '\n';
    return 0;
}