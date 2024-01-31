#include <iostream>
#include <cmath>

using namespace std;

int main(void)
{
    string a, b;
    cin >> a >> b; // 문자열 형태로 입력받음
    int len = min(a.length(),b.length()); // 더 짧은 문자열 길이 기준으로
    if(a.length() > b.length())
    {
        swap(a,b); // a가 길이가 더 짧도록 수정
    }
    // 뒤에서부터 더해야 가능함
    string ans = "";
    int num = 0;
    for(int i = 0; i < len; i++)
    {
        num += a[a.length()-1-i] - '0' + b[b.length()-1-i] - '0';
        ans.insert(ans.begin(),(num % 10)+'0');
        //cout << ans << '\n';
        num /= 10;
    } // a의 길이까지
    for(int i = len; i < b.length(); i++)
    {
        num += b[b.length()-1-i] - '0';
        ans.insert(ans.begin(),(num % 10)+'0');
        //cout << ans << '\n';
        num /= 10;
    }
    if(num > 0)
        ans.insert(ans.begin(),(num % 10)+'0');
    num /= 10;
    cout << ans << '\n';
    return 0;
}