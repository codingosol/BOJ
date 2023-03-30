#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
    string str;
    cin >> str;
    sort(str.begin(), str.end(), greater<>()); // 내림차순으로 정렬
    // 끝자리 수가 0이며 모든 자릿수의 합이 3의 배수여야 함
    // 자리는 10000자리까지 있으므로 다 더해도 충분히 int범위 내
    int total = 0;
    for(int i = 0; i < str.length(); i++)
    {
        total += str[i] - '0';
    }
    if(str[str.length() - 1] - '0' != 0 || total % 3 != 0) // 조건검사
    {
        cout << "-1\n";
    }
    else
    {
        cout << str << "\n";
    }
    return 0;
}