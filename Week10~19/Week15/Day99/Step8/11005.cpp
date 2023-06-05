#include <iostream>

using namespace std;

char trans(int n)
{
    if(10 <= n && n <= 35)
    {
        return n+55;
    }
    else if(0 <= n && n <= 9)
    {
        return n+48;
    }
}

int main(void)
{
    int n; // n은 10진법 정수
    cin >> n;
    int m; // m은 m진법
    cin >> m;
    // n진법으로 변환하려고 할 때 m으로 계속해서 나눠가면서 몫을 문자열에 저장함
    string ans = "";
    while(n > 0)
    {
        int rem = n % m;
        char ch = trans(rem);
        ans.insert(ans.begin(),ch);
        n /= m;
    } // 거꾸로 출력되고 있음 나중에 연산한 값이 더 앞으로 와야함
    cout << ans << '\n';
    return 0;
}