#include <iostream>
#include <cmath>

using namespace std;

int trans(char ch)
{
    if(65 <= ch && ch <= 90) // 알파벳일 경우
    {
        return ch - 55;
    }
    else if(48 <= ch && ch <= 57)
    {
        return ch - 48;
    }
}

int main(void)
{
    string str;
    cin >> str;
    int n; // str은 n진법임
    cin >> n;
    int ans = 0;
    // 문자열의 끝자리수 0 1 2 3 4 .. 제곱순
    for(int i = 0; i < str.length(); i++)
    {
        ans += trans(str[str.length()-1-i])*pow(n,i);
    }
    cout << ans << '\n';
    return 0;
}