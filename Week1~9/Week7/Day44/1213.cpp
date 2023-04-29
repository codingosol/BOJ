#include <iostream>
#include <string>

int alphabet[26];

using namespace std;

int main(void)
{
    string str;
    cin >> str;
    // 대문자 A가 65이므로 한글자씩 분리 후 -65하여 집어넣음
    // 펠린드롬이 되려면 모든 알파벳의 수가 짝수 혹은 하나만 홀수여야 가능함
    for(int i = 0 ; i < str.length(); i++)
    {
        alphabet[str[i] - 65]++;
    }
    int cnt = 0; // 홀수인 수의 개수
    int index = 0; // 홀수인 수의 인덱스
    for(int i = 0; i < 26; i++)
    {
        if(alphabet[i] % 2 == 1)
        {
            cnt++;
            index = i;
        }
    }
    if(cnt > 1)
    {
        cout << "I'm Sorry Hansoo\n";
    }
    else {
        string ans;
        for(int i = 0; i < 26; i++) // 앞의 절반
        {
            for(int j = 0; j < alphabet[i] / 2; j++) // 절반 먼저 더함
            {
                ans += char(i + 65);
            }
        }
        // 이제 홀수 있으면 더함
        if(cnt != 0)
            ans += char(index + 65);
        for(int i = 25; i >= 0; i--) // 뒤의 절반
        {
            for(int j = 0; j < alphabet[i] / 2; j++) // 나머지 절반 더하되 역순임
            {
                ans += char(i + 65);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}