#include <iostream>

using namespace std;

bool ispalindrom(string str) // 주어진 수가 팰린드롬인지 아닌지 판별
{
    for(int i = 0; i < str.length() / 2; i++)
    {
        if(str[i] != str[str.length()-i-1])
            return false;
    }
    return true;
}

int main(void)
{
    string str;
    while(true)
    {
        cin >> str;
        if(str == "0")
            break;
        else
        {
            // ispalindrom 함수 사용
            if(ispalindrom(str))
                cout << "yes\n";
            else
                cout << "no\n";
        }    
    }
    return 0;
}