#include <iostream>

using namespace std;

string ans;

void solve(string str, string bomb)
{
    // 메모리초과 발생...ㅜ
    if(str.length() == 0)
    {
        ans = "FRULA";
        return;
    }
    bool flag = false; // 폭탄이 터졌는가
    for(int i = 0; i <= str.length() - bomb.length(); i++)
    {
        for(int j = 0; j < bomb.length(); j++)
        {
            if(str[i+j] != bomb[j]) // 폭탄 문자열과 일치하는지 확인
            {
                break;
            }
            if(j == bomb.length() - 1) // 끝까지 일치하다면 폭발
            {
                flag = true;
                // i에서 폭발했으므로 0~i-1 그리고 i+bomb.length() ~ end까지 
                string newstr;
                newstr = str.substr(0,i) + str.substr(i+bomb.length(),str.length() - 1);
                // cout << str.substr(0,i) << " / " << str.substr(i+bomb.length()) << '\n';
                // cout << newstr << '\n';
                solve(newstr,bomb);
            }
        }
    }
    if(!flag) // 안터졌으면
        ans = str;
}

int main(void)
{
    string str;
    cin >> str;
    string bomb;
    cin >> bomb;
    // 문자열을 받아서 안에 bomb 문자열이 있는지 검사하고 있다면 폭발시킴
    // 새로운 문자열을 만든 뒤 처음부터 다시 시작함. -> 재귀로 구현?
    solve(str,bomb);
    cout << ans << '\n';
    return 0;
}