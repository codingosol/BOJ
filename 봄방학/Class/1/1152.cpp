#include <iostream>

using namespace std;

int main(void)
{
    // 공백을 제외하고 단어의 개수를 세는 문제
    int cnt = 0;
    string str;
    while(cin >> str)
    {
        if(str == " ")
        {
            continue;
        }
        else
        {
            cnt++;
        }
    }
    cout << cnt << '\n';
    return 0;
}